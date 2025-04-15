<?php

/**
 * Implements theme_preprocess_HOOK().
 */
function scale_preprocess_user(&$variables) {
  $user = $variables['elements']['#user'];

  $speaker = get_user_speakers($user);
  $variables['user_speaker'] = $speaker;

  $sessions = get_user_sessions($user, $speaker);
  $variables['user_sessions'] = join(',', $sessions);
}

function get_user_speakers($user) {
  // Get speaker nodes that point to current user
  $query = \Drupal::entityQuery('node')
    ->condition('type', 'speaker');

  $group = $query->orConditionGroup()
    ->condition('field_user_account', $user->id(), 'IN')
    ->condition('uid', $user->id());

  $query->condition($group);
  $query->accessCheck(TRUE);

  $speakers = $query->execute();
  $speaker = reset($speakers);
  return $speaker;
}

function get_user_sessions($user, $speaker) {
  // Get session nodes that point to current user
  $query = \Drupal::entityQuery('node')
    ->condition('type', 'session');

  $group = $query->orConditionGroup()
    ->condition('field_speakers_ref', $speaker, 'IN')
    ->condition('uid', $user->id());

  $query->condition($group);
  $query->accessCheck(TRUE);

  $sessions = $query->execute();
  return $sessions;
}
