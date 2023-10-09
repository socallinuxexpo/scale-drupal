<?php

namespace Drupal\d10_migration\Plugin\migrate\source;

use Drupal\migrate\Plugin\migrate\source\SourcePluginBase;

/**
 * @MigrateSource(
 *  id = "tax_event_source",
 * )
 */
class TaxScaleEvent extends SourcePluginBase {

  /**
   * {@inheritdoc}
   */
  public function initializeIterator() {
    $client = \Drupal::service('d10_migration.client');
    $response = $client->get('/migrate/tax/event/json/all');

    return new \ArrayIterator($response);
  }

  /**
   * {@inheritdoc}
   */
  public function fields() {
  }

  /**
   * {@inheritdoc}
   */
  public function getIds() {
    return [
      'tid' => [
        'type' => 'string',
      ],
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function __toString() {
    return "Taxonomy Event";
  }

}
