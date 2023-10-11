<?php

namespace Drupal\d10_migration\Plugin\migrate\source;

use Drupal\migrate\Plugin\migrate\source\SourcePluginBase;

/**
 * @MigrateSource(
 *  id = "user_source",
 * )
 */
class User extends SourcePluginBase {

  /**
   * {@inheritdoc}
   */
  public function initializeIterator() {
    $client = \Drupal::service('d10_migration.client');
    $response = $client->get('/migrate/user/json/test');

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
      'uid' => [
        'type' => 'string',
      ],
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function __toString() {
    return "User";
  }

}
