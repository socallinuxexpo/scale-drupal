<?php
/**
 * @file
 * sessions.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function sessions_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'electronic_sign';
  $view->description = 'XML feed for electronic schedule signs';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Electronic Sign';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Electronic Sign';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Room */
  $handler->display->display_options['fields']['field_room']['id'] = 'field_room';
  $handler->display->display_options['fields']['field_room']['table'] = 'field_data_field_room';
  $handler->display->display_options['fields']['field_room']['field'] = 'field_room';
  $handler->display->display_options['fields']['field_room']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_room']['delta_offset'] = '0';
  /* Field: Content: Time */
  $handler->display->display_options['fields']['field_time']['id'] = 'field_time';
  $handler->display->display_options['fields']['field_time']['table'] = 'field_data_field_time';
  $handler->display->display_options['fields']['field_time']['field'] = 'field_time';
  $handler->display->display_options['fields']['field_time']['label'] = 'Day';
  $handler->display->display_options['fields']['field_time']['settings'] = array(
    'format_type' => 'day_of_week',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Time */
  $handler->display->display_options['fields']['field_time_1']['id'] = 'field_time_1';
  $handler->display->display_options['fields']['field_time_1']['table'] = 'field_data_field_time';
  $handler->display->display_options['fields']['field_time_1']['field'] = 'field_time';
  $handler->display->display_options['fields']['field_time_1']['settings'] = array(
    'format_type' => '24_hour_time',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Speaker */
  $handler->display->display_options['fields']['field_speaker']['id'] = 'field_speaker';
  $handler->display->display_options['fields']['field_speaker']['table'] = 'field_data_field_speaker';
  $handler->display->display_options['fields']['field_speaker']['field'] = 'field_speaker';
  $handler->display->display_options['fields']['field_speaker']['type'] = 'user_reference_plain';
  $handler->display->display_options['fields']['field_speaker']['delta_offset'] = '0';
  /* Field: Content: Topic */
  $handler->display->display_options['fields']['field_topic']['id'] = 'field_topic';
  $handler->display->display_options['fields']['field_topic']['table'] = 'field_data_field_topic';
  $handler->display->display_options['fields']['field_topic']['field'] = 'field_topic';
  $handler->display->display_options['fields']['field_topic']['type'] = 'taxonomy_term_reference_plain';
  /* Sort criterion: Content: Time -  start date (field_time) */
  $handler->display->display_options['sorts']['field_time_value']['id'] = 'field_time_value';
  $handler->display->display_options['sorts']['field_time_value']['table'] = 'field_data_field_time';
  $handler->display->display_options['sorts']['field_time_value']['field'] = 'field_time_value';
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
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'presentation' => 'presentation',
  );
  /* Filter criterion: Content: Room (field_room) */
  $handler->display->display_options['filters']['field_room_tid']['id'] = 'field_room_tid';
  $handler->display->display_options['filters']['field_room_tid']['table'] = 'field_data_field_room';
  $handler->display->display_options['filters']['field_room_tid']['field'] = 'field_room_tid';
  $handler->display->display_options['filters']['field_room_tid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_room_tid']['value'] = '';
  $handler->display->display_options['filters']['field_room_tid']['vocabulary'] = 'room';
  /* Filter criterion: Content: Time -  start date (field_time) */
  $handler->display->display_options['filters']['field_time_value']['id'] = 'field_time_value';
  $handler->display->display_options['filters']['field_time_value']['table'] = 'field_data_field_time';
  $handler->display->display_options['filters']['field_time_value']['field'] = 'field_time_value';
  $handler->display->display_options['filters']['field_time_value']['operator'] = 'not empty';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'electronic-sign';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xml';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['transform'] = 1;
  $handler->display->display_options['path'] = 'scale11x/sign.xml';
  $export['electronic_sign'] = $view;

  $view = new view();
  $view->name = 'my_presentations';
  $view->description = 'List of links to current user\'s presentations';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'My presentations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My presentations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Speaker (field_speaker) */
  $handler->display->display_options['arguments']['field_speaker_uid']['id'] = 'field_speaker_uid';
  $handler->display->display_options['arguments']['field_speaker_uid']['table'] = 'field_data_field_speaker';
  $handler->display->display_options['arguments']['field_speaker_uid']['field'] = 'field_speaker_uid';
  $handler->display->display_options['arguments']['field_speaker_uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_speaker_uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['field_speaker_uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_speaker_uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_speaker_uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'presentation' => 'presentation',
  );
  /* Filter criterion: Content: SCALE event (field_scale_event) */
  $handler->display->display_options['filters']['field_scale_event_tid']['id'] = 'field_scale_event_tid';
  $handler->display->display_options['filters']['field_scale_event_tid']['table'] = 'field_data_field_scale_event';
  $handler->display->display_options['filters']['field_scale_event_tid']['field'] = 'field_scale_event_tid';
  $handler->display->display_options['filters']['field_scale_event_tid']['value'] = array(
    504 => '504',
  );
  $handler->display->display_options['filters']['field_scale_event_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_scale_event_tid']['vocabulary'] = 'scale_event';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'my-presentations';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['block_description'] = 'My presentations';
  $export['my_presentations'] = $view;

  $view = new view();
  $view->name = 'my_votes';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'My Votes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My Votes';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_speaker' => 'field_speaker',
    'value' => 'value',
  );
  $handler->display->display_options['style_options']['default'] = 'value';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_speaker' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Content: Votes */
  $handler->display->display_options['relationships']['votingapi_vote']['id'] = 'votingapi_vote';
  $handler->display->display_options['relationships']['votingapi_vote']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_vote']['field'] = 'votingapi_vote';
  $handler->display->display_options['relationships']['votingapi_vote']['votingapi'] = array(
    'value_type' => '',
    'tag' => '',
  );
  $handler->display->display_options['relationships']['votingapi_vote']['current_user'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Speaker */
  $handler->display->display_options['fields']['field_speaker']['id'] = 'field_speaker';
  $handler->display->display_options['fields']['field_speaker']['table'] = 'field_data_field_speaker';
  $handler->display->display_options['fields']['field_speaker']['field'] = 'field_speaker';
  $handler->display->display_options['fields']['field_speaker']['delta_offset'] = '0';
  /* Field: Votes: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['value']['precision'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'presentation' => 'presentation',
  );
  /* Filter criterion: Content: SCALE event (field_scale_event) */
  $handler->display->display_options['filters']['field_scale_event_tid']['id'] = 'field_scale_event_tid';
  $handler->display->display_options['filters']['field_scale_event_tid']['table'] = 'field_data_field_scale_event';
  $handler->display->display_options['filters']['field_scale_event_tid']['field'] = 'field_scale_event_tid';
  $handler->display->display_options['filters']['field_scale_event_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_scale_event_tid']['expose']['operator_id'] = 'field_scale_event_tid_op';
  $handler->display->display_options['filters']['field_scale_event_tid']['expose']['label'] = 'SCALE event';
  $handler->display->display_options['filters']['field_scale_event_tid']['expose']['operator'] = 'field_scale_event_tid_op';
  $handler->display->display_options['filters']['field_scale_event_tid']['expose']['identifier'] = 'scale_event';
  $handler->display->display_options['filters']['field_scale_event_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_scale_event_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_scale_event_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_scale_event_tid']['vocabulary'] = 'scale_event';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'my-votes';
  $export['my_votes'] = $view;

  $view = new view();
  $view->name = 'presentation_downloads';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Presentation Downloads';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Presentation Downloads';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_audio_video' => 'field_audio_video',
    'field_presentation_to_upload' => 'field_presentation_to_upload',
    'field_presentation_link' => 'field_presentation_link',
  );
  $handler->display->display_options['row_options']['separator'] = ' | ';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Audio/Video */
  $handler->display->display_options['fields']['field_audio_video']['id'] = 'field_audio_video';
  $handler->display->display_options['fields']['field_audio_video']['table'] = 'field_data_field_audio_video';
  $handler->display->display_options['fields']['field_audio_video']['field'] = 'field_audio_video';
  $handler->display->display_options['fields']['field_audio_video']['label'] = '';
  $handler->display->display_options['fields']['field_audio_video']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_audio_video']['alter']['text'] = 'Video';
  $handler->display->display_options['fields']['field_audio_video']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_audio_video']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_audio_video']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_audio_video']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_audio_video']['hide_empty'] = TRUE;
  /* Field: Content: Presentation */
  $handler->display->display_options['fields']['field_presentation_to_upload']['id'] = 'field_presentation_to_upload';
  $handler->display->display_options['fields']['field_presentation_to_upload']['table'] = 'field_data_field_presentation_to_upload';
  $handler->display->display_options['fields']['field_presentation_to_upload']['field'] = 'field_presentation_to_upload';
  $handler->display->display_options['fields']['field_presentation_to_upload']['label'] = '';
  $handler->display->display_options['fields']['field_presentation_to_upload']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_presentation_to_upload']['alter']['text'] = 'Slides';
  $handler->display->display_options['fields']['field_presentation_to_upload']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_presentation_to_upload']['alter']['path'] = '[field_presentation_to_upload]';
  $handler->display->display_options['fields']['field_presentation_to_upload']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_presentation_to_upload']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_presentation_to_upload']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_presentation_to_upload']['type'] = 'file_url_plain';
  /* Field: Content: Presentation Link */
  $handler->display->display_options['fields']['field_presentation_link']['id'] = 'field_presentation_link';
  $handler->display->display_options['fields']['field_presentation_link']['table'] = 'field_data_field_presentation_link';
  $handler->display->display_options['fields']['field_presentation_link']['field'] = 'field_presentation_link';
  $handler->display->display_options['fields']['field_presentation_link']['label'] = '';
  $handler->display->display_options['fields']['field_presentation_link']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_presentation_link']['alter']['text'] = 'Slides';
  $handler->display->display_options['fields']['field_presentation_link']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_presentation_link']['alter']['path'] = '[field_presentation_link]';
  $handler->display->display_options['fields']['field_presentation_link']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_presentation_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_presentation_link']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_presentation_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_presentation_link']['type'] = 'link_plain';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
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
    'presentation' => 'presentation',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Audio/Video (field_audio_video) */
  $handler->display->display_options['filters']['field_audio_video_value']['id'] = 'field_audio_video_value';
  $handler->display->display_options['filters']['field_audio_video_value']['table'] = 'field_data_field_audio_video';
  $handler->display->display_options['filters']['field_audio_video_value']['field'] = 'field_audio_video_value';
  $handler->display->display_options['filters']['field_audio_video_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_audio_video_value']['group'] = 2;
  /* Filter criterion: Content: Presentation (field_presentation_to_upload:fid) */
  $handler->display->display_options['filters']['field_presentation_to_upload_fid']['id'] = 'field_presentation_to_upload_fid';
  $handler->display->display_options['filters']['field_presentation_to_upload_fid']['table'] = 'field_data_field_presentation_to_upload';
  $handler->display->display_options['filters']['field_presentation_to_upload_fid']['field'] = 'field_presentation_to_upload_fid';
  $handler->display->display_options['filters']['field_presentation_to_upload_fid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_presentation_to_upload_fid']['group'] = 2;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'scale11x/presentations/downloads';
  $export['presentation_downloads'] = $view;

  $view = new view();
  $view->name = 'presentation_filter';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Presentation Filter';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Presentation Filter';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'track-[tid]';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_time' => 'field_time',
    'field_time_1' => 'field_time_1',
  );
  $handler->display->display_options['row_options']['separator'] = ' - ';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No presentations match the selected filters.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['label'] = 'track term';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'topic' => 'topic',
    'audience' => 0,
    'room' => 0,
    'tags' => 0,
  );
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Speaker */
  $handler->display->display_options['fields']['field_speaker']['id'] = 'field_speaker';
  $handler->display->display_options['fields']['field_speaker']['table'] = 'field_data_field_speaker';
  $handler->display->display_options['fields']['field_speaker']['field'] = 'field_speaker';
  $handler->display->display_options['fields']['field_speaker']['label'] = '';
  $handler->display->display_options['fields']['field_speaker']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_speaker']['delta_offset'] = '0';
  /* Field: Content: Time */
  $handler->display->display_options['fields']['field_time']['id'] = 'field_time';
  $handler->display->display_options['fields']['field_time']['table'] = 'field_data_field_time';
  $handler->display->display_options['fields']['field_time']['field'] = 'field_time';
  $handler->display->display_options['fields']['field_time']['label'] = '';
  $handler->display->display_options['fields']['field_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_time']['settings'] = array(
    'format_type' => 'day_of_week',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Time */
  $handler->display->display_options['fields']['field_time_1']['id'] = 'field_time_1';
  $handler->display->display_options['fields']['field_time_1']['table'] = 'field_data_field_time';
  $handler->display->display_options['fields']['field_time_1']['field'] = 'field_time';
  $handler->display->display_options['fields']['field_time_1']['label'] = '';
  $handler->display->display_options['fields']['field_time_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_time_1']['settings'] = array(
    'format_type' => '24_hour_time',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Sort criterion: Content: Time -  start date (field_time) */
  $handler->display->display_options['sorts']['field_time_value']['id'] = 'field_time_value';
  $handler->display->display_options['sorts']['field_time_value']['table'] = 'field_data_field_time';
  $handler->display->display_options['sorts']['field_time_value']['field'] = 'field_time_value';
  /* Sort criterion: Content: Room (field_room) */
  $handler->display->display_options['sorts']['field_room_tid']['id'] = 'field_room_tid';
  $handler->display->display_options['sorts']['field_room_tid']['table'] = 'field_data_field_room';
  $handler->display->display_options['sorts']['field_room_tid']['field'] = 'field_room_tid';
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
    'presentation' => 'presentation',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Topic (field_topic) */
  $handler->display->display_options['filters']['field_topic_tid']['id'] = 'field_topic_tid';
  $handler->display->display_options['filters']['field_topic_tid']['table'] = 'field_data_field_topic';
  $handler->display->display_options['filters']['field_topic_tid']['field'] = 'field_topic_tid';
  $handler->display->display_options['filters']['field_topic_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_topic_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_topic_tid']['expose']['operator_id'] = 'field_topic_tid_op';
  $handler->display->display_options['filters']['field_topic_tid']['expose']['label'] = 'Track';
  $handler->display->display_options['filters']['field_topic_tid']['expose']['operator'] = 'field_topic_tid_op';
  $handler->display->display_options['filters']['field_topic_tid']['expose']['identifier'] = 'field_topic_tid';
  $handler->display->display_options['filters']['field_topic_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_topic_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_topic_tid']['vocabulary'] = 'topic';
  /* Filter criterion: Content: Audience (field_audience) */
  $handler->display->display_options['filters']['field_audience_tid']['id'] = 'field_audience_tid';
  $handler->display->display_options['filters']['field_audience_tid']['table'] = 'field_data_field_audience';
  $handler->display->display_options['filters']['field_audience_tid']['field'] = 'field_audience_tid';
  $handler->display->display_options['filters']['field_audience_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_audience_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_audience_tid']['expose']['operator_id'] = 'field_audience_tid_op';
  $handler->display->display_options['filters']['field_audience_tid']['expose']['label'] = 'Audience';
  $handler->display->display_options['filters']['field_audience_tid']['expose']['operator'] = 'field_audience_tid_op';
  $handler->display->display_options['filters']['field_audience_tid']['expose']['identifier'] = 'field_audience_tid';
  $handler->display->display_options['filters']['field_audience_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_audience_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_audience_tid']['vocabulary'] = 'audience';
  /* Filter criterion: Content: SCALE event (field_scale_event) */
  $handler->display->display_options['filters']['field_scale_event_tid']['id'] = 'field_scale_event_tid';
  $handler->display->display_options['filters']['field_scale_event_tid']['table'] = 'field_data_field_scale_event';
  $handler->display->display_options['filters']['field_scale_event_tid']['field'] = 'field_scale_event_tid';
  $handler->display->display_options['filters']['field_scale_event_tid']['value'] = array(
    504 => '504',
  );
  $handler->display->display_options['filters']['field_scale_event_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_scale_event_tid']['vocabulary'] = 'scale_event';

  /* Display: scale12x */
  $handler = $view->new_display('page', 'scale12x', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'scale12x/presentation-filter';

  /* Display: scale11x */
  $handler = $view->new_display('page', 'scale11x', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'presentation' => 'presentation',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Topic (field_topic) */
  $handler->display->display_options['filters']['field_topic_tid']['id'] = 'field_topic_tid';
  $handler->display->display_options['filters']['field_topic_tid']['table'] = 'field_data_field_topic';
  $handler->display->display_options['filters']['field_topic_tid']['field'] = 'field_topic_tid';
  $handler->display->display_options['filters']['field_topic_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_topic_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_topic_tid']['expose']['operator_id'] = 'field_topic_tid_op';
  $handler->display->display_options['filters']['field_topic_tid']['expose']['label'] = 'Track';
  $handler->display->display_options['filters']['field_topic_tid']['expose']['operator'] = 'field_topic_tid_op';
  $handler->display->display_options['filters']['field_topic_tid']['expose']['identifier'] = 'field_topic_tid';
  $handler->display->display_options['filters']['field_topic_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_topic_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_topic_tid']['vocabulary'] = 'topic';
  /* Filter criterion: Content: Audience (field_audience) */
  $handler->display->display_options['filters']['field_audience_tid']['id'] = 'field_audience_tid';
  $handler->display->display_options['filters']['field_audience_tid']['table'] = 'field_data_field_audience';
  $handler->display->display_options['filters']['field_audience_tid']['field'] = 'field_audience_tid';
  $handler->display->display_options['filters']['field_audience_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_audience_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_audience_tid']['expose']['operator_id'] = 'field_audience_tid_op';
  $handler->display->display_options['filters']['field_audience_tid']['expose']['label'] = 'Audience';
  $handler->display->display_options['filters']['field_audience_tid']['expose']['operator'] = 'field_audience_tid_op';
  $handler->display->display_options['filters']['field_audience_tid']['expose']['identifier'] = 'field_audience_tid';
  $handler->display->display_options['filters']['field_audience_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_audience_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_audience_tid']['vocabulary'] = 'audience';
  /* Filter criterion: Content: SCALE event (field_scale_event) */
  $handler->display->display_options['filters']['field_scale_event_tid']['id'] = 'field_scale_event_tid';
  $handler->display->display_options['filters']['field_scale_event_tid']['table'] = 'field_data_field_scale_event';
  $handler->display->display_options['filters']['field_scale_event_tid']['field'] = 'field_scale_event_tid';
  $handler->display->display_options['filters']['field_scale_event_tid']['value'] = array(
    503 => '503',
  );
  $handler->display->display_options['filters']['field_scale_event_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_scale_event_tid']['vocabulary'] = 'scale_event';
  $handler->display->display_options['path'] = 'scale12x/presentation-filter';
  $export['presentation_filter'] = $view;

  $view = new view();
  $view->name = 'presentation_page';
  $view->description = 'The public view of a presentation list page';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Presentation List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Presentations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_audience' => 'field_audience',
    'field_topic' => 'field_topic',
  );
  /* Relationship: Content: Speaker (field_speaker) */
  $handler->display->display_options['relationships']['field_speaker_uid']['id'] = 'field_speaker_uid';
  $handler->display->display_options['relationships']['field_speaker_uid']['table'] = 'field_data_field_speaker';
  $handler->display->display_options['relationships']['field_speaker_uid']['field'] = 'field_speaker_uid';
  $handler->display->display_options['relationships']['field_speaker_uid']['delta'] = '0';
  /* Field: User: Photo */
  $handler->display->display_options['fields']['field_speaker_photo']['id'] = 'field_speaker_photo';
  $handler->display->display_options['fields']['field_speaker_photo']['table'] = 'field_data_field_speaker_photo';
  $handler->display->display_options['fields']['field_speaker_photo']['field'] = 'field_speaker_photo';
  $handler->display->display_options['fields']['field_speaker_photo']['relationship'] = 'field_speaker_uid';
  $handler->display->display_options['fields']['field_speaker_photo']['label'] = '';
  $handler->display->display_options['fields']['field_speaker_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_speaker_photo']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_speaker_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_speaker_photo']['settings'] = array(
    'image_style' => 'square_thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Speaker */
  $handler->display->display_options['fields']['field_speaker']['id'] = 'field_speaker';
  $handler->display->display_options['fields']['field_speaker']['table'] = 'field_data_field_speaker';
  $handler->display->display_options['fields']['field_speaker']['field'] = 'field_speaker';
  $handler->display->display_options['fields']['field_speaker']['label'] = '';
  $handler->display->display_options['fields']['field_speaker']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_speaker']['delta_offset'] = '0';
  /* Field: Content: Audience */
  $handler->display->display_options['fields']['field_audience']['id'] = 'field_audience';
  $handler->display->display_options['fields']['field_audience']['table'] = 'field_data_field_audience';
  $handler->display->display_options['fields']['field_audience']['field'] = 'field_audience';
  $handler->display->display_options['fields']['field_audience']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_audience']['element_wrapper_class'] = 'terms';
  $handler->display->display_options['fields']['field_audience']['hide_empty'] = TRUE;
  /* Field: Content: Topic */
  $handler->display->display_options['fields']['field_topic']['id'] = 'field_topic';
  $handler->display->display_options['fields']['field_topic']['table'] = 'field_data_field_topic';
  $handler->display->display_options['fields']['field_topic']['field'] = 'field_topic';
  $handler->display->display_options['fields']['field_topic']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_topic']['element_wrapper_class'] = 'terms';
  $handler->display->display_options['fields']['field_topic']['hide_empty'] = TRUE;
  /* Field: Content: Short abstract */
  $handler->display->display_options['fields']['field_short_abstract']['id'] = 'field_short_abstract';
  $handler->display->display_options['fields']['field_short_abstract']['table'] = 'field_data_field_short_abstract';
  $handler->display->display_options['fields']['field_short_abstract']['field'] = 'field_short_abstract';
  $handler->display->display_options['fields']['field_short_abstract']['label'] = '';
  $handler->display->display_options['fields']['field_short_abstract']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'presentation' => 'presentation',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    6 => '6',
    7 => '7',
    9 => '9',
    4 => '4',
    10 => '10',
    8 => '8',
  );
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Photo */
  $handler->display->display_options['fields']['field_speaker_photo']['id'] = 'field_speaker_photo';
  $handler->display->display_options['fields']['field_speaker_photo']['table'] = 'field_data_field_speaker_photo';
  $handler->display->display_options['fields']['field_speaker_photo']['field'] = 'field_speaker_photo';
  $handler->display->display_options['fields']['field_speaker_photo']['relationship'] = 'field_speaker_uid';
  $handler->display->display_options['fields']['field_speaker_photo']['label'] = '';
  $handler->display->display_options['fields']['field_speaker_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_speaker_photo']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_speaker_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_speaker_photo']['settings'] = array(
    'image_style' => 'square_thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Speaker */
  $handler->display->display_options['fields']['field_speaker']['id'] = 'field_speaker';
  $handler->display->display_options['fields']['field_speaker']['table'] = 'field_data_field_speaker';
  $handler->display->display_options['fields']['field_speaker']['field'] = 'field_speaker';
  $handler->display->display_options['fields']['field_speaker']['label'] = '';
  $handler->display->display_options['fields']['field_speaker']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_speaker']['delta_offset'] = '0';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'field_speaker_uid';
  /* Field: Content: Primary contact email address */
  $handler->display->display_options['fields']['field_primary_email']['id'] = 'field_primary_email';
  $handler->display->display_options['fields']['field_primary_email']['table'] = 'field_data_field_primary_email';
  $handler->display->display_options['fields']['field_primary_email']['field'] = 'field_primary_email';
  /* Field: Content: Audience */
  $handler->display->display_options['fields']['field_audience']['id'] = 'field_audience';
  $handler->display->display_options['fields']['field_audience']['table'] = 'field_data_field_audience';
  $handler->display->display_options['fields']['field_audience']['field'] = 'field_audience';
  $handler->display->display_options['fields']['field_audience']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_audience']['element_wrapper_class'] = 'terms';
  $handler->display->display_options['fields']['field_audience']['hide_empty'] = TRUE;
  /* Field: Content: Topic */
  $handler->display->display_options['fields']['field_topic']['id'] = 'field_topic';
  $handler->display->display_options['fields']['field_topic']['table'] = 'field_data_field_topic';
  $handler->display->display_options['fields']['field_topic']['field'] = 'field_topic';
  $handler->display->display_options['fields']['field_topic']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_topic']['element_wrapper_class'] = 'terms';
  $handler->display->display_options['fields']['field_topic']['hide_empty'] = TRUE;
  /* Field: Content: Short abstract */
  $handler->display->display_options['fields']['field_short_abstract']['id'] = 'field_short_abstract';
  $handler->display->display_options['fields']['field_short_abstract']['table'] = 'field_data_field_short_abstract';
  $handler->display->display_options['fields']['field_short_abstract']['field'] = 'field_short_abstract';
  $handler->display->display_options['fields']['field_short_abstract']['label'] = '';
  $handler->display->display_options['fields']['field_short_abstract']['element_label_colon'] = FALSE;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Accepted';
  $handler->display->display_options['fields']['status']['not'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: scale event */
  $handler->display->display_options['arguments']['field_scale_event_tid']['id'] = 'field_scale_event_tid';
  $handler->display->display_options['arguments']['field_scale_event_tid']['table'] = 'field_data_field_scale_event';
  $handler->display->display_options['arguments']['field_scale_event_tid']['field'] = 'field_scale_event_tid';
  $handler->display->display_options['arguments']['field_scale_event_tid']['ui_name'] = 'scale event';
  $handler->display->display_options['arguments']['field_scale_event_tid']['default_action'] = 'not found';
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
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'presentation' => 'presentation',
  );
  $handler->display->display_options['path'] = 'presentations/%/presentations.csv';

  /* Display: Presentations 11x */
  $handler = $view->new_display('page', 'Presentations 11x', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'scale11x/presentations';

  /* Display: Presentations 12x */
  $handler = $view->new_display('page', 'Presentations 12x', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'scale12x/presentations';
  $export['presentation_page'] = $view;

  $view = new view();
  $view->name = 'presentation_single';
  $view->description = 'A single presentation in a given SCALE event';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Presentation single';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Content: Speaker (field_speaker) */
  $handler->display->display_options['relationships']['field_speaker_uid']['id'] = 'field_speaker_uid';
  $handler->display->display_options['relationships']['field_speaker_uid']['table'] = 'field_data_field_speaker';
  $handler->display->display_options['relationships']['field_speaker_uid']['field'] = 'field_speaker_uid';
  $handler->display->display_options['relationships']['field_speaker_uid']['delta'] = '-1';
  /* Field: User: Photo */
  $handler->display->display_options['fields']['field_speaker_photo']['id'] = 'field_speaker_photo';
  $handler->display->display_options['fields']['field_speaker_photo']['table'] = 'field_data_field_speaker_photo';
  $handler->display->display_options['fields']['field_speaker_photo']['field'] = 'field_speaker_photo';
  $handler->display->display_options['fields']['field_speaker_photo']['relationship'] = 'field_speaker_uid';
  $handler->display->display_options['fields']['field_speaker_photo']['label'] = '';
  $handler->display->display_options['fields']['field_speaker_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_speaker_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_speaker_photo']['settings'] = array(
    'image_style' => 'square_thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Speaker */
  $handler->display->display_options['fields']['field_speaker']['id'] = 'field_speaker';
  $handler->display->display_options['fields']['field_speaker']['table'] = 'field_data_field_speaker';
  $handler->display->display_options['fields']['field_speaker']['field'] = 'field_speaker';
  $handler->display->display_options['fields']['field_speaker']['label'] = '';
  $handler->display->display_options['fields']['field_speaker']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_speaker']['alter']['path'] = '11x/speakers/[field_speaker]';
  $handler->display->display_options['fields']['field_speaker']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['field_speaker']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['field_speaker']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_speaker']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_speaker']['delta_offset'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_speaker]';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = '!1/speakers/[field_speaker]';
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Audience */
  $handler->display->display_options['fields']['field_audience']['id'] = 'field_audience';
  $handler->display->display_options['fields']['field_audience']['table'] = 'field_data_field_audience';
  $handler->display->display_options['fields']['field_audience']['field'] = 'field_audience';
  $handler->display->display_options['fields']['field_audience']['element_class'] = 'terms';
  $handler->display->display_options['fields']['field_audience']['element_label_class'] = 'terms';
  $handler->display->display_options['fields']['field_audience']['hide_empty'] = TRUE;
  /* Field: Content: Topic */
  $handler->display->display_options['fields']['field_topic']['id'] = 'field_topic';
  $handler->display->display_options['fields']['field_topic']['table'] = 'field_data_field_topic';
  $handler->display->display_options['fields']['field_topic']['field'] = 'field_topic';
  $handler->display->display_options['fields']['field_topic']['element_class'] = 'terms';
  $handler->display->display_options['fields']['field_topic']['element_label_class'] = 'terms';
  $handler->display->display_options['fields']['field_topic']['hide_empty'] = TRUE;
  /* Field: Content: Long abstract */
  $handler->display->display_options['fields']['field_long_abstract']['id'] = 'field_long_abstract';
  $handler->display->display_options['fields']['field_long_abstract']['table'] = 'field_data_field_long_abstract';
  $handler->display->display_options['fields']['field_long_abstract']['field'] = 'field_long_abstract';
  $handler->display->display_options['fields']['field_long_abstract']['label'] = '';
  $handler->display->display_options['fields']['field_long_abstract']['element_label_colon'] = FALSE;
  /* Field: Content: Presentation */
  $handler->display->display_options['fields']['field_presentation_to_upload']['id'] = 'field_presentation_to_upload';
  $handler->display->display_options['fields']['field_presentation_to_upload']['table'] = 'field_data_field_presentation_to_upload';
  $handler->display->display_options['fields']['field_presentation_to_upload']['field'] = 'field_presentation_to_upload';
  $handler->display->display_options['fields']['field_presentation_to_upload']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_presentation_to_upload']['click_sort_column'] = 'fid';
  /* Field: Content: Presentation Link */
  $handler->display->display_options['fields']['field_presentation_link']['id'] = 'field_presentation_link';
  $handler->display->display_options['fields']['field_presentation_link']['table'] = 'field_data_field_presentation_link';
  $handler->display->display_options['fields']['field_presentation_link']['field'] = 'field_presentation_link';
  $handler->display->display_options['fields']['field_presentation_link']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_presentation_link']['click_sort_column'] = 'url';
  /* Field: Content: Room */
  $handler->display->display_options['fields']['field_room']['id'] = 'field_room';
  $handler->display->display_options['fields']['field_room']['table'] = 'field_data_field_room';
  $handler->display->display_options['fields']['field_room']['field'] = 'field_room';
  $handler->display->display_options['fields']['field_room']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_room']['delta_offset'] = '0';
  /* Field: Content: Time */
  $handler->display->display_options['fields']['field_time']['id'] = 'field_time';
  $handler->display->display_options['fields']['field_time']['table'] = 'field_data_field_time';
  $handler->display->display_options['fields']['field_time']['field'] = 'field_time';
  $handler->display->display_options['fields']['field_time']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_time']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Audio/Video */
  $handler->display->display_options['fields']['field_audio_video']['id'] = 'field_audio_video';
  $handler->display->display_options['fields']['field_audio_video']['table'] = 'field_data_field_audio_video';
  $handler->display->display_options['fields']['field_audio_video']['field'] = 'field_audio_video';
  $handler->display->display_options['fields']['field_audio_video']['hide_empty'] = TRUE;
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
  /* Contextual filter: Presentation ID */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['ui_name'] = 'Presentation ID';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'presentation' => 'presentation',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['access'] = TRUE;
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
    'presentation' => 'presentation',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['argument_input'] = array(
    'field_scale_event_tid' => array(
      'type' => 'none',
      'context' => 'entity:comment.author',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'scale event',
    ),
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Presentation ID',
    ),
  );
  $export['presentation_single'] = $view;

  $view = new view();
  $view->name = 'presentation_vote_tally';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Presentation Votes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Presentation Votes';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_speaker' => 'field_speaker',
    'value' => 'value',
    'value_1' => 'value_1',
    'value_2' => 'value_2',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_speaker' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'value_2' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Content: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['label'] = 'Vote averages';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => '',
    'tag' => 'vote',
    'function' => 'average',
  );
  /* Relationship: vote count */
  $handler->display->display_options['relationships']['votingapi_cache_1']['id'] = 'votingapi_cache_1';
  $handler->display->display_options['relationships']['votingapi_cache_1']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache_1']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache_1']['ui_name'] = 'vote count';
  $handler->display->display_options['relationships']['votingapi_cache_1']['label'] = 'number of votes';
  $handler->display->display_options['relationships']['votingapi_cache_1']['votingapi'] = array(
    'value_type' => '',
    'tag' => 'vote',
    'function' => 'count',
  );
  /* Relationship: Content: Votes */
  $handler->display->display_options['relationships']['votingapi_vote']['id'] = 'votingapi_vote';
  $handler->display->display_options['relationships']['votingapi_vote']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_vote']['field'] = 'votingapi_vote';
  $handler->display->display_options['relationships']['votingapi_vote']['votingapi'] = array(
    'value_type' => '',
    'tag' => 'vote',
  );
  $handler->display->display_options['relationships']['votingapi_vote']['current_user'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Speaker */
  $handler->display->display_options['fields']['field_speaker']['id'] = 'field_speaker';
  $handler->display->display_options['fields']['field_speaker']['table'] = 'field_data_field_speaker';
  $handler->display->display_options['fields']['field_speaker']['field'] = 'field_speaker';
  $handler->display->display_options['fields']['field_speaker']['delta_offset'] = '0';
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['label'] = 'Rating';
  $handler->display->display_options['fields']['value']['set_precision'] = TRUE;
  $handler->display->display_options['fields']['value']['precision'] = '2';
  /* Field: number of votes */
  $handler->display->display_options['fields']['value_1']['id'] = 'value_1';
  $handler->display->display_options['fields']['value_1']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value_1']['field'] = 'value';
  $handler->display->display_options['fields']['value_1']['relationship'] = 'votingapi_cache_1';
  $handler->display->display_options['fields']['value_1']['ui_name'] = 'number of votes';
  $handler->display->display_options['fields']['value_1']['label'] = 'No. of Votes';
  $handler->display->display_options['fields']['value_1']['precision'] = '0';
  /* Field: My vote */
  $handler->display->display_options['fields']['value_2']['id'] = 'value_2';
  $handler->display->display_options['fields']['value_2']['table'] = 'votingapi_vote';
  $handler->display->display_options['fields']['value_2']['field'] = 'value';
  $handler->display->display_options['fields']['value_2']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['fields']['value_2']['ui_name'] = 'My vote';
  $handler->display->display_options['fields']['value_2']['label'] = 'My Rating';
  $handler->display->display_options['fields']['value_2']['precision'] = '0';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'presentation' => 'presentation',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: SCALE event (field_scale_event) */
  $handler->display->display_options['filters']['field_scale_event_tid']['id'] = 'field_scale_event_tid';
  $handler->display->display_options['filters']['field_scale_event_tid']['table'] = 'field_data_field_scale_event';
  $handler->display->display_options['filters']['field_scale_event_tid']['field'] = 'field_scale_event_tid';
  $handler->display->display_options['filters']['field_scale_event_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_scale_event_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_scale_event_tid']['expose']['operator_id'] = 'field_scale_event_tid_op';
  $handler->display->display_options['filters']['field_scale_event_tid']['expose']['label'] = 'SCALE event';
  $handler->display->display_options['filters']['field_scale_event_tid']['expose']['operator'] = 'field_scale_event_tid_op';
  $handler->display->display_options['filters']['field_scale_event_tid']['expose']['identifier'] = 'field_scale_event_tid';
  $handler->display->display_options['filters']['field_scale_event_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_scale_event_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_scale_event_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_scale_event_tid']['vocabulary'] = 'scale_event';
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['group'] = 1;
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Search Terms';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
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
  /* Filter criterion: Content: Audience (field_audience) */
  $handler->display->display_options['filters']['field_audience_tid']['id'] = 'field_audience_tid';
  $handler->display->display_options['filters']['field_audience_tid']['table'] = 'field_data_field_audience';
  $handler->display->display_options['filters']['field_audience_tid']['field'] = 'field_audience_tid';
  $handler->display->display_options['filters']['field_audience_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_audience_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_audience_tid']['expose']['operator_id'] = 'field_audience_tid_op';
  $handler->display->display_options['filters']['field_audience_tid']['expose']['label'] = 'Audience';
  $handler->display->display_options['filters']['field_audience_tid']['expose']['operator'] = 'field_audience_tid_op';
  $handler->display->display_options['filters']['field_audience_tid']['expose']['identifier'] = 'field_audience_tid';
  $handler->display->display_options['filters']['field_audience_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_audience_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_audience_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_audience_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_audience_tid']['vocabulary'] = 'audience';
  /* Filter criterion: Content: Topic (field_topic) */
  $handler->display->display_options['filters']['field_topic_tid']['id'] = 'field_topic_tid';
  $handler->display->display_options['filters']['field_topic_tid']['table'] = 'field_data_field_topic';
  $handler->display->display_options['filters']['field_topic_tid']['field'] = 'field_topic_tid';
  $handler->display->display_options['filters']['field_topic_tid']['value'] = array(
    6 => '6',
    8 => '8',
    9 => '9',
    10 => '10',
    11 => '11',
    12 => '12',
    13 => '13',
    14 => '14',
    15 => '15',
    16 => '16',
    506 => '506',
    17 => '17',
    18 => '18',
    19 => '19',
    20 => '20',
    21 => '21',
    22 => '22',
    23 => '23',
    24 => '24',
    25 => '25',
  );
  $handler->display->display_options['filters']['field_topic_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_topic_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_topic_tid']['expose']['operator_id'] = 'field_topic_tid_op';
  $handler->display->display_options['filters']['field_topic_tid']['expose']['label'] = 'Topic';
  $handler->display->display_options['filters']['field_topic_tid']['expose']['operator'] = 'field_topic_tid_op';
  $handler->display->display_options['filters']['field_topic_tid']['expose']['identifier'] = 'field_topic_tid';
  $handler->display->display_options['filters']['field_topic_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_topic_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_topic_tid']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_topic_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_topic_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_topic_tid']['vocabulary'] = 'topic';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'presentation-votes';
  $export['presentation_vote_tally'] = $view;

  $view = new view();
  $view->name = 'presentations_all';
  $view->description = 'A list of all presentations for reviewers';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Presentations All';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Presentations All';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'status',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_speaker' => 'field_speaker',
    'realname' => 'realname',
    'status' => 'status',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_speaker' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'realname' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Speaker */
  $handler->display->display_options['fields']['field_speaker']['id'] = 'field_speaker';
  $handler->display->display_options['fields']['field_speaker']['table'] = 'field_data_field_speaker';
  $handler->display->display_options['fields']['field_speaker']['field'] = 'field_speaker';
  $handler->display->display_options['fields']['field_speaker']['delta_offset'] = '0';
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['realname']['label'] = 'Node author';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = '';
  $handler->display->display_options['fields']['status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['status']['type'] = 'published-notpublished';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'presentation' => 'presentation',
  );
  /* Filter criterion: Content: SCALE event (field_scale_event) */
  $handler->display->display_options['filters']['field_scale_event_tid']['id'] = 'field_scale_event_tid';
  $handler->display->display_options['filters']['field_scale_event_tid']['table'] = 'field_data_field_scale_event';
  $handler->display->display_options['filters']['field_scale_event_tid']['field'] = 'field_scale_event_tid';
  $handler->display->display_options['filters']['field_scale_event_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_scale_event_tid']['expose']['operator_id'] = 'field_scale_event_tid_op';
  $handler->display->display_options['filters']['field_scale_event_tid']['expose']['label'] = 'SCALE event';
  $handler->display->display_options['filters']['field_scale_event_tid']['expose']['operator'] = 'field_scale_event_tid_op';
  $handler->display->display_options['filters']['field_scale_event_tid']['expose']['identifier'] = 'field_scale_event_tid';
  $handler->display->display_options['filters']['field_scale_event_tid']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_scale_event_tid']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['filters']['field_scale_event_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_scale_event_tid']['vocabulary'] = 'scale_event';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'presentations-all';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'All presentations';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $export['presentations_all'] = $view;

  return $export;
}
