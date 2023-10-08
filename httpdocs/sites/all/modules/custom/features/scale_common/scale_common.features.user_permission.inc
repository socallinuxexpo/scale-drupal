<?php

/**
 * @file
 * scale_common.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function scale_common_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_room'.
  $permissions['create field_room'] = array(
    'name' => 'create field_room',
    'roles' => array(
      'administrator' => 'administrator',
      'presentation editor' => 'presentation editor',
      'special events editor' => 'special events editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_scale_event'.
  $permissions['create field_scale_event'] = array(
    'name' => 'create field_scale_event',
    'roles' => array(
      'administrator' => 'administrator',
      'blogger' => 'blogger',
      'editor' => 'editor',
      'presentation editor' => 'presentation editor',
      'special events editor' => 'special events editor',
      'sponsorship editor' => 'sponsorship editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_time'.
  $permissions['create field_time'] = array(
    'name' => 'create field_time',
    'roles' => array(
      'administrator' => 'administrator',
      'presentation editor' => 'presentation editor',
      'special events editor' => 'special events editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_room'.
  $permissions['edit field_room'] = array(
    'name' => 'edit field_room',
    'roles' => array(
      'administrator' => 'administrator',
      'presentation editor' => 'presentation editor',
      'special events editor' => 'special events editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_scale_event'.
  $permissions['edit field_scale_event'] = array(
    'name' => 'edit field_scale_event',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'presentation editor' => 'presentation editor',
      'special events editor' => 'special events editor',
      'sponsorship editor' => 'sponsorship editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_time'.
  $permissions['edit field_time'] = array(
    'name' => 'edit field_time',
    'roles' => array(
      'administrator' => 'administrator',
      'presentation editor' => 'presentation editor',
      'special events editor' => 'special events editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_room'.
  $permissions['edit own field_room'] = array(
    'name' => 'edit own field_room',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_scale_event'.
  $permissions['edit own field_scale_event'] = array(
    'name' => 'edit own field_scale_event',
    'roles' => array(
      'administrator' => 'administrator',
      'blogger' => 'blogger',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_time'.
  $permissions['edit own field_time'] = array(
    'name' => 'edit own field_time',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_room'.
  $permissions['view field_room'] = array(
    'name' => 'view field_room',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_scale_event'.
  $permissions['view field_scale_event'] = array(
    'name' => 'view field_scale_event',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'editor' => 'editor',
      'presentation editor' => 'presentation editor',
      'special events editor' => 'special events editor',
      'sponsorship editor' => 'sponsorship editor',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_time'.
  $permissions['view field_time'] = array(
    'name' => 'view field_time',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_room'.
  $permissions['view own field_room'] = array(
    'name' => 'view own field_room',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_scale_event'.
  $permissions['view own field_scale_event'] = array(
    'name' => 'view own field_scale_event',
    'roles' => array(
      'administrator' => 'administrator',
      'blogger' => 'blogger',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_time'.
  $permissions['view own field_time'] = array(
    'name' => 'view own field_time',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
