<?php

/**
 * @file
 * Theme PHP code.
 */

/**
 * Preprocess variables for html.tpl.php.
 */
function scale14x_preprocess_html(&$variables) {
  // Fix head titles for previous SCALE events.
  $current_event = variable_get('site_slogan');
  $scale_event = (arg(0) == 'node' && is_numeric(arg(1))) ? scale_utility_get_scale_event(arg(1)) : arg(1);
  if (!empty($scale_event) && ($scale_event != $current_event)) {
    if (isset($variables['head_title_array']['title'])) {
      $variables['head_title'] = $variables['head_title_array']['title'] . ' | SCALE ' . $scale_event;
    }
    else {
      $variables['head_title'] = 'SCALE ' . $scale_event;
    }
  }
}

/**
 * Preprocess variables for page.tpl.php.
 *
 * @see page.tpl.php
 */
function scale14x_preprocess_page(&$variables) {
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
    $variables['primary_nav'] = menu_tree('menu-14x-main');
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
}

function scale14x_preprocess_block(&$variables) {
  // Show Guidebook link block only on mobile.
  $block_id = $variables['block']->module . '-' . $variables['block']->delta;
  if ($block_id == 'block-11') {
    $variables['classes_array'][] = 'visible-phone';
  }
}
