<?php

/**
 * @file
 * migration.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function migration_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'migration_blog';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Migration - Blog';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['top_child_object'] = '';
  $handler->display->display_options['style_options']['plaintext_output'] = 0;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['translate_labels'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'path';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'U';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Published status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'published';
  $handler->display->display_options['fields']['status']['type'] = 'boolean';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'body';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_blog_image']['id'] = 'field_blog_image';
  $handler->display->display_options['fields']['field_blog_image']['table'] = 'field_data_field_blog_image';
  $handler->display->display_options['fields']['field_blog_image']['field'] = 'field_blog_image';
  $handler->display->display_options['fields']['field_blog_image']['label'] = 'image';
  $handler->display->display_options['fields']['field_blog_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_blog_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Ready for approval */
  $handler->display->display_options['fields']['field_ready_for_approval']['id'] = 'field_ready_for_approval';
  $handler->display->display_options['fields']['field_ready_for_approval']['table'] = 'field_data_field_ready_for_approval';
  $handler->display->display_options['fields']['field_ready_for_approval']['field'] = 'field_ready_for_approval';
  $handler->display->display_options['fields']['field_ready_for_approval']['label'] = 'ready_for_approval';
  /* Field: Content: Tags */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['label'] = 'tags';
  $handler->display->display_options['fields']['field_tags']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body_1']['id'] = 'body_1';
  $handler->display->display_options['fields']['body_1']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_1']['field'] = 'body';
  $handler->display->display_options['fields']['body_1']['label'] = 'body_summary';
  $handler->display->display_options['fields']['body_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body_1']['alter']['text'] = '[body_1-summary]';
  $handler->display->display_options['fields']['body_1']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body_1']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: SCALE event */
  $handler->display->display_options['fields']['field_scale_event']['id'] = 'field_scale_event';
  $handler->display->display_options['fields']['field_scale_event']['table'] = 'field_data_field_scale_event';
  $handler->display->display_options['fields']['field_scale_event']['field'] = 'field_scale_event';
  $handler->display->display_options['fields']['field_scale_event']['label'] = 'scale_event';
  $handler->display->display_options['fields']['field_scale_event']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_scale_event']['delta_offset'] = '0';
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
    'blog' => 'blog',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'migrate/type/blog/json/test';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['path'] = 'migrate/type/blog/json/all';
  $export['migration_blog'] = $view;

  $view = new view();
  $view->name = 'migration_presentation';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Migration - Presentation';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['top_child_object'] = '';
  $handler->display->display_options['style_options']['plaintext_output'] = 0;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['translate_labels'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  /* Field: Content: appropriate for */
  $handler->display->display_options['fields']['field_appropriate_for']['id'] = 'field_appropriate_for';
  $handler->display->display_options['fields']['field_appropriate_for']['table'] = 'field_data_field_appropriate_for';
  $handler->display->display_options['fields']['field_appropriate_for']['field'] = 'field_appropriate_for';
  $handler->display->display_options['fields']['field_appropriate_for']['label'] = 'rating';
  /* Field: Content: Audience */
  $handler->display->display_options['fields']['field_audience']['id'] = 'field_audience';
  $handler->display->display_options['fields']['field_audience']['table'] = 'field_data_field_audience';
  $handler->display->display_options['fields']['field_audience']['field'] = 'field_audience';
  $handler->display->display_options['fields']['field_audience']['label'] = 'audience';
  $handler->display->display_options['fields']['field_audience']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Tags */
  $handler->display->display_options['fields']['field_presentation_tags']['id'] = 'field_presentation_tags';
  $handler->display->display_options['fields']['field_presentation_tags']['table'] = 'field_data_field_presentation_tags';
  $handler->display->display_options['fields']['field_presentation_tags']['field'] = 'field_presentation_tags';
  $handler->display->display_options['fields']['field_presentation_tags']['label'] = 'tags';
  $handler->display->display_options['fields']['field_presentation_tags']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_presentation_tags']['delta_offset'] = '0';
  /* Field: Content: Topic */
  $handler->display->display_options['fields']['field_topic']['id'] = 'field_topic';
  $handler->display->display_options['fields']['field_topic']['table'] = 'field_data_field_topic';
  $handler->display->display_options['fields']['field_topic']['field'] = 'field_topic';
  $handler->display->display_options['fields']['field_topic']['label'] = 'topic';
  $handler->display->display_options['fields']['field_topic']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'path';
  /* Field: Content: Brief description */
  $handler->display->display_options['fields']['field_brief_description']['id'] = 'field_brief_description';
  $handler->display->display_options['fields']['field_brief_description']['table'] = 'field_data_field_brief_description';
  $handler->display->display_options['fields']['field_brief_description']['field'] = 'field_brief_description';
  $handler->display->display_options['fields']['field_brief_description']['label'] = 'description';
  /* Field: Content: Long abstract */
  $handler->display->display_options['fields']['field_long_abstract']['id'] = 'field_long_abstract';
  $handler->display->display_options['fields']['field_long_abstract']['table'] = 'field_data_field_long_abstract';
  $handler->display->display_options['fields']['field_long_abstract']['field'] = 'field_long_abstract';
  $handler->display->display_options['fields']['field_long_abstract']['label'] = 'long_abstract';
  /* Field: Content: Short abstract */
  $handler->display->display_options['fields']['field_short_abstract']['id'] = 'field_short_abstract';
  $handler->display->display_options['fields']['field_short_abstract']['table'] = 'field_data_field_short_abstract';
  $handler->display->display_options['fields']['field_short_abstract']['field'] = 'field_short_abstract';
  $handler->display->display_options['fields']['field_short_abstract']['label'] = 'short_abstract';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'U';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Published status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'published';
  $handler->display->display_options['fields']['status']['type'] = 'boolean';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Message to the reviewers */
  $handler->display->display_options['fields']['field_message_to_reviewers']['id'] = 'field_message_to_reviewers';
  $handler->display->display_options['fields']['field_message_to_reviewers']['table'] = 'field_data_field_message_to_reviewers';
  $handler->display->display_options['fields']['field_message_to_reviewers']['field'] = 'field_message_to_reviewers';
  $handler->display->display_options['fields']['field_message_to_reviewers']['label'] = 'moderation_message';
  /* Field: Content: Presentation Link */
  $handler->display->display_options['fields']['field_presentation_link']['id'] = 'field_presentation_link';
  $handler->display->display_options['fields']['field_presentation_link']['table'] = 'field_data_field_presentation_link';
  $handler->display->display_options['fields']['field_presentation_link']['field'] = 'field_presentation_link';
  $handler->display->display_options['fields']['field_presentation_link']['label'] = 'link_to_prezi__title';
  $handler->display->display_options['fields']['field_presentation_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_presentation_link']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_presentation_link']['settings'] = array(
    'custom_title' => '',
  );
  /* Field: Content: Presentation Link */
  $handler->display->display_options['fields']['field_presentation_link_1']['id'] = 'field_presentation_link_1';
  $handler->display->display_options['fields']['field_presentation_link_1']['table'] = 'field_data_field_presentation_link';
  $handler->display->display_options['fields']['field_presentation_link_1']['field'] = 'field_presentation_link';
  $handler->display->display_options['fields']['field_presentation_link_1']['label'] = 'link_to_prezi__url';
  $handler->display->display_options['fields']['field_presentation_link_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_presentation_link_1']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_presentation_link_1']['settings'] = array(
    'custom_title' => '',
  );
  /* Field: Content: Audio/Video */
  $handler->display->display_options['fields']['field_audio_video']['id'] = 'field_audio_video';
  $handler->display->display_options['fields']['field_audio_video']['table'] = 'field_data_field_audio_video';
  $handler->display->display_options['fields']['field_audio_video']['field'] = 'field_audio_video';
  $handler->display->display_options['fields']['field_audio_video']['label'] = 'audio_video';
  /* Field: Content: Primary contact email address */
  $handler->display->display_options['fields']['field_primary_email']['id'] = 'field_primary_email';
  $handler->display->display_options['fields']['field_primary_email']['table'] = 'field_data_field_primary_email';
  $handler->display->display_options['fields']['field_primary_email']['field'] = 'field_primary_email';
  $handler->display->display_options['fields']['field_primary_email']['label'] = 'primary_contact';
  /* Field: Content: Overflow room */
  $handler->display->display_options['fields']['field_overflow_room']['id'] = 'field_overflow_room';
  $handler->display->display_options['fields']['field_overflow_room']['table'] = 'field_data_field_overflow_room';
  $handler->display->display_options['fields']['field_overflow_room']['field'] = 'field_overflow_room';
  $handler->display->display_options['fields']['field_overflow_room']['label'] = 'room_overflow';
  $handler->display->display_options['fields']['field_overflow_room']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_overflow_room']['delta_offset'] = '0';
  /* Field: Content: Room */
  $handler->display->display_options['fields']['field_room']['id'] = 'field_room';
  $handler->display->display_options['fields']['field_room']['table'] = 'field_data_field_room';
  $handler->display->display_options['fields']['field_room']['field'] = 'field_room';
  $handler->display->display_options['fields']['field_room']['label'] = 'room';
  $handler->display->display_options['fields']['field_room']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_room']['delta_offset'] = '0';
  /* Field: Content: SCALE event */
  $handler->display->display_options['fields']['field_scale_event']['id'] = 'field_scale_event';
  $handler->display->display_options['fields']['field_scale_event']['table'] = 'field_data_field_scale_event';
  $handler->display->display_options['fields']['field_scale_event']['field'] = 'field_scale_event';
  $handler->display->display_options['fields']['field_scale_event']['label'] = 'scale_event';
  $handler->display->display_options['fields']['field_scale_event']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_scale_event']['delta_offset'] = '0';
  /* Field: Content: Speakers */
  $handler->display->display_options['fields']['field_speaker']['id'] = 'field_speaker';
  $handler->display->display_options['fields']['field_speaker']['table'] = 'field_data_field_speaker';
  $handler->display->display_options['fields']['field_speaker']['field'] = 'field_speaker';
  $handler->display->display_options['fields']['field_speaker']['label'] = 'speakers';
  $handler->display->display_options['fields']['field_speaker']['type'] = 'user_reference_plain';
  $handler->display->display_options['fields']['field_speaker']['delta_offset'] = '0';
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'migrate/type/presentation/json/test';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['path'] = 'migrate/type/presentation/json/all';
  $export['migration_presentation'] = $view;

  $view = new view();
  $view->name = 'migration_room';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Migration - Room';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Migration - SCaLE Event';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['top_child_object'] = '';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['translate_labels'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = 'tid';
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'room' => 'room',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'migrate/tax/room/json/all';
  $export['migration_room'] = $view;

  $view = new view();
  $view->name = 'migration_scale_event';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Migration - SCaLE Event';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Migration - SCaLE Event';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['top_child_object'] = '';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['translate_labels'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = 'tid';
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'scale_event' => 'scale_event',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'migrate/tax/event/json/all';
  $export['migration_scale_event'] = $view;

  $view = new view();
  $view->name = 'migration_speakers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Migration - Speakers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['top_child_object'] = '';
  $handler->display->display_options['style_options']['plaintext_output'] = 0;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['translate_labels'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  /* Relationship: User: Speakers (field_speaker) - reverse */
  $handler->display->display_options['relationships']['reverse_field_speaker_node']['id'] = 'reverse_field_speaker_node';
  $handler->display->display_options['relationships']['reverse_field_speaker_node']['table'] = 'users';
  $handler->display->display_options['relationships']['reverse_field_speaker_node']['field'] = 'reverse_field_speaker_node';
  $handler->display->display_options['relationships']['reverse_field_speaker_node']['required'] = TRUE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'uid';
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = 'email';
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = 'first_name';
  /* Field: User: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = 'last_name';
  /* Field: User: Biography */
  $handler->display->display_options['fields']['field_biography']['id'] = 'field_biography';
  $handler->display->display_options['fields']['field_biography']['table'] = 'field_data_field_biography';
  $handler->display->display_options['fields']['field_biography']['field'] = 'field_biography';
  $handler->display->display_options['fields']['field_biography']['label'] = 'bio';
  /* Field: User: Age */
  $handler->display->display_options['fields']['field_age']['id'] = 'field_age';
  $handler->display->display_options['fields']['field_age']['table'] = 'field_data_field_age';
  $handler->display->display_options['fields']['field_age']['field'] = 'field_age';
  $handler->display->display_options['fields']['field_age']['label'] = 'age';
  $handler->display->display_options['fields']['field_age']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_age']['alter']['text'] = '[field_age-value]';
  /* Field: User: Education */
  $handler->display->display_options['fields']['field_education']['id'] = 'field_education';
  $handler->display->display_options['fields']['field_education']['table'] = 'field_data_field_education';
  $handler->display->display_options['fields']['field_education']['field'] = 'field_education';
  $handler->display->display_options['fields']['field_education']['label'] = 'education';
  /* Field: User: Employment Status */
  $handler->display->display_options['fields']['field_employment_status']['id'] = 'field_employment_status';
  $handler->display->display_options['fields']['field_employment_status']['table'] = 'field_data_field_employment_status';
  $handler->display->display_options['fields']['field_employment_status']['field'] = 'field_employment_status';
  $handler->display->display_options['fields']['field_employment_status']['label'] = 'employment';
  /* Field: User: Ethnicity */
  $handler->display->display_options['fields']['field_ethnicity']['id'] = 'field_ethnicity';
  $handler->display->display_options['fields']['field_ethnicity']['table'] = 'field_data_field_ethnicity';
  $handler->display->display_options['fields']['field_ethnicity']['field'] = 'field_ethnicity';
  $handler->display->display_options['fields']['field_ethnicity']['label'] = 'ethnicity';
  /* Field: User: Gender */
  $handler->display->display_options['fields']['field_gender']['id'] = 'field_gender';
  $handler->display->display_options['fields']['field_gender']['table'] = 'field_data_field_gender';
  $handler->display->display_options['fields']['field_gender']['field'] = 'field_gender';
  $handler->display->display_options['fields']['field_gender']['label'] = 'gender';
  /* Field: User: Household Income */
  $handler->display->display_options['fields']['field_household_income']['id'] = 'field_household_income';
  $handler->display->display_options['fields']['field_household_income']['table'] = 'field_data_field_household_income';
  $handler->display->display_options['fields']['field_household_income']['field'] = 'field_household_income';
  $handler->display->display_options['fields']['field_household_income']['label'] = 'household_income';
  /* Field: User: I would like to be a speaker and... */
  $handler->display->display_options['fields']['field_is_speaker']['id'] = 'field_is_speaker';
  $handler->display->display_options['fields']['field_is_speaker']['table'] = 'field_data_field_is_speaker';
  $handler->display->display_options['fields']['field_is_speaker']['field'] = 'field_is_speaker';
  $handler->display->display_options['fields']['field_is_speaker']['label'] = 'is_speaker';
  /* Field: User: Job title */
  $handler->display->display_options['fields']['field_job_title']['id'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['table'] = 'field_data_field_job_title';
  $handler->display->display_options['fields']['field_job_title']['field'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['label'] = 'job_title';
  /* Field: User: Marital Status */
  $handler->display->display_options['fields']['field_marital_status']['id'] = 'field_marital_status';
  $handler->display->display_options['fields']['field_marital_status']['table'] = 'field_data_field_marital_status';
  $handler->display->display_options['fields']['field_marital_status']['field'] = 'field_marital_status';
  $handler->display->display_options['fields']['field_marital_status']['label'] = 'marital_status';
  /* Field: User: Organization */
  $handler->display->display_options['fields']['field_organization']['id'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['table'] = 'field_data_field_organization';
  $handler->display->display_options['fields']['field_organization']['field'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['label'] = 'organization';
  /* Field: User: Phone */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['label'] = 'phone';
  /* Field: User: Photo */
  $handler->display->display_options['fields']['field_speaker_photo']['id'] = 'field_speaker_photo';
  $handler->display->display_options['fields']['field_speaker_photo']['table'] = 'field_data_field_speaker_photo';
  $handler->display->display_options['fields']['field_speaker_photo']['field'] = 'field_speaker_photo';
  $handler->display->display_options['fields']['field_speaker_photo']['label'] = 'photo';
  $handler->display->display_options['fields']['field_speaker_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_speaker_photo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: User: Postal code */
  $handler->display->display_options['fields']['field_postal_code']['id'] = 'field_postal_code';
  $handler->display->display_options['fields']['field_postal_code']['table'] = 'field_data_field_postal_code';
  $handler->display->display_options['fields']['field_postal_code']['field'] = 'field_postal_code';
  $handler->display->display_options['fields']['field_postal_code']['label'] = 'postal_code';
  /* Field: User: Twitter URL */
  $handler->display->display_options['fields']['field_twitter_url']['id'] = 'field_twitter_url';
  $handler->display->display_options['fields']['field_twitter_url']['table'] = 'field_data_field_twitter_url';
  $handler->display->display_options['fields']['field_twitter_url']['field'] = 'field_twitter_url';
  $handler->display->display_options['fields']['field_twitter_url']['label'] = 'twitter';
  $handler->display->display_options['fields']['field_twitter_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_twitter_url']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_twitter_url']['settings'] = array(
    'custom_title' => '',
  );
  /* Field: User: Website */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['label'] = 'website';
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_website']['settings'] = array(
    'custom_title' => '',
  );
  /* Field: User: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'U';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'migrate/user/speaker/json/test';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3000';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['path'] = 'migrate/user/speaker/json/all';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3000';
  $handler->display->display_options['pager']['options']['offset'] = '3000';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['path'] = 'migrate/user/speaker/json/2';
  $export['migration_speakers'] = $view;

  $view = new view();
  $view->name = 'migration_sponsor';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Migration - Sponsor';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['top_child_object'] = '';
  $handler->display->display_options['style_options']['plaintext_output'] = 0;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['translate_labels'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'path';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'U';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Published status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'published';
  $handler->display->display_options['fields']['status']['type'] = 'boolean';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'body';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body_1']['id'] = 'body_1';
  $handler->display->display_options['fields']['body_1']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_1']['field'] = 'body';
  $handler->display->display_options['fields']['body_1']['label'] = 'body_summary';
  $handler->display->display_options['fields']['body_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body_1']['alter']['text'] = '[body_1-summary]';
  $handler->display->display_options['fields']['body_1']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Logo (website) */
  $handler->display->display_options['fields']['field_logo_website']['id'] = 'field_logo_website';
  $handler->display->display_options['fields']['field_logo_website']['table'] = 'field_data_field_logo_website';
  $handler->display->display_options['fields']['field_logo_website']['field'] = 'field_logo_website';
  $handler->display->display_options['fields']['field_logo_website']['label'] = 'logo';
  $handler->display->display_options['fields']['field_logo_website']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo_website']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_sponsor_website']['id'] = 'field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['table'] = 'field_data_field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['field'] = 'field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['label'] = 'website_url';
  $handler->display->display_options['fields']['field_sponsor_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_sponsor_website']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_sponsor_website']['settings'] = array(
    'custom_title' => '',
  );
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_sponsor_website_1']['id'] = 'field_sponsor_website_1';
  $handler->display->display_options['fields']['field_sponsor_website_1']['table'] = 'field_data_field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website_1']['field'] = 'field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website_1']['label'] = 'website_title';
  $handler->display->display_options['fields']['field_sponsor_website_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_sponsor_website_1']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_sponsor_website_1']['settings'] = array(
    'custom_title' => '',
  );
  /* Field: Content: Exhibitor Type */
  $handler->display->display_options['fields']['field_exhibitor_type']['id'] = 'field_exhibitor_type';
  $handler->display->display_options['fields']['field_exhibitor_type']['table'] = 'field_data_field_exhibitor_type';
  $handler->display->display_options['fields']['field_exhibitor_type']['field'] = 'field_exhibitor_type';
  $handler->display->display_options['fields']['field_exhibitor_type']['label'] = 'exhibitor_type';
  /* Field: Content: Exhibitor, Sponsor */
  $handler->display->display_options['fields']['field_exhibitor_sponsor']['id'] = 'field_exhibitor_sponsor';
  $handler->display->display_options['fields']['field_exhibitor_sponsor']['table'] = 'field_data_field_exhibitor_sponsor';
  $handler->display->display_options['fields']['field_exhibitor_sponsor']['field'] = 'field_exhibitor_sponsor';
  $handler->display->display_options['fields']['field_exhibitor_sponsor']['label'] = 'sponsor_type';
  $handler->display->display_options['fields']['field_exhibitor_sponsor']['delta_offset'] = '0';
  /* Field: Content: Sponsor Type */
  $handler->display->display_options['fields']['field_sponsor_type']['id'] = 'field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['field'] = 'field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['label'] = 'sponsor_tier';
  $handler->display->display_options['fields']['field_sponsor_type']['delta_offset'] = '0';
  /* Field: Content: Booth Number */
  $handler->display->display_options['fields']['field_booth_number']['id'] = 'field_booth_number';
  $handler->display->display_options['fields']['field_booth_number']['table'] = 'field_data_field_booth_number';
  $handler->display->display_options['fields']['field_booth_number']['field'] = 'field_booth_number';
  $handler->display->display_options['fields']['field_booth_number']['label'] = 'booth';
  /* Field: Content: Ready for approval */
  $handler->display->display_options['fields']['field_ready_for_approval']['id'] = 'field_ready_for_approval';
  $handler->display->display_options['fields']['field_ready_for_approval']['table'] = 'field_data_field_ready_for_approval';
  $handler->display->display_options['fields']['field_ready_for_approval']['field'] = 'field_ready_for_approval';
  $handler->display->display_options['fields']['field_ready_for_approval']['label'] = 'ready_for_approval';
  $handler->display->display_options['fields']['field_ready_for_approval']['type'] = 'list_key';
  /* Field: Content: SCALE event */
  $handler->display->display_options['fields']['field_scale_event']['id'] = 'field_scale_event';
  $handler->display->display_options['fields']['field_scale_event']['table'] = 'field_data_field_scale_event';
  $handler->display->display_options['fields']['field_scale_event']['field'] = 'field_scale_event';
  $handler->display->display_options['fields']['field_scale_event']['label'] = 'scale_event';
  $handler->display->display_options['fields']['field_scale_event']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_scale_event']['delta_offset'] = '0';
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
    'sponsor' => 'sponsor',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'migrate/type/sponsor/json/test';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['path'] = 'migrate/type/sponsor/json/all';
  $export['migration_sponsor'] = $view;

  $view = new view();
  $view->name = 'migration_users';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Migration - Users';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['top_child_object'] = '';
  $handler->display->display_options['style_options']['plaintext_output'] = 0;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['translate_labels'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'uid';
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = 'email';
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = 'first_name';
  /* Field: User: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = 'last_name';
  /* Field: User: Biography */
  $handler->display->display_options['fields']['field_biography']['id'] = 'field_biography';
  $handler->display->display_options['fields']['field_biography']['table'] = 'field_data_field_biography';
  $handler->display->display_options['fields']['field_biography']['field'] = 'field_biography';
  $handler->display->display_options['fields']['field_biography']['label'] = 'bio';
  /* Field: User: Education */
  $handler->display->display_options['fields']['field_education']['id'] = 'field_education';
  $handler->display->display_options['fields']['field_education']['table'] = 'field_data_field_education';
  $handler->display->display_options['fields']['field_education']['field'] = 'field_education';
  $handler->display->display_options['fields']['field_education']['label'] = 'education';
  /* Field: User: Employment Status */
  $handler->display->display_options['fields']['field_employment_status']['id'] = 'field_employment_status';
  $handler->display->display_options['fields']['field_employment_status']['table'] = 'field_data_field_employment_status';
  $handler->display->display_options['fields']['field_employment_status']['field'] = 'field_employment_status';
  $handler->display->display_options['fields']['field_employment_status']['label'] = 'employment';
  /* Field: User: Ethnicity */
  $handler->display->display_options['fields']['field_ethnicity']['id'] = 'field_ethnicity';
  $handler->display->display_options['fields']['field_ethnicity']['table'] = 'field_data_field_ethnicity';
  $handler->display->display_options['fields']['field_ethnicity']['field'] = 'field_ethnicity';
  $handler->display->display_options['fields']['field_ethnicity']['label'] = 'ethnicity';
  /* Field: User: Gender */
  $handler->display->display_options['fields']['field_gender']['id'] = 'field_gender';
  $handler->display->display_options['fields']['field_gender']['table'] = 'field_data_field_gender';
  $handler->display->display_options['fields']['field_gender']['field'] = 'field_gender';
  $handler->display->display_options['fields']['field_gender']['label'] = 'gender';
  /* Field: User: Household Income */
  $handler->display->display_options['fields']['field_household_income']['id'] = 'field_household_income';
  $handler->display->display_options['fields']['field_household_income']['table'] = 'field_data_field_household_income';
  $handler->display->display_options['fields']['field_household_income']['field'] = 'field_household_income';
  $handler->display->display_options['fields']['field_household_income']['label'] = 'household_income';
  /* Field: User: I would like to be a speaker and... */
  $handler->display->display_options['fields']['field_is_speaker']['id'] = 'field_is_speaker';
  $handler->display->display_options['fields']['field_is_speaker']['table'] = 'field_data_field_is_speaker';
  $handler->display->display_options['fields']['field_is_speaker']['field'] = 'field_is_speaker';
  $handler->display->display_options['fields']['field_is_speaker']['label'] = 'is_speaker';
  /* Field: User: Job title */
  $handler->display->display_options['fields']['field_job_title']['id'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['table'] = 'field_data_field_job_title';
  $handler->display->display_options['fields']['field_job_title']['field'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['label'] = 'job_title';
  /* Field: User: Marital Status */
  $handler->display->display_options['fields']['field_marital_status']['id'] = 'field_marital_status';
  $handler->display->display_options['fields']['field_marital_status']['table'] = 'field_data_field_marital_status';
  $handler->display->display_options['fields']['field_marital_status']['field'] = 'field_marital_status';
  $handler->display->display_options['fields']['field_marital_status']['label'] = 'marital_status';
  /* Field: User: Organization */
  $handler->display->display_options['fields']['field_organization']['id'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['table'] = 'field_data_field_organization';
  $handler->display->display_options['fields']['field_organization']['field'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['label'] = 'organization';
  /* Field: User: Phone */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['label'] = 'phone';
  /* Field: User: Photo */
  $handler->display->display_options['fields']['field_speaker_photo']['id'] = 'field_speaker_photo';
  $handler->display->display_options['fields']['field_speaker_photo']['table'] = 'field_data_field_speaker_photo';
  $handler->display->display_options['fields']['field_speaker_photo']['field'] = 'field_speaker_photo';
  $handler->display->display_options['fields']['field_speaker_photo']['label'] = 'photo';
  $handler->display->display_options['fields']['field_speaker_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_speaker_photo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: User: Postal code */
  $handler->display->display_options['fields']['field_postal_code']['id'] = 'field_postal_code';
  $handler->display->display_options['fields']['field_postal_code']['table'] = 'field_data_field_postal_code';
  $handler->display->display_options['fields']['field_postal_code']['field'] = 'field_postal_code';
  $handler->display->display_options['fields']['field_postal_code']['label'] = 'postal_code';
  /* Field: User: Twitter URL */
  $handler->display->display_options['fields']['field_twitter_url']['id'] = 'field_twitter_url';
  $handler->display->display_options['fields']['field_twitter_url']['table'] = 'field_data_field_twitter_url';
  $handler->display->display_options['fields']['field_twitter_url']['field'] = 'field_twitter_url';
  $handler->display->display_options['fields']['field_twitter_url']['label'] = 'twitter';
  $handler->display->display_options['fields']['field_twitter_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_twitter_url']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_twitter_url']['settings'] = array(
    'custom_title' => '',
  );
  /* Field: User: Website */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['label'] = 'website';
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_website']['settings'] = array(
    'custom_title' => '',
  );
  /* Field: User: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'U';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: User: Age */
  $handler->display->display_options['fields']['field_age']['id'] = 'field_age';
  $handler->display->display_options['fields']['field_age']['table'] = 'field_data_field_age';
  $handler->display->display_options['fields']['field_age']['field'] = 'field_age';
  $handler->display->display_options['fields']['field_age']['label'] = 'age';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'migrate/user/json/test';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['path'] = 'migrate/user/json/all';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['path'] = 'migrate/user/json/2';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_3');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['path'] = 'migrate/user/json/3';
  $export['migration_users'] = $view;

  $view = new view();
  $view->name = 'migration_vendor';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Migration - Vendor';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['top_child_object'] = '';
  $handler->display->display_options['style_options']['plaintext_output'] = 0;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['translate_labels'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'path';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'U';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Published status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'published';
  $handler->display->display_options['fields']['status']['type'] = 'boolean';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'body';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body_1']['id'] = 'body_1';
  $handler->display->display_options['fields']['body_1']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_1']['field'] = 'body';
  $handler->display->display_options['fields']['body_1']['label'] = 'body_summary';
  $handler->display->display_options['fields']['body_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body_1']['alter']['text'] = '[body_1-summary]';
  $handler->display->display_options['fields']['body_1']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Logo (website) */
  $handler->display->display_options['fields']['field_logo_website']['id'] = 'field_logo_website';
  $handler->display->display_options['fields']['field_logo_website']['table'] = 'field_data_field_logo_website';
  $handler->display->display_options['fields']['field_logo_website']['field'] = 'field_logo_website';
  $handler->display->display_options['fields']['field_logo_website']['label'] = 'logo';
  $handler->display->display_options['fields']['field_logo_website']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo_website']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_sponsor_website']['id'] = 'field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['table'] = 'field_data_field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['field'] = 'field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['label'] = 'website_url';
  $handler->display->display_options['fields']['field_sponsor_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_sponsor_website']['type'] = 'link_plain';
  $handler->display->display_options['fields']['field_sponsor_website']['settings'] = array(
    'custom_title' => '',
  );
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_sponsor_website_1']['id'] = 'field_sponsor_website_1';
  $handler->display->display_options['fields']['field_sponsor_website_1']['table'] = 'field_data_field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website_1']['field'] = 'field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website_1']['label'] = 'website_title';
  $handler->display->display_options['fields']['field_sponsor_website_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_sponsor_website_1']['type'] = 'link_title_plain';
  $handler->display->display_options['fields']['field_sponsor_website_1']['settings'] = array(
    'custom_title' => '',
  );
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
    'sponsor' => 'sponsor',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'migrate/type/vendor/json/test';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['path'] = 'migrate/type/vendor/json/all';
  $export['migration_vendor'] = $view;

  return $export;
}
