<?php

/**
 * @file
 * scale_presentation.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function scale_presentation_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = TRUE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__hide_presentations_from_public';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'http_response';
  $handler->weight = -29;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'context' => 'logged-in-user',
          'name' => 'role',
          'not' => TRUE,
          'settings' => array(
            'rids' => array(
              0 => 4,
              1 => 9,
              2 => 10,
              3 => 8,
              4 => 7,
            ),
          ),
        ),
        1 => array(
          'context' => 'argument_entity_id:node_1',
          'name' => 'node_type',
          'not' => FALSE,
          'settings' => array(
            'type' => array(
              'presentation' => 'presentation',
            ),
          ),
        ),
        2 => array(
          'context' => 'argument_entity_id:node_1',
          'name' => 'entity_field_value:node:presentation:field_scale_event',
          'not' => FALSE,
          'settings' => array(
            'field_scale_event' => array(
              'und' => array(
                0 => array(
                  'tid' => '1963',
                ),
              ),
            ),
            'field_scale_event_tid' => array(
              0 => '1963',
            ),
          ),
        ),
      ),
    ),
    'code' => '404',
    'contexts' => array(),
    'destination' => '',
    'name' => 'hide_presentations_from_public',
    'relationships' => array(),
    'title' => 'hide presentations from public',
  );
  $export['node_view__hide_presentations_from_public'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__presentation-review';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'context' => 'argument_entity_id:node_1',
          'name' => 'node_type',
          'not' => FALSE,
          'settings' => array(
            'type' => array(
              'presentation' => 'presentation',
            ),
          ),
        ),
        1 => array(
          'context' => 'logged-in-user',
          'name' => 'role',
          'not' => FALSE,
          'settings' => array(
            'rids' => array(
              0 => 4,
              1 => 9,
              2 => 3,
            ),
          ),
        ),
        2 => array(
          'context' => 'argument_entity_id:node_1',
          'name' => 'node_status',
          'not' => TRUE,
          'settings' => NULL,
        ),
      ),
    ),
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'name' => 'presentation-review',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(
      0 => array(
        'context' => 'argument_entity_id:node_1',
        'delta' => '0',
        'id' => 1,
        'identifier' => 'User from Node (on Node: Speaker [field_speaker])',
        'keyword' => 'speaker',
        'name' => 'entity_from_field:field_speaker-node-user',
      ),
      1 => array(
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
        'identifier' => 'User from Node (on node.node_author)',
        'keyword' => 'author',
        'name' => 'entity_from_schema:uid-node-user',
      ),
    ),
    'title' => 'Presentation review',
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
  $display->uuid = '8ae5405a-7e24-478d-99cb-0fe8014298bb';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__presentation-review';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-f491f23d-8c0a-4866-bf22-0a5146638ff4';
  $pane->panel = 'middle';
  $pane->type = 'rate_widget';
  $pane->subtype = 'rate_widget';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'context' => 'logged-in-user',
        'name' => 'role',
        'not' => FALSE,
        'settings' => array(
          'rids' => array(
            0 => 4,
            1 => 9,
            2 => 3,
          ),
        ),
      ),
    ),
  );
  $pane->configuration = array(
    'build_mode' => '2',
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
    'widget_name' => '1',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f491f23d-8c0a-4866-bf22-0a5146638ff4';
  $display->content['new-f491f23d-8c0a-4866-bf22-0a5146638ff4'] = $pane;
  $display->panels['middle'][0] = 'new-f491f23d-8c0a-4866-bf22-0a5146638ff4';
  $pane = new stdClass();
  $pane->pid = 'new-75d6f716-b5cc-4374-92b9-f9e73270cf7c';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'presentation_single-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'context' => 'argument_entity_id:node_1',
        'name' => 'entity_field_value:node:presentation:field_presentation_status',
        'not' => FALSE,
        'settings' => array(
          'field_presentation_status' => array(
            'und' => array(
              0 => array(
                'value' => '20',
              ),
            ),
          ),
          'field_presentation_status_value' => array(
            0 => '20',
          ),
        ),
      ),
    ),
  );
  $pane->configuration = array(
    'context' => array(
      1 => 'argument_entity_id:node_1',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '75d6f716-b5cc-4374-92b9-f9e73270cf7c';
  $display->content['new-75d6f716-b5cc-4374-92b9-f9e73270cf7c'] = $pane;
  $display->panels['middle'][1] = 'new-75d6f716-b5cc-4374-92b9-f9e73270cf7c';
  $pane = new stdClass();
  $pane->pid = 'new-07e6ac5a-9deb-4640-9aa3-9b2bd230fb99';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'presentation_single-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array(
    'logic' => 'or',
    'plugins' => array(
      0 => array(
        'context' => 'logged-in-user',
        'name' => 'role',
        'not' => FALSE,
        'settings' => array(
          'rids' => array(
            0 => 4,
            1 => 9,
            2 => 10,
            3 => 8,
            4 => 6,
            5 => 7,
            6 => 3,
          ),
        ),
      ),
      1 => array(
        'context' => array(
          0 => 'logged-in-user',
          1 => 'relationship_entity_from_field:field_speaker-node-user_1',
        ),
        'name' => 'compare_users',
        'not' => FALSE,
        'settings' => array(
          'equality' => '1',
        ),
      ),
      2 => array(
        'context' => array(
          0 => 'logged-in-user',
          1 => 'relationship_entity_from_schema:uid-node-user_1',
        ),
        'name' => 'compare_users',
        'not' => FALSE,
        'settings' => array(
          'equality' => '1',
        ),
      ),
      3 => array(
        'context' => 'argument_entity_id:node_1',
        'name' => 'entity_field_value:node:presentation:field_presentation_status',
        'not' => TRUE,
        'settings' => array(
          'field_presentation_status' => array(
            'und' => array(
              0 => array(
                'value' => '20',
              ),
            ),
          ),
          'field_presentation_status_value' => array(
            0 => '20',
          ),
        ),
      ),
    ),
  );
  $pane->configuration = array(
    'context' => array(
      1 => 'argument_entity_id:node_1',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '07e6ac5a-9deb-4640-9aa3-9b2bd230fb99';
  $display->content['new-07e6ac5a-9deb-4640-9aa3-9b2bd230fb99'] = $pane;
  $display->panels['middle'][2] = 'new-07e6ac5a-9deb-4640-9aa3-9b2bd230fb99';
  $pane = new stdClass();
  $pane->pid = 'new-e051c359-e836-42e2-a249-6eed217169b6';
  $pane->panel = 'middle';
  $pane->type = 'node_comment_wrapper';
  $pane->subtype = 'node_comment_wrapper';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'comments_per_page' => '50',
    'context' => 'argument_entity_id:node_1',
    'mode' => '1',
    'override_title' => 0,
    'override_title_heading' => 'h2',
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'e051c359-e836-42e2-a249-6eed217169b6';
  $display->content['new-e051c359-e836-42e2-a249-6eed217169b6'] = $pane;
  $display->panels['middle'][3] = 'new-e051c359-e836-42e2-a249-6eed217169b6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__presentation-review'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'context' => 'argument_entity_id:node_1',
          'name' => 'node_type',
          'not' => FALSE,
          'settings' => array(
            'type' => array(
              'presentation' => 'presentation',
            ),
          ),
        ),
      ),
    ),
    'body_classes_to_add' => '',
    'body_classes_to_remove' => '',
    'contexts' => array(),
    'css' => '',
    'css_id' => '',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'relationships' => array(
      0 => array(
        'context' => 'argument_entity_id:node_1',
        'delta' => '0',
        'id' => 1,
        'identifier' => 'User from Node (on Node: Speaker [field_speaker])',
        'keyword' => 'speaker',
        'name' => 'entity_from_field:field_speaker-node-user',
      ),
      1 => array(
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
        'identifier' => 'User from Node (on node.node_author)',
        'keyword' => 'author',
        'name' => 'entity_from_schema:uid-node-user',
      ),
    ),
    'title' => 'Presentation page',
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
  $display->uuid = '33b138ec-a7af-4544-888e-0cee6b00e8da';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-007d3f2a-7104-41b8-8da6-296818068de6';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'presentation_single-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'context' => 'argument_entity_id:node_1',
        'name' => 'entity_field_value:node:presentation:field_presentation_status',
        'not' => FALSE,
        'settings' => array(
          'field_presentation_status' => array(
            'und' => array(
              0 => array(
                'value' => '20',
              ),
            ),
          ),
          'field_presentation_status_value' => array(
            0 => '20',
          ),
        ),
      ),
    ),
  );
  $pane->configuration = array(
    'context' => array(
      1 => 'argument_entity_id:node_1',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '007d3f2a-7104-41b8-8da6-296818068de6';
  $display->content['new-007d3f2a-7104-41b8-8da6-296818068de6'] = $pane;
  $display->panels['middle'][0] = 'new-007d3f2a-7104-41b8-8da6-296818068de6';
  $pane = new stdClass();
  $pane->pid = 'new-54870e57-9b71-46e2-8cc5-80ed0227ac38';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'presentation_single-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array(
    'logic' => 'or',
    'plugins' => array(
      0 => array(
        'context' => 'logged-in-user',
        'name' => 'role',
        'not' => FALSE,
        'settings' => array(
          'rids' => array(
            0 => 4,
            1 => 9,
            2 => 10,
            3 => 8,
            4 => 6,
            5 => 7,
            6 => 3,
          ),
        ),
      ),
      1 => array(
        'context' => array(
          0 => 'logged-in-user',
          1 => 'relationship_entity_from_field:field_speaker-node-user_1',
        ),
        'name' => 'compare_users',
        'not' => FALSE,
        'settings' => array(
          'equality' => '1',
        ),
      ),
      2 => array(
        'context' => array(
          0 => 'logged-in-user',
          1 => 'relationship_entity_from_schema:uid-node-user_1',
        ),
        'name' => 'compare_users',
        'not' => FALSE,
        'settings' => array(
          'equality' => '1',
        ),
      ),
    ),
  );
  $pane->configuration = array(
    'context' => array(
      1 => 'argument_entity_id:node_1',
    ),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '54870e57-9b71-46e2-8cc5-80ed0227ac38';
  $display->content['new-54870e57-9b71-46e2-8cc5-80ed0227ac38'] = $pane;
  $display->panels['middle'][1] = 'new-54870e57-9b71-46e2-8cc5-80ed0227ac38';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  return $export;
}
