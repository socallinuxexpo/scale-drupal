<?php

/**
 * @file
 * scale_common.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function scale_common_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_scale_event_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_scale_event_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_topic_pattern';
  $strongarm->value = 'scale/[site:slogan]/[term:vocabulary]/[term:name]';
  $export['pathauto_taxonomy_term_topic_pattern'] = $strongarm;

  return $export;
}
