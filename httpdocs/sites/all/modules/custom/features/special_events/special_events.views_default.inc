<?php
/**
 * @file
 * special_events.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function special_events_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'event_sponsors';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Event Sponsors';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Event Sponsors';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'panels_fields';
  $handler->display->display_options['row_options']['regions'] = array(
    'title' => 'left',
  );
  /* Relationship: Content: Sponsor (field_sponsor) */
  $handler->display->display_options['relationships']['field_sponsor_nid']['id'] = 'field_sponsor_nid';
  $handler->display->display_options['relationships']['field_sponsor_nid']['table'] = 'field_data_field_sponsor';
  $handler->display->display_options['relationships']['field_sponsor_nid']['field'] = 'field_sponsor_nid';
  $handler->display->display_options['relationships']['field_sponsor_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_sponsor_nid']['delta'] = '-1';
  /* Field: Content: Logo (website) */
  $handler->display->display_options['fields']['field_logo_website']['id'] = 'field_logo_website';
  $handler->display->display_options['fields']['field_logo_website']['table'] = 'field_data_field_logo_website';
  $handler->display->display_options['fields']['field_logo_website']['field'] = 'field_logo_website';
  $handler->display->display_options['fields']['field_logo_website']['relationship'] = 'field_sponsor_nid';
  $handler->display->display_options['fields']['field_logo_website']['label'] = '';
  $handler->display->display_options['fields']['field_logo_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logo_website']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo_website']['settings'] = array(
    'image_style' => 'logo_large',
    'image_link' => '',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'special_event' => 'special_event',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'event-sponsors';
  $export['event_sponsors'] = $view;

  $view = new view();
  $view->name = 'special_events';
  $view->description = 'List of special events';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Special events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Special events';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Logo */
  $handler->display->display_options['fields']['field_logo']['id'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['table'] = 'field_data_field_logo';
  $handler->display->display_options['fields']['field_logo']['field'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['label'] = '';
  $handler->display->display_options['fields']['field_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logo']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_class'] = 'title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '300';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: scale event */
  $handler->display->display_options['arguments']['field_scale_event_tid']['id'] = 'field_scale_event_tid';
  $handler->display->display_options['arguments']['field_scale_event_tid']['table'] = 'field_data_field_scale_event';
  $handler->display->display_options['arguments']['field_scale_event_tid']['field'] = 'field_scale_event_tid';
  $handler->display->display_options['arguments']['field_scale_event_tid']['ui_name'] = 'scale event';
  $handler->display->display_options['arguments']['field_scale_event_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_scale_event_tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_scale_event_tid']['default_argument_options']['index'] = '0';
  $handler->display->display_options['arguments']['field_scale_event_tid']['default_argument_options']['use_alias'] = TRUE;
  $handler->display->display_options['arguments']['field_scale_event_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_scale_event_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_scale_event_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_scale_event_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_scale_event_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_scale_event_tid']['validate_options']['vocabularies'] = array(
    'scale_event' => 'scale_event',
  );
  $handler->display->display_options['arguments']['field_scale_event_tid']['validate_options']['type'] = 'convert';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'special_event' => 'special_event',
  );

  /* Display: Special events 11x */
  $handler = $view->new_display('page', 'Special events 11x', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'scale11x/events';
  $handler->display->display_options['menu']['title'] = 'Special Events';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Special events 12x */
  $handler = $view->new_display('page', 'Special events 12x', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'scale12x/events';
  $handler->display->display_options['menu']['title'] = 'Special Events';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $export['special_events'] = $view;

  return $export;
}
