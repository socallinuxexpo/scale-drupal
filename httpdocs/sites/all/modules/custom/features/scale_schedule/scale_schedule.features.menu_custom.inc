<?php
/**
 * @file
 * scale_schedule.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function scale_schedule_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-schedule-13x.
  $menus['menu-schedule-13x'] = array(
    'menu_name' => 'menu-schedule-13x',
    'title' => 'Schedule 13x',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Schedule 13x');


  return $menus;
}
