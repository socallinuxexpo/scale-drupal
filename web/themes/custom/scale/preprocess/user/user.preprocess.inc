<?php

/**
 * Implements theme_preprocess_HOOK().
 */
function scale_preprocess_user(&$variables) {
  $user = $variables['elements']['#user'];

  $speakers = getUserSpeakerIds($user);
  $variables['user_speaker_ids'] = $speakers;

  $sessions = getUserSessionIds($user, $speakers);
  $variables['user_session_ids'] = join(',', $sessions);

  $variables['user'] = $user;
}

function getUserSpeakerIds($user) {
  // Get speaker nodes that point to current user
  $query = \Drupal::entityQuery('node')
    ->condition('type', 'speaker');

  $group = $query->orConditionGroup()
    ->condition('field_user_account', $user->id(), 'IN')
    ->condition('uid', $user->id());

  $query->condition($group);
  $query->accessCheck(TRUE);

  return $query->execute();
}

function getUserSessionIds($user, $speakers) {
  // Get session nodes that point to current user
  $query = \Drupal::entityQuery('node')
    ->condition('type', 'session');

  $group = $query->orConditionGroup()
//    ->condition('field_speakers_ref', $speakers, 'IN')
    ->condition('uid', $user->id());

  if(!empty($speakers)) {
    $group->condition('field_speakers_ref', $speakers, 'IN');
  }

  $query->condition($group);
  $query->accessCheck(TRUE);

  $sessions = $query->execute();
  return $sessions;
}


