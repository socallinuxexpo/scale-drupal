<?php

/*
 * UI Toolkit Base Theme
 *
 * Provided functions 
 *
 * - ui_toolkit_nav($menuname)
 *     Renders a Drupal menu using a structure that Bootstrap can work with. Use
 *     this instead of render($page['menuname']) in the template file.
 *
 * - theme('ui_toolkit_btn', $variables)
 *     Renders a button.
 *     $variables is an array with the following keys:
 *       'title': Title of the button.
 *
 *       'path': Path the button should link to.
 *
 *       'style': Button style.
 *       Available styles: 'standard' (default), 'primary', 'info', 'success', 
 *       'warning', 'danger', 'inverse'.
 *       See http://twitter.github.com/bootstrap/base-css.html#buttons
 *
 *       'icon': Icon to show in the button near the title.
 *       For available icons, see 
 *       http://twitter.github.com/bootstrap/base-css.html#icons
 *
 * - theme('ui_toolkit_modal', $variables)
 *     Renders a button that brings up a pop-up window when clicked.
 *     $variables is an array with the following keys:
 *       'button': Title of the button.
 *
 *       'title': Title of the pop-up window.
 *
 *       'content': Content of the pop-up window.
 *
* - theme('ui_toolkit_carousel', $variables)
 *     Renders carousel with the images provided.
 *     $variables is an array with the following keys:
 *       'style': The image style to use to display the images. If not defined,
 *        the original image will be used. 
 *
 *       'images': An array containing the images. The array elements can either
 *        be strings containing the url to the image, or an array contain the
 *        following keys:
 *          'file': The url to the image.
 *          'title': The text to use as image caption.
 *        
 *     The image url should contain the stream wrapper. E.g.
 *     $variables['images'] = array(
 *       array('file' => 'public://slideshow/test1.jpg', 'title' => 'Test title'),
 *       array('file' => 'public://slideshow/test2.jpg', 'title' => 'Test title 2'),
 *     );
 *
 *     or
 *
 *     $variables['images'] = array(
 *       'public://slideshow/test1.jpg',
 *       'public://slideshow/test2.jpg',
 *     );   
 *
 */


/* HOOKS */

/**
 * Implements hook_preprocess_hook().
 */
function ui_toolkit_preprocess_page(&$vars) {
  // Calculate the width of the content area depending on what sidebars are shown.
  $vars['content_span'] = 6;
  if (empty($vars['page']['left'])) {
    $vars['content_span'] += 3;
  }
  if (empty($vars['page']['right'])) {
    $vars['content_span'] += 2;
  } 

  drupal_add_js("jQuery(function () { jQuery('.carousel').carousel(); });", 'inline');
}

/**
 * Implements hook_preprocess_hook().
 */
function ui_toolkit_preprocess_ui_toolkit_modal(&$vars) {
  static $modal_counter = 0;
  
  $vars['counter'] = $modal_counter++;
}

/**
 * Implements hook_preprocess_hook().
 */
function ui_toolkit_preprocess_ui_toolkit_carousel(&$vars) {
  static $carousel_counter = 0;

  foreach ($vars['images'] as $key => $value) {
    if (is_array($vars['images'][$key])) {
      $vars['images'][$key]['file'] = $vars['style'] ? image_style_url($vars['style'], $vars['images'][$key]['file']) : file_create_url($vars['images'][$key]['file']);
    }
    else {
      $vars['images'][$key] = $vars['style'] ? image_style_url($vars['style'], $vars['images'][$key]) : file_create_url($vars['images'][$key]);
    }
  }

  $vars['counter'] = $carousel_counter++;
}

/**
 * Implements hook_js_alter().
 *
 * Replaces jQuery with version 1.7 for public, leaves the Drupal jQuery on admin pages. (Bootstrap requires jQuery 1.7)
 */
function ui_toolkit_js_alter(&$javascript) {
  // Swap out jQuery to use an updated version of the library.
  $path = isset($_GET['q']) ? $_GET['q'] : '';
  if (!path_is_admin($path) && !strstr($path, 'node/add/') && !preg_match('/node\/(.*?)\/edit/i', $path)) {
    $javascript['misc/jquery.js']['data'] = drupal_get_path('theme', 'ui_toolkit') . '/js/jquery-1.7.js';
  }
}

/**
 * Implements hook_theme().
 */
function ui_toolkit_theme() {
  return array(
    'ui_toolkit_modal' => array(
      'variables' => array('button' => FALSE, 'title' => FALSE, 'content' => FALSE),
      'template' => 'ui_toolkit_modal',
    ), 
    'ui_toolkit_btn' => array(
      'variables' => array('title' => FALSE, 'path' => FALSE, 'style' => 'standard', 'icon' => FALSE),
    ), 
    'ui_toolkit_carousel' => array(
      'variables' => array('images' => array(), 'style' => FALSE),
      'template' => 'ui_toolkit_carousel',
    ), 
  );
}

/* THEME FUNCTIONS */

/*
 * Implements theme_ui_toolkit_btn().
 */
function ui_toolkit_ui_toolkit_btn($variables) {
  $classes = array('btn');

  if (in_array($variables['style'], array('primary', 'info', 'success', 'warning', 'danger', 'inverse'))) {
    $classes[] = 'btn-' . $variables['style'];
  }

  if ($variables['icon']) {
    $icon = '<i class="icon-' . $variables['icon'] . '"></i>';
  }
  else {
    $icon = '';
  }
  return l($icon . $variables['title'], $variables['path'], array('html' => TRUE, 'attributes' => array('class' => $classes)));
}

/*
 * Implements theme_status_messages().
 */
function ui_toolkit_status_messages($variables) {
  $display = $variables['display'];
  $output = '';

  $status_heading = array(
    'status' => t('Status message'),
    'error' => t('Error message'),
    'warning' => t('Warning message'),
  );

  foreach (drupal_get_messages($display) as $type => $messages) {
    switch ($type) {
      case "status":
        $alerttype = "alert-success";
        break;
      case "error":
        $alerttype = "alert-error";
        break;
      case "warning":
      default;
        $alerttype = "";
        break;
    }

    $output .= '<a class="close" href="#" data-dismiss="alert">×</a>';
    $output .= '<div class="alert ' . $alerttype . '">';
    
    if (!empty($status_heading[$type])) {
      $output .= '<h2 class="element-invisible">' . $status_heading[$type] . "</h2>";
    }

    if (count($messages) > 1) {
      $output .= " <ul>";
      foreach ($messages as $message) {
        $output .= '  <li>' . $message . "</li>";
      }
      $output .= " </ul>";
    }
    else {
      $output .= $messages[0];
    }
    $output .= "</div>";
  }
  return $output;
}

/**
 * Implements theme_menu_local_tasks().
 */
function ui_toolkit_menu_local_tasks(&$variables) {
  $output = '';

  if (!empty($variables['primary'])) {
    $variables['primary']['#prefix'] = '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
    $variables['primary']['#prefix'] .= '<ul class="nav nav-tabs">';
    $variables['primary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['primary']);
  }
  if (!empty($variables['secondary'])) {
    $variables['secondary']['#prefix'] = '<h2 class="element-invisible">' . t('Secondary tabs') . '</h2>';
    $variables['secondary']['#prefix'] .= '<ul class="nav nav-pills">';
    $variables['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['secondary']);
  }

  return $output;
}

/*
 * Implements theme_pager().
 */
function ui_toolkit_pager($variables) {
  $tags = $variables['tags'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $quantity = $variables['quantity'];
  global $pager_page_array, $pager_total;

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // current is the page we are currently paged to
  $pager_current = $pager_page_array[$element] + 1;
  // first is the first page listed by this pager piece (re quantity)
  $pager_first = $pager_current - $pager_middle + 1;
  // last is the last page listed by this pager piece (re quantity)
  $pager_last = $pager_current + $quantity - $pager_middle;
  // max is the maximum page number
  $pager_max = $pager_total[$element];
  // End of marker calculations.

  // Prepare for generation loop.
  $i = $pager_first;
  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }
  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }
  // End of generation loop preparation.

  $li_first = theme('pager_first', array('text' => (isset($tags[0]) ? $tags[0] : t('« first')), 'element' => $element, 'parameters' => $parameters));
  $li_previous = theme('pager_previous', array('text' => (isset($tags[1]) ? $tags[1] : t('‹ previous')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_next = theme('pager_next', array('text' => (isset($tags[3]) ? $tags[3] : t('next ›')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_last = theme('pager_last', array('text' => (isset($tags[4]) ? $tags[4] : t('last »')), 'element' => $element, 'parameters' => $parameters));

  if ($pager_total[$element] > 1) {
    if ($li_first) {
      $items[] = array(
        'class' => array('pager-first'),
        'data' => $li_first,
      );
    }
    if ($li_previous) {
      $items[] = array(
        'class' => array('pager-previous'),
        'data' => $li_previous,
      );
    }

    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      if ($i > 1) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => l('…',''),
        );
      }
      // Now generate the actual pager piece.
      for (; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
          $items[] = array(
            'class' => array(''),
            'data' => theme('pager_previous', array('text' => $i, 'element' => $element, 'interval' => ($pager_current - $i), 'parameters' => $parameters)),
          );
        }
        if ($i == $pager_current) {
          $items[] = array(
            'class' => array('active'),
            'data' => l($i,''),
          );
        }
        if ($i > $pager_current) {
          $items[] = array(
            'data' => theme('pager_next', array('text' => $i, 'element' => $element, 'interval' => ($i - $pager_current), 'parameters' => $parameters)),
          );
        }
      }
      if ($i < $pager_max) {
        $items[] = array(
          'class' => array('pager-ellipsis'),
          'data' => l('…',''),
        );
      }
    }
    // End generation.
    if ($li_next) {
      $items[] = array(
        'class' => array('pager-next'),
        'data' => $li_next,
      );
    }
    if ($li_last) {
      $items[] = array(
        'class' => array('pager-last'),
        'data' => $li_last,
      );
    }
    return '<h2 class="element-invisible">' . t('Pages') . '</h2>' . theme('item_list', array(
      'items' => $items,
      'attributes' => array('class' => array('pagination')),
    ));
  }

}

/* CUSTOM FUNCTIONS */

/**
 * Renders a menu with Bootstrap's structure.
 */
function ui_toolkit_nav($menuname) {

  $output = '<ul class="nav">';

  $count = 0;
  //dpm(menu_tree_all_data($menuname));
  foreach (menu_tree_all_data($menuname) as $menu_item) {

    if (isset($menu_item['link']['href'])) {
      if ($count==0) {
        $output .= '<li class="first">';
      }
      elseif ($count==count(menu_tree($menuname))-3) {
        $output .= '<li class="last">';
      }
      else {
        $output .= '<li>';
      }

      $output .= '<a href="' . url($menu_item['link']['href']) . '">' . $menu_item['link']['link_title'] . '</a>';
      // Insert submenus here
      $submenu_count = count($menu_item['below']);
      if ($submenu_count != 0) {
        $output .= '<ul>';
        foreach ($menu_item['below'] as $submenu_item) {
          if (isset($submenu_item['link']['href'])) {
            $output .= '<li><a href="' . url($submenu_item['link']['href']) . '">' . $submenu_item['link']['link_title'] . '</a></li>';
          }
        }
        $output .= '</ul>';
      }
      // End of submenu code
      $output .= '</li>';
    }
    $count++;
  }

  $output .= '</ul>';
  return $output;
}
