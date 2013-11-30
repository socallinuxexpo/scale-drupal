<?php
/**
 * @file
 * press.features.inc
 */

/**
 * Implements hook_views_api().
 */
function press_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function press_node_info() {
  $items = array(
    'press_coverage' => array(
      'name' => t('Press Coverage'),
      'base' => 'node_content',
      'description' => t('Document stories in other publications about SCALE'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'press_release' => array(
      'name' => t('Press Release'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Headline'),
      'help' => '',
    ),
  );
  return $items;
}
