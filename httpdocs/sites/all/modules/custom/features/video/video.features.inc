<?php
/**
 * @file
 * video.features.inc
 */

/**
 * Implements hook_views_api().
 */
function video_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function video_node_info() {
  $items = array(
    'streaming_video' => array(
      'name' => t('Streaming Video'),
      'base' => 'node_content',
      'description' => t('Pages for streaming video content viewable from outside the SCALE network.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
