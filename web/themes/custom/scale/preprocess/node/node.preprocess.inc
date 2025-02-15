<?php

/**
 * Implements theme_preprocess_HOOK().
 */
function scale_preprocess_node(&$variables): void {
  $node = $variables['node'];
  if ($node->hasField('field_scale_event')) {
    $variables['event']['id'] = $node->field_scale_event->target_id;
  }
}
