<?php
/**
 * @file
 * scale_promo.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function scale_promo_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'promo_items_multi_year';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Promo Items multi-year';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Promo Items';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3 class="title">Buttons</h3>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Promo file */
  $handler->display->display_options['fields']['field_promo_file']['id'] = 'field_promo_file';
  $handler->display->display_options['fields']['field_promo_file']['table'] = 'field_data_field_promo_file';
  $handler->display->display_options['fields']['field_promo_file']['field'] = 'field_promo_file';
  $handler->display->display_options['fields']['field_promo_file']['label'] = '';
  $handler->display->display_options['fields']['field_promo_file']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_promo_file']['alter']['text'] = '<div class="promo-item-image"><img src="[field_promo_file]"></div>';
  $handler->display->display_options['fields']['field_promo_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_promo_file']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_promo_file']['settings'] = array(
    'file_view_mode' => 'media_link',
  );
  /* Field: Content: Specifications */
  $handler->display->display_options['fields']['field_specificatins']['id'] = 'field_specificatins';
  $handler->display->display_options['fields']['field_specificatins']['table'] = 'field_data_field_specificatins';
  $handler->display->display_options['fields']['field_specificatins']['field'] = 'field_specificatins';
  /* Field: Content: Embed code */
  $handler->display->display_options['fields']['field_embed_code']['id'] = 'field_embed_code';
  $handler->display->display_options['fields']['field_embed_code']['table'] = 'field_data_field_embed_code';
  $handler->display->display_options['fields']['field_embed_code']['field'] = 'field_embed_code';
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
  $handler->display->display_options['arguments']['field_scale_event_tid']['validate']['fail'] = 'access denied';
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
    'promo_item' => 'promo_item',
  );
  /* Filter criterion: Content: Item type (field_item_type) */
  $handler->display->display_options['filters']['field_item_type_value']['id'] = 'field_item_type_value';
  $handler->display->display_options['filters']['field_item_type_value']['table'] = 'field_data_field_item_type';
  $handler->display->display_options['filters']['field_item_type_value']['field'] = 'field_item_type_value';
  $handler->display->display_options['filters']['field_item_type_value']['value'] = array(
    'buttons' => 'buttons',
  );

  /* Display: buttons */
  $handler = $view->new_display('page', 'buttons', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'scale/%/promo-items';

  /* Display: banners */
  $handler = $view->new_display('attachment', 'banners', 'attachment_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3 class="title">Banners</h3>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
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
    'promo_item' => 'promo_item',
  );
  /* Filter criterion: Content: Item type (field_item_type) */
  $handler->display->display_options['filters']['field_item_type_value']['id'] = 'field_item_type_value';
  $handler->display->display_options['filters']['field_item_type_value']['table'] = 'field_data_field_item_type';
  $handler->display->display_options['filters']['field_item_type_value']['field'] = 'field_item_type_value';
  $handler->display->display_options['filters']['field_item_type_value']['value'] = array(
    'banners' => 'banners',
  );
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: audio */
  $handler = $view->new_display('attachment', 'audio', 'attachment_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3 class="title">Audio</h3>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Promo file */
  $handler->display->display_options['fields']['field_promo_file']['id'] = 'field_promo_file';
  $handler->display->display_options['fields']['field_promo_file']['table'] = 'field_data_field_promo_file';
  $handler->display->display_options['fields']['field_promo_file']['field'] = 'field_promo_file';
  $handler->display->display_options['fields']['field_promo_file']['label'] = '';
  $handler->display->display_options['fields']['field_promo_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_promo_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_promo_file']['settings'] = array(
    'file_view_mode' => 'media_link',
  );
  /* Field: Content: Specifications */
  $handler->display->display_options['fields']['field_specificatins']['id'] = 'field_specificatins';
  $handler->display->display_options['fields']['field_specificatins']['table'] = 'field_data_field_specificatins';
  $handler->display->display_options['fields']['field_specificatins']['field'] = 'field_specificatins';
  /* Field: Content: Embed code */
  $handler->display->display_options['fields']['field_embed_code']['id'] = 'field_embed_code';
  $handler->display->display_options['fields']['field_embed_code']['table'] = 'field_data_field_embed_code';
  $handler->display->display_options['fields']['field_embed_code']['field'] = 'field_embed_code';
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
    'promo_item' => 'promo_item',
  );
  /* Filter criterion: Content: Item type (field_item_type) */
  $handler->display->display_options['filters']['field_item_type_value']['id'] = 'field_item_type_value';
  $handler->display->display_options['filters']['field_item_type_value']['table'] = 'field_data_field_item_type';
  $handler->display->display_options['filters']['field_item_type_value']['field'] = 'field_item_type_value';
  $handler->display->display_options['filters']['field_item_type_value']['value'] = array(
    'audio files' => 'audio files',
  );
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $export['promo_items_multi_year'] = $view;

  return $export;
}
