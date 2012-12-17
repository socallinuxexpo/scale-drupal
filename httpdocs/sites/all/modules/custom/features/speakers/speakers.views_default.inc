<?php
/**
 * @file
 * speakers.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function speakers_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'featured_speakers';
  $view->description = 'Shows featured speakers in block';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Featured Speakers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Featured Speakers';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: featured speaker */
  $handler->display->display_options['relationships']['field_featured_speaker_uid']['id'] = 'field_featured_speaker_uid';
  $handler->display->display_options['relationships']['field_featured_speaker_uid']['table'] = 'field_data_field_featured_speaker';
  $handler->display->display_options['relationships']['field_featured_speaker_uid']['field'] = 'field_featured_speaker_uid';
  $handler->display->display_options['relationships']['field_featured_speaker_uid']['ui_name'] = 'featured speaker';
  $handler->display->display_options['relationships']['field_featured_speaker_uid']['delta'] = '-1';
  /* Relationship: featured speaker content */
  $handler->display->display_options['relationships']['reverse_field_featured_speaker_node']['id'] = 'reverse_field_featured_speaker_node';
  $handler->display->display_options['relationships']['reverse_field_featured_speaker_node']['table'] = 'users';
  $handler->display->display_options['relationships']['reverse_field_featured_speaker_node']['field'] = 'reverse_field_featured_speaker_node';
  $handler->display->display_options['relationships']['reverse_field_featured_speaker_node']['relationship'] = 'field_featured_speaker_uid';
  $handler->display->display_options['relationships']['reverse_field_featured_speaker_node']['ui_name'] = 'featured speaker content';
  /* Field: Content: Speaker */
  $handler->display->display_options['fields']['field_featured_speaker']['id'] = 'field_featured_speaker';
  $handler->display->display_options['fields']['field_featured_speaker']['table'] = 'field_data_field_featured_speaker';
  $handler->display->display_options['fields']['field_featured_speaker']['field'] = 'field_featured_speaker';
  $handler->display->display_options['fields']['field_featured_speaker']['label'] = '';
  $handler->display->display_options['fields']['field_featured_speaker']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_featured_speaker']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_featured_speaker']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_featured_speaker']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_featured_speaker']['multi_type'] = 'ul';
  /* Field: User: Photo */
  $handler->display->display_options['fields']['field_speaker_photo']['id'] = 'field_speaker_photo';
  $handler->display->display_options['fields']['field_speaker_photo']['table'] = 'field_data_field_speaker_photo';
  $handler->display->display_options['fields']['field_speaker_photo']['field'] = 'field_speaker_photo';
  $handler->display->display_options['fields']['field_speaker_photo']['relationship'] = 'field_featured_speaker_uid';
  $handler->display->display_options['fields']['field_speaker_photo']['label'] = '';
  $handler->display->display_options['fields']['field_speaker_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_speaker_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_speaker_photo']['settings'] = array(
    'image_style' => 'square_thumbnail',
    'image_link' => '',
  );
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'field_featured_speaker_uid';
  $handler->display->display_options['fields']['realname']['label'] = '';
  $handler->display->display_options['fields']['realname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['realname']['link_to_user'] = FALSE;
  /* Field: User: Organization */
  $handler->display->display_options['fields']['field_organization']['id'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['table'] = 'field_data_field_organization';
  $handler->display->display_options['fields']['field_organization']['field'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['relationship'] = 'field_featured_speaker_uid';
  $handler->display->display_options['fields']['field_organization']['label'] = '';
  $handler->display->display_options['fields']['field_organization']['element_label_colon'] = FALSE;
  /* Field: User: Job title */
  $handler->display->display_options['fields']['field_job_title']['id'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['table'] = 'field_data_field_job_title';
  $handler->display->display_options['fields']['field_job_title']['field'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['relationship'] = 'field_featured_speaker_uid';
  $handler->display->display_options['fields']['field_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_job_title']['element_label_colon'] = FALSE;
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
    'featured_speakers' => 'featured_speakers',
  );
  /* Filter criterion: Content: Sticky */
  $handler->display->display_options['filters']['sticky']['id'] = 'sticky';
  $handler->display->display_options['filters']['sticky']['table'] = 'node';
  $handler->display->display_options['filters']['sticky']['field'] = 'sticky';
  $handler->display->display_options['filters']['sticky']['value'] = '1';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['block_description'] = 'Featured Speakers';
  $export['featured_speakers'] = $view;

  return $export;
}
