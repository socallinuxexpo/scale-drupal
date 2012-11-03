<?php
/**
 * @file
 * sessions.features.inc
 */

/**
 * Implements hook_views_api().
 */
function sessions_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function sessions_node_info() {
  $items = array(
    'presentation' => array(
      'name' => t('Presentation'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}