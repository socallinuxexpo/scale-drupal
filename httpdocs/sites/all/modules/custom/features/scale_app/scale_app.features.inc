<?php

/**
 * @file
 * scale_app.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function scale_app_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function scale_app_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function scale_app_node_info() {
  $items = array(
    'announcement' => array(
      'name' => t('Announcement'),
      'base' => 'node_content',
      'description' => t('Announcements for mobile app'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
