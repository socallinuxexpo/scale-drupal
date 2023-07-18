<?php

/**
 * @file
 * scale_presentation.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function scale_presentation_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_audio_video'.
  $permissions['create field_audio_video'] = array(
    'name' => 'create field_audio_video',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'presentation editor' => 'presentation editor',
      'special events editor' => 'special events editor',
      'sponsorship editor' => 'sponsorship editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_overflow_room'.
  $permissions['create field_overflow_room'] = array(
    'name' => 'create field_overflow_room',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'presentation editor' => 'presentation editor',
      'special events editor' => 'special events editor',
      'sponsorship editor' => 'sponsorship editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_presentation_link'.
  $permissions['create field_presentation_link'] = array(
    'name' => 'create field_presentation_link',
    'roles' => array(
      'editor' => 'editor',
      'presentation editor' => 'presentation editor',
      'speaker' => 'speaker',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_presentation_status'.
  $permissions['create field_presentation_status'] = array(
    'name' => 'create field_presentation_status',
    'roles' => array(
      'administrator' => 'administrator',
      'presentation editor' => 'presentation editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_presentation_to_upload'.
  $permissions['create field_presentation_to_upload'] = array(
    'name' => 'create field_presentation_to_upload',
    'roles' => array(
      'editor' => 'editor',
      'presentation editor' => 'presentation editor',
      'speaker' => 'speaker',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_audio_video'.
  $permissions['edit field_audio_video'] = array(
    'name' => 'edit field_audio_video',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'presentation editor' => 'presentation editor',
      'special events editor' => 'special events editor',
      'sponsorship editor' => 'sponsorship editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_overflow_room'.
  $permissions['edit field_overflow_room'] = array(
    'name' => 'edit field_overflow_room',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'presentation editor' => 'presentation editor',
      'special events editor' => 'special events editor',
      'sponsorship editor' => 'sponsorship editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_presentation_link'.
  $permissions['edit field_presentation_link'] = array(
    'name' => 'edit field_presentation_link',
    'roles' => array(
      'editor' => 'editor',
      'presentation editor' => 'presentation editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_presentation_status'.
  $permissions['edit field_presentation_status'] = array(
    'name' => 'edit field_presentation_status',
    'roles' => array(
      'administrator' => 'administrator',
      'presentation editor' => 'presentation editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_presentation_to_upload'.
  $permissions['edit field_presentation_to_upload'] = array(
    'name' => 'edit field_presentation_to_upload',
    'roles' => array(
      'editor' => 'editor',
      'presentation editor' => 'presentation editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_audio_video'.
  $permissions['edit own field_audio_video'] = array(
    'name' => 'edit own field_audio_video',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_overflow_room'.
  $permissions['edit own field_overflow_room'] = array(
    'name' => 'edit own field_overflow_room',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_presentation_link'.
  $permissions['edit own field_presentation_link'] = array(
    'name' => 'edit own field_presentation_link',
    'roles' => array(
      'editor' => 'editor',
      'presentation editor' => 'presentation editor',
      'speaker' => 'speaker',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_presentation_status'.
  $permissions['edit own field_presentation_status'] = array(
    'name' => 'edit own field_presentation_status',
    'roles' => array(
      'administrator' => 'administrator',
      'presentation editor' => 'presentation editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_presentation_to_upload'.
  $permissions['edit own field_presentation_to_upload'] = array(
    'name' => 'edit own field_presentation_to_upload',
    'roles' => array(
      'editor' => 'editor',
      'presentation editor' => 'presentation editor',
      'speaker' => 'speaker',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_audio_video'.
  $permissions['view field_audio_video'] = array(
    'name' => 'view field_audio_video',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_overflow_room'.
  $permissions['view field_overflow_room'] = array(
    'name' => 'view field_overflow_room',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
      'presentation editor' => 'presentation editor',
      'special events editor' => 'special events editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_presentation_link'.
  $permissions['view field_presentation_link'] = array(
    'name' => 'view field_presentation_link',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_presentation_status'.
  $permissions['view field_presentation_status'] = array(
    'name' => 'view field_presentation_status',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'presentation editor' => 'presentation editor',
      'presentation reviewer' => 'presentation reviewer',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_presentation_to_upload'.
  $permissions['view field_presentation_to_upload'] = array(
    'name' => 'view field_presentation_to_upload',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_audio_video'.
  $permissions['view own field_audio_video'] = array(
    'name' => 'view own field_audio_video',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_overflow_room'.
  $permissions['view own field_overflow_room'] = array(
    'name' => 'view own field_overflow_room',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_presentation_link'.
  $permissions['view own field_presentation_link'] = array(
    'name' => 'view own field_presentation_link',
    'roles' => array(
      'editor' => 'editor',
      'presentation editor' => 'presentation editor',
      'speaker' => 'speaker',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_presentation_status'.
  $permissions['view own field_presentation_status'] = array(
    'name' => 'view own field_presentation_status',
    'roles' => array(
      'administrator' => 'administrator',
      'presentation editor' => 'presentation editor',
      'speaker' => 'speaker',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_presentation_to_upload'.
  $permissions['view own field_presentation_to_upload'] = array(
    'name' => 'view own field_presentation_to_upload',
    'roles' => array(
      'editor' => 'editor',
      'presentation editor' => 'presentation editor',
      'speaker' => 'speaker',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
