<?php

/**
 * @file
 * migration.features.inc
 */

/**
 * Implements hook_views_api().
 */
function migration_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
