<?php
/**
 * @file
 * scale_sponsor.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function scale_sponsor_ctools_plugin_api($module = NULL, $api = NULL) {
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
function scale_sponsor_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function scale_sponsor_node_info() {
  $items = array(
    'sponsor' => array(
      'name' => t('Sponsor'),
      'base' => 'node_content',
      'description' => t('Create a new Exhibitor and/or Sponsor. Enter the logo, type of exhibitor and sponsor, website URL, assigned booth number, description of the organization.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => t('The name of the organization.'),
    ),
  );
  return $items;
}
