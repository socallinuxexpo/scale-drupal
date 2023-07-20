<?php

/**
 * @file
 * scale_speaker.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function scale_speaker_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__featured_speakers';
  $strongarm->value = array(
    'extra_fields' => array(
      'display' => array(),
      'form' => array(
        'path' => array(
          'weight' => '3',
        ),
        'title' => array(
          'weight' => '0',
        ),
      ),
    ),
    'view_modes' => array(
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
  );
  $export['field_bundle_settings_node__featured_speakers'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_user__user';
  $strongarm->value = array(
    'extra_fields' => array(
      'display' => array(
        'summary' => array(
          'default' => array(
            'visible' => TRUE,
            'weight' => '10',
          ),
          'entityreference_view_widget' => array(
            'visible' => FALSE,
            'weight' => '2',
          ),
        ),
      ),
      'form' => array(
        'account' => array(
          'weight' => '0',
        ),
        'googleanalytics' => array(
          'weight' => '3',
        ),
        'mollom' => array(
          'weight' => '16',
        ),
        'timezone' => array(
          'weight' => '15',
        ),
      ),
    ),
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
  );
  $export['field_bundle_settings_user__user'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_featured_speakers_pattern';
  $strongarm->value = '';
  $export['pathauto_node_featured_speakers_pattern'] = $strongarm;

  return $export;
}
