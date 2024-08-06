<?php

/**
 * Implements theme_preprocess_HOOK().
 */
function scale_preprocess_node__session(&$variables) {
  /** @var \Drupal\node\Entity\Node $ndoe */
  $node = $variables["elements"]["#node"];

  // Get speakers and render the nodes using the listing view mode
  $speakers = $node->get('field_speakers_ref')->referencedEntities();
  $speaker_nodes = [];
  foreach ($speakers as $speaker) {
    $speaker_nodes[] = \Drupal::entityTypeManager()
      ->getViewBuilder('node')
      ->view($speaker, 'listing_small');
  }

  $variables['content']['speakers'] = $speaker_nodes;
}
