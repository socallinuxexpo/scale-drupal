<?php

/**
 * Implements theme_preprocess_HOOK().
 */
function scale_preprocess_paragraph(&$variables) {
  $node = \Drupal::routeMatch()->getParameter('node');
  if ($node instanceof \Drupal\node\NodeInterface) {
    if ($node->hasField('field_scale_event')) {
      $variables['event']['id'] = $node->field_scale_event->target_id;
    }
  }
}
