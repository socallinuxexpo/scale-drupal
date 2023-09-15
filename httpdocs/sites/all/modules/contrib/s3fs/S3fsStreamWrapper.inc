<?php

/**
 * @file
 * Drupal stream wrapper implementation for S3 File System.
 *
 * Implements DrupalStreamWrapperInterface to provide an Amazon S3 wrapper
 * using the "s3://" scheme. It can optionally take over for the "public://"
 * stream wrapper, too.
 */

// If using Libraries instead of Composer Manager, load the AWS SDK.
if (!module_exists('composer_manager')) {
  _s3fs_load_awssdk_library();
}

use Aws\CacheInterface;
use Aws\S3\Exception\S3Exception;
use Aws\S3\StreamWrapper;
use Aws\S3\S3ClientInterface;

/**
 * The stream wrapper class.
 *
 * In the docs for this class, anywhere you see "<scheme>", it can mean either
 * "s3" or "public", depending on which stream is currently being serviced.
 */
class S3fsStreamWrapper extends StreamWrapper implements DrupalStreamWrapperInterface {

  /**
   * Stream context (this is set by PHP when a context is used).
   *
   * @var resource
   */
  public $context;

  /**
   * Hash of opened stream parameters.
   *
   * @var array
   */
  private $params = array();

  /**
   * Module configuration for stream.
   *
   * @var array
   */
  private $config = array();

  /**
   * Mode in which the stream was opened.
   *
   * @var string
   */
  private $mode;

  /**
   * Instance URI referenced as "<scheme>://key".
   *
   * @var string
   */
  protected $uri = NULL;

  /**
   * The AWS SDK for PHP S3Client object.
   *
   * @var Aws\S3\S3Client
   */
  protected $s3 = NULL;

  /**
   * The opened protocol (e.g., "s3").
   *
   * @var string
   */
  private $protocol = 's3';

  /**
   * Domain we use to access files over http.
   *
   * @var string
   */
  protected $domain = NULL;

  /**
   * Directory listing used by the dir_* methods.
   *
   * @var array
   */
  protected $dir = NULL;

  /**
   * Map for files that should be delivered with a torrent URL.
   *
   * @var array
   */
  protected $torrents = array();

  /**
   * Files that the user has said must be downloaded, rather than viewed.
   *
   * @var array
   */
  protected $saveas = array();

  /**
   * Files which should be created with URLs that eventually time out.
   *
   * @var array
   */
  protected $presignedURLs = array();

  /**
   * Default map for determining file mime types.
   *
   * @var array
   */
  protected static $mimeTypeMapping = NULL;

  /**
   * Indicates the current error state in the wrapper.
   *
   * @var bool
   */
  protected $_error_state = FALSE;


  /**
   * Stream wrapper constructor.
   *
   * Creates the Aws\S3\S3Client client object and activates the options
   * specified on the S3 File System Settings page.
   */
  public function __construct() {
    // Since S3fsStreamWrapper is always constructed with the same inputs (the
    // file uri is not part of construction), we store the constructed settings
    // statically. This is important for performance because the way Drupal's
    // APIs are used causes stream wrappers to be frequently re-constructed.
    // Get the S3 client object and register the stream wrapper again so it is
    // configured as needed.
    $settings = &drupal_static('S3fsStreamWrapper_constructed_settings');

    if ($settings !== NULL) {
      $this->config = $settings['config'];
      $this->domain = $settings['domain'];
      $this->torrents = $settings['torrents'];
      $this->presignedURLs = $settings['presignedURLs'];
      $this->saveas = $settings['saveas'];
      $this->s3 = _s3fs_get_amazons3_client($this->config);
      $this->register($this->s3);
      return;
    }

    // Begin construction if not cached.
    $this->config = _s3fs_get_config();
    $this->s3 = _s3fs_get_amazons3_client($this->config);
    $this->register($this->s3);
    $this->context = stream_context_get_default();
    stream_context_set_option($this->context, 's3', 'seekable', TRUE);

    // Check if bucket is configured.
    if (empty($this->config['bucket'])) {
      $msg = t('Your AmazonS3 bucket name is not configured. Please visit the !settings_page.',
        array('!settings_page' => l(t('configuration page'), '/admin/config/media/s3fs/settings')));
      watchdog('S3 File System', $msg, array(), WATCHDOG_ERROR);
      throw new Exception($msg);
    }

    // Always use HTTPS when the page is being served via HTTPS, to avoid
    // complaints from the browser about insecure content.
    global $is_https;
    if ($is_https) {
      // We change the config itself, rather than simply using $is_https in
      // the following if condition, because $this->config['use_https'] gets
      // used again later.
      $this->config['use_https'] = TRUE;
    }

    $scheme = (!empty($this->config['use_https'])) ? 'https' : 'http';

    // CNAME support for customizing S3 URLs.
    // If use_cname is not enabled, file URLs do not use $this->domain.
    if (!empty($this->config['use_cname']) && !empty($this->config['domain'])) {
      $domain = check_url($this->config['domain']);
      if ($domain) {
        // If domain is set to a root-relative path, add the hostname back in.
        if (strpos($domain, '/') === 0) {
          $domain = $_SERVER['HTTP_HOST'] . $domain;
        }
        $this->domain = "$scheme://$domain";
      }
      else {
        // Due to the config form's validation, this shouldn't ever happen.
        throw new Exception(t('The "Use a CNAME" option is enabled, but no CDN Domain Name has been set.'));
      }
    }

    // Convert the torrents string to an array.
    if (!empty($this->config['torrents'])) {
      foreach (explode("\n", $this->config['torrents']) as $line) {
        $blob = trim($line);
        if ($blob) {
          $this->torrents[] = $blob;
        }
      }
    }

    // Convert the presigned URLs string to an associative array like
    // array(blob => timeout).
    if (!empty($this->config['presigned_urls'])) {
      foreach (explode("\n", $this->config['presigned_urls']) as $line) {
        $blob = trim($line);
        if ($blob) {
          $matches = array();
          if (preg_match('/(.*)\|(.*)/', $blob, $matches)) {
            $blob = $matches[2];
            $timeout = $matches[1];
            $this->presignedURLs[$blob] = $timeout;
          }
          else {
            $this->presignedURLs[$blob] = 60;
          }
        }
      }
    }

    // Convert the forced save-as string to an array.
    if (!empty($this->config['saveas'])) {
      foreach (explode("\n", $this->config['saveas']) as $line) {
        $blob = trim($line);
        if ($blob) {
          $this->saveas[] = $blob;
        }
      }
    }

    // Save all the work we just did, so that subsequent S3fsStreamWrapper
    // constructions don't have to repeat it.
    $settings['config'] = $this->config;
    $settings['domain'] = $this->domain;
    $settings['torrents'] = $this->torrents;
    $settings['presignedURLs'] = $this->presignedURLs;
    $settings['saveas'] = $this->saveas;
  }

  /**
   * Ensure the S3 protocol is registered to this class and not parents.
   *
   * @param \Aws\S3\S3ClientInterface $client
   * @param string $protocol
   * @param \Aws\CacheInterface|null $cache
   */
  public static function register(S3ClientInterface $client, $protocol = 's3', CacheInterface $cache = null) {
    parent::register($client, $protocol, $cache);
  }

  /***************************************************************************
                 DrupalStreamWrapperInterface Implementations
  ***************************************************************************/

  public static function getMimeType($uri, $mapping = NULL) {
    // Load the default mime type map.
    if (!isset(self::$mimeTypeMapping)) {
      include_once DRUPAL_ROOT . '/includes/file.mimetypes.inc';
      self::$mimeTypeMapping = file_mimetype_mapping();
    }

    // If a mapping wasn't specified, use the default map.
    if ($mapping == NULL) {
      $mapping = self::$mimeTypeMapping;
    }

    $extension = '';
    $file_parts = explode('.', drupal_basename($uri));

    // Remove the first part: a full filename should not match an extension.
    array_shift($file_parts);

    // Iterate over the file parts, trying to find a match.
    // For my.awesome.image.jpeg, we try:
    // - jpeg
    // - image.jpeg
    // - awesome.image.jpeg
    while ($additional_part = array_pop($file_parts)) {
      $extension = strtolower($additional_part . ($extension ? '.' . $extension : ''));
      if (isset($mapping['extensions'][$extension])) {
        return $mapping['mimetypes'][$mapping['extensions'][$extension]];
      }
    }

    // No mime type matches, so return the default.
    return 'application/octet-stream';
  }

  /**
   * Sets the stream resource URI. URIs are formatted as "<scheme>://filepath".
   *
   * @param string $uri
   *   The URI that should be used for this instance.
   */
  public function setUri($uri) {
    $this->_prevent_cross_scheme_access($uri);
    $this->uri = $uri;
  }

  /**
   * Returns the stream resource URI, which looks like "<scheme>://filepath".
   *
   * @return string
   *   The current URI of the instance.
   */
  public function getUri() {
    return $this->uri;
  }

  /**
   * Returns a web accessible URL for the resource.
   *
   * The format of the returned URL will be different depending on how the S3
   * integration has been configured on the S3 File System admin page.
   *
   * @param bool $no_redirect
   *  A custom parameter for internal use by s3fs.
   *
   * @return string
   *   A web accessible URL for the resource.
   */
  public function getExternalUrl() {
    // In case we're on Windows, replace backslashes with forward-slashes.
    // Note that $uri is the unaltered value of the File's URI, while
    // $s3_key may be changed at various points to account for implementation
    // details on the S3 side (e.g. root_folder, s3fs_public_folder).
    $s3_key = str_replace('\\', '/', file_uri_target($this->uri));

    // If this is a private:// file, it must be served through the
    // system/files/$uri URL, which allows Drupal to restrict access
    // based on who's logged in.
    if (file_uri_scheme($this->uri) == 'private') {
      return url("system/files/$s3_key", array('absolute' => TRUE));
    }

    // When generating an image derivative URL, e.g. styles/thumbnail/blah.jpg,
    // if the file doesn't exist, provide a URL to s3fs's special version of
    // image_style_deliver(), which will create the derivative when that URL
    // gets requested.
    $uri_parts = explode('/', $s3_key);
    if ($uri_parts[0] == 'styles' && substr($s3_key, -4) != '.css') {
      $metadata = $this->_s3fs_get_object($this->uri);
      $is_zero_byte = !isset($metadata['filesize']) || $metadata['filesize'] == 0;
      if (!$metadata || $is_zero_byte) {
        if ($is_zero_byte) {
          $this->unlink($this->uri);
        }
        // The style delivery path looks like: s3/files/styles/thumbnail/...
        // And $uri_parts looks like array('styles', 'thumbnail', ...),
        // so just prepend s3/files/.
        array_unshift($uri_parts, 's3', 'files');
        return url(implode('/', $uri_parts), array('absolute' => TRUE));
      }
      unset($metadata);
    }

    // Deal with public:// files.
    if (file_uri_scheme($this->uri) == 'public') {
      // Rewrite all css/js file paths unless the user has told us not to.
      if (empty($this->config['no_rewrite_cssjs'])) {
        if (substr($s3_key, -4) == '.css') {
          // Send requests for public CSS files to /s3fs-css/path/to/file.css.
          // Users must set that path up in the webserver config as a proxy into
          // their S3 bucket's s3fs_public_folder.
          return "{$GLOBALS['base_url']}/s3fs-css/" . drupal_encode_path($s3_key);
        }
        elseif (substr($s3_key, -3) == '.js') {
          // Send requests for public JS files to /s3fs-js/path/to/file.js.
          // Like with CSS, the user must set up that path as a proxy.
          return "{$GLOBALS['base_url']}/s3fs-js/" . drupal_encode_path($s3_key);
        }
      }

      // public:// files are stored in S3 inside the s3fs_public_folder.
      $public_folder = !empty($this->config['public_folder']) ? $this->config['public_folder'] : 's3fs-public';
      // If domain root is not set, or the value is set to map to the root
      // folder, include the public folder.
      if ($this->config['domain_root'] == 'none' || $this->config['domain_root'] == 'root') {
        $s3_key = "{$public_folder}/$s3_key";
      }
    }

    // Set up the URL settings as specified in our settings page.
    $url_settings = array(
      'torrent' => FALSE,
      'presigned_url' => FALSE,
      'timeout' => 60,
      'forced_saveas' => FALSE,
      'api_args' => array('Scheme' => !empty($this->config['use_https']) ? 'https' : 'http'),
      'custom_GET_args' => array(),
    );

    // Presigned URLs.
    foreach ($this->presignedURLs as $blob => $timeout) {
      // ^ is used as the delimeter because it's an illegal character in URLs.
      if (preg_match("^$blob^", $s3_key)) {
        $url_settings['presigned_url'] = TRUE;
        $url_settings['timeout'] = $timeout;
        break;
      }
    }
    // Forced Save As.
    foreach ($this->saveas as $blob) {
      if (preg_match("^$blob^", $s3_key)) {
        $filename = drupal_basename($s3_key);
        $url_settings['api_args']['ResponseContentDisposition'] = "attachment; filename=\"$filename\"";
        $url_settings['forced_saveas'] = TRUE;
        break;
      }
    }

    // Allow other modules to change the URL settings.
    drupal_alter('s3fs_url_settings', $url_settings, $s3_key);

    // If a root folder has been set, and domain root is not set, prepend
    // the root folder to the $s3_key at this time.
    if (!empty($this->config['root_folder']) && ($this->config['domain_root'] == 'none')) {
      $s3_key = "{$this->config['root_folder']}/$s3_key";
    }

    if (empty($this->config['use_cname'])) {
      // We're not using a CNAME, so we ask S3 for the URL.
      $expires = NULL;
      if ($url_settings['presigned_url']) {
        $expires = "+{$url_settings['timeout']} seconds";
      }
      else {
        // Due to Amazon's security policies (see Request Parameters section @
        // http://docs.aws.amazon.com/AmazonS3/latest/API/RESTObjectGET.html),
        // only signed requests can use request parameters.
        // Thus, we must provide an expiry time for any URLs which specify
        // Response* API args. Currently, this only includes "Forced Save As".
        foreach ($url_settings['api_args'] as $key => $arg) {
          if (strpos($key, 'Response') === 0) {
            $expires = "+10 years";
            break;
          }
        }
      }
      if ($url_settings['presigned_url']) {
        $cmd = $this->s3->getCommand('GetObject', array(
          'Bucket' => $this->config['bucket'],
          'Key' => $s3_key,
        ));
        $external_url = (string) $this->s3->createPresignedRequest($cmd, $expires)->getUri();
      }
      else {
        $external_url = $this->s3->getObjectUrl($this->config['bucket'], $s3_key);
      }
    }
    else {
      // We are using a CNAME, so we need to manually construct the URL.
      $external_url = "{$this->domain}/$s3_key";
    }

    // If this file is versioned, append the version number as a GET arg to
    // ensure that browser caches will be bypassed upon version changes.
    $meta = $this->_read_cache($this->uri);
    if (!empty($meta['version']) && !empty($this->config['use_versioning'])) {
      $external_url = $this->_append_get_arg($external_url, $meta['version']);
    }
    // Torrents can only be created for publicly-accessible files:
    // https://forums.aws.amazon.com/thread.jspa?threadID=140949
    // So Forced SaveAs and Presigned URLs cannot be served as torrents.
    if (!$url_settings['forced_saveas'] && !$url_settings['presigned_url']) {
      foreach ($this->torrents as $blob) {
        if (preg_match("^$blob^", $s3_key)) {
          // You get a torrent URL by adding a "torrent" GET arg.
          $external_url = $this->_append_get_arg($external_url, 'torrent');
          break;
        }
      }
    }

    // If another module added a 'custom_GET_args' array to the url settings, process it here.
    if (!empty($url_settings['custom_GET_args'])) {
      foreach ($url_settings['custom_GET_args'] as $name => $value) {
        $external_url = $this->_append_get_arg($external_url, $name, $value);
      }
    }

    return $external_url;
  }

  /**
   * Gets the path that the wrapper is responsible for.
   *
   * This function isn't part of DrupalStreamWrapperInterface, but the rest
   * of Drupal calls it as if it were, so we need to define it.
   *
   * @return string
   *   The empty string. Since this is a remote stream wrapper,
   *   it has no directory path.
   */
  public function getDirectoryPath() {
    return '';
  }

  /***************************************************************************
              Public Functions for External Use of the Wrapper
  ***************************************************************************/

  /**
   * Wait for the specified file to exist in the bucket.
   *
   * @param string $uri
   *   The uri of the file.
   *
   * @return bool
   *   Returns TRUE once the waiting finishes, or FALSE if the file does not
   *   begin to exist within 10 seconds.
   */
  public function waitUntilFileExists($uri) {
    $this->_prevent_cross_scheme_access($uri);
    // Retry ten times, once every second.
    $params = $this->getCommandParams($uri);
    $params['@waiter'] = array(
      'delay' => 1,
      'maxAttempts' => 10,
    );
    try {
      $this->s3->waitUntil('ObjectExists', $params);
      return TRUE;
    }
    catch (S3Exception $e) {
      watchdog_exception('S3FS', $e);
      return FALSE;
    }
  }

  /**
   * Write the file at the given uri into the metadata cache.
   *
   * This function is public so that other code can upload files to S3 and
   * then have us write the correct metadata into our cache.
   */
  public function writeUriToCache($uri) {
    $this->_prevent_cross_scheme_access($uri);
    if ($this->waitUntilFileExists($uri)) {
      $metadata = $this->_get_metadata_from_s3($uri);
      $this->_write_cache($metadata);
      clearstatcache(TRUE, $uri);
    }
  }

  /***************************************************************************
                      PHP Stream Wrapper Implementations
  ***************************************************************************/

  /**
   * This wrapper doesn't support file permissions.
   *
   * @param int $mode
   *   The file's desired permissions in octal. Consult PHP chmod() documentation
   *   for more information.
   *
   * @return bool
   *   Always returns TRUE.
   */
  public function chmod($mode) {
    $octal_mode = decoct($mode);
    return TRUE;
  }

  /**
   * This wrapper does not support realpath().
   *
   * @return bool
   *   Always returns FALSE.
   */
  public function realpath() {
    return FALSE;
  }

  /**
   * Gets the name of the parent directory of a given path.
   *
   * This method is usually accessed through drupal_dirname(), which wraps
   * around the normal PHP dirname() function, since it doesn't support stream
   * wrappers.
   *
   * @param string $uri
   *   An optional URI.
   *
   * @return string
   *   The directory name, or FALSE if not applicable.
   *
   * @see drupal_dirname()
   */
  public function dirname($uri = NULL) {
    if (!isset($uri)) {
      $uri = $this->uri;
    }
    $scheme = file_uri_scheme($uri);
    $dirname = dirname(file_uri_target($uri));

    // When the dirname() call above is given '$scheme://', it returns '.'.
    // But '$scheme://.' is an invalid uri, so we return "$scheme://" instead.
    if ($dirname == '.') {
      $dirname = '';
    }

    return "$scheme://$dirname";
  }

  /**
   * Support for fopen(), file_get_contents(), file_put_contents() etc.
   *
   * @param string $uri
   *   The URI of the file to open.
   * @param string $mode
   *   The file mode. Only 'r', 'w', 'a', and 'x' are supported.
   * @param int $options
   *   A bit mask of STREAM_USE_PATH and STREAM_REPORT_ERRORS.
   * @param string $opened_path
   *   An OUT parameter populated with the path which was opened.
   *   This wrapper does not support this parameter.
   *
   * @return bool
   *   TRUE if file was opened successfully. Otherwise, FALSE.
   *
   * @see http://php.net/manual/en/streamwrapper.stream-open.php
   */
  public function stream_open($uri, $mode, $options, &$opened_path) {
    $this->setUri($uri);
    $converted = $this->convertUriToKeyedPath($uri);
    return parent::stream_open($converted, $mode, $options, $opened_path);
  }

  /**
   * This wrapper does not support flock().
   *
   * @return bool
   *   Always Returns FALSE.
   *
   * @see http://php.net/manual/en/streamwrapper.stream-lock.php
   */
  public function stream_lock($operation) {
    return FALSE;
  }

  public function stream_metadata($path, $option, $value) {
    return FALSE;
  }

  /**
   * Support for fflush(). Flush current cached stream data to a file in S3.
   *
   * @return bool
   *   TRUE if data was successfully stored in S3.
   *
   * @see http://php.net/manual/en/streamwrapper.stream-flush.php
   */
  public function stream_flush() {
    // Prepare upload parameters.
    $options = $this->getOptions();

    $options[$this->protocol]['ContentType'] = $this->getMimeType($this->uri);

    // All non-private files uploaded to S3 must be set to public-read, or users' browsers
    // will get PermissionDenied errors, and torrent URLs won't work. The one exception to
    // this is when all content is being routed through an edge service and access via S3
    // should be blocked.
    if (!empty($this->config['use_cname']) && !empty($this->config['domain']) && !empty($this->config['domain_s3_private'])) {
      $options[$this->protocol]['ACL'] = 'private';
    }
    elseif (file_uri_scheme($this->uri) != 'private') {
      // All non-private files uploaded to S3 must be set to public-read, or users' browsers
      // will get PermissionDenied errors, and torrent URLs won't work.
      $options[$this->protocol]['ACL'] = 'public-read';
    }
    // Set the Cache-Control header, if the user specified one.
    if (!empty($this->config['cache_control_header'])) {
      $options[$this->protocol]['CacheControl'] = $this->config['cache_control_header'];
    }

    if (!empty($this->config['encryption'])) {
      $options[$this->protocol]['ServerSideEncryption'] = $this->config['encryption'];
    }

    // Legacy support: set bucket and key values that were present with
    // AWS SDK v2. Used by AdvAgg module with hook_s3fs_upload_params_alter().
    $options[$this->protocol]['Bucket'] = $this->config['bucket'];
    $convertedPath = $this->convertUriToKeyedPath($this->uri, FALSE);
    $options[$this->protocol]['Key'] = file_uri_target($convertedPath);

    // Allow other modules to alter the upload params.
    drupal_alter('s3fs_upload_params', $options[$this->protocol]);

    // Legacy support: unset bucket and key values. Retaining them will
    // cause conflicts when saving AdvAgg's aggregated css/js files.
    unset($options[$this->protocol]['Bucket']);
    unset($options[$this->protocol]['Key']);

    stream_context_set_option($this->context, $options);

    if (parent::stream_flush()) {
      $this->writeUriToCache($this->uri);
      return TRUE;
    }
    else {
      return FALSE;
    }
  }

  /**
   * Support for unlink().
   *
   * @param string $uri
   *   The uri of the resource to delete.
   *
   * @return bool
   *   TRUE if resource was successfully deleted, regardless of whether or not
   *   the file actually existed.
   *   FALSE if the call to S3 failed, in which case the file will not be
   *   removed from the cache.
   *
   * @see http://php.net/manual/en/streamwrapper.unlink.php
   */
  public function unlink($uri) {
    $this->setUri($uri);
    $converted = $this->convertUriToKeyedPath($uri);
    if (parent::unlink($converted)) {
      $this->_delete_cache($uri);
      clearstatcache(TRUE, $uri);
      return TRUE;
    }
    else {
      return FALSE;
    }
  }

  public function url_stat($uri, $flags) {
    $this->setUri($uri);
    return $this->_stat($uri);
  }

  /**
   * Support for mkdir().
   *
   * @param string $uri
   *   The URI to the directory to create.
   * @param int $mode
   *   Permission flags - see mkdir().
   * @param int $options
   *   A bit mask of STREAM_REPORT_ERRORS and STREAM_MKDIR_RECURSIVE.
   *
   * @return bool
   *   TRUE if the directory was successfully created. Otherwise, FALSE.
   *
   * @see http://php.net/manual/en/streamwrapper.mkdir.php
   */
  public function mkdir($uri, $mode, $options) {
    // Some Drupal plugins call mkdir with a trailing slash. We mustn't store
    // that slash in the cache.
    $uri = rtrim($uri, '/');

    $this->_prevent_cross_scheme_access($uri);

    clearstatcache(TRUE, $uri);
    // If this uri already exists in the cache, return TRUE if it's a folder
    // (so that recursive calls won't improperly report failure when they
    // reach an existing ancestor), or FALSE if it's a file (failure).
    $test_metadata = $this->_read_cache($uri);
    if ($test_metadata) {
      return (bool) $test_metadata['dir'];
    }

    // S3 is a flat file system, with no concept of directories (just files
    // with slashes in their names). We store folders in the metadata cache,
    // but don't create an object for them in S3.
    $metadata = _s3fs_convert_metadata($uri, array());
    $this->_write_cache($metadata);

    // If the STREAM_MKDIR_RECURSIVE option was specified, also create all the
    // ancestor folders of this uri, except for the root directory.
    $parent_dir = drupal_dirname($uri);
    if (($options & STREAM_MKDIR_RECURSIVE) && file_uri_target($parent_dir) != '') {
      return $this->mkdir($parent_dir, $mode, $options);
    }
    return TRUE;
  }

  /**
   * Support for rmdir().
   *
   * @param string $uri
   *   The URI to the folder to delete.
   * @param int $options
   *   A bit mask of STREAM_REPORT_ERRORS.
   *
   * @return bool
   *   TRUE if folder is successfully removed.
   *   FALSE if $uri isn't a folder, or the folder is not empty.
   *
   * @see http://php.net/manual/en/streamwrapper.rmdir.php
   */
  public function rmdir($uri, $options) {
    if (!$this->_path_is_dir($uri)) {
      return FALSE;
    }

    // We need a version of $uri with no / because folders are cached with no /.
    // We also need one with the /, because it might be a file in S3 that
    // ends with /. In addition, we must differentiate against files with this
    // folder's name as a substring.
    // e.g. rmdir('s3://foo/bar') should ignore s3://foo/barbell.jpg.
    $bare_path = rtrim($uri, '/');
    $slash_path = $bare_path . '/';

    $this->_prevent_cross_scheme_access($uri);

    // If the folder is empty, it's eligible for deletion.
    $file_count = db_select('s3fs_file', 's')
      ->fields('s')
      ->condition('uri', db_like($slash_path) . '%', 'LIKE')
      ->execute()
      ->rowCount();
    if ($file_count === 0) {
      if (parent::rmdir($this->convertUriToKeyedPath($uri), $options)) {
        $this->_delete_cache($uri);
        clearstatcache(TRUE, $uri);
        return TRUE;
      }
    }

    // The folder is non-empty.
    return FALSE;
  }

  /**
   * Support for opendir().
   *
   * @param string $uri
   *   The URI to the directory to open.
   * @param int $options
   *   A flag used to enable safe_mode.
   *   This wrapper doesn't support safe_mode, so this parameter is ignored.
   *
   * @return bool
   *   TRUE on success. Otherwise, FALSE.
   *
   * @see http://php.net/manual/en/streamwrapper.dir-opendir.php
   */
  public function dir_opendir($uri, $options = NULL) {
    $this->_prevent_cross_scheme_access($uri);

    if (!$this->_path_is_dir($uri)) {
      return FALSE;
    }

    $scheme = file_uri_scheme($uri);
    $bare_path = rtrim($uri, '/');
    $slash_path = $bare_path . '/';

    // If this path was originally a root folder (e.g. s3://), the above code
    // removed *both* slashes but only added one back. So we need to add
    // back the second slash.
    if ($slash_path == "$scheme:/") {
      $slash_path = "$scheme://";
    }

    $public_folder = !empty($this->config['public_folder']) ? $this->config['public_folder'] : 's3fs-public';
    $public_folder = trim($public_folder, '/');
    $private_folder = !empty($this->config['private_folder']) ? $this->config['private_folder'] : 's3fs-private';
    $private_folder = trim($private_folder, '/');

    // Get the list of paths for files and folders which are children of the
    // specified folder, but not grandchildren.
    $query = db_select('s3fs_file', 's')
      ->fields('s', array('uri'))
      ->condition('uri', db_like($slash_path) . '%', 'LIKE')
      ->condition('uri', db_like($slash_path) . '%/%', 'NOT LIKE');

    switch (file_uri_scheme($slash_path)) {
      case 's3':
        // Prevent private and public folder from showing nested under
        // s3://.
        $query->condition('uri', 's3://' . db_like($public_folder) . '/%', 'NOT LIKE');
        $query->condition('uri', 's3://' . $public_folder, '<>');
        $query->condition('uri', 's3://' . db_like($private_folder) . '/%', 'NOT LIKE');
        $query->condition('uri', 's3://' . $private_folder, '<>');
        break;

      case 'public':
        // Prevent the private folder from appearing nested under public://.
        if (strpos($private_folder, $public_folder) === 0) {
          $private_search = '#^' . $private_folder . '#';
          $prefix = preg_replace($private_search, '', $public_folder);
          $query->condition('uri', 'public://' . db_like($prefix) . '/%', 'NOT LIKE');
          $query->condition('uri', 'public://' . $prefix, '<>');
        }
        break;

     case 'private':
        // Prevent the public folder from showing up nested under
        // private://.
        if (strpos($public_folder, $private_folder) === 0) {
          $public_search = '#^' . $public_folder . '#';
          $prefix = preg_replace($public_search, '', $private_folder);
          $query->condition('uri', 'private://' . db_like($prefix) . '/%', 'NOT LIKE');
          $query->condition('uri', 'private://' . $prefix, '<>');
        }
        break;
    }

    $child_paths = $query->execute()->fetchCol(0);

    $this->dir = array();
    foreach ($child_paths as $child_path) {
      $this->dir[] = drupal_basename($child_path);
    }
    return TRUE;
  }

  /**
   * Support for readdir().
   *
   * @return string
   *   The next filename, or FALSE if there are no more files in the directory.
   *
   * @see http://php.net/manual/en/streamwrapper.dir-readdir.php
   */
  public function dir_readdir() {
    $current = current($this->dir);
    if ($current) {
      next($this->dir);
    }
    return $current;
  }

  public function rename($from_path, $to_path) {
    $this->_prevent_cross_scheme_access($from_path);
    $this->_prevent_cross_scheme_access($to_path);

    // Set access for new item in stream context.
    if (file_uri_scheme($from_path) != 'private') {
      stream_context_set_option($this->context, 's3', 'ACL', 'public-read');
    }

    // If parent succeeds in renaming, updated local metadata and cache.
    if (parent::rename($this->convertUriToKeyedPath($from_path), $this->convertUriToKeyedPath($to_path))) {
      $metadata = $this->_read_cache($from_path);
      $metadata['uri'] = $to_path;
      $this->_write_cache($metadata);
      $this->_delete_cache($from_path);
      clearstatcache(TRUE, $from_path);
      clearstatcache(TRUE, $to_path);
      return TRUE;
    }
    else {
      return FALSE;
    }
  }

  /***************************************************************************
                              Internal Functions
  ***************************************************************************/

  /**
   * Determine whether the $uri is a directory.
   *
   * @param string $uri
   *   The path of the resource to check.
   *
   * @return bool
   *   TRUE if the resource is a directory.
   */
  protected function _path_is_dir($uri) {
    $metadata = $this->_s3fs_get_object($uri);
    return $metadata ? $metadata['dir'] : FALSE;
  }

  /**
   * Implementation of a stat method to ensure that remote files don't fail
   * checks when they should pass.
   *
   * @param $uri
   * @return array|bool
   */
  protected function _stat($uri) {
    $this->_prevent_cross_scheme_access($uri);

    $metadata = $this->_s3fs_get_object($uri);
    if ($metadata) {
      $stat = array();
      $stat[0]  = $stat['dev'] = 0;
      $stat[1]  = $stat['ino'] = 0;
      // Use the S_IFDIR posix flag for directories, S_IFREG for files.
      // All files are considered writable, so OR in 0777.
      $stat[2]  = $stat['mode'] = ($metadata['dir'] ? 0040000 : 0100000) | 0777;
      $stat[3]  = $stat['nlink'] = 0;
      $stat[4]  = $stat['uid'] = 0;
      $stat[5]  = $stat['gid'] = 0;
      $stat[6]  = $stat['rdev'] = 0;
      $stat[7]  = $stat['size'] = 0;
      $stat[8]  = $stat['atime'] = 0;
      $stat[9]  = $stat['mtime'] = 0;
      $stat[10] = $stat['ctime'] = 0;
      $stat[11] = $stat['blksize'] = 0;
      $stat[12] = $stat['blocks'] = 0;

      if (!$metadata['dir']) {
        $stat[4]  = $stat['uid'] = 's3fs';
        $stat[7]  = $stat['size'] = $metadata['filesize'];
        $stat[8]  = $stat['atime'] = $metadata['timestamp'];
        $stat[9]  = $stat['mtime'] = $metadata['timestamp'];
        $stat[10] = $stat['ctime'] = $metadata['timestamp'];
      }
      return $stat;
    }
    return FALSE;
  }

  /**
   * Try to fetch an object from the metadata cache.
   *
   * If that file isn't in the cache, we assume it does not exist.
   *
   * @param string $uri
   *   The uri of the resource to check.
   *
   * @return array|bool
   *   An array if the $uri exists, otherwise FALSE.
   */
  protected function _s3fs_get_object($uri) {
    // For the root directory, return metadata for a generic folder.
    if (file_uri_target($uri) == '') {
      return _s3fs_convert_metadata('/', array());
    }

    // Trim any trailing '/', in case this is a folder request.
    $uri = rtrim($uri, '/');

    // Check if this uri is in the cache.
    $metadata = $this->_read_cache($uri);

    // If cache ignore is enabled, query S3 for all uris which aren't in the
    // cache, and non-folder uris which are.
    if (!empty($this->config['ignore_cache']) && !$metadata['dir']) {
      try {
        // If _get_metadata_from_s3() returns FALSE, the file doesn't exist.
        $metadata = $this->_get_metadata_from_s3($uri);
      }
      catch (\Exception $e) {
        return $this->_trigger_error($e->getMessage());
      }
    }

    return $metadata;
  }

  /**
   * Fetch an object from the file metadata cache table.
   *
   * @param string $uri
   *   The uri of the resource to check.
   *
   * @return array|bool
   *   An array of metadata if the $uri is in the cache. Otherwise, FALSE.
   */
  protected function _read_cache($uri) {
    // Since public:///blah.jpg and public://blah.jpg refer to the same file
    // (a file named blah.jpg at the root of the file system), we'll sometimes
    // receive files with a /// in their uri. This messes with our caching
    // scheme, though, so we need to remove the extra /.
    if (strpos($uri, 'public:///') === 0) {
      $uri = preg_replace('^public://[/]+^', 'public://', $uri);
    }
    elseif (strpos($uri, 'private:///') === 0) {
      $uri = preg_replace('^private://[/]+^', 'private://', $uri);
    }

    $public_folder = !empty($this->config['public_folder']) ? $this->config['public_folder'] : 's3fs-public';
    $public_folder = trim($public_folder, '/');
    $private_folder = !empty($this->config['private_folder']) ? $this->config['private_folder'] : 's3fs-private';
    $private_folder = trim($private_folder, '/');

    $query = db_select('s3fs_file', 's')
      ->fields('s')
      ->condition('uri', $uri, '=');

    switch (file_uri_scheme($uri)) {
      case 's3':
        // Prevent private and public folder from showing nested under
        // s3://.
        $query->condition('uri', 's3://' . db_like($public_folder) . '/%', 'NOT LIKE');
        $query->condition('uri', 's3://' . $public_folder, '<>');
        $query->condition('uri', 's3://' . db_like($private_folder) . '/%', 'NOT LIKE');
        $query->condition('uri', 's3://' . $private_folder, '<>');
        break;

      case 'public':
        // Prevent the private folder from appearing nested under public://.
        if (strpos($private_folder, $public_folder) === 0) {
          $private_search = '#^' . $private_folder . '#';
          $prefix = preg_replace($private_search, '', $public_folder);
          $query->condition('uri', 'public://' . db_like($prefix) . '/%', 'NOT LIKE');
          $query->condition('uri', 'public://' . $prefix, '<>');
        }
        break;

      case 'private':
        // Prevent the public folder from showing up nested under
        // private://.
        if (strpos($public_folder, $private_folder) === 0) {
          $public_search = '#^' . $public_folder . '#';
          $prefix = preg_replace($public_search, '', $private_folder);
          $query->condition('uri', 'private://' . db_like($prefix) . '/%', 'NOT LIKE');
          $query->condition('uri', 'private://' . $prefix, '<>');
        }
        break;
    }

    $record = $query->execute()->fetchAssoc();

    return $record ? $record : FALSE;
  }

  /**
   * Write an object's (and its ancestor folders') metadata to the cache.
   *
   * @param array $metadata
   *   An associative array of file metadata in this format:
   *     'uri' => The full URI of the file, including the scheme.
   *     'filesize' => The size of the file, in bytes.
   *     'timestamp' => The file's create/update timestamp.
   *     'dir' => A boolean indicating whether the object is a directory.
   *
   * @throws
   *   Exceptions which occur in the database call will percolate.
   */
  protected function _write_cache($metadata) {
    // Since public:///blah.jpg and public://blah.jpg refer to the same file
    // (a file named blah.jpg at the root of the file system), we'll sometimes
    // receive files with a /// in their URI. This messes with our caching
    // scheme, though, so we need to remove the extra /.
    if (strpos($metadata['uri'], 'public:///') === 0) {
      $metadata['uri'] = preg_replace('^public://[/]+^', 'public://', $metadata['uri']);
    }
    elseif (strpos($metadata['uri'], 'private:///') === 0) {
      $metadata['uri'] = preg_replace('^private://[/]+^', 'private://', $metadata['uri']);
    }

    db_merge('s3fs_file')
      ->key(array('uri' => $metadata['uri']))
      ->fields($metadata)
      ->execute();

    $dirname = drupal_dirname($metadata['uri']);
    // If this file isn't in the root directory, also write this file's
    // ancestor folders to the cache.
    if (file_uri_target($dirname) != '') {
      $this->mkdir($dirname, NULL, STREAM_MKDIR_RECURSIVE);
    }
  }

  /**
   * Delete an object's metadata from the cache.
   *
   * @param mixed $uri
   *   A string (or array of strings) containing the uri(s) of the object(s)
   *   to be deleted.
   *
   * @return object|bool
   *   Returns a query object or FALSE.
   *
   * @throws
   *   Exceptions which occur in the database call will percolate.
   */
  protected function _delete_cache($uri) {
    if (!is_array($uri)) {
      $uri = array($uri);
    }

    // Build an OR query to delete all the URIs at once.
    $delete_query = db_delete('s3fs_file');
    $or = db_or();
    foreach ($uri as $u) {
      $or->condition('uri', $u, '=');
    }
    $delete_query->condition($or);
    return $delete_query->execute();
  }

  /**
   * Get the stream's context options or remove them if wanting default.
   *
   * @param bool $removeContextData
   *   Whether to remove the stream's context information.
   *
   * @return array
   *   An array of options.
   */
  public function getOptions($removeContextData = false) {
    // Context is not set when doing things like stat
    if (is_null($this->context)) {
      $this->context = stream_context_get_default();
    }
    $options = stream_context_get_options($this->context);

    if ($removeContextData) {
      unset($options['client'], $options['seekable'], $options['cache']);
    }

    return $options;
  }

  /**
   * Converts a Drupal URI path into what is expected to be stored in S3.
   *
   * @param $uri
   *   An appropriate URI formatted like 'protocol://path'.
   * @param bool $prepend_bucket
   *   Whether to prepend the bucket name. S3's stream wrapper requires this for
   *   some functions.
   *
   * @return string
   *   A converted string ready for S3 to process it.
   */
  protected function convertUriToKeyedPath($uri, $prepend_bucket = TRUE) {
    // Remove the protocol
    $parts = explode('://', $uri);

    if (!empty($parts[1])) {
      // public:// file are all placed in the s3fs_public_folder.
      $public_folder = !empty($this->config['public_folder']) ? $this->config['public_folder'] : 's3fs-public';
      $private_folder = !empty($this->config['private_folder']) ? $this->config['private_folder'] : 's3fs-private';
      if (file_uri_scheme($uri) == 'public') {
        $parts[1] = "$public_folder/{$parts[1]}";
      }
      // private:// file are all placed in the s3fs_private_folder.
      elseif (file_uri_scheme($uri) == 'private') {
        $parts[1] = "$private_folder/{$parts[1]}";
      }

      // If it's set, all files are placed in the root folder.
      if (!empty($this->config['root_folder'])) {
        $parts[1] = "{$this->config['root_folder']}/{$parts[1]}";
      }

      // Prepend the uri with a bucket since AWS SDK expects this.
      if ($prepend_bucket) {
        $parts[1] = $this->config['bucket'] . '/' . $parts[1];
      }
    }

    // Set protocol to S3 so AWS stream wrapper works correctly.
    $parts[0] = 's3';
    return implode('://', $parts);
  }

  /**
   * Return bucket and key for a command array.
   *
   * @param string $uri
   *   Uri to the required object.
   *
   * @return array
   *   A modified path to the key in S3.
   */
  protected function getCommandParams($uri) {
    $convertedPath = $this->convertUriToKeyedPath($uri, FALSE);
    $params = $this->getOptions(true);
    $params['Bucket'] = $this->config['bucket'];
    $params['Key'] = file_uri_target($convertedPath);
    return $params;
  }

  /**
   * Returns the converted metadata for an object in S3.
   *
   * @param string $uri
   *   The uri for the object in S3.
   *
   * @return array|bool
   *   An array of DB-compatible file metadata.
   *
   * @throws \Exception
   *   Any exception raised by the listObjects() S3 command will percolate
   *   out of this function.
   */
  protected function _get_metadata_from_s3($uri) {
    $params = $this->getCommandParams($uri);
    try {
      $result = $this->s3->headObject($params);
    }
    catch (S3Exception $e) {
      // headObject() throws this exception if the requested key doesn't exist
      // in the bucket.
      watchdog_exception('S3FS', $e);
      return FALSE;
    }

    return _s3fs_convert_metadata($uri, $result);
  }

  /**
   * Triggers one or more errors.
   *
   * @param string|array $errors
   *   Errors to trigger.
   * @param mixed $flags
   *   If set to STREAM_URL_STAT_QUIET, no error or exception is triggered.
   *
   * @return bool
   *   Always returns FALSE.
   *
   * @throws RuntimeException
   *   If the 'throw_exceptions' option is TRUE.
   */
  protected function _trigger_error($errors, $flags = NULL) {
    if ($flags != STREAM_URL_STAT_QUIET) {
      trigger_error(implode("\n", (array) $errors), E_USER_ERROR);
    }
    $this->_error_state = TRUE;
    return FALSE;
  }

  /**
   * Helper function to safely append a GET argument to a given base URL.
   *
   * @param string $base_url
   *   The URL onto which the GET arg will be appended.
   * @param string $name
   *   The name of the GET argument.
   * @param string $value
   *   The value of the GET argument. Optional.
   *
   * @return string
   *   The converted path GET argument.
   */
  protected static function _append_get_arg($base_url, $name, $value = NULL) {
    $separator = strpos($base_url, '?') === FALSE ? '?' : '&';
    $new_url = "{$base_url}{$separator}{$name}";
    if ($value !== NULL) {
      $new_url .= "=$value";
    }
    return $new_url;
  }

  /**
   * Prevent cross scheme access attempts.
   *
   * @param string $uri
   *   Uri attempt to access.
   *
   * @throws \Exception
   *   Cross scheme access attempt has been rejected.
   */
  protected function _prevent_cross_scheme_access($uri) {
    $uri = file_stream_wrapper_uri_normalize($uri);

    $public_folder = !empty($this->config['public_folder']) ? $this->config['public_folder'] : 's3fs-public';
    $public_folder = trim($public_folder, '/');
    $private_folder = !empty($this->config['private_folder']) ? $this->config['private_folder'] : 's3fs-private';
    $private_folder = trim($private_folder, '/');

    $scheme = file_uri_scheme($uri);

    switch ($scheme) {
      case 's3':
        // Attempt to use s3:// to access public:// or private:// path.
        if (strpos($uri, 's3://' . $public_folder) === 0 || strpos($uri, 's3://' . $private_folder) === 0) {
          throw new Exception("Cross scheme access attempt blocked");
        }
        break;

      case 'public':
        // Private folder may be nested under public folder.
        if (strpos($private_folder, $public_folder) === 0) {
          $public_search = '#^' . $public_folder . '#';
          $prefix = preg_replace($public_search, '', $private_folder);
          $prefix = trim($prefix, '/');

          if (strpos($uri, 'public://' . $prefix . '/') === 0) {
            throw new Exception("Cross scheme access attempt blocked");
          }
        }
        break;

      case 'private':
        // Public folder may be nested under private folder.
        if (strpos($public_folder, $private_folder) === 0) {
          $private_search = '#^' . $private_folder . '#';
          $prefix = preg_replace($private_search, '', $public_folder);
          $prefix = trim($prefix, '/');
          if (strpos($uri, 'private://' . $prefix . '/') === 0) {
            throw new Exception("Cross scheme access attempt blocked");
          }
        }
        break;
    }
  }
}
