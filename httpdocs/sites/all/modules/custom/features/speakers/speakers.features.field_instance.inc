<?php
/**
 * @file
 * speakers.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function speakers_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-featured_speakers-field_featured_speaker'
  $field_instances['node-featured_speakers-field_featured_speaker'] = array(
    'bundle' => 'featured_speakers',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select the speakers to show in the Featured Speakers block on the front page.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_featured_speaker',
    'label' => 'Speaker',
    'required' => 0,
    'settings' => array(
      'nodeaccess_userreference' => array(
        'all' => array(
          'view' => 0,
        ),
        'all_published' => 0,
        'author' => array(
          'delete' => 0,
          'update' => 0,
          'view' => 0,
        ),
        'author_published' => 0,
        'create' => array(
          'blog' => 0,
          'featured_speakers' => 0,
          'notice' => 0,
          'page' => 0,
          'presentation' => 0,
          'press_coverage' => 0,
          'press_release' => 0,
          'special_event' => 0,
          'sponsor' => 0,
        ),
        'priority' => 0,
        'referenced' => array(
          'delete' => 0,
          'deny_delete' => 0,
          'deny_update' => 0,
          'deny_view' => 0,
          'update' => 0,
          'view' => 0,
        ),
        'referenced_published' => 0,
        'unused' => 0,
        'views' => array(
          'view' => '',
          'view_args' => '',
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'user_reference',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'autocomplete_path' => 'user_reference/autocomplete',
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'user_reference_autocomplete',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Select the speakers to show in the Featured Speakers block on the front page.');
  t('Speaker');

  return $field_instances;
}