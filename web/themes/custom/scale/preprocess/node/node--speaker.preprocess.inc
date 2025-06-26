<?php

/**
 * Implements theme_preprocess_HOOK().
 */
function scale_preprocess_node__speaker(&$variables) {
  /** @var \Drupal\node\Entity\Node $ndoe */
  $node = $variables["elements"]["#node"];

  // If user is the author of the current node, add variable
  $variables['is_author'] = \Drupal::currentUser()->id() === $node->getOwnerId();
}
