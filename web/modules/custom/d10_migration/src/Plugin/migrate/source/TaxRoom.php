<?php

namespace Drupal\d10_migration\Plugin\migrate\source;


/**
 * @MigrateSource(
 *  id = "tax_room_source",
 * )
 */
class TaxRoom extends Source {

  protected string $endpoint = '/migrate/tax/room/json/all';

  /**
   * {@inheritdoc}
   */
  public function fields() {}

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
