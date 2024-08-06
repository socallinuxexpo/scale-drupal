<?php

namespace Drupal\d10_migration\Plugin\migrate\source;

/**
 * @MigrateSource(
 *  id = "type_session_source",
 * )
 */
class TypeSession extends PaginatedSource {

  protected string $endpoint = '/migrate/type/presentation/json/all';

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
    return "Type Presentation";
  }

}
