<?php
/**
 * @file
 * scale_speaker.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function scale_speaker_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_view__speaker-individual-for-reviewer';
  $handler->task = 'user_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Speaker Individual for reviewer',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'speaker-individual',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'review presentations',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
      'logic' => 'or',
    ),
    'name' => 'speaker-individual-for-reviewer',
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
  $display->uuid = '65b99614-c6fd-4c93-9478-85003a69d0d2';
  $display->storage_type = '';
  $display->storage_id = '';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-9221d179-6db2-4915-bb84-079e916c3277';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'user:field_speaker_photo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'square_thumbnail',
      'image_link' => '',
    ),
    'context' => 'argument_entity_id:user_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9221d179-6db2-4915-bb84-079e916c3277';
  $display->content['new-9221d179-6db2-4915-bb84-079e916c3277'] = $pane;
  $display->panels['middle'][0] = 'new-9221d179-6db2-4915-bb84-079e916c3277';
  $pane = new stdClass();
  $pane->pid = 'new-af4c07e3-9e27-408f-9bd4-4cab1142f3f8';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'presentations_by_speaker-panel_pane_3';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:user_1',
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
  $pane->uuid = 'af4c07e3-9e27-408f-9bd4-4cab1142f3f8';
  $display->content['new-af4c07e3-9e27-408f-9bd4-4cab1142f3f8'] = $pane;
  $display->panels['middle'][1] = 'new-af4c07e3-9e27-408f-9bd4-4cab1142f3f8';
  $pane = new stdClass();
  $pane->pid = 'new-35ac2ff1-1ea4-41b5-92c2-c6c6d1ca4b9e';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'speaker_individual-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:user_1',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '35ac2ff1-1ea4-41b5-92c2-c6c6d1ca4b9e';
  $display->content['new-35ac2ff1-1ea4-41b5-92c2-c6c6d1ca4b9e'] = $pane;
  $display->panels['middle'][2] = 'new-35ac2ff1-1ea4-41b5-92c2-c6c6d1ca4b9e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['user_view__speaker-individual-for-reviewer'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_view_panel_context';
  $handler->task = 'user_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Speaker individual public',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'speaker-individual',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
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
  $display->uuid = 'e375d2f7-ad72-4de3-bbf4-7e39405ff5df';
  $display->storage_type = '';
  $display->storage_id = '';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-f36fa0bb-8ee6-4a8e-9b2e-0528da3df941';
  $pane->panel = 'middle';
  $pane->type = 'entity_field';
  $pane->subtype = 'user:field_speaker_photo';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'square_thumbnail',
      'image_link' => '',
    ),
    'context' => 'argument_entity_id:user_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f36fa0bb-8ee6-4a8e-9b2e-0528da3df941';
  $display->content['new-f36fa0bb-8ee6-4a8e-9b2e-0528da3df941'] = $pane;
  $display->panels['middle'][0] = 'new-f36fa0bb-8ee6-4a8e-9b2e-0528da3df941';
  $pane = new stdClass();
  $pane->pid = 'new-819e0539-1529-4d20-9a58-bd79f0c0ffd5';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'presentations_by_speaker-panel_pane_3';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:user_1',
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
  $pane->uuid = '819e0539-1529-4d20-9a58-bd79f0c0ffd5';
  $display->content['new-819e0539-1529-4d20-9a58-bd79f0c0ffd5'] = $pane;
  $display->panels['middle'][1] = 'new-819e0539-1529-4d20-9a58-bd79f0c0ffd5';
  $pane = new stdClass();
  $pane->pid = 'new-c7b044d7-0e0a-4b11-a311-459abf4362dd';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'speaker_individual-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:user_1',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'c7b044d7-0e0a-4b11-a311-459abf4362dd';
  $display->content['new-c7b044d7-0e0a-4b11-a311-459abf4362dd'] = $pane;
  $display->panels['middle'][2] = 'new-c7b044d7-0e0a-4b11-a311-459abf4362dd';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-c7b044d7-0e0a-4b11-a311-459abf4362dd';
  $handler->conf['display'] = $display;
  $export['user_view_panel_context'] = $handler;

  return $export;
}
