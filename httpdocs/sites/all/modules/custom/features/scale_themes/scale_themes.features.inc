<?php
/**
 * @file
 * scale_themes.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function scale_themes_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
