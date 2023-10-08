<?php

namespace Drupal\d10_migration\Plugin\migrate\source;

use Drupal\migrate\Plugin\migrate\source\SourcePluginBase;

/**
 * @MigrateSource(
 *  id = "type_blog_source",
 * )
 */
class TypeBlog extends SourcePluginBase {

  /**
   * {@inheritdoc}
   */
  public function initializeIterator() {
    $client = \Drupal::service('d10_migration.client');
    $response = $client->get('/migrate/type/blog/json/test');

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
      'nid' => [
        'type' => 'string',
      ],
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function __toString() {
    return "Type Blog";
  }

}
