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
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__hide_presentations_from_public';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'http_response';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'hide presentations from public',
    'contexts' => array(),
    'relationships' => array(),
    'code' => '404',
    'destination' => '',
    'name' => 'hide_presentations_from_public',
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 4,
              1 => 9,
              2 => 10,
              3 => 8,
              4 => 7,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => TRUE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'presentation' => 'presentation',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'entity_field_value:node:presentation:field_scale_event',
          'settings' => array(
            'field_scale_event' => array(
              'und' => array(
                0 => array(
                  'tid' => '1644',
                ),
              ),
            ),
            'field_scale_event_tid' => array(
              0 => '1644',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
    ),
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
    'title' => 'Presentation review',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'User from Node (on Node: Speaker [field_speaker])',
        'keyword' => 'speaker',
        'name' => 'entity_from_field:field_speaker-node-user',
        'delta' => '0',
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'User from Node (on node.node_author)',
        'keyword' => 'author',
        'name' => 'entity_from_schema:uid-node-user',
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'presentation' => 'presentation',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 4,
              1 => 9,
              2 => 3,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'node_status',
          'settings' => NULL,
          'context' => 'argument_entity_id:node_1',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
    'name' => 'presentation-review',
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
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 4,
            1 => 9,
            2 => 3,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'build_mode' => '2',
    'widget_name' => '1',
    'context' => 'argument_entity_id:node_1',
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
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
        'name' => 'entity_field_value:node:presentation:field_presentation_status',
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
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
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
    'plugins' => array(
      0 => array(
        'name' => 'role',
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
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'compare_users',
        'settings' => array(
          'equality' => '1',
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'relationship_entity_from_field:field_speaker-node-user_1',
        ),
        'not' => FALSE,
      ),
      2 => array(
        'name' => 'compare_users',
        'settings' => array(
          'equality' => '1',
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'relationship_entity_from_schema:uid-node-user_1',
        ),
        'not' => FALSE,
      ),
      3 => array(
        'name' => 'entity_field_value:node:presentation:field_presentation_status',
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
        'context' => 'argument_entity_id:node_1',
        'not' => TRUE,
      ),
    ),
    'logic' => 'or',
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
    'mode' => '1',
    'comments_per_page' => '50',
    'context' => 'argument_entity_id:node_1',
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
    'title' => 'Presentation page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'User from Node (on Node: Speaker [field_speaker])',
        'keyword' => 'speaker',
        'name' => 'entity_from_field:field_speaker-node-user',
        'delta' => '0',
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'User from Node (on node.node_author)',
        'keyword' => 'author',
        'name' => 'entity_from_schema:uid-node-user',
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'presentation' => 'presentation',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
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
  $display->uuid = '33b138ec-a7af-4544-888e-0cee6b00e8da';
  $display->storage_type = '';
  $display->storage_id = '';
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
        'name' => 'entity_field_value:node:presentation:field_presentation_status',
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
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
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
    'plugins' => array(
      0 => array(
        'name' => 'role',
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
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'compare_users',
        'settings' => array(
          'equality' => '1',
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'relationship_entity_from_field:field_speaker-node-user_1',
        ),
        'not' => FALSE,
      ),
      2 => array(
        'name' => 'compare_users',
        'settings' => array(
          'equality' => '1',
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'relationship_entity_from_schema:uid-node-user_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'or',
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
