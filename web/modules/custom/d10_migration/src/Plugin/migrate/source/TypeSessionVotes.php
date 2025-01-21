<?php

namespace Drupal\d10_migration\Plugin\migrate\source;

/**
 * @MigrateSource(
 *  id = "type_session_votes_source",
 * )
 */
class TypeSessionVotes extends PaginatedSource {

  protected string $endpoint = '/migrate/type/presentation-ratings/json/paged';

  /**
   * {@inheritdoc}
   */
  public function fields() {}

  /**
   * {@inheritdoc}
   */
  public function getIds() {
    return [
      'uuid' => [
        'type' => 'string',
      ],
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function __toString() {
    return "Type Session Votes";
  }

}
