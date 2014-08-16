<?php
/**
 * @file
 * scale_promo.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function scale_promo_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function scale_promo_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function scale_promo_node_info() {
  $items = array(
    'promo_item' => array(
      'name' => t('Promo Item'),
      'base' => 'node_content',
      'description' => t('Web banners, buttons, flyers, audio files for public consumption'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
