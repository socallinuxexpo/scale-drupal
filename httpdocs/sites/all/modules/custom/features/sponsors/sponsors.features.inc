<?php
/**
 * @file
 * sponsors.features.inc
 */

/**
 * Implements hook_views_api().
 */
function sponsors_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function sponsors_node_info() {
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
