<?php
/**
 * @file
 * scale_video.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function scale_video_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function scale_video_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function scale_video_node_info() {
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
