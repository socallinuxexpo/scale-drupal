<?php

/**
 * @file
 * Theme PHP code.
 */

/**
 * Preprocess variables for page.tpl.php.
 *
 * @see page.tpl.php
 */
function scale19x_preprocess_page(&$variables) {
  // Add information about the number of sidebars.
  if (!empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    $variables['columns'] = 3;
  }
  elseif (!empty($variables['page']['sidebar_first'])) {
    $variables['columns'] = 2;
  }
  elseif (!empty($variables['page']['sidebar_second'])) {
    $variables['columns'] = 2;
  }
  else {
    $variables['columns'] = 1;
  }

  // Primary nav.
  $variables['primary_nav'] = FALSE;
  if ($variables['main_menu']) {
    // Build links
    // $variables['primary_nav'] = menu_tree(variable_get('menu_main_links_source', 'main-menu'));
    $variables['primary_nav'] = menu_tree('menu-19x-main');
    // Provide default theme wrapper function.
    $variables['primary_nav']['#theme_wrappers'] = array('menu_tree__primary');
  }

  // Secondary nav.
  $variables['secondary_nav'] = FALSE;
  if ($variables['secondary_menu']) {
    // Build links.
    $variables['secondary_nav'] = menu_tree(variable_get('menu_secondary_links_source', 'user-menu'));
    // Provide default theme wrapper function.
    $variables['secondary_nav']['#theme_wrappers'] = array('menu_tree__secondary');
  }

  $theme_name = __FUNCTION__;
  $theme_name = substr($theme_name, 0, strpos($theme_name, '_'));
  $variables['current_theme'] = $theme_name;
  $variables['current_image_alt'] = drupal_strtoupper(substr($theme_name, 0, 5)) . ' '. substr($theme_name, -3) . ' logo';
}

function scale19x_preprocess_block(&$variables) {
  // Show Guidebook link block only on mobile.
  $block_id = $variables['block']->module . '-' . $variables['block']->delta;
  if ($block_id == 'block-11') {
    $variables['classes_array'][] = 'visible-phone';
  }
}

function scale19x_preprocess_calendar_day_overlap(&$variables) {
  $view = $variables['view'];
  if (count($view->args) > 1 && !empty($variables['rows']['empty'])) {
    $variables['display_empty'] = TRUE;
  }
}
