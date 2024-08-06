<?php

/**
 * Implements theme_preprocess_HOOK().
 */
function scale_preprocess_node__article(&$variables) {
  /** @var \Drupal\node\Entity\Node $ndoe */
  $node = $variables["elements"]["#node"];
}
