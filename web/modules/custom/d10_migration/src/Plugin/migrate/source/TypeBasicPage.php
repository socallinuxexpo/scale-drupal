<?php

namespace Drupal\d10_migration\Plugin\migrate\source;

/**
 * @MigrateSource(
 *  id = "type_basic_page_source",
 * )
 */
class TypeBasicPage extends PaginatedSource {

  protected string $endpoint = '/migrate/type/basic_page/json/paged';

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
    return "Type Basic Page";
  }

}
