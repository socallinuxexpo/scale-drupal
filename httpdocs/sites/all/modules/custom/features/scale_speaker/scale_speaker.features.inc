<?php

/**
 * @file
 * scale_speaker.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function scale_speaker_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function scale_speaker_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function scale_speaker_node_info() {
  $items = array(
    'featured_speakers' => array(
      'name' => t('Featured Speakers'),
      'base' => 'node_content',
      'description' => t('Shows featured speakers on front page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
