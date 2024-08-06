<?php

namespace Drupal\d10_migration\Plugin\migrate\source;

use Drupal\migrate\Plugin\migrate\source\SourcePluginBase;

abstract class Source extends SourcePluginBase {

  /**
   * Initialize the iterator with the first page of results.
   */
  public function initializeIterator(): \ArrayIterator {
    $client = \Drupal::service('d10_migration.client');
    $response = $client->get($this->endpoint);

    if (!empty($response['nodes'])) {
      return new \ArrayIterator($response['nodes']);
    }

    return new \ArrayIterator([]);
  }

}
