<?php
/**
 * @file
 * presentations.features.inc
 */

/**
 * Implements hook_node_info().
 */
function presentations_node_info() {
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
