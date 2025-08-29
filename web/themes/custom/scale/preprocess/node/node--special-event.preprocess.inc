<?php

use Drupal\Core\Datetime\DrupalDateTime;

/**
 * Implements theme_preprocess_HOOK().
 *
 * @throws \DateInvalidTimeZoneException
 */
function scale_preprocess_node__special_event(&$variables) {
  /** @var \Drupal\node\Entity\Node $node */
  $node = $variables["elements"]["#node"];

  if(!$node->get('field_when')->isEmpty()) {
    /** @var \Drupal\datetime_range\Plugin\Field\FieldType\DateRangeItem $field_item */
    $field_item = $node->get('field_when')->first();

    // Get the DrupalDateTime objects which include timezone info
    $start_date_time = $field_item->get('value')->getDateTime();
    $end_date_time = $field_item->get('end_value')->getDateTime();

    // Set the timezone to your site's timezone
    $timezone = new \DateTimeZone(date_default_timezone_get());
    $start_date_time->setTimezone($timezone);
    $end_date_time->setTimezone($timezone);

    $variables['start_date'] = $start_date_time->format('l, F j, Y - H:i');
    $variables['end_date'] = $end_date_time->format('H:i');
  }
}
