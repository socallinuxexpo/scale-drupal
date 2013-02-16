<?php
/**
 * @file
 * video.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function video_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'video';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Video';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Video';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] Video Stream';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_class'] = 'video-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Embed Code */
  $handler->display->display_options['fields']['field_embed_code_video']['id'] = 'field_embed_code_video';
  $handler->display->display_options['fields']['field_embed_code_video']['table'] = 'field_data_field_embed_code_video';
  $handler->display->display_options['fields']['field_embed_code_video']['field'] = 'field_embed_code_video';
  $handler->display->display_options['fields']['field_embed_code_video']['label'] = '';
  $handler->display->display_options['fields']['field_embed_code_video']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_embed_code_video']['empty'] = 'Video is not available at this time.';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'streaming_video' => 'streaming_video',
  );
  /* Filter criterion: Content: Room (field_room_video) */
  $handler->display->display_options['filters']['field_room_video_tid']['id'] = 'field_room_video_tid';
  $handler->display->display_options['filters']['field_room_video_tid']['table'] = 'field_data_field_room_video';
  $handler->display->display_options['filters']['field_room_video_tid']['field'] = 'field_room_video_tid';
  $handler->display->display_options['filters']['field_room_video_tid']['value'] = array(
    467 => '467',
    468 => '468',
    442 => '442',
    448 => '448',
    451 => '451',
    454 => '454',
    455 => '455',
    457 => '457',
    458 => '458',
    459 => '459',
  );
  $handler->display->display_options['filters']['field_room_video_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_room_video_tid']['expose']['operator_id'] = 'field_room_video_tid_op';
  $handler->display->display_options['filters']['field_room_video_tid']['expose']['label'] = 'Room';
  $handler->display->display_options['filters']['field_room_video_tid']['expose']['operator'] = 'field_room_video_tid_op';
  $handler->display->display_options['filters']['field_room_video_tid']['expose']['identifier'] = 'room';
  $handler->display->display_options['filters']['field_room_video_tid']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['field_room_video_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    5 => 0,
    4 => 0,
    9 => 0,
    10 => 0,
    8 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_room_video_tid']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_room_video_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_room_video_tid']['vocabulary'] = 'room';
  $handler->display->display_options['filters']['field_room_video_tid']['error_message'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'scale11x/video';
  $export['video'] = $view;

  return $export;
}
