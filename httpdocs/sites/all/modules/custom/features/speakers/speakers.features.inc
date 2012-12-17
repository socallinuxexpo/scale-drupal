<?php
/**
 * @file
 * speakers.features.inc
 */

/**
 * Implements hook_views_api().
 */
function speakers_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function speakers_node_info() {
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
  return $items;
}
