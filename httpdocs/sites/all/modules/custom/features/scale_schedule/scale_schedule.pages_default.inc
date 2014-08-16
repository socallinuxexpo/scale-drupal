<?php
/**
 * @file
 * scale_schedule.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function scale_schedule_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'schedule';
  $page->task = 'page';
  $page->admin_title = 'Schedule';
  $page->admin_description = '';
  $page->path = 'scale11x/schedule';
  $page->access = array(
    'logic' => 'and',
    'plugins' => array(),
  );
  $page->menu = array(
    'type' => 'none',
    'title' => '',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $pages['schedule'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'schedule_12x';
  $page->task = 'page';
  $page->admin_title = 'Schedule 12x';
  $page->admin_description = '';
  $page->path = 'scale12x/schedule';
  $page->access = array(
    'logic' => 'and',
    'plugins' => array(),
  );
  $page->menu = array(
    'type' => 'none',
    'title' => '',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $pages['schedule_12x'] = $page;

  return $pages;

}
