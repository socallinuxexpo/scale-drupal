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

  // Initialize default values
  $earliest_start_date = date('Y-m-d');
  $latest_end_date = date('Y-m-d');
  $earliest_start_time = '08:00:00';
  $latest_end_time = '23:59:59';

  // Filter out empty values before processing
  $start_dates = array_filter($start_dates, function($date) {
    return !empty($date);
  });
  $end_dates = array_filter($end_dates, function($date) {
    return !empty($date);
  });

  // Only process dates if we have valid agenda items
  if (!empty($start_dates) && !empty($end_dates)) {
    // Convert to DateTime for comparison
    $earliest_start = min(array_map('strtotime', $start_dates));
    $latest_end = max(array_map('strtotime', $end_dates));

    // Convert back to readable date format
    $earliest_start_date = date('Y-m-d', $earliest_start);
    $latest_end_date = date('Y-m-d', $latest_end);

    // Calculate time ranges for better schedule display
    $start_times = [];
    $end_times = [];
    
    foreach ($agenda as $session) {
      if (!empty($session['start']) && !empty($session['end'])) {
        $start_times[] = date('H:i:s', strtotime($session['start']));
        $end_times[] = date('H:i:s', strtotime($session['end']));
      }
    }
    
    if (!empty($start_times) && !empty($end_times)) {
      // Find earliest start time and latest end time
      $earliest_start_time = min($start_times);
      $latest_end_time = max($end_times);
      
      // Round down start time to nearest 30 minutes for better display
      $start_hour = (int) date('H', strtotime($earliest_start_time));
      $start_minute = (int) date('i', strtotime($earliest_start_time));
      $rounded_start_minute = $start_minute < 30 ? 0 : 30;
      if ($start_minute > 0 && $start_minute < 30) {
        // Round down to the hour
        $rounded_start_minute = 0;
      } elseif ($start_minute > 30) {
        // Round down to 30 minutes
        $rounded_start_minute = 30;
      }
      $earliest_start_time = sprintf('%02d:%02d:00', $start_hour, $rounded_start_minute);
      
      // Round up end time to nearest 30 minutes for better display
      $end_hour = (int) date('H', strtotime($latest_end_time));
      $end_minute = (int) date('i', strtotime($latest_end_time));
      if ($end_minute > 0 && $end_minute <= 30) {
        // Round up to 30 minutes
        $rounded_end_minute = 30;
      } elseif ($end_minute > 30) {
        // Round up to next hour
        $end_hour++;
        $rounded_end_minute = 0;
      } else {
        $rounded_end_minute = $end_minute;
      }
      
      // Handle hour overflow
      if ($end_hour >= 24) {
        $end_hour = 23;
        $rounded_end_minute = 59;
      }
      
      $latest_end_time = sprintf('%02d:%02d:00', $end_hour, $rounded_end_minute);
    }
  }

  $variables['#attached']['drupalSettings']['schedule']['tracks'] = $tracks;
  $variables['#attached']['drupalSettings']['schedule']['agenda'] = $agenda;
  $variables['#attached']['drupalSettings']['schedule']['range'] = [
    'start' => $earliest_start_date,
    'end' => $latest_end_date,
  ];
  $variables['#attached']['drupalSettings']['schedule']['timeRange'] = [
    'start' => $earliest_start_time,
    'end' => $latest_end_time,
  ];
}
