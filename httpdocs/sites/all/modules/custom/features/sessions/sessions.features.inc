<?php
/**
 * @file
 * sessions.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sessions_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

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
    'notice' => array(
      'name' => t('Notice'),
      'base' => 'node_content',
      'description' => t('Use for event notices not to attributed to any specific user.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
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
