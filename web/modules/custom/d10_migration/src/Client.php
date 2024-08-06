<?php

namespace Drupal\d10_migration;

use Drupal\Component\Serialization\Json;
use GuzzleHttp\ClientInterface;
use GuzzleHttp\Exception\RequestException;
use GuzzleHttp\Psr7\Query;

class Client {

  /**
   * @var \GuzzleHttp\ClientInterface
   */
  protected $client;

  /**
   * @var array
   */
  protected $clientHeaders = [
    'Accept' => 'application/json',
    'Content-Type' => 'application/json',
    'Authorization' => 'Basic bWlncmF0aW9uOmQxZzFjMG5m',
    'User-Agent' => 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3'
  ];

  /**
   * Any Params
   *
   * Example:
   *  'N/A'
   *
   * @var string
   */
  protected $params = '';

  /**
   * Client constructor.
   *
   * @param \GuzzleHttp\ClientInterface $client
   *   The HTTP client.
   */
  public function __construct(ClientInterface $client) {
    $this->client = $client;
  }

  /**
   * Helper function to reduce bloat
   *
   * @return mixed
   *   JSON formatted string with the nodes from the remote server.
   *
   * @throws \RuntimeException|\GuzzleHttp\Exception\GuzzleException
   */
  public function get($path, $params = []) {
    $rootEndpoint = $this->getBaseUrl();

    try {
      \Drupal::logger('migration_client')->info("Making GET request to: " . $rootEndpoint . $path);
      $response = $this->client->get($rootEndpoint . $path, [
          'headers' => $this->clientHeaders,
          'query' => Query::build($params),
        ]
      );
      $body = Json::decode($response->getBody());
      if (!empty($body['nodes'])) {
        return $body;
      }
      else {
        \Drupal::logger('migration_client')
          ->error('Empty body for ' . $rootEndpoint . $path);
        return [];
      }
    }
    catch (RequestException $e) {
      \Drupal::logger('migration_client')->error($e->getMessage());
    }

    return [];
  }

  public function getBaseUrl() {
    return 'https://www.socallinuxexpo.org';
    //    return 'http://scale.lndo.site';
  }

}
