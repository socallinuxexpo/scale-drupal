<?php
/**
 * @file
 * scale_press.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function scale_press_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function scale_press_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function scale_press_node_info() {
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
  drupal_alter('node_info', $items);
  return $items;
}
