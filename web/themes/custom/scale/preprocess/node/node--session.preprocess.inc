<?php

use Drupal\Core\Datetime\DrupalDateTime;

/**
 * Implements theme_preprocess_HOOK().
 */
function scale_preprocess_node__session(&$variables) {
  /** @var \Drupal\node\Entity\Node $node */
  $node = $variables["elements"]["#node"];

  if(!$node->get('field_time_slot')->isEmpty()) {
    $start_date = $node->get('field_time_slot')->value;
    $end_date = $node->get('field_time_slot')->end_value;

    $start_date_time = new DrupalDateTime($start_date);
    $end_date_time = new DrupalDateTime($end_date);

    $variables['start_date'] = $start_date_time->format('l, F j, Y - H:i');
    $variables['end_date'] = $end_date_time->format('H:i');
  }
}
