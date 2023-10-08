<?php

/**
 * @file
 * scale_front_page.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function scale_front_page_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'front_page_multi_year';
  $view->description = 'Emulates the default Drupal front page; you may set the default home page path to this view to make it your front page.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Front page multi-year';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Sort criterion: Content: Sticky status */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: SCALE event (field_scale_event) */
  $handler->display->display_options['arguments']['field_scale_event_tid']['id'] = 'field_scale_event_tid';
  $handler->display->display_options['arguments']['field_scale_event_tid']['table'] = 'field_data_field_scale_event';
  $handler->display->display_options['arguments']['field_scale_event_tid']['field'] = 'field_scale_event_tid';
  $handler->display->display_options['arguments']['field_scale_event_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_scale_event_tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_scale_event_tid']['default_argument_options']['index'] = '1';
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
  /* Filter criterion: Content: Promoted to front page status */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['filters']['promote']['group'] = 0;
  $handler->display->display_options['filters']['promote']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: SCALE event (field_scale_event) */
  $handler->display->display_options['filters']['field_scale_event_tid']['id'] = 'field_scale_event_tid';
  $handler->display->display_options['filters']['field_scale_event_tid']['table'] = 'field_data_field_scale_event';
  $handler->display->display_options['filters']['field_scale_event_tid']['field'] = 'field_scale_event_tid';
  $handler->display->display_options['filters']['field_scale_event_tid']['value'] = array(
    503 => '503',
  );
  $handler->display->display_options['filters']['field_scale_event_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_scale_event_tid']['vocabulary'] = 'scale_event';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Front page feed';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Promoted to front page status */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['filters']['promote']['group'] = 0;
  $handler->display->display_options['filters']['promote']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: SCALE event (field_scale_event) */
  $handler->display->display_options['filters']['field_scale_event_tid']['id'] = 'field_scale_event_tid';
  $handler->display->display_options['filters']['field_scale_event_tid']['table'] = 'field_data_field_scale_event';
  $handler->display->display_options['filters']['field_scale_event_tid']['field'] = 'field_scale_event_tid';
  $handler->display->display_options['filters']['field_scale_event_tid']['value'] = array(
    504 => '504',
  );
  $handler->display->display_options['filters']['field_scale_event_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_scale_event_tid']['vocabulary'] = 'scale_event';
  $handler->display->display_options['path'] = 'rss.xml';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );
  $handler->display->display_options['sitename_title'] = '1';

  /* Display: multi-year */
  $handler = $view->new_display('page', 'multi-year', 'page_3');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Promoted to front page status */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['filters']['promote']['group'] = 0;
  $handler->display->display_options['filters']['promote']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Published status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  $handler->display->display_options['path'] = 'scale/%';
  $export['front_page_multi_year'] = $view;

  return $export;
}
