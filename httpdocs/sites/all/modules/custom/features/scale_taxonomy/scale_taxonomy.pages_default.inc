<?php
/**
 * @file
 * scale_taxonomy.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function scale_taxonomy_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view_panel_context';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Term List',
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
  $display->uuid = 'bd12fde8-78d0-42a4-97c9-69ee5c02e800';
  $display->storage_type = '';
  $display->storage_id = '';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-d28c1e74-7412-4fd5-abd8-f0c15364d97c';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'term_list-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'd28c1e74-7412-4fd5-abd8-f0c15364d97c';
  $display->content['new-d28c1e74-7412-4fd5-abd8-f0c15364d97c'] = $pane;
  $display->panels['middle'][0] = 'new-d28c1e74-7412-4fd5-abd8-f0c15364d97c';
  $pane = new stdClass();
  $pane->pid = 'new-6a42df5c-3550-4461-b7f3-f1b881ecf9c4';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'term_list';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 1,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'page_1',
    'context' => array(
      0 => '',
      1 => '',
      2 => '',
    ),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '6a42df5c-3550-4461-b7f3-f1b881ecf9c4';
  $display->content['new-6a42df5c-3550-4461-b7f3-f1b881ecf9c4'] = $pane;
  $display->panels['middle'][1] = 'new-6a42df5c-3550-4461-b7f3-f1b881ecf9c4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view_panel_context'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function scale_taxonomy_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'audience_page';
  $page->task = 'page';
  $page->admin_title = 'Audience page';
  $page->admin_description = '';
  $page->path = 'scale/%event/audience-level/%term';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'event' => array(
      'id' => 1,
      'identifier' => 'scale_event',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
    'term' => array(
      'id' => 2,
      'identifier' => 'term',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_audience_page__panel_context_8a839b80-f9ef-4f72-a943-0914e7d26c91';
  $handler->task = 'page';
  $handler->subtask = 'audience_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
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
  $display->title = '%term:uppercase_words_html_safe';
  $display->uuid = 'd14034a1-77bd-4617-a25b-660ecb34a7cf';
  $display->storage_type = '';
  $display->storage_id = '';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-717d8f37-6f1e-4b4f-861b-6ccbc6dc9c32';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'term_list';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 1,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'default',
    'context' => array(
      0 => 'argument_string_1.raw',
      1 => 'argument_string_2.raw',
      2 => '',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '717d8f37-6f1e-4b4f-861b-6ccbc6dc9c32';
  $display->content['new-717d8f37-6f1e-4b4f-861b-6ccbc6dc9c32'] = $pane;
  $display->panels['middle'][0] = 'new-717d8f37-6f1e-4b4f-861b-6ccbc6dc9c32';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-717d8f37-6f1e-4b4f-861b-6ccbc6dc9c32';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['audience_page'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'term_page';
  $page->task = 'page';
  $page->admin_title = 'Track page';
  $page->admin_description = '';
  $page->path = 'scale/%event/track/%term';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'event' => array(
      'id' => 1,
      'identifier' => 'scale_event',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
    'term' => array(
      'id' => 2,
      'identifier' => 'term',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_term_page__panel';
  $handler->task = 'page';
  $handler->subtask = 'term_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
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
  $display->title = '%term:uppercase_words_html_safe';
  $display->uuid = 'c50509d4-0659-4703-afe2-ffe14f73e481';
  $display->storage_type = '';
  $display->storage_id = '';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-645e5f09-9ae4-4d53-9740-ada30b0b9a92';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'term_list';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 1,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'default',
    'context' => array(
      0 => 'argument_string_1.raw',
      1 => 'argument_string_2.raw',
      2 => '',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '645e5f09-9ae4-4d53-9740-ada30b0b9a92';
  $display->content['new-645e5f09-9ae4-4d53-9740-ada30b0b9a92'] = $pane;
  $display->panels['middle'][0] = 'new-645e5f09-9ae4-4d53-9740-ada30b0b9a92';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['term_page'] = $page;

  return $pages;

}
