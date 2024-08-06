<?php

/**
 * Implements theme_preprocess_HOOK().
 */
function scale_preprocess_node__article__summary_card(&$variables) {
  /** @var \Drupal\node\Entity\Node $ndoe */
  $node = $variables["elements"]["#node"];

  // Check if the node has a body field.
  if ($node->hasField('body') && !$node->get('body')->isEmpty()) {
    // Get the body field.
    $body_field = $node->get('body');

    // Check if there's a summary.
    if (!empty($body_field->summary)) {
      // Use the summary and strip HTML tags.
      $body_summary = \Drupal\Component\Utility\Xss::filter($body_field->summary);
    } else {
      // If no summary, use a trimmed version of the full body text.
      $full_body = $body_field->value;
      // Strip HTML tags.
      $stripped_body = \Drupal\Component\Utility\Xss::filter($full_body);
      // Trim the text (e.g., to 100 characters).
      $body_summary = \Drupal\Component\Utility\Unicode::truncate($stripped_body, 250, true, true);
    }

    // Make the variable available in the node template.
    $variables['body_summary'] = $body_summary;
  }
}
