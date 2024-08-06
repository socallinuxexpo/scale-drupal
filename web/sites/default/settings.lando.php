<?php

if (getenv('LANDO_INFO')) {
  $lando_info = json_decode(getenv('LANDO_INFO'), TRUE);
  $databases['default']['default'] = [
    'database' => $lando_info["database"]["creds"]["database"],
    'username' => $lando_info["database"]["creds"]["user"],
    'password' => $lando_info["database"]["creds"]["password"],
    'host' => $lando_info['database']['internal_connection']['host'],
    'port' => $lando_info['database']['internal_connection']['port'],
    'driver' => 'mysql',
  ];
}

$settings['config_sync_directory'] = '../config/sync';
$settings['container_yamls'][] = DRUPAL_ROOT . '/sites/lando.services.yml';
$config['system.performance']['css']['preprocess'] = FALSE;
$config['system.performance']['js']['preprocess'] = FALSE;
$settings['cache']['bins']['render'] = 'cache.backend.null';
$settings['cache']['bins']['page'] = 'cache.backend.null';
$settings['cache']['bins']['dynamic_page_cache'] = 'cache.backend.null';
