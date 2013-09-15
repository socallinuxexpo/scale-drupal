<?php

/**
 * @file template.php
 */

/**
 * Preprocess variables for page.tpl.php
 *
 * @see page.tpl.php
 */
function scale12x_preprocess_page(&$variables) {
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

  // Primary nav
  $variables['primary_nav'] = FALSE;
  if ($variables['main_menu']) {
    // Build links
    //$variables['primary_nav'] = menu_tree(variable_get('menu_main_links_source', 'main-menu'));
    $variables['primary_nav'] = menu_tree('menu-12x-main');
    // Provide default theme wrapper function
    $variables['primary_nav']['#theme_wrappers'] = array('menu_tree__primary');
  }

  // Secondary nav
  $variables['secondary_nav'] = FALSE;
  if ($variables['secondary_menu']) {
    // Build links
    $variables['secondary_nav'] = menu_tree(variable_get('menu_secondary_links_source', 'user-menu'));
    // Provide default theme wrapper function
    $variables['secondary_nav']['#theme_wrappers'] = array('menu_tree__secondary');
  }

}

/**
 * Preprocess variables for html.tpl.php
 *
 * @see system_elements()
 * @see html.tpl.php
 */
//function template_preprocess_html(&$variables) {
function scale12x_preprocess_html(&$variables) {
  // Compile a list of classes that are going to be applied to the body element.
  // This allows advanced theming based on context (home page, node of certain type, etc.).
  // Add a class that tells us whether we're on the front page or not.
  $variables['classes_array'][] = $variables['is_front'] ? 'front' : 'not-front';
  // Add a class that tells us whether the page is viewed by an authenticated user or not.
  $variables['classes_array'][] = $variables['logged_in'] ? 'logged-in' : 'not-logged-in';

  // Add information about the number of sidebars.
  if (!empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    $variables['classes_array'][] = 'two-sidebars';
  }
  elseif (!empty($variables['page']['sidebar_first'])) {
    $variables['classes_array'][] = 'one-sidebar sidebar-first';
  }
  elseif (!empty($variables['page']['sidebar_second'])) {
    $variables['classes_array'][] = 'one-sidebar sidebar-second';
  }
  else {
    $variables['classes_array'][] = 'no-sidebars';
  }

  // Populate the body classes.
  if ($suggestions = theme_get_suggestions(arg(), 'page', '-')) {
    foreach ($suggestions as $suggestion) {
      if ($suggestion != 'page-front') {
        // Add current suggestion to page classes to make it possible to theme
        // the page depending on the current page type (e.g. node, admin, user,
        // etc.) as well as more specific data like node-12 or node-edit.
        $variables['classes_array'][] = drupal_html_class($suggestion);
      }
    }
  }

  // If on an individual node page, add the node type to body classes.
  if ($node = menu_get_object()) {
    $variables['classes_array'][] = drupal_html_class('node-type-' . $node->type);
  }

  // RDFa allows annotation of XHTML pages with RDF data, while GRDDL provides
  // mechanisms for extraction of this RDF content via XSLT transformation
  // using an associated GRDDL profile.
  $variables['rdf_namespaces']    = drupal_get_rdf_namespaces();
  $variables['grddl_profile']     = 'http://www.w3.org/1999/xhtml/vocab';
  $variables['language']          = $GLOBALS['language'];
  $variables['language']->dir     = $GLOBALS['language']->direction ? 'rtl' : 'ltr';

  // Add favicon.
  if (theme_get_setting('toggle_favicon')) {
    $favicon = theme_get_setting('favicon');
    $type = theme_get_setting('favicon_mimetype');
    drupal_add_html_head_link(array('rel' => 'shortcut icon', 'href' => drupal_strip_dangerous_protocols($favicon), 'type' => $type));
  }

  // Construct page title.
  if (drupal_get_title()) {
    $head_title = array(
      'title' => strip_tags(drupal_get_title()),
      //'name' => check_plain(variable_get('site_name', 'Drupal')),
      // Override Site Name for each new SCALE
      'name' => t('SCALE 12x'),
    );
  }
  else {
    // Override Site Name for each new SCALE
    $head_title = array('name' => t('SCALE 12x'));
    if (variable_get('site_slogan', '')) {
      $head_title['slogan'] = filter_xss_admin(variable_get('site_slogan', ''));
    }
  }
  $variables['head_title_array'] = $head_title;
  $variables['head_title'] = implode(' | ', $head_title);

  // Populate the page template suggestions.
  if ($suggestions = theme_get_suggestions(arg(), 'html')) {
    $variables['theme_hook_suggestions'] = $suggestions;
  }
}

