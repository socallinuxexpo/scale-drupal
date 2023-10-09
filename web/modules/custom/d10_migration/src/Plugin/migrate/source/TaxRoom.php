<?php

namespace Drupal\d10_migration\Plugin\migrate\source;

use Drupal\migrate\Plugin\migrate\source\SourcePluginBase;

/**
 * @MigrateSource(
 *  id = "tax_room_source",
 * )
 */
class TaxRoom extends SourcePluginBase {

  /**
   * {@inheritdoc}
   */
  public function initializeIterator() {
    $client = \Drupal::service('d10_migration.client');
    $response = $client->get('/migrate/tax/room/json/all');

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
    return "Taxonomy Room";
  }

}
