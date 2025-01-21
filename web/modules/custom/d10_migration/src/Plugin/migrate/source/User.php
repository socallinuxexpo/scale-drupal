<?php

namespace Drupal\d10_migration\Plugin\migrate\source;

/**
 * @MigrateSource(
 *  id = "user_source",
 * )
 */
class User extends PaginatedSource {

  protected string $endpoint = '/migrate/user/json/paged';

  /**
   * {@inheritdoc}
   */
  public function fields() {}

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
