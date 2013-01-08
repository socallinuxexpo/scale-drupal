<?php
/**
 * @file
 * promo_items.features.inc
 */

/**
 * Implements hook_views_api().
 */
function promo_items_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function promo_items_node_info() {
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
