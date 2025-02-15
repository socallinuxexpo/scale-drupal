<?php

/**
 * Implements theme_preprocess_HOOK().
 */
function scale_preprocess_user(&$variables) {
  $user = $variables['elements']['#user'];

  // Get speaker nodes that point to current user
  $query = \Drupal::entityQuery('node')
    ->condition('type', 'speaker')
    ->accessCheck(TRUE)
    ->condition('field_user_account', $user->id());

  $speakers = $query->execute();
  $speaker = reset($speakers);

  $variables['user_speaker'] = $speaker;

  // Get session nodes that point to current user
  $query = \Drupal::entityQuery('node')
    ->condition('type', 'session')
    ->accessCheck(TRUE)
    ->condition('field_speakers_ref', $speaker, 'IN');

  $sessions = $query->execute();

  $variables['user_sessions'] = join(',', $sessions);
}
