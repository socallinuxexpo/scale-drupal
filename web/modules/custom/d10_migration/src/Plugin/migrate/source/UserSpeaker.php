<?php

namespace Drupal\d10_migration\Plugin\migrate\source;


/**
 * @MigrateSource(
 *  id = "user_speaker_source",
 * )
 */
class UserSpeaker extends PaginatedSource {

  protected string $endpoint = '/migrate/user/speaker/json/all';

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
    return "User Speaker";
  }

}
