<?php
/**
 * @file
 * scale_notice.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function scale_notice_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function scale_notice_node_info() {
  $items = array(
    'notice' => array(
      'name' => t('Notice'),
      'base' => 'node_content',
      'description' => t('Use for event notices not to attributed to any specific user.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
