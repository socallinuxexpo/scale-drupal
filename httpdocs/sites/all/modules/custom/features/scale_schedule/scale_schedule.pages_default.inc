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
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_schedule_12x_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'schedule_12x';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Friday',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'schedule_11x friday',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'scale12x/schedule/friday
scale12x/schedule/2014-02-21',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 2,
          1 => 'main-row',
          2 => 1,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'time',
          1 => 'center',
        ),
        'parent' => 'main',
        'class' => 'row-main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Rooms',
        'width' => '100',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'region-rooms',
      ),
      'time' => array(
        'type' => 'region',
        'title' => 'Time',
        'width' => '50',
        'width_type' => 'px',
        'parent' => 'main-row',
        'class' => 'region-time',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'notice',
        ),
        'parent' => 'main',
        'class' => 'row-notice',
      ),
      'notice' => array(
        'type' => 'region',
        'title' => 'Notice',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'schedule-notice',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'schedule_top',
        ),
        'parent' => 'main',
        'class' => 'row-schedule-top',
      ),
      'schedule_top' => array(
        'type' => 'region',
        'title' => 'Schedule Top',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => 'schedule-top',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'time' => NULL,
      'notice' => NULL,
      'schedule_top' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Friday, February 21, 2014';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-21/454',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'La Jolla',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'la-jolla',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-1'] = $pane;
    $display->panels['center'][0] = 'new-1';
    $pane = new stdClass();
    $pane->pid = 'new-2';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-21/442',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Carmel',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'carmel',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-2'] = $pane;
    $display->panels['center'][1] = 'new-2';
    $pane = new stdClass();
    $pane->pid = 'new-3';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-21/455',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Los Angeles A',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'los-angeles-a',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $display->content['new-3'] = $pane;
    $display->panels['center'][2] = 'new-3';
    $pane = new stdClass();
    $pane->pid = 'new-4';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-21/457',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Los Angeles B',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'los-angeles-b',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $display->content['new-4'] = $pane;
    $display->panels['center'][3] = 'new-4';
    $pane = new stdClass();
    $pane->pid = 'new-5';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-21/458',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Los Angeles C',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'los-angeles-c',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $display->content['new-5'] = $pane;
    $display->panels['center'][4] = 'new-5';
    $pane = new stdClass();
    $pane->pid = 'new-6';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-21/448',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Century AB',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'century-ab',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $display->content['new-6'] = $pane;
    $display->panels['center'][5] = 'new-6';
    $pane = new stdClass();
    $pane->pid = 'new-7';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-21/451',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Century CD',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'century-cd',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $display->content['new-7'] = $pane;
    $display->panels['center'][6] = 'new-7';
    $pane = new stdClass();
    $pane->pid = 'new-8';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-21/459',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Marina',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'marina',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $display->content['new-8'] = $pane;
    $display->panels['center'][7] = 'new-8';
    $pane = new stdClass();
    $pane->pid = 'new-9';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-21/441',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Bel Air',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'bel-air',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 8;
    $pane->locks = array();
    $display->content['new-9'] = $pane;
    $display->panels['center'][8] = 'new-9';
    $pane = new stdClass();
    $pane->pid = 'new-10';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-21/462',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Santa Monica A',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'santa-monica-a',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 9;
    $pane->locks = array();
    $display->content['new-10'] = $pane;
    $display->panels['center'][9] = 'new-10';
    $pane = new stdClass();
    $pane->pid = 'new-11';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-21/463',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Santa Monica B',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'santa-monica-b',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 10;
    $pane->locks = array();
    $display->content['new-11'] = $pane;
    $display->panels['center'][10] = 'new-11';
    $pane = new stdClass();
    $pane->pid = 'new-12';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-21/464',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo B',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-b',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 11;
    $pane->locks = array();
    $display->content['new-12'] = $pane;
    $display->panels['center'][11] = 'new-12';
    $pane = new stdClass();
    $pane->pid = 'new-13';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-21/465',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo C',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-c',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 12;
    $pane->locks = array();
    $display->content['new-13'] = $pane;
    $display->panels['center'][12] = 'new-13';
    $pane = new stdClass();
    $pane->pid = 'new-14';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-21/466',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo D',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-d',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 13;
    $pane->locks = array();
    $display->content['new-14'] = $pane;
    $display->panels['center'][13] = 'new-14';
    $pane = new stdClass();
    $pane->pid = 'new-15';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-21/467',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo E',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-e',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 14;
    $pane->locks = array();
    $display->content['new-15'] = $pane;
    $display->panels['center'][14] = 'new-15';
    $pane = new stdClass();
    $pane->pid = 'new-16';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-21/468',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo F',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-f',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 15;
    $pane->locks = array();
    $display->content['new-16'] = $pane;
    $display->panels['center'][15] = 'new-16';
    $pane = new stdClass();
    $pane->pid = 'new-17';
    $pane->panel = 'notice';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Schedule change notice',
      'title' => '',
      'body' => '<p>* The schedule of events is subjected to change without prior notifications.</p>',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-17'] = $pane;
    $display->panels['notice'][0] = 'new-17';
    $pane = new stdClass();
    $pane->pid = 'new-18';
    $pane->panel = 'notice';
    $pane->type = 'views_panes';
    $pane->subtype = 'room_schedule_legend-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_time_value' => '2014-02-21',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-18'] = $pane;
    $display->panels['notice'][1] = 'new-18';
    $pane = new stdClass();
    $pane->pid = 'new-19';
    $pane->panel = 'schedule_top';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-schedule-12x';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-19'] = $pane;
    $display->panels['schedule_top'][0] = 'new-19';
    $pane = new stdClass();
    $pane->pid = 'new-20';
    $pane->panel = 'schedule_top';
    $pane->type = 'views_panes';
    $pane->subtype = 'room_schedule_legend-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_time_value' => '2014-02-21',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-20'] = $pane;
    $display->panels['schedule_top'][1] = 'new-20';
    $pane = new stdClass();
    $pane->pid = 'new-21';
    $pane->panel = 'time';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-21',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Time',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'time',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-21'] = $pane;
    $display->panels['time'][0] = 'new-21';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_schedule_12x_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'schedule_12x';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Saturday',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'schedule_11x saturday',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'scale12x/schedule/saturday
scale12x/schedule/2014-02-22',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 2,
          1 => 'main-row',
          2 => 1,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'time',
          1 => 'center',
        ),
        'parent' => 'main',
        'class' => 'row-main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Rooms',
        'width' => '100',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'region-rooms',
      ),
      'time' => array(
        'type' => 'region',
        'title' => 'Time',
        'width' => '50',
        'width_type' => 'px',
        'parent' => 'main-row',
        'class' => 'region-time',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'notice',
        ),
        'parent' => 'main',
        'class' => 'row-notice',
      ),
      'notice' => array(
        'type' => 'region',
        'title' => 'Notice',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'schedule-notice',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'schedule_top',
        ),
        'parent' => 'main',
        'class' => 'row-schedule-top',
      ),
      'schedule_top' => array(
        'type' => 'region',
        'title' => 'Schedule Top',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => 'schedule-top',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'time' => NULL,
      'notice' => NULL,
      'schedule_top' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Saturday, February 22, 2014';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-22';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-22/454',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'La Jolla',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'la-jolla',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-22'] = $pane;
    $display->panels['center'][0] = 'new-22';
    $pane = new stdClass();
    $pane->pid = 'new-23';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-22/442',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Carmel',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'carmel',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-23'] = $pane;
    $display->panels['center'][1] = 'new-23';
    $pane = new stdClass();
    $pane->pid = 'new-24';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-22/455',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Los Angeles A',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'los-angeles-a',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $display->content['new-24'] = $pane;
    $display->panels['center'][2] = 'new-24';
    $pane = new stdClass();
    $pane->pid = 'new-25';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-22/457',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Los Angeles B',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'los-angeles-b',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $display->content['new-25'] = $pane;
    $display->panels['center'][3] = 'new-25';
    $pane = new stdClass();
    $pane->pid = 'new-26';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-22/458',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Los Angeles C',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'los-angeles-c',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $display->content['new-26'] = $pane;
    $display->panels['center'][4] = 'new-26';
    $pane = new stdClass();
    $pane->pid = 'new-27';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-22/448',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Century AB',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'century-ab',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $display->content['new-27'] = $pane;
    $display->panels['center'][5] = 'new-27';
    $pane = new stdClass();
    $pane->pid = 'new-28';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-22/451',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Century CD',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'century-cd',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $display->content['new-28'] = $pane;
    $display->panels['center'][6] = 'new-28';
    $pane = new stdClass();
    $pane->pid = 'new-29';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-22/459',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Marina',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'marina',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $display->content['new-29'] = $pane;
    $display->panels['center'][7] = 'new-29';
    $pane = new stdClass();
    $pane->pid = 'new-30';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-22/441',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Bel Air',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'bel-air',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 8;
    $pane->locks = array();
    $display->content['new-30'] = $pane;
    $display->panels['center'][8] = 'new-30';
    $pane = new stdClass();
    $pane->pid = 'new-31';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-22/462',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Santa Monica A',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'santa-monica-a',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 9;
    $pane->locks = array();
    $display->content['new-31'] = $pane;
    $display->panels['center'][9] = 'new-31';
    $pane = new stdClass();
    $pane->pid = 'new-32';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-22/463',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Santa Monica B',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'santa-monica-b',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 10;
    $pane->locks = array();
    $display->content['new-32'] = $pane;
    $display->panels['center'][10] = 'new-32';
    $pane = new stdClass();
    $pane->pid = 'new-33';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-22/464',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo B',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-b',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 11;
    $pane->locks = array();
    $display->content['new-33'] = $pane;
    $display->panels['center'][11] = 'new-33';
    $pane = new stdClass();
    $pane->pid = 'new-34';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-22/465',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo C',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-c',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 12;
    $pane->locks = array();
    $display->content['new-34'] = $pane;
    $display->panels['center'][12] = 'new-34';
    $pane = new stdClass();
    $pane->pid = 'new-35';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-22/466',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo D',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-d',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 13;
    $pane->locks = array();
    $display->content['new-35'] = $pane;
    $display->panels['center'][13] = 'new-35';
    $pane = new stdClass();
    $pane->pid = 'new-36';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-22/467',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo E',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-e',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 14;
    $pane->locks = array();
    $display->content['new-36'] = $pane;
    $display->panels['center'][14] = 'new-36';
    $pane = new stdClass();
    $pane->pid = 'new-37';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-22/468',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo F',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-f',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 15;
    $pane->locks = array();
    $display->content['new-37'] = $pane;
    $display->panels['center'][15] = 'new-37';
    $pane = new stdClass();
    $pane->pid = 'new-38';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-22/461',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Plaza Ballroom',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 16;
    $pane->locks = array();
    $display->content['new-38'] = $pane;
    $display->panels['center'][16] = 'new-38';
    $pane = new stdClass();
    $pane->pid = 'new-39';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-22/453',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Expo',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 17;
    $pane->locks = array();
    $display->content['new-39'] = $pane;
    $display->panels['center'][17] = 'new-39';
    $pane = new stdClass();
    $pane->pid = 'new-40';
    $pane->panel = 'notice';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Schedule change notice',
      'title' => '',
      'body' => '<p>* The schedule of events is subjected to change without prior notifications.</p>',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-40'] = $pane;
    $display->panels['notice'][0] = 'new-40';
    $pane = new stdClass();
    $pane->pid = 'new-41';
    $pane->panel = 'notice';
    $pane->type = 'views_panes';
    $pane->subtype = 'room_schedule_legend-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_time_value' => '2014-02-22',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-41'] = $pane;
    $display->panels['notice'][1] = 'new-41';
    $pane = new stdClass();
    $pane->pid = 'new-42';
    $pane->panel = 'schedule_top';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-schedule-12x';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-42'] = $pane;
    $display->panels['schedule_top'][0] = 'new-42';
    $pane = new stdClass();
    $pane->pid = 'new-43';
    $pane->panel = 'schedule_top';
    $pane->type = 'views_panes';
    $pane->subtype = 'room_schedule_legend-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_time_value' => '2014-02-22',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-43'] = $pane;
    $display->panels['schedule_top'][1] = 'new-43';
    $pane = new stdClass();
    $pane->pid = 'new-44';
    $pane->panel = 'time';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-22',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Time',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'time',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-44'] = $pane;
    $display->panels['time'][0] = 'new-44';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_schedule_12x_panel_context_3';
  $handler->task = 'page';
  $handler->subtask = 'schedule_12x';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'Sunday',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'schedule_11x sunday',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'scale12x/schedule/sunday
scale12x/schedule/2014-02-23
scale12x/blah',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 2,
          1 => 'main-row',
          2 => 1,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'time',
          1 => 'center',
        ),
        'parent' => 'main',
        'class' => 'row-main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Rooms',
        'width' => '100',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'region-rooms',
      ),
      'time' => array(
        'type' => 'region',
        'title' => 'Time',
        'width' => '50',
        'width_type' => 'px',
        'parent' => 'main-row',
        'class' => 'region-time',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'notice',
        ),
        'parent' => 'main',
        'class' => 'row-notice',
      ),
      'notice' => array(
        'type' => 'region',
        'title' => 'Notice',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'schedule-notice',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'schedule_top',
        ),
        'parent' => 'main',
        'class' => 'row-schedule-top',
      ),
      'schedule_top' => array(
        'type' => 'region',
        'title' => 'Schedule Top',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => 'schedule-top',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'time' => NULL,
      'notice' => NULL,
      'schedule_top' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Sunday, February 23, 2014';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-45';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-23/454',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'La Jolla',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'la-jolla',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-45'] = $pane;
    $display->panels['center'][0] = 'new-45';
    $pane = new stdClass();
    $pane->pid = 'new-46';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-23/442',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Carmel',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'carmel',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-46'] = $pane;
    $display->panels['center'][1] = 'new-46';
    $pane = new stdClass();
    $pane->pid = 'new-47';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-23/455',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Los Angeles A',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'los-angeles-a',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $display->content['new-47'] = $pane;
    $display->panels['center'][2] = 'new-47';
    $pane = new stdClass();
    $pane->pid = 'new-48';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-23/457',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Los Angeles B',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'los-angeles-b',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $display->content['new-48'] = $pane;
    $display->panels['center'][3] = 'new-48';
    $pane = new stdClass();
    $pane->pid = 'new-49';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-23/458',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Los Angeles C',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'los-angeles-c',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $display->content['new-49'] = $pane;
    $display->panels['center'][4] = 'new-49';
    $pane = new stdClass();
    $pane->pid = 'new-50';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-23/448',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Century AB',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'century-ab',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $display->content['new-50'] = $pane;
    $display->panels['center'][5] = 'new-50';
    $pane = new stdClass();
    $pane->pid = 'new-51';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-23/451',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Century CD',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'century-cd',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $display->content['new-51'] = $pane;
    $display->panels['center'][6] = 'new-51';
    $pane = new stdClass();
    $pane->pid = 'new-52';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-23/459',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Marina',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'marina',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $display->content['new-52'] = $pane;
    $display->panels['center'][7] = 'new-52';
    $pane = new stdClass();
    $pane->pid = 'new-53';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-23/441',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Bel Air',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'bel-air',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 8;
    $pane->locks = array();
    $display->content['new-53'] = $pane;
    $display->panels['center'][8] = 'new-53';
    $pane = new stdClass();
    $pane->pid = 'new-54';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-23/462',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Santa Monica A',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'santa-monica-a',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 9;
    $pane->locks = array();
    $display->content['new-54'] = $pane;
    $display->panels['center'][9] = 'new-54';
    $pane = new stdClass();
    $pane->pid = 'new-55';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-23/463',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Santa Monica B',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'santa-monica-b',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 10;
    $pane->locks = array();
    $display->content['new-55'] = $pane;
    $display->panels['center'][10] = 'new-55';
    $pane = new stdClass();
    $pane->pid = 'new-56';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-23/464',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo B',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-b',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 11;
    $pane->locks = array();
    $display->content['new-56'] = $pane;
    $display->panels['center'][11] = 'new-56';
    $pane = new stdClass();
    $pane->pid = 'new-57';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-23/465',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo C',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-c',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 12;
    $pane->locks = array();
    $display->content['new-57'] = $pane;
    $display->panels['center'][12] = 'new-57';
    $pane = new stdClass();
    $pane->pid = 'new-58';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-23/466',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo D',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-d',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 13;
    $pane->locks = array();
    $display->content['new-58'] = $pane;
    $display->panels['center'][13] = 'new-58';
    $pane = new stdClass();
    $pane->pid = 'new-59';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-23/467',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo E',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-e',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 14;
    $pane->locks = array();
    $display->content['new-59'] = $pane;
    $display->panels['center'][14] = 'new-59';
    $pane = new stdClass();
    $pane->pid = 'new-60';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-23/468',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo F',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-f',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 15;
    $pane->locks = array();
    $display->content['new-60'] = $pane;
    $display->panels['center'][15] = 'new-60';
    $pane = new stdClass();
    $pane->pid = 'new-61';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-23/453',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Expo',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 16;
    $pane->locks = array();
    $display->content['new-61'] = $pane;
    $display->panels['center'][16] = 'new-61';
    $pane = new stdClass();
    $pane->pid = 'new-62';
    $pane->panel = 'notice';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Schedule change notice',
      'title' => '',
      'body' => '<p>* The schedule of events is subjected to change without prior notifications.</p>',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-62'] = $pane;
    $display->panels['notice'][0] = 'new-62';
    $pane = new stdClass();
    $pane->pid = 'new-63';
    $pane->panel = 'notice';
    $pane->type = 'views_panes';
    $pane->subtype = 'room_schedule_legend-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_time_value' => '2014-02-23',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-63'] = $pane;
    $display->panels['notice'][1] = 'new-63';
    $pane = new stdClass();
    $pane->pid = 'new-64';
    $pane->panel = 'schedule_top';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-schedule-12x';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-64'] = $pane;
    $display->panels['schedule_top'][0] = 'new-64';
    $pane = new stdClass();
    $pane->pid = 'new-65';
    $pane->panel = 'schedule_top';
    $pane->type = 'views_panes';
    $pane->subtype = 'room_schedule_legend-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_time_value' => '2014-02-23',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-65'] = $pane;
    $display->panels['schedule_top'][1] = 'new-65';
    $pane = new stdClass();
    $pane->pid = 'new-66';
    $pane->panel = 'time';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2014-02-23',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Time',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'time',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-66'] = $pane;
    $display->panels['time'][0] = 'new-66';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_schedule_12x_panel_context_4';
  $handler->task = 'page';
  $handler->subtask = 'schedule_12x';
  $handler->handler = 'panel_context';
  $handler->weight = 3;
  $handler->conf = array(
    'title' => 'Schedule',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-67';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'menu_block-4';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-67'] = $pane;
    $display->panels['middle'][0] = 'new-67';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['schedule_12x'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'schedule_multiyear';
  $page->task = 'page';
  $page->admin_title = 'Schedule multiyear';
  $page->admin_description = '';
  $page->path = 'scale/13x/schedule/!date';
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
  $page->arguments = array(
    'date' => array(
      'id' => '',
      'identifier' => '',
      'argument' => '',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_schedule_multiyear_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'schedule_multiyear';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Friday',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'schedule_11x friday',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'scale/13x/schedule/2015-02-20
scale/13x/schedule/friday',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 2,
          1 => 'main-row',
          2 => 1,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'time',
          1 => 'center',
        ),
        'parent' => 'main',
        'class' => 'row-main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Rooms',
        'width' => '100',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'region-rooms',
      ),
      'time' => array(
        'type' => 'region',
        'title' => 'Time',
        'width' => '50',
        'width_type' => 'px',
        'parent' => 'main-row',
        'class' => 'region-time',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'notice',
        ),
        'parent' => 'main',
        'class' => 'row-notice',
      ),
      'notice' => array(
        'type' => 'region',
        'title' => 'Notice',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'schedule-notice',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'schedule_top',
        ),
        'parent' => 'main',
        'class' => 'row-schedule-top',
      ),
      'schedule_top' => array(
        'type' => 'region',
        'title' => 'Schedule Top',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => 'schedule-top',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'time' => NULL,
      'notice' => NULL,
      'schedule_top' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Friday, February 20, 2015';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-68';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-20/454',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'La Jolla',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'la-jolla',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-68'] = $pane;
    $display->panels['center'][0] = 'new-68';
    $pane = new stdClass();
    $pane->pid = 'new-69';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-20/442',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Carmel',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'carmel',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-69'] = $pane;
    $display->panels['center'][1] = 'new-69';
    $pane = new stdClass();
    $pane->pid = 'new-70';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-20/455',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Los Angeles A',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'los-angeles-a',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $display->content['new-70'] = $pane;
    $display->panels['center'][2] = 'new-70';
    $pane = new stdClass();
    $pane->pid = 'new-71';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-20/457',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Los Angeles B',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'los-angeles-b',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $display->content['new-71'] = $pane;
    $display->panels['center'][3] = 'new-71';
    $pane = new stdClass();
    $pane->pid = 'new-72';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-20/458',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Los Angeles C',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'los-angeles-c',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $display->content['new-72'] = $pane;
    $display->panels['center'][4] = 'new-72';
    $pane = new stdClass();
    $pane->pid = 'new-73';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-20/448',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Century AB',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'century-ab',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $display->content['new-73'] = $pane;
    $display->panels['center'][5] = 'new-73';
    $pane = new stdClass();
    $pane->pid = 'new-74';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-20/451',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Century CD',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'century-cd',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $display->content['new-74'] = $pane;
    $display->panels['center'][6] = 'new-74';
    $pane = new stdClass();
    $pane->pid = 'new-75';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-20/459',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Marina',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'marina',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $display->content['new-75'] = $pane;
    $display->panels['center'][7] = 'new-75';
    $pane = new stdClass();
    $pane->pid = 'new-76';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-20/441',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Bel Air',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'bel-air',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 8;
    $pane->locks = array();
    $display->content['new-76'] = $pane;
    $display->panels['center'][8] = 'new-76';
    $pane = new stdClass();
    $pane->pid = 'new-77';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-20/462',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Santa Monica A',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'santa-monica-a',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 9;
    $pane->locks = array();
    $display->content['new-77'] = $pane;
    $display->panels['center'][9] = 'new-77';
    $pane = new stdClass();
    $pane->pid = 'new-78';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-20/463',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Santa Monica B',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'santa-monica-b',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 10;
    $pane->locks = array();
    $display->content['new-78'] = $pane;
    $display->panels['center'][10] = 'new-78';
    $pane = new stdClass();
    $pane->pid = 'new-79';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-20/464',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo B',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-b',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 11;
    $pane->locks = array();
    $display->content['new-79'] = $pane;
    $display->panels['center'][11] = 'new-79';
    $pane = new stdClass();
    $pane->pid = 'new-80';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-20/465',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo C',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-c',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 12;
    $pane->locks = array();
    $display->content['new-80'] = $pane;
    $display->panels['center'][12] = 'new-80';
    $pane = new stdClass();
    $pane->pid = 'new-81';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-20/466',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo D',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-d',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 13;
    $pane->locks = array();
    $display->content['new-81'] = $pane;
    $display->panels['center'][13] = 'new-81';
    $pane = new stdClass();
    $pane->pid = 'new-82';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-20/467',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo E',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-e',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 14;
    $pane->locks = array();
    $display->content['new-82'] = $pane;
    $display->panels['center'][14] = 'new-82';
    $pane = new stdClass();
    $pane->pid = 'new-83';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-20/468',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo F',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-f',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 15;
    $pane->locks = array();
    $display->content['new-83'] = $pane;
    $display->panels['center'][15] = 'new-83';
    $pane = new stdClass();
    $pane->pid = 'new-84';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-20/1207',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Plaza BC',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 16;
    $pane->locks = array();
    $display->content['new-84'] = $pane;
    $display->panels['center'][16] = 'new-84';
    $pane = new stdClass();
    $pane->pid = 'new-85';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-20/1208',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Plaza D',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 17;
    $pane->locks = array();
    $display->content['new-85'] = $pane;
    $display->panels['center'][17] = 'new-85';
    $pane = new stdClass();
    $pane->pid = 'new-86';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-20/453',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Expo',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 18;
    $pane->locks = array();
    $display->content['new-86'] = $pane;
    $display->panels['center'][18] = 'new-86';
    $pane = new stdClass();
    $pane->pid = 'new-87';
    $pane->panel = 'notice';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Schedule change notice',
      'title' => '',
      'body' => '<p>* The schedule of events is subjected to change without prior notifications.</p>',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-87'] = $pane;
    $display->panels['notice'][0] = 'new-87';
    $pane = new stdClass();
    $pane->pid = 'new-88';
    $pane->panel = 'notice';
    $pane->type = 'views_panes';
    $pane->subtype = 'room_schedule_legend-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_time_value' => '2015-02-20',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-88'] = $pane;
    $display->panels['notice'][1] = 'new-88';
    $pane = new stdClass();
    $pane->pid = 'new-89';
    $pane->panel = 'schedule_top';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-schedule-13x';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-89'] = $pane;
    $display->panels['schedule_top'][0] = 'new-89';
    $pane = new stdClass();
    $pane->pid = 'new-90';
    $pane->panel = 'schedule_top';
    $pane->type = 'views_panes';
    $pane->subtype = 'room_schedule_legend-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_time_value' => '2015-02-20',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-90'] = $pane;
    $display->panels['schedule_top'][1] = 'new-90';
    $pane = new stdClass();
    $pane->pid = 'new-91';
    $pane->panel = 'time';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-20',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Time',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'time',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-91'] = $pane;
    $display->panels['time'][0] = 'new-91';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_schedule_multiyear_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'schedule_multiyear';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'Saturday',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'schedule_11x saturday',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'scale/13x/schedule/saturday
scale/13x/schedule/2015-02-21',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 2,
          1 => 'main-row',
          2 => 1,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'time',
          1 => 'center',
        ),
        'parent' => 'main',
        'class' => 'row-main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Rooms',
        'width' => '100',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'region-rooms',
      ),
      'time' => array(
        'type' => 'region',
        'title' => 'Time',
        'width' => '50',
        'width_type' => 'px',
        'parent' => 'main-row',
        'class' => 'region-time',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'notice',
        ),
        'parent' => 'main',
        'class' => 'row-notice',
      ),
      'notice' => array(
        'type' => 'region',
        'title' => 'Notice',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'schedule-notice',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'schedule_top',
        ),
        'parent' => 'main',
        'class' => 'row-schedule-top',
      ),
      'schedule_top' => array(
        'type' => 'region',
        'title' => 'Schedule Top',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => 'schedule-top',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'time' => NULL,
      'notice' => NULL,
      'schedule_top' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Saturday, February 21, 2015';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-92';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-21/454',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'La Jolla',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'la-jolla',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-92'] = $pane;
    $display->panels['center'][0] = 'new-92';
    $pane = new stdClass();
    $pane->pid = 'new-93';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-21/442',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Carmel',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'carmel',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-93'] = $pane;
    $display->panels['center'][1] = 'new-93';
    $pane = new stdClass();
    $pane->pid = 'new-94';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-21/455',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Los Angeles A',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'los-angeles-a',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $display->content['new-94'] = $pane;
    $display->panels['center'][2] = 'new-94';
    $pane = new stdClass();
    $pane->pid = 'new-95';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-21/457',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Los Angeles B',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'los-angeles-b',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $display->content['new-95'] = $pane;
    $display->panels['center'][3] = 'new-95';
    $pane = new stdClass();
    $pane->pid = 'new-96';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-21/458',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Los Angeles C',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'los-angeles-c',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $display->content['new-96'] = $pane;
    $display->panels['center'][4] = 'new-96';
    $pane = new stdClass();
    $pane->pid = 'new-97';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-21/448',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Century AB',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'century-ab',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $display->content['new-97'] = $pane;
    $display->panels['center'][5] = 'new-97';
    $pane = new stdClass();
    $pane->pid = 'new-98';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-21/451',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Century CD',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'century-cd',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $display->content['new-98'] = $pane;
    $display->panels['center'][6] = 'new-98';
    $pane = new stdClass();
    $pane->pid = 'new-99';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-21/459',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Marina',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'marina',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $display->content['new-99'] = $pane;
    $display->panels['center'][7] = 'new-99';
    $pane = new stdClass();
    $pane->pid = 'new-100';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-21/441',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Bel Air',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'bel-air',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 8;
    $pane->locks = array();
    $display->content['new-100'] = $pane;
    $display->panels['center'][8] = 'new-100';
    $pane = new stdClass();
    $pane->pid = 'new-101';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-21/462',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Santa Monica A',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'santa-monica-a',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 9;
    $pane->locks = array();
    $display->content['new-101'] = $pane;
    $display->panels['center'][9] = 'new-101';
    $pane = new stdClass();
    $pane->pid = 'new-102';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-21/463',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Santa Monica B',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'santa-monica-b',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 10;
    $pane->locks = array();
    $display->content['new-102'] = $pane;
    $display->panels['center'][10] = 'new-102';
    $pane = new stdClass();
    $pane->pid = 'new-103';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-21/464',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo B',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-b',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 11;
    $pane->locks = array();
    $display->content['new-103'] = $pane;
    $display->panels['center'][11] = 'new-103';
    $pane = new stdClass();
    $pane->pid = 'new-104';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-21/465',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo C',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-c',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 12;
    $pane->locks = array();
    $display->content['new-104'] = $pane;
    $display->panels['center'][12] = 'new-104';
    $pane = new stdClass();
    $pane->pid = 'new-105';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-21/466',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo D',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-d',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 13;
    $pane->locks = array();
    $display->content['new-105'] = $pane;
    $display->panels['center'][13] = 'new-105';
    $pane = new stdClass();
    $pane->pid = 'new-106';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-21/467',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo E',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-e',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 14;
    $pane->locks = array();
    $display->content['new-106'] = $pane;
    $display->panels['center'][14] = 'new-106';
    $pane = new stdClass();
    $pane->pid = 'new-107';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-21/468',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo F',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-f',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 15;
    $pane->locks = array();
    $display->content['new-107'] = $pane;
    $display->panels['center'][15] = 'new-107';
    $pane = new stdClass();
    $pane->pid = 'new-108';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-21/461',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Plaza Ballroom',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 16;
    $pane->locks = array();
    $display->content['new-108'] = $pane;
    $display->panels['center'][16] = 'new-108';
    $pane = new stdClass();
    $pane->pid = 'new-109';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-21/1207',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Plaza BC',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 17;
    $pane->locks = array();
    $display->content['new-109'] = $pane;
    $display->panels['center'][17] = 'new-109';
    $pane = new stdClass();
    $pane->pid = 'new-110';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-21/1208',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Plaza D',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 18;
    $pane->locks = array();
    $display->content['new-110'] = $pane;
    $display->panels['center'][18] = 'new-110';
    $pane = new stdClass();
    $pane->pid = 'new-111';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-21/453',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Expo',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 19;
    $pane->locks = array();
    $display->content['new-111'] = $pane;
    $display->panels['center'][19] = 'new-111';
    $pane = new stdClass();
    $pane->pid = 'new-112';
    $pane->panel = 'notice';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Schedule change notice',
      'title' => '',
      'body' => '<p>* The schedule of events is subjected to change without prior notifications.</p>',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-112'] = $pane;
    $display->panels['notice'][0] = 'new-112';
    $pane = new stdClass();
    $pane->pid = 'new-113';
    $pane->panel = 'notice';
    $pane->type = 'views_panes';
    $pane->subtype = 'room_schedule_legend-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_time_value' => '2015-02-21',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-113'] = $pane;
    $display->panels['notice'][1] = 'new-113';
    $pane = new stdClass();
    $pane->pid = 'new-114';
    $pane->panel = 'schedule_top';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-schedule-13x';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-114'] = $pane;
    $display->panels['schedule_top'][0] = 'new-114';
    $pane = new stdClass();
    $pane->pid = 'new-115';
    $pane->panel = 'schedule_top';
    $pane->type = 'views_panes';
    $pane->subtype = 'room_schedule_legend-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_time_value' => '2015-02-21',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-115'] = $pane;
    $display->panels['schedule_top'][1] = 'new-115';
    $pane = new stdClass();
    $pane->pid = 'new-116';
    $pane->panel = 'time';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-21',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Time',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'time',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-116'] = $pane;
    $display->panels['time'][0] = 'new-116';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_schedule_multiyear_panel_context_3';
  $handler->task = 'page';
  $handler->subtask = 'schedule_multiyear';
  $handler->handler = 'panel_context';
  $handler->weight = -27;
  $handler->conf = array(
    'title' => 'Sunday',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'schedule_11x sunday',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'scale/13x/schedule/sunday
scale/13x/schedule/2015-02-22',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 2,
          1 => 'main-row',
          2 => 1,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'time',
          1 => 'center',
        ),
        'parent' => 'main',
        'class' => 'row-main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Rooms',
        'width' => '100',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'region-rooms',
      ),
      'time' => array(
        'type' => 'region',
        'title' => 'Time',
        'width' => '50',
        'width_type' => 'px',
        'parent' => 'main-row',
        'class' => 'region-time',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'notice',
        ),
        'parent' => 'main',
        'class' => 'row-notice',
      ),
      'notice' => array(
        'type' => 'region',
        'title' => 'Notice',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'schedule-notice',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'schedule_top',
        ),
        'parent' => 'main',
        'class' => 'row-schedule-top',
      ),
      'schedule_top' => array(
        'type' => 'region',
        'title' => 'Schedule Top',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => 'schedule-top',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'time' => NULL,
      'notice' => NULL,
      'schedule_top' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Sunday, February 22, 2015';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-117';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-22/454',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'La Jolla',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'la-jolla',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-117'] = $pane;
    $display->panels['center'][0] = 'new-117';
    $pane = new stdClass();
    $pane->pid = 'new-118';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-22/442',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Carmel',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'carmel',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-118'] = $pane;
    $display->panels['center'][1] = 'new-118';
    $pane = new stdClass();
    $pane->pid = 'new-119';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-22/455',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Los Angeles A',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'los-angeles-a',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $display->content['new-119'] = $pane;
    $display->panels['center'][2] = 'new-119';
    $pane = new stdClass();
    $pane->pid = 'new-120';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-22/457',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Los Angeles B',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'los-angeles-b',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $display->content['new-120'] = $pane;
    $display->panels['center'][3] = 'new-120';
    $pane = new stdClass();
    $pane->pid = 'new-121';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-22/458',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Los Angeles C',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'los-angeles-c',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $display->content['new-121'] = $pane;
    $display->panels['center'][4] = 'new-121';
    $pane = new stdClass();
    $pane->pid = 'new-122';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-22/448',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Century AB',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'century-ab',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $display->content['new-122'] = $pane;
    $display->panels['center'][5] = 'new-122';
    $pane = new stdClass();
    $pane->pid = 'new-123';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-22/451',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Century CD',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'century-cd',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $display->content['new-123'] = $pane;
    $display->panels['center'][6] = 'new-123';
    $pane = new stdClass();
    $pane->pid = 'new-124';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-22/459',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Marina',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'marina',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $display->content['new-124'] = $pane;
    $display->panels['center'][7] = 'new-124';
    $pane = new stdClass();
    $pane->pid = 'new-125';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-22/441',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Bel Air',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'bel-air',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 8;
    $pane->locks = array();
    $display->content['new-125'] = $pane;
    $display->panels['center'][8] = 'new-125';
    $pane = new stdClass();
    $pane->pid = 'new-126';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-22/462',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Santa Monica A',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'santa-monica-a',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 9;
    $pane->locks = array();
    $display->content['new-126'] = $pane;
    $display->panels['center'][9] = 'new-126';
    $pane = new stdClass();
    $pane->pid = 'new-127';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-22/463',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Santa Monica B',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'santa-monica-b',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 10;
    $pane->locks = array();
    $display->content['new-127'] = $pane;
    $display->panels['center'][10] = 'new-127';
    $pane = new stdClass();
    $pane->pid = 'new-128';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-22/464',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo B',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-b',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 11;
    $pane->locks = array();
    $display->content['new-128'] = $pane;
    $display->panels['center'][11] = 'new-128';
    $pane = new stdClass();
    $pane->pid = 'new-129';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-22/465',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo C',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-c',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 12;
    $pane->locks = array();
    $display->content['new-129'] = $pane;
    $display->panels['center'][12] = 'new-129';
    $pane = new stdClass();
    $pane->pid = 'new-130';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-22/466',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo D',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-d',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 13;
    $pane->locks = array();
    $display->content['new-130'] = $pane;
    $display->panels['center'][13] = 'new-130';
    $pane = new stdClass();
    $pane->pid = 'new-131';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-22/467',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo E',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-e',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 14;
    $pane->locks = array();
    $display->content['new-131'] = $pane;
    $display->panels['center'][14] = 'new-131';
    $pane = new stdClass();
    $pane->pid = 'new-132';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-22/468',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo F',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-f',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 15;
    $pane->locks = array();
    $display->content['new-132'] = $pane;
    $display->panels['center'][15] = 'new-132';
    $pane = new stdClass();
    $pane->pid = 'new-133';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-22/1207',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Plaza BC',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 16;
    $pane->locks = array();
    $display->content['new-133'] = $pane;
    $display->panels['center'][16] = 'new-133';
    $pane = new stdClass();
    $pane->pid = 'new-134';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-22/1208',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Plaza D',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 17;
    $pane->locks = array();
    $display->content['new-134'] = $pane;
    $display->panels['center'][17] = 'new-134';
    $pane = new stdClass();
    $pane->pid = 'new-135';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-22/453',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Expo',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 18;
    $pane->locks = array();
    $display->content['new-135'] = $pane;
    $display->panels['center'][18] = 'new-135';
    $pane = new stdClass();
    $pane->pid = 'new-136';
    $pane->panel = 'notice';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Schedule change notice',
      'title' => '',
      'body' => '<p>* The schedule of events is subjected to change without prior notifications.</p>',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-136'] = $pane;
    $display->panels['notice'][0] = 'new-136';
    $pane = new stdClass();
    $pane->pid = 'new-137';
    $pane->panel = 'notice';
    $pane->type = 'views_panes';
    $pane->subtype = 'room_schedule_legend-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_time_value' => '2015-02-22',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-137'] = $pane;
    $display->panels['notice'][1] = 'new-137';
    $pane = new stdClass();
    $pane->pid = 'new-138';
    $pane->panel = 'schedule_top';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-schedule-13x';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-138'] = $pane;
    $display->panels['schedule_top'][0] = 'new-138';
    $pane = new stdClass();
    $pane->pid = 'new-139';
    $pane->panel = 'schedule_top';
    $pane->type = 'views_panes';
    $pane->subtype = 'room_schedule_legend-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_time_value' => '2015-02-22',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-139'] = $pane;
    $display->panels['schedule_top'][1] = 'new-139';
    $pane = new stdClass();
    $pane->pid = 'new-140';
    $pane->panel = 'time';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-22',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Time',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'time',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-140'] = $pane;
    $display->panels['time'][0] = 'new-140';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_schedule_multiyear_panel_context_4';
  $handler->task = 'page';
  $handler->subtask = 'schedule_multiyear';
  $handler->handler = 'panel_context';
  $handler->weight = -26;
  $handler->conf = array(
    'title' => 'Schedule',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Schedules';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-141';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-schedule-13x';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-141'] = $pane;
    $display->panels['middle'][0] = 'new-141';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_schedule_multiyear_panel_context_5';
  $handler->task = 'page';
  $handler->subtask = 'schedule_multiyear';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Thursday',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'schedule_11x friday',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'scale/13x/schedule/2015-02-19
scale/13x/schedule/thursday',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 2,
          1 => 'main-row',
          2 => 1,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'time',
          1 => 'center',
        ),
        'parent' => 'main',
        'class' => 'row-main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Rooms',
        'width' => '100',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'region-rooms',
      ),
      'time' => array(
        'type' => 'region',
        'title' => 'Time',
        'width' => '50',
        'width_type' => 'px',
        'parent' => 'main-row',
        'class' => 'region-time',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'notice',
        ),
        'parent' => 'main',
        'class' => 'row-notice',
      ),
      'notice' => array(
        'type' => 'region',
        'title' => 'Notice',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'schedule-notice',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'schedule_top',
        ),
        'parent' => 'main',
        'class' => 'row-schedule-top',
      ),
      'schedule_top' => array(
        'type' => 'region',
        'title' => 'Schedule Top',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => 'schedule-top',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'time' => NULL,
      'notice' => NULL,
      'schedule_top' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Thursday, February 19, 2015';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-142';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-19/454',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'La Jolla',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'la-jolla',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-142'] = $pane;
    $display->panels['center'][0] = 'new-142';
    $pane = new stdClass();
    $pane->pid = 'new-143';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-19/442',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Carmel',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'carmel',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-143'] = $pane;
    $display->panels['center'][1] = 'new-143';
    $pane = new stdClass();
    $pane->pid = 'new-144';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-19/455',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Los Angeles A',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'los-angeles-a',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $display->content['new-144'] = $pane;
    $display->panels['center'][2] = 'new-144';
    $pane = new stdClass();
    $pane->pid = 'new-145';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-19/457',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Los Angeles B',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'los-angeles-b',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $display->content['new-145'] = $pane;
    $display->panels['center'][3] = 'new-145';
    $pane = new stdClass();
    $pane->pid = 'new-146';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-19/458',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Los Angeles C',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'los-angeles-c',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $display->content['new-146'] = $pane;
    $display->panels['center'][4] = 'new-146';
    $pane = new stdClass();
    $pane->pid = 'new-147';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-19/448',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Century AB',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'century-ab',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $display->content['new-147'] = $pane;
    $display->panels['center'][5] = 'new-147';
    $pane = new stdClass();
    $pane->pid = 'new-148';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-19/451',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Century CD',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'century-cd',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $display->content['new-148'] = $pane;
    $display->panels['center'][6] = 'new-148';
    $pane = new stdClass();
    $pane->pid = 'new-149';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-19/459',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Marina',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'marina',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $display->content['new-149'] = $pane;
    $display->panels['center'][7] = 'new-149';
    $pane = new stdClass();
    $pane->pid = 'new-150';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-19/441',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Bel Air',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'bel-air',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 8;
    $pane->locks = array();
    $display->content['new-150'] = $pane;
    $display->panels['center'][8] = 'new-150';
    $pane = new stdClass();
    $pane->pid = 'new-151';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-19/462',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Santa Monica A',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'santa-monica-a',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 9;
    $pane->locks = array();
    $display->content['new-151'] = $pane;
    $display->panels['center'][9] = 'new-151';
    $pane = new stdClass();
    $pane->pid = 'new-152';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-19/463',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Santa Monica B',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'santa-monica-b',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 10;
    $pane->locks = array();
    $display->content['new-152'] = $pane;
    $display->panels['center'][10] = 'new-152';
    $pane = new stdClass();
    $pane->pid = 'new-153';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-19/464',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo B',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-b',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 11;
    $pane->locks = array();
    $display->content['new-153'] = $pane;
    $display->panels['center'][11] = 'new-153';
    $pane = new stdClass();
    $pane->pid = 'new-154';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-19/465',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo C',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-c',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 12;
    $pane->locks = array();
    $display->content['new-154'] = $pane;
    $display->panels['center'][12] = 'new-154';
    $pane = new stdClass();
    $pane->pid = 'new-155';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-19/466',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo D',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-d',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 13;
    $pane->locks = array();
    $display->content['new-155'] = $pane;
    $display->panels['center'][13] = 'new-155';
    $pane = new stdClass();
    $pane->pid = 'new-156';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-19/467',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo E',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-e',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 14;
    $pane->locks = array();
    $display->content['new-156'] = $pane;
    $display->panels['center'][14] = 'new-156';
    $pane = new stdClass();
    $pane->pid = 'new-157';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-19/468',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'San Lorenzo F',
      'context' => array(
        0 => '',
        1 => '',
        2 => '',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'san-lorenzo-f',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 15;
    $pane->locks = array();
    $display->content['new-157'] = $pane;
    $display->panels['center'][15] = 'new-157';
    $pane = new stdClass();
    $pane->pid = 'new-158';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-19/1207',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Plaza BC',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 16;
    $pane->locks = array();
    $display->content['new-158'] = $pane;
    $display->panels['center'][16] = 'new-158';
    $pane = new stdClass();
    $pane->pid = 'new-159';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-19/1208',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Plaza D',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 17;
    $pane->locks = array();
    $display->content['new-159'] = $pane;
    $display->panels['center'][17] = 'new-159';
    $pane = new stdClass();
    $pane->pid = 'new-160';
    $pane->panel = 'notice';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Schedule change notice',
      'title' => '',
      'body' => '<p>* The schedule of events is subjected to change without prior notifications.</p>',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-160'] = $pane;
    $display->panels['notice'][0] = 'new-160';
    $pane = new stdClass();
    $pane->pid = 'new-161';
    $pane->panel = 'notice';
    $pane->type = 'views_panes';
    $pane->subtype = 'room_schedule_legend-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_time_value' => '2015-02-19',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-161'] = $pane;
    $display->panels['notice'][1] = 'new-161';
    $pane = new stdClass();
    $pane->pid = 'new-162';
    $pane->panel = 'schedule_top';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-schedule-13x';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-162'] = $pane;
    $display->panels['schedule_top'][0] = 'new-162';
    $pane = new stdClass();
    $pane->pid = 'new-163';
    $pane->panel = 'schedule_top';
    $pane->type = 'views_panes';
    $pane->subtype = 'room_schedule_legend-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_time_value' => '2015-02-19',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $display->content['new-163'] = $pane;
    $display->panels['schedule_top'][1] = 'new-163';
    $pane = new stdClass();
    $pane->pid = 'new-164';
    $pane->panel = 'time';
    $pane->type = 'views';
    $pane->subtype = 'room_schedule';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '2015-02-19',
      'url' => '',
      'display' => 'page_3',
      'override_title' => 1,
      'override_title_text' => 'Time',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => 'time',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-164'] = $pane;
    $display->panels['time'][0] = 'new-164';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['schedule_multiyear'] = $page;

  return $pages;

}
