<?php
/**
 * @file
 * sponsors.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function sponsors_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'exhibitors';
  $view->description = 'Sponsors page';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Exhibitors';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Sponsors';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_booth_number' => 'field_booth_number',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Logo (website) */
  $handler->display->display_options['fields']['field_logo_website']['id'] = 'field_logo_website';
  $handler->display->display_options['fields']['field_logo_website']['table'] = 'field_data_field_logo_website';
  $handler->display->display_options['fields']['field_logo_website']['field'] = 'field_logo_website';
  $handler->display->display_options['fields']['field_logo_website']['label'] = '';
  $handler->display->display_options['fields']['field_logo_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logo_website']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo_website']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Field: Content: Sponsor Type */
  $handler->display->display_options['fields']['field_sponsor_type']['id'] = 'field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['field'] = 'field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_type']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_type']['delta_offset'] = '0';
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_sponsor_website']['id'] = 'field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['table'] = 'field_data_field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['field'] = 'field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_website']['click_sort_column'] = 'url';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Booth Number */
  $handler->display->display_options['fields']['field_booth_number']['id'] = 'field_booth_number';
  $handler->display->display_options['fields']['field_booth_number']['table'] = 'field_data_field_booth_number';
  $handler->display->display_options['fields']['field_booth_number']['field'] = 'field_booth_number';
  $handler->display->display_options['fields']['field_booth_number']['label'] = 'Booth';
  $handler->display->display_options['fields']['field_booth_number']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_booth_number']['hide_empty'] = TRUE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
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
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Exhibitor, Sponsor (field_exhibitor_sponsor) */
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['id'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['table'] = 'field_data_field_exhibitor_sponsor';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['field'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['value'] = array(
    'Sponsor' => 'Sponsor',
  );

  /* Display: Exhibitors */
  $handler = $view->new_display('page', 'Exhibitors', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Exhibitors';
  $handler->display->display_options['display_description'] = 'Sponsors page';
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
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Exhibitor, Sponsor (field_exhibitor_sponsor) */
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['id'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['table'] = 'field_data_field_exhibitor_sponsor';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['field'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['value'] = array(
    'Exhibitor' => 'Exhibitor',
  );
  $handler->display->display_options['path'] = 'scale11x/exhibitors';
  $export['exhibitors'] = $view;

  $view = new view();
  $view->name = 'sponsor_logos';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Sponsor logos';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Sponsors';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3>Silver Sponsors</h3>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Field: Content: Logo (website) */
  $handler->display->display_options['fields']['field_logo_website']['id'] = 'field_logo_website';
  $handler->display->display_options['fields']['field_logo_website']['table'] = 'field_data_field_logo_website';
  $handler->display->display_options['fields']['field_logo_website']['field'] = 'field_logo_website';
  $handler->display->display_options['fields']['field_logo_website']['label'] = '';
  $handler->display->display_options['fields']['field_logo_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logo_website']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_logo_website']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo_website']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
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
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    4 => '4',
  );

  /* Display: Top */
  $handler = $view->new_display('block', 'Top', 'block_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '&nbsp;';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor' => 'sponsor',
  );

  /* Display: Diamond */
  $handler = $view->new_display('attachment', 'Diamond', 'attachment_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3>Diamond Sponsors</h3>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['displays'] = array(
    'block_2' => 'block_2',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Platinum */
  $handler = $view->new_display('attachment', 'Platinum', 'attachment_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3>Platinum Sponsors</h3>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    2 => '2',
  );
  $handler->display->display_options['displays'] = array(
    'block_2' => 'block_2',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Gold */
  $handler = $view->new_display('attachment', 'Gold', 'attachment_3');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3>Gold Sponsors</h3>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    3 => '3',
  );
  $handler->display->display_options['displays'] = array(
    'block_2' => 'block_2',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Silver */
  $handler = $view->new_display('attachment', 'Silver', 'attachment_16');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['displays'] = array(
    'block_2' => 'block_2',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: ISP */
  $handler = $view->new_display('attachment', 'ISP', 'attachment_4');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3>ISP Sponsors</h3>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    5 => '5',
  );
  $handler->display->display_options['displays'] = array(
    'block_2' => 'block_2',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Network */
  $handler = $view->new_display('attachment', 'Network', 'attachment_5');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3>Network Sponsors</h3>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    6 => '6',
  );
  $handler->display->display_options['displays'] = array(
    'block_2' => 'block_2',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Wireless */
  $handler = $view->new_display('attachment', 'Wireless', 'attachment_6');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3>Wireless Sponsors</h3>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    7 => '7',
  );
  $handler->display->display_options['displays'] = array(
    'block_2' => 'block_2',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Registration */
  $handler = $view->new_display('attachment', 'Registration', 'attachment_7');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3>Registration Sponsors</h3>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    8 => '8',
  );
  $handler->display->display_options['displays'] = array(
    'block_2' => 'block_2',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Reception */
  $handler = $view->new_display('attachment', 'Reception', 'attachment_8');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3>Reception Sponsors</h3>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    9 => '9',
  );
  $handler->display->display_options['displays'] = array(
    'block_2' => 'block_2',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Special Event */
  $handler = $view->new_display('attachment', 'Special Event', 'attachment_9');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3>Special Event Sponsors</h3>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    10 => '10',
  );
  $handler->display->display_options['displays'] = array(
    'block_2' => 'block_2',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Speaker Track */
  $handler = $view->new_display('attachment', 'Speaker Track', 'attachment_10');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3>Speaker Track Sponsors</h3>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    11 => '11',
  );
  $handler->display->display_options['displays'] = array(
    'block_2' => 'block_2',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Streaming */
  $handler = $view->new_display('attachment', 'Streaming', 'attachment_11');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3>Streaming Sponsors</h3>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    12 => '12',
  );
  $handler->display->display_options['displays'] = array(
    'block_2' => 'block_2',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Travel */
  $handler = $view->new_display('attachment', 'Travel', 'attachment_12');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3>Travel Sponsors</h3>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    13 => '13',
  );
  $handler->display->display_options['displays'] = array(
    'block_2' => 'block_2',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Try It Lab */
  $handler = $view->new_display('attachment', 'Try It Lab', 'attachment_13');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3>Try It Lab Sponsors</h3>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    14 => '14',
  );
  $handler->display->display_options['displays'] = array(
    'block_2' => 'block_2',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Raffle */
  $handler = $view->new_display('attachment', 'Raffle', 'attachment_14');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3>Raffle Sponsors</h3>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    15 => '15',
  );
  $handler->display->display_options['displays'] = array(
    'block_2' => 'block_2',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Media */
  $handler = $view->new_display('attachment', 'Media', 'attachment_15');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['slideshow_type'] = 'views_slideshow_cycle';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Default',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_logo_website' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_logo_website' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['effect'] = 'scrollDown';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['transition_advanced'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = '5000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = '700';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['action_advanced'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '3';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load_timeout'] = '3000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3>Media Sponsors</h3>';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    16 => '16',
  );
  $handler->display->display_options['displays'] = array(
    'block_2' => 'block_2',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $export['sponsor_logos'] = $view;

  $view = new view();
  $view->name = 'sponsors';
  $view->description = 'Sponsors page';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Sponsors';
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_booth_number' => 'field_booth_number',
  );
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Logo (website) */
  $handler->display->display_options['fields']['field_logo_website']['id'] = 'field_logo_website';
  $handler->display->display_options['fields']['field_logo_website']['table'] = 'field_data_field_logo_website';
  $handler->display->display_options['fields']['field_logo_website']['field'] = 'field_logo_website';
  $handler->display->display_options['fields']['field_logo_website']['label'] = '';
  $handler->display->display_options['fields']['field_logo_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logo_website']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo_website']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Field: Content: Sponsor Type */
  $handler->display->display_options['fields']['field_sponsor_type']['id'] = 'field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['field'] = 'field_sponsor_type';
  $handler->display->display_options['fields']['field_sponsor_type']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_type']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_sponsor_type']['delta_offset'] = '0';
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_sponsor_website']['id'] = 'field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['table'] = 'field_data_field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['field'] = 'field_sponsor_website';
  $handler->display->display_options['fields']['field_sponsor_website']['label'] = '';
  $handler->display->display_options['fields']['field_sponsor_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsor_website']['click_sort_column'] = 'url';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Booth Number */
  $handler->display->display_options['fields']['field_booth_number']['id'] = 'field_booth_number';
  $handler->display->display_options['fields']['field_booth_number']['table'] = 'field_data_field_booth_number';
  $handler->display->display_options['fields']['field_booth_number']['field'] = 'field_booth_number';
  $handler->display->display_options['fields']['field_booth_number']['label'] = 'Booth';
  $handler->display->display_options['fields']['field_booth_number']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_booth_number']['hide_empty'] = TRUE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';

  /* Display: Sponsors */
  $handler = $view->new_display('page', 'Sponsors', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Sponsors';
  $handler->display->display_options['display_description'] = 'Sponsors page';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['hide_empty'] = TRUE;
  $handler->display->display_options['path'] = 'scale11x/sponsors';

  /* Display: Diamond */
  $handler = $view->new_display('attachment', 'Diamond', 'attachment_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Exhibitor, Sponsor (field_exhibitor_sponsor) */
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['id'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['table'] = 'field_data_field_exhibitor_sponsor';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['field'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['value'] = array(
    'Sponsor' => 'Sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Platinum */
  $handler = $view->new_display('attachment', 'Platinum', 'attachment_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Exhibitor, Sponsor (field_exhibitor_sponsor) */
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['id'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['table'] = 'field_data_field_exhibitor_sponsor';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['field'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['value'] = array(
    'Sponsor' => 'Sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    2 => '2',
  );
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Gold */
  $handler = $view->new_display('attachment', 'Gold', 'attachment_3');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Exhibitor, Sponsor (field_exhibitor_sponsor) */
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['id'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['table'] = 'field_data_field_exhibitor_sponsor';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['field'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['value'] = array(
    'Sponsor' => 'Sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    3 => '3',
  );
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Silver */
  $handler = $view->new_display('attachment', 'Silver', 'attachment_4');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Exhibitor, Sponsor (field_exhibitor_sponsor) */
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['id'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['table'] = 'field_data_field_exhibitor_sponsor';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['field'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['value'] = array(
    'Sponsor' => 'Sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    4 => '4',
  );
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: ISP */
  $handler = $view->new_display('attachment', 'ISP', 'attachment_5');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Exhibitor, Sponsor (field_exhibitor_sponsor) */
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['id'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['table'] = 'field_data_field_exhibitor_sponsor';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['field'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['value'] = array(
    'Sponsor' => 'Sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    5 => '5',
  );
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Network */
  $handler = $view->new_display('attachment', 'Network', 'attachment_6');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Exhibitor, Sponsor (field_exhibitor_sponsor) */
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['id'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['table'] = 'field_data_field_exhibitor_sponsor';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['field'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['value'] = array(
    'Sponsor' => 'Sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    6 => '6',
  );
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Wireless */
  $handler = $view->new_display('attachment', 'Wireless', 'attachment_7');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Exhibitor, Sponsor (field_exhibitor_sponsor) */
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['id'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['table'] = 'field_data_field_exhibitor_sponsor';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['field'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['value'] = array(
    'Sponsor' => 'Sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    7 => '7',
  );
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Registration */
  $handler = $view->new_display('attachment', 'Registration', 'attachment_8');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Exhibitor, Sponsor (field_exhibitor_sponsor) */
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['id'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['table'] = 'field_data_field_exhibitor_sponsor';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['field'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['value'] = array(
    'Sponsor' => 'Sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    8 => '8',
  );
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Reception */
  $handler = $view->new_display('attachment', 'Reception', 'attachment_9');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Exhibitor, Sponsor (field_exhibitor_sponsor) */
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['id'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['table'] = 'field_data_field_exhibitor_sponsor';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['field'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['value'] = array(
    'Sponsor' => 'Sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    9 => '9',
  );
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Special Event */
  $handler = $view->new_display('attachment', 'Special Event', 'attachment_10');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Exhibitor, Sponsor (field_exhibitor_sponsor) */
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['id'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['table'] = 'field_data_field_exhibitor_sponsor';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['field'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['value'] = array(
    'Sponsor' => 'Sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    10 => '10',
  );
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Special Event */
  $handler = $view->new_display('attachment', 'Special Event', 'attachment_11');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Exhibitor, Sponsor (field_exhibitor_sponsor) */
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['id'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['table'] = 'field_data_field_exhibitor_sponsor';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['field'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['value'] = array(
    'Sponsor' => 'Sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    11 => '11',
  );
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Streaming */
  $handler = $view->new_display('attachment', 'Streaming', 'attachment_12');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Exhibitor, Sponsor (field_exhibitor_sponsor) */
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['id'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['table'] = 'field_data_field_exhibitor_sponsor';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['field'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['value'] = array(
    'Sponsor' => 'Sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    12 => '12',
  );
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Travel */
  $handler = $view->new_display('attachment', 'Travel', 'attachment_13');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Exhibitor, Sponsor (field_exhibitor_sponsor) */
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['id'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['table'] = 'field_data_field_exhibitor_sponsor';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['field'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['value'] = array(
    'Sponsor' => 'Sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    13 => '13',
  );
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Try It Lab */
  $handler = $view->new_display('attachment', 'Try It Lab', 'attachment_14');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Exhibitor, Sponsor (field_exhibitor_sponsor) */
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['id'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['table'] = 'field_data_field_exhibitor_sponsor';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['field'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['value'] = array(
    'Sponsor' => 'Sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    14 => '14',
  );
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Raffle */
  $handler = $view->new_display('attachment', 'Raffle', 'attachment_15');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Exhibitor, Sponsor (field_exhibitor_sponsor) */
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['id'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['table'] = 'field_data_field_exhibitor_sponsor';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['field'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['value'] = array(
    'Sponsor' => 'Sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    15 => '15',
  );
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Media */
  $handler = $view->new_display('attachment', 'Media', 'attachment_16');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
    'sponsor' => 'sponsor',
  );
  /* Filter criterion: Content: Exhibitor, Sponsor (field_exhibitor_sponsor) */
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['id'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['table'] = 'field_data_field_exhibitor_sponsor';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['field'] = 'field_exhibitor_sponsor_value';
  $handler->display->display_options['filters']['field_exhibitor_sponsor_value']['value'] = array(
    'Sponsor' => 'Sponsor',
  );
  /* Filter criterion: Content: Sponsor Type (field_sponsor_type) */
  $handler->display->display_options['filters']['field_sponsor_type_value']['id'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['table'] = 'field_data_field_sponsor_type';
  $handler->display->display_options['filters']['field_sponsor_type_value']['field'] = 'field_sponsor_type_value';
  $handler->display->display_options['filters']['field_sponsor_type_value']['value'] = array(
    16 => '16',
  );
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $export['sponsors'] = $view;

  return $export;
}
