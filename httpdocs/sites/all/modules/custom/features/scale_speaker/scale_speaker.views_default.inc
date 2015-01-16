<?php
/**
 * @file
 * scale_speaker.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function scale_speaker_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'speaker_individual';
  $view->description = 'Individual speaker page';
  $view->tag = 'new speaker system';
  $view->base_table = 'users';
  $view->human_name = 'Speaker individual';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'This user is not a speaker in the current year.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: User: Speaker (field_speaker) - reverse */
  $handler->display->display_options['relationships']['reverse_field_speaker_node']['id'] = 'reverse_field_speaker_node';
  $handler->display->display_options['relationships']['reverse_field_speaker_node']['table'] = 'users';
  $handler->display->display_options['relationships']['reverse_field_speaker_node']['field'] = 'reverse_field_speaker_node';
  $handler->display->display_options['relationships']['reverse_field_speaker_node']['required'] = TRUE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: User: Photo */
  $handler->display->display_options['fields']['field_speaker_photo']['id'] = 'field_speaker_photo';
  $handler->display->display_options['fields']['field_speaker_photo']['table'] = 'field_data_field_speaker_photo';
  $handler->display->display_options['fields']['field_speaker_photo']['field'] = 'field_speaker_photo';
  $handler->display->display_options['fields']['field_speaker_photo']['label'] = '';
  $handler->display->display_options['fields']['field_speaker_photo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_speaker_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_speaker_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_speaker_photo']['settings'] = array(
    'image_style' => 'square_thumbnail',
    'image_link' => '',
  );
  /* Field: User: Job title */
  $handler->display->display_options['fields']['field_job_title']['id'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['table'] = 'field_data_field_job_title';
  $handler->display->display_options['fields']['field_job_title']['field'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_job_title']['element_label_colon'] = FALSE;
  /* Field: User: Organization */
  $handler->display->display_options['fields']['field_organization']['id'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['table'] = 'field_data_field_organization';
  $handler->display->display_options['fields']['field_organization']['field'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['label'] = '';
  $handler->display->display_options['fields']['field_organization']['element_label_colon'] = FALSE;
  /* Field: User: Biography */
  $handler->display->display_options['fields']['field_biography']['id'] = 'field_biography';
  $handler->display->display_options['fields']['field_biography']['table'] = 'field_data_field_biography';
  $handler->display->display_options['fields']['field_biography']['field'] = 'field_biography';
  $handler->display->display_options['fields']['field_biography']['label'] = '';
  $handler->display->display_options['fields']['field_biography']['element_label_colon'] = FALSE;
  /* Field: User: Website */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['label'] = '';
  $handler->display->display_options['fields']['field_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  /* Contextual filter: speaker ID */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['ui_name'] = 'speaker ID';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['uid']['validate_options']['type'] = 'either';
  $handler->display->display_options['arguments']['uid']['validate_options']['restrict_roles'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate_options']['roles'] = array(
    5 => '5',
  );
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['relationship'] = 'reverse_field_speaker_node';
  $handler->display->display_options['filters']['status_1']['value'] = '1';

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'uid' => array(
      'type' => 'context',
      'context' => 'entity:user.uid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'speaker ID',
    ),
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'speaker-test/%';
  $export['speaker_individual'] = $view;

  $view = new view();
  $view->name = 'speaker_list';
  $view->description = 'List of speakers by name';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Speaker list';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Speaker list';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'realname' => 'realname',
    'name' => 'name',
    'title' => 'title',
    'mail' => 'mail',
    'field_primary_email' => 'field_primary_email',
  );
  $handler->display->display_options['style_options']['default'] = 'realname';
  $handler->display->display_options['style_options']['info'] = array(
    'realname' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_primary_email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: User: Speaker (field_speaker) - reverse */
  $handler->display->display_options['relationships']['reverse_field_speaker_node']['id'] = 'reverse_field_speaker_node';
  $handler->display->display_options['relationships']['reverse_field_speaker_node']['table'] = 'users';
  $handler->display->display_options['relationships']['reverse_field_speaker_node']['field'] = 'reverse_field_speaker_node';
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_speaker_node';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  /* Field: Content: Primary contact email address */
  $handler->display->display_options['fields']['field_primary_email']['id'] = 'field_primary_email';
  $handler->display->display_options['fields']['field_primary_email']['table'] = 'field_data_field_primary_email';
  $handler->display->display_options['fields']['field_primary_email']['field'] = 'field_primary_email';
  $handler->display->display_options['fields']['field_primary_email']['relationship'] = 'reverse_field_speaker_node';
  $handler->display->display_options['fields']['field_primary_email']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_primary_email']['alter']['text'] = '<a href="mailto:[field_primary_email]">[field_primary_email]</a>';
  /* Sort criterion: User: Last name (field_last_name) */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    5 => '5',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'reverse_field_speaker_node';
  $handler->display->display_options['filters']['title']['operator'] = 'not empty';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'speaker-list';

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $export['speaker_list'] = $view;

  $view = new view();
  $view->name = 'speaker_page';
  $view->description = 'Speaker page for public view';
  $view->tag = 'multi-year';
  $view->base_table = 'users';
  $view->human_name = 'Speaker page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Speaker page';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Footer: Global: View area */
  $handler->display->display_options['footer']['view']['id'] = 'view';
  $handler->display->display_options['footer']['view']['table'] = 'views';
  $handler->display->display_options['footer']['view']['field'] = 'view';
  /* Relationship: User: Speaker (field_speaker) - reverse */
  $handler->display->display_options['relationships']['reverse_field_speaker_node']['id'] = 'reverse_field_speaker_node';
  $handler->display->display_options['relationships']['reverse_field_speaker_node']['table'] = 'users';
  $handler->display->display_options['relationships']['reverse_field_speaker_node']['field'] = 'reverse_field_speaker_node';
  /* Field: User: Photo */
  $handler->display->display_options['fields']['field_speaker_photo']['id'] = 'field_speaker_photo';
  $handler->display->display_options['fields']['field_speaker_photo']['table'] = 'field_data_field_speaker_photo';
  $handler->display->display_options['fields']['field_speaker_photo']['field'] = 'field_speaker_photo';
  $handler->display->display_options['fields']['field_speaker_photo']['label'] = '';
  $handler->display->display_options['fields']['field_speaker_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_speaker_photo']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_speaker_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_speaker_photo']['settings'] = array(
    'image_style' => 'square_thumbnail',
    'image_link' => '',
  );
  /* Field: User: Job title */
  $handler->display->display_options['fields']['field_job_title']['id'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['table'] = 'field_data_field_job_title';
  $handler->display->display_options['fields']['field_job_title']['field'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_job_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_job_title']['hide_empty'] = TRUE;
  /* Field: User: Organization */
  $handler->display->display_options['fields']['field_organization']['id'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['table'] = 'field_data_field_organization';
  $handler->display->display_options['fields']['field_organization']['field'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['label'] = '';
  $handler->display->display_options['fields']['field_organization']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization']['hide_empty'] = TRUE;
  /* Field: User: Biography */
  $handler->display->display_options['fields']['field_biography']['id'] = 'field_biography';
  $handler->display->display_options['fields']['field_biography']['table'] = 'field_data_field_biography';
  $handler->display->display_options['fields']['field_biography']['field'] = 'field_biography';
  $handler->display->display_options['fields']['field_biography']['label'] = '';
  $handler->display->display_options['fields']['field_biography']['element_label_colon'] = FALSE;
  /* Field: User: Website */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['label'] = '';
  $handler->display->display_options['fields']['field_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_speaker_node';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Sort criterion: User: Last name (field_last_name) */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['uid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['uid']['title'] = '%1';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    5 => '5',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['relationship'] = 'reverse_field_speaker_node';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  /* Filter criterion: Content: SCALE event (field_scale_event) */
  $handler->display->display_options['filters']['field_scale_event_tid']['id'] = 'field_scale_event_tid';
  $handler->display->display_options['filters']['field_scale_event_tid']['table'] = 'field_data_field_scale_event';
  $handler->display->display_options['filters']['field_scale_event_tid']['field'] = 'field_scale_event_tid';
  $handler->display->display_options['filters']['field_scale_event_tid']['relationship'] = 'reverse_field_speaker_node';
  $handler->display->display_options['filters']['field_scale_event_tid']['value'] = array(
    504 => '504',
  );
  $handler->display->display_options['filters']['field_scale_event_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_scale_event_tid']['vocabulary'] = 'scale_event';

  /* Display: Speaker */
  $handler = $view->new_display('page', 'Speaker', 'page');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: View area */
  $handler->display->display_options['footer']['view']['id'] = 'view';
  $handler->display->display_options['footer']['view']['table'] = 'views';
  $handler->display->display_options['footer']['view']['field'] = 'view';
  $handler->display->display_options['footer']['view']['label'] = 'Presentations';
  $handler->display->display_options['footer']['view']['view_to_insert'] = 'presentations_by_speaker:panel_pane_2';
  $handler->display->display_options['footer']['view']['inherit_arguments'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Speaker (field_speaker) - reverse */
  $handler->display->display_options['relationships']['reverse_field_speaker_node']['id'] = 'reverse_field_speaker_node';
  $handler->display->display_options['relationships']['reverse_field_speaker_node']['table'] = 'users';
  $handler->display->display_options['relationships']['reverse_field_speaker_node']['field'] = 'reverse_field_speaker_node';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Photo */
  $handler->display->display_options['fields']['field_speaker_photo']['id'] = 'field_speaker_photo';
  $handler->display->display_options['fields']['field_speaker_photo']['table'] = 'field_data_field_speaker_photo';
  $handler->display->display_options['fields']['field_speaker_photo']['field'] = 'field_speaker_photo';
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
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_speaker_node';
  $handler->display->display_options['fields']['title']['label'] = 'Presentation';
  /* Field: User: Job title */
  $handler->display->display_options['fields']['field_job_title']['id'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['table'] = 'field_data_field_job_title';
  $handler->display->display_options['fields']['field_job_title']['field'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_job_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_job_title']['hide_empty'] = TRUE;
  /* Field: User: Organization */
  $handler->display->display_options['fields']['field_organization']['id'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['table'] = 'field_data_field_organization';
  $handler->display->display_options['fields']['field_organization']['field'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['label'] = '';
  $handler->display->display_options['fields']['field_organization']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization']['hide_empty'] = TRUE;
  /* Field: User: Biography */
  $handler->display->display_options['fields']['field_biography']['id'] = 'field_biography';
  $handler->display->display_options['fields']['field_biography']['table'] = 'field_data_field_biography';
  $handler->display->display_options['fields']['field_biography']['field'] = 'field_biography';
  $handler->display->display_options['fields']['field_biography']['label'] = '';
  $handler->display->display_options['fields']['field_biography']['element_label_colon'] = FALSE;
  /* Field: User: Website */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['label'] = '';
  $handler->display->display_options['fields']['field_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['uid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['uid']['title'] = '%1';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: scale event */
  $handler->display->display_options['arguments']['field_scale_event_tid']['id'] = 'field_scale_event_tid';
  $handler->display->display_options['arguments']['field_scale_event_tid']['table'] = 'field_data_field_scale_event';
  $handler->display->display_options['arguments']['field_scale_event_tid']['field'] = 'field_scale_event_tid';
  $handler->display->display_options['arguments']['field_scale_event_tid']['relationship'] = 'reverse_field_speaker_node';
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
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    5 => '5',
  );
  $handler->display->display_options['path'] = 'user/%';

  /* Display: Speakers 11x */
  $handler = $view->new_display('page', 'Speakers 11x', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Speakers';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['label'] = '';
  $handler->display->display_options['fields']['realname']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['realname']['alter']['path'] = 'scale11x/speakers/[realname]';
  $handler->display->display_options['fields']['realname']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['realname']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['realname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['realname']['link_to_user'] = FALSE;
  /* Field: User: Photo */
  $handler->display->display_options['fields']['field_speaker_photo']['id'] = 'field_speaker_photo';
  $handler->display->display_options['fields']['field_speaker_photo']['table'] = 'field_data_field_speaker_photo';
  $handler->display->display_options['fields']['field_speaker_photo']['field'] = 'field_speaker_photo';
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
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_speaker_node';
  $handler->display->display_options['fields']['title']['label'] = 'Presentation';
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  /* Field: User: Job title */
  $handler->display->display_options['fields']['field_job_title']['id'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['table'] = 'field_data_field_job_title';
  $handler->display->display_options['fields']['field_job_title']['field'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_job_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_job_title']['hide_empty'] = TRUE;
  /* Field: User: Organization */
  $handler->display->display_options['fields']['field_organization']['id'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['table'] = 'field_data_field_organization';
  $handler->display->display_options['fields']['field_organization']['field'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['label'] = '';
  $handler->display->display_options['fields']['field_organization']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization']['hide_empty'] = TRUE;
  /* Field: User: Biography */
  $handler->display->display_options['fields']['field_biography']['id'] = 'field_biography';
  $handler->display->display_options['fields']['field_biography']['table'] = 'field_data_field_biography';
  $handler->display->display_options['fields']['field_biography']['field'] = 'field_biography';
  $handler->display->display_options['fields']['field_biography']['label'] = '';
  $handler->display->display_options['fields']['field_biography']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_biography']['settings'] = array(
    'trim_length' => '200',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    5 => '5',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['relationship'] = 'reverse_field_speaker_node';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  /* Filter criterion: Content: SCALE event (field_scale_event) */
  $handler->display->display_options['filters']['field_scale_event_tid']['id'] = 'field_scale_event_tid';
  $handler->display->display_options['filters']['field_scale_event_tid']['table'] = 'field_data_field_scale_event';
  $handler->display->display_options['filters']['field_scale_event_tid']['field'] = 'field_scale_event_tid';
  $handler->display->display_options['filters']['field_scale_event_tid']['relationship'] = 'reverse_field_speaker_node';
  $handler->display->display_options['filters']['field_scale_event_tid']['value'] = array(
    503 => '503',
  );
  $handler->display->display_options['filters']['field_scale_event_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_scale_event_tid']['vocabulary'] = 'scale_event';
  $handler->display->display_options['path'] = 'scale11x/speakers';

  /* Display: Speakers 12x */
  $handler = $view->new_display('page', 'Speakers 12x', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Speakers';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Speaker (field_speaker) - reverse */
  $handler->display->display_options['relationships']['reverse_field_speaker_node']['id'] = 'reverse_field_speaker_node';
  $handler->display->display_options['relationships']['reverse_field_speaker_node']['table'] = 'users';
  $handler->display->display_options['relationships']['reverse_field_speaker_node']['field'] = 'reverse_field_speaker_node';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['label'] = '';
  $handler->display->display_options['fields']['realname']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['realname']['alter']['path'] = 'scale12x/speakers/[realname]';
  $handler->display->display_options['fields']['realname']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['realname']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['realname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['realname']['link_to_user'] = FALSE;
  /* Field: User: Photo */
  $handler->display->display_options['fields']['field_speaker_photo']['id'] = 'field_speaker_photo';
  $handler->display->display_options['fields']['field_speaker_photo']['table'] = 'field_data_field_speaker_photo';
  $handler->display->display_options['fields']['field_speaker_photo']['field'] = 'field_speaker_photo';
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
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_speaker_node';
  $handler->display->display_options['fields']['title']['label'] = 'Presentation';
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  /* Field: User: Job title */
  $handler->display->display_options['fields']['field_job_title']['id'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['table'] = 'field_data_field_job_title';
  $handler->display->display_options['fields']['field_job_title']['field'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_job_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_job_title']['hide_empty'] = TRUE;
  /* Field: User: Organization */
  $handler->display->display_options['fields']['field_organization']['id'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['table'] = 'field_data_field_organization';
  $handler->display->display_options['fields']['field_organization']['field'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['label'] = '';
  $handler->display->display_options['fields']['field_organization']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization']['hide_empty'] = TRUE;
  /* Field: User: Biography */
  $handler->display->display_options['fields']['field_biography']['id'] = 'field_biography';
  $handler->display->display_options['fields']['field_biography']['table'] = 'field_data_field_biography';
  $handler->display->display_options['fields']['field_biography']['field'] = 'field_biography';
  $handler->display->display_options['fields']['field_biography']['label'] = '';
  $handler->display->display_options['fields']['field_biography']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_biography']['settings'] = array(
    'trim_length' => '200',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'scale12x/speakers';

  /* Display: Speakers 13x */
  $handler = $view->new_display('page', 'Speakers 13x', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Speakers';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Speaker (field_speaker) - reverse */
  $handler->display->display_options['relationships']['reverse_field_speaker_node']['id'] = 'reverse_field_speaker_node';
  $handler->display->display_options['relationships']['reverse_field_speaker_node']['table'] = 'users';
  $handler->display->display_options['relationships']['reverse_field_speaker_node']['field'] = 'reverse_field_speaker_node';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['label'] = '';
  $handler->display->display_options['fields']['realname']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['realname']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['realname']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['realname']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['realname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['realname']['link_to_user'] = FALSE;
  /* Field: User: Photo */
  $handler->display->display_options['fields']['field_speaker_photo']['id'] = 'field_speaker_photo';
  $handler->display->display_options['fields']['field_speaker_photo']['table'] = 'field_data_field_speaker_photo';
  $handler->display->display_options['fields']['field_speaker_photo']['field'] = 'field_speaker_photo';
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
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_speaker_node';
  $handler->display->display_options['fields']['title']['label'] = 'Presentation';
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  /* Field: User: Job title */
  $handler->display->display_options['fields']['field_job_title']['id'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['table'] = 'field_data_field_job_title';
  $handler->display->display_options['fields']['field_job_title']['field'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_job_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_job_title']['hide_empty'] = TRUE;
  /* Field: User: Organization */
  $handler->display->display_options['fields']['field_organization']['id'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['table'] = 'field_data_field_organization';
  $handler->display->display_options['fields']['field_organization']['field'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['label'] = '';
  $handler->display->display_options['fields']['field_organization']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization']['hide_empty'] = TRUE;
  /* Field: User: Biography */
  $handler->display->display_options['fields']['field_biography']['id'] = 'field_biography';
  $handler->display->display_options['fields']['field_biography']['table'] = 'field_data_field_biography';
  $handler->display->display_options['fields']['field_biography']['field'] = 'field_biography';
  $handler->display->display_options['fields']['field_biography']['label'] = '';
  $handler->display->display_options['fields']['field_biography']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_biography']['settings'] = array(
    'trim_length' => '200',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    5 => '5',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['relationship'] = 'reverse_field_speaker_node';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  /* Filter criterion: Content: SCALE event (field_scale_event) */
  $handler->display->display_options['filters']['field_scale_event_tid']['id'] = 'field_scale_event_tid';
  $handler->display->display_options['filters']['field_scale_event_tid']['table'] = 'field_data_field_scale_event';
  $handler->display->display_options['filters']['field_scale_event_tid']['field'] = 'field_scale_event_tid';
  $handler->display->display_options['filters']['field_scale_event_tid']['relationship'] = 'reverse_field_speaker_node';
  $handler->display->display_options['filters']['field_scale_event_tid']['value'] = array(
    885 => '885',
  );
  $handler->display->display_options['filters']['field_scale_event_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_scale_event_tid']['vocabulary'] = 'scale_event';
  $handler->display->display_options['path'] = 'scale13x/speakers';

  /* Display: Speakers multi-year */
  $handler = $view->new_display('page', 'Speakers multi-year', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Speakers';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Speaker (field_speaker) - reverse */
  $handler->display->display_options['relationships']['reverse_field_speaker_node']['id'] = 'reverse_field_speaker_node';
  $handler->display->display_options['relationships']['reverse_field_speaker_node']['table'] = 'users';
  $handler->display->display_options['relationships']['reverse_field_speaker_node']['field'] = 'reverse_field_speaker_node';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['label'] = '';
  $handler->display->display_options['fields']['realname']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['realname']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['realname']['alter']['replace_spaces'] = TRUE;
  $handler->display->display_options['fields']['realname']['alter']['path_case'] = 'lower';
  $handler->display->display_options['fields']['realname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['realname']['link_to_user'] = FALSE;
  /* Field: User: Photo */
  $handler->display->display_options['fields']['field_speaker_photo']['id'] = 'field_speaker_photo';
  $handler->display->display_options['fields']['field_speaker_photo']['table'] = 'field_data_field_speaker_photo';
  $handler->display->display_options['fields']['field_speaker_photo']['field'] = 'field_speaker_photo';
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
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_speaker_node';
  $handler->display->display_options['fields']['title']['label'] = 'Presentation';
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  /* Field: User: Job title */
  $handler->display->display_options['fields']['field_job_title']['id'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['table'] = 'field_data_field_job_title';
  $handler->display->display_options['fields']['field_job_title']['field'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_job_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_job_title']['hide_empty'] = TRUE;
  /* Field: User: Organization */
  $handler->display->display_options['fields']['field_organization']['id'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['table'] = 'field_data_field_organization';
  $handler->display->display_options['fields']['field_organization']['field'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['label'] = '';
  $handler->display->display_options['fields']['field_organization']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization']['hide_empty'] = TRUE;
  /* Field: User: Biography */
  $handler->display->display_options['fields']['field_biography']['id'] = 'field_biography';
  $handler->display->display_options['fields']['field_biography']['table'] = 'field_data_field_biography';
  $handler->display->display_options['fields']['field_biography']['field'] = 'field_biography';
  $handler->display->display_options['fields']['field_biography']['label'] = '';
  $handler->display->display_options['fields']['field_biography']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_biography']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_biography']['settings'] = array(
    'trim_length' => '200',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: User: Last name (field_last_name) */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: SCALE event (field_scale_event) */
  $handler->display->display_options['arguments']['field_scale_event_tid']['id'] = 'field_scale_event_tid';
  $handler->display->display_options['arguments']['field_scale_event_tid']['table'] = 'field_data_field_scale_event';
  $handler->display->display_options['arguments']['field_scale_event_tid']['field'] = 'field_scale_event_tid';
  $handler->display->display_options['arguments']['field_scale_event_tid']['relationship'] = 'reverse_field_speaker_node';
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
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    5 => '5',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['relationship'] = 'reverse_field_speaker_node';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  /* Filter criterion: Content: Status (field_presentation_status) */
  $handler->display->display_options['filters']['field_presentation_status_value']['id'] = 'field_presentation_status_value';
  $handler->display->display_options['filters']['field_presentation_status_value']['table'] = 'field_data_field_presentation_status';
  $handler->display->display_options['filters']['field_presentation_status_value']['field'] = 'field_presentation_status_value';
  $handler->display->display_options['filters']['field_presentation_status_value']['relationship'] = 'reverse_field_speaker_node';
  $handler->display->display_options['filters']['field_presentation_status_value']['value'] = array(
    20 => '20',
  );
  $handler->display->display_options['path'] = 'scale/%/speakers';
  $export['speaker_page'] = $view;

  return $export;
}
