<?php

use Drupal\Core\Datetime\DrupalDateTime;

/**
 * Implements theme_preprocess_HOOK().
 */
function scale_preprocess_node__session(&$variables): void
{
    _session_dates($variables);
    _session_moderation_state_label($variables);
}

/**
 * Implements theme_preprocess_HOOK().
 */
function scale_preprocess_node__session__teaser(&$variables): void
{
    _session_dates($variables);
    _session_moderation_state_label($variables);
}

/**
 * Implements theme_preprocess_HOOK().
 */
function scale_preprocess_node__session__my_session(&$variables): void
{
    _session_dates($variables);
    _session_moderation_state_label($variables);
}

/**
 * Add moderation state label to variables.
 */
function _session_moderation_state_label(&$variables)
{
    /** @var \Drupal\node\Entity\Node $node */
    $node = $variables["elements"]["#node"];

    if ($node->hasField('moderation_state') &&
      !$node->get('moderation_state')->isEmpty()) {
        $moderation_state_value = $node->get('moderation_state')->value;

        // Load the workflow state configuration entity
        $workflow_state = \Drupal::entityTypeManager()
          ->getStorage('workflow')
          ->loadByProperties(['type' => 'content_moderation']);

        if (!empty($workflow_state)) {
            $workflow = reset($workflow_state);
            $states = $workflow->getTypePlugin()->getStates();

            if (isset($states[$moderation_state_value])) {
                $variables['moderation_state_label'] = $states[$moderation_state_value]->label();
            }
        }
    }
}

/**
 * Implements theme_preprocess_HOOK().
 *
 * @throws \Drupal\Core\TypedData\Exception\MissingDataException
 * @throws \DateInvalidTimeZoneException
 */
function _session_dates(&$variables)
{
    /** @var \Drupal\node\Entity\Node $node */
    $node = $variables["elements"]["#node"];

    if (!$node->get('field_time_slot')->isEmpty()) {
        /** @var \Drupal\datetime_range\Plugin\Field\FieldType\DateRangeItem $field_item */
        $field_item = $node->get('field_time_slot')->first();

        // Get the DrupalDateTime objects which include timezone info
        $start_date_time = $field_item->get('value')->getDateTime();
        $end_date_time = $field_item->get('end_value')->getDateTime();

        // Set the timezone to your site's timezone
        $timezone = new \DateTimeZone(date_default_timezone_get());
        $start_date_time->setTimezone($timezone);
        $end_date_time->setTimezone($timezone);

        $variables['start_date'] = $start_date_time->format('l, F j, Y - H:i');

        // Check if start and end dates are on different days
        if ($start_date_time->format('Y-m-d') !== $end_date_time->format('Y-m-d')) {
            // Multi-day session: show full date and time for end date
            $variables['end_date'] = $end_date_time->format('l, F j, Y - H:i');
        } else {
            // Same day session: show only time for end date
            $variables['end_date'] = $end_date_time->format('H:i');
        }
    }
}
