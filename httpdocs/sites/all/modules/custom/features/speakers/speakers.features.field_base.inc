<?php
/**
 * @file
 * speakers.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function speakers_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_featured_speaker'
  $field_bases['field_featured_speaker'] = array(
    'active' => 1,
    'cardinality' => 3,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_featured_speaker',
    'foreign keys' => array(
      'uid' => array(
        'columns' => array(
          'uid' => 'uid',
        ),
        'table' => 'users',
      ),
    ),
    'indexes' => array(
      'uid' => array(
        0 => 'uid',
      ),
    ),
    'locked' => 0,
    'module' => 'user_reference',
    'settings' => array(
      'referenceable_roles' => array(
        2 => 0,
        3 => 0,
        4 => 0,
        5 => 5,
        6 => 0,
        7 => 0,
        8 => 0,
        9 => 0,
        10 => 0,
      ),
      'referenceable_status' => array(
        0 => 0,
        1 => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => '',
        'view_name' => '',
      ),
    ),
    'translatable' => 0,
    'type' => 'user_reference',
  );

  return $field_bases;
}
