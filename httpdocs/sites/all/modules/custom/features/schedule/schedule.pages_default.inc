<?php
/**
 * @file
 * schedule.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function schedule_default_page_manager_pages() {
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
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_schedule_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'schedule';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
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
            'paths' => 'scale11x/schedule/saturday
scale11x/schedule/2013-02-23',
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
  $display->title = 'Saturday, February 23, 2013';
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
      'args' => '2013-02-23/454',
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
      'args' => '2013-02-23/442',
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
      'args' => '2013-02-23/455',
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
      'args' => '2013-02-23/457',
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
      'args' => '2013-02-23/458',
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
      'args' => '2013-02-23/448',
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
      'args' => '2013-02-23/451',
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
      'args' => '2013-02-23/459',
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
      'args' => '2013-02-23/441',
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
      'args' => '2013-02-23/462',
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
      'args' => '2013-02-23/463',
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
      'args' => '2013-02-23/464',
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
      'args' => '2013-02-23/465',
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
      'args' => '2013-02-23/466',
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
      'args' => '2013-02-23/467',
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
      'args' => '2013-02-23/468',
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
      'args' => '2013-02-23/453',
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
    $display->content['new-17'] = $pane;
    $display->panels['center'][16] = 'new-17';
    $pane = new stdClass();
    $pane->pid = 'new-18';
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
    $display->content['new-18'] = $pane;
    $display->panels['notice'][0] = 'new-18';
    $pane = new stdClass();
    $pane->pid = 'new-19';
    $pane->panel = 'notice';
    $pane->type = 'views_panes';
    $pane->subtype = 'room_schedule_legend-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_time_value' => '2013-02-23',
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
    $display->content['new-19'] = $pane;
    $display->panels['notice'][1] = 'new-19';
    $pane = new stdClass();
    $pane->pid = 'new-20';
    $pane->panel = 'schedule_top';
    $pane->type = 'block';
    $pane->subtype = 'menu_block-1';
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
    $display->content['new-20'] = $pane;
    $display->panels['schedule_top'][0] = 'new-20';
    $pane = new stdClass();
    $pane->pid = 'new-21';
    $pane->panel = 'schedule_top';
    $pane->type = 'views_panes';
    $pane->subtype = 'room_schedule_legend-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_time_value' => '2013-02-23',
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
    $display->content['new-21'] = $pane;
    $display->panels['schedule_top'][1] = 'new-21';
    $pane = new stdClass();
    $pane->pid = 'new-22';
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
      'args' => '2013-02-20',
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
    $display->content['new-22'] = $pane;
    $display->panels['time'][0] = 'new-22';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_schedule_panel_context_3';
  $handler->task = 'page';
  $handler->subtask = 'schedule';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
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
            'paths' => 'scale11x/schedule/sunday
scale11x/schedule/2013-02-24',
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
  $display->title = 'Sunday, February 24, 2013';
  $display->content = array();
  $display->panels = array();
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
      'args' => '2013-02-24/454',
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
    $display->content['new-23'] = $pane;
    $display->panels['center'][0] = 'new-23';
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
      'args' => '2013-02-24/442',
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
    $display->content['new-24'] = $pane;
    $display->panels['center'][1] = 'new-24';
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
      'args' => '2013-02-24/455',
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
    $display->content['new-25'] = $pane;
    $display->panels['center'][2] = 'new-25';
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
      'args' => '2013-02-24/457',
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
    $display->content['new-26'] = $pane;
    $display->panels['center'][3] = 'new-26';
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
      'args' => '2013-02-24/458',
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
    $display->content['new-27'] = $pane;
    $display->panels['center'][4] = 'new-27';
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
      'args' => '2013-02-24/448',
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
    $display->content['new-28'] = $pane;
    $display->panels['center'][5] = 'new-28';
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
      'args' => '2013-02-24/451',
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
    $display->content['new-29'] = $pane;
    $display->panels['center'][6] = 'new-29';
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
      'args' => '2013-02-24/459',
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
    $display->content['new-30'] = $pane;
    $display->panels['center'][7] = 'new-30';
    $pane = new stdClass();
    $pane->pid = 'new-31';
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
      'args' => '2013-02-24/441',
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
    $display->content['new-31'] = $pane;
    $display->panels['center'][8] = 'new-31';
    $pane = new stdClass();
    $pane->pid = 'new-32';
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
      'args' => '2013-02-24/462',
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
    $display->content['new-32'] = $pane;
    $display->panels['center'][9] = 'new-32';
    $pane = new stdClass();
    $pane->pid = 'new-33';
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
      'args' => '2013-02-24/463',
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
    $display->content['new-33'] = $pane;
    $display->panels['center'][10] = 'new-33';
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
      'args' => '2013-02-24/464',
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
    $display->content['new-34'] = $pane;
    $display->panels['center'][11] = 'new-34';
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
      'args' => '2013-02-24/465',
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
    $display->content['new-35'] = $pane;
    $display->panels['center'][12] = 'new-35';
    $pane = new stdClass();
    $pane->pid = 'new-36';
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
      'args' => '2013-02-24/466',
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
    $display->content['new-36'] = $pane;
    $display->panels['center'][13] = 'new-36';
    $pane = new stdClass();
    $pane->pid = 'new-37';
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
      'args' => '2013-02-24/467',
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
    $display->content['new-37'] = $pane;
    $display->panels['center'][14] = 'new-37';
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
      'args' => '2013-02-24/468',
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
    $display->content['new-38'] = $pane;
    $display->panels['center'][15] = 'new-38';
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
      'args' => '2013-02-24/453',
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
    $display->content['new-39'] = $pane;
    $display->panels['center'][16] = 'new-39';
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
        'field_time_value' => '2013-02-24',
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
    $pane->subtype = 'menu_block-1';
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
        'field_time_value' => '2013-02-24',
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
      'args' => '2013-02-20',
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
  $handler->name = 'page_schedule_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'schedule';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
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
            'paths' => 'scale11x/schedule/friday
scale11x/schedule/2013-02-22',
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
  $display->title = 'Friday, February 22, 2013';
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
      'args' => '2013-02-22/454',
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
      'args' => '2013-02-22/442',
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
      'args' => '2013-02-22/455',
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
      'args' => '2013-02-22/457',
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
      'args' => '2013-02-22/458',
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
      'args' => '2013-02-22/448',
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
      'args' => '2013-02-22/451',
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
      'args' => '2013-02-22/459',
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
      'args' => '2013-02-22/441',
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
      'args' => '2013-02-22/462',
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
      'args' => '2013-02-22/463',
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
      'args' => '2013-02-22/464',
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
      'args' => '2013-02-22/465',
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
      'args' => '2013-02-22/466',
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
      'args' => '2013-02-22/467',
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
      'args' => '2013-02-22/468',
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
    $display->content['new-61'] = $pane;
    $display->panels['notice'][0] = 'new-61';
    $pane = new stdClass();
    $pane->pid = 'new-62';
    $pane->panel = 'notice';
    $pane->type = 'views_panes';
    $pane->subtype = 'room_schedule_legend-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_time_value' => '2013-02-22',
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
    $display->content['new-62'] = $pane;
    $display->panels['notice'][1] = 'new-62';
    $pane = new stdClass();
    $pane->pid = 'new-63';
    $pane->panel = 'schedule_top';
    $pane->type = 'block';
    $pane->subtype = 'menu_block-1';
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
    $display->content['new-63'] = $pane;
    $display->panels['schedule_top'][0] = 'new-63';
    $pane = new stdClass();
    $pane->pid = 'new-64';
    $pane->panel = 'schedule_top';
    $pane->type = 'views_panes';
    $pane->subtype = 'room_schedule_legend-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_time_value' => '2013-02-22',
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
    $display->content['new-64'] = $pane;
    $display->panels['schedule_top'][1] = 'new-64';
    $pane = new stdClass();
    $pane->pid = 'new-65';
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
      'args' => '2013-02-20',
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
    $display->content['new-65'] = $pane;
    $display->panels['time'][0] = 'new-65';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['schedule'] = $page;

  return $pages;

}
