<?php

namespace Drupal\d10_migration\Plugin\migrate\source;

/**
 * @MigrateSource(
 *  id = "type_special_event_source",
 * )
 */
class TypeSpecialEvent extends PaginatedSource {

  protected string $endpoint = '/migrate/type/special_event/json/paged';

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
    return "Type Special Event";
  }

}
