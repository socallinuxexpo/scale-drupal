<?php
/**
 * @file
 * special_events.features.inc
 */

/**
 * Implements hook_views_api().
 */
function special_events_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function special_events_node_info() {
  $items = array(
    'special_event' => array(
      'name' => t('Special Event'),
      'base' => 'node_content',
      'description' => t('Details for special events that are in addition to the regular activities'),
      'has_title' => '1',
      'title_label' => t('Name of event'),
      'help' => '',
    ),
  );
  return $items;
}
