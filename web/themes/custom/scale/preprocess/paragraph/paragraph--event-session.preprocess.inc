<?php

/**
 * Implements theme_preprocess_HOOK().
 */
function scale_preprocess_paragraph__event_sessions(&$variables) {
  // Load the event selected
  $event_id = $variables["event"]["id"];

  $variables['#attached']['drupalSettings']['schedule']['event_id'] = $event_id;

  // Load view and pass event node nid as argument
  $view = \Drupal\views\Views::getView('schedule_json');
  $view->setDisplay('json');
  $view->setArguments([$event_id]);
  $view->preExecute();
  $view->execute();

  $render_array = $view->buildRenderable('json', [$event_id]);
  $rendered = \Drupal::service('renderer')->renderRoot($render_array);
  $json = json_decode($rendered);

  $tracks = [];
  $agenda = [];
  foreach ($json as $result) {
    $tracks[] = [
      'id' => $result->room_id,
      'title' => $result->room_name,
    ];

    $agenda[] = [
      'id' => $result->nid,
      'resourceId' => $result->room_id,
      'title' => $result->title,
      'start' => $result->start,
      'end' => $result->end,
      'color' => $result->color,
      'extendedProps' => [
        'speakers' => $result->speakers,
        'url' => $result->url,
        'range_str' => $result->range_str,
      ],
    ];
  }

  // Finding the earliest start date and the latest end date
  $start_dates = array_column($agenda, 'start');
  $end_dates = array_column($agenda, 'end');

  // Convert to DateTime for comparison
  $earliest_start = min(array_map('strtotime', $start_dates));
  $latest_end = max(array_map('strtotime', $end_dates));

  // Convert back to readable date format
  $earliest_start_date = date('Y-m-d', $earliest_start);
  $latest_end_date = date('Y-m-d', $latest_end);

  $variables['#attached']['drupalSettings']['schedule']['tracks'] = $tracks;
  $variables['#attached']['drupalSettings']['schedule']['agenda'] = $agenda;
  $variables['#attached']['drupalSettings']['schedule']['range'] = [
    'start' => $earliest_start_date,
    'end' => $latest_end_date,
  ];
}
