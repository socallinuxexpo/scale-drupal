<?php

/**
 * @file
 * scale_special_event.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function scale_special_event_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function scale_special_event_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function scale_special_event_node_info() {
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
  drupal_alter('node_info', $items);
  return $items;
}
