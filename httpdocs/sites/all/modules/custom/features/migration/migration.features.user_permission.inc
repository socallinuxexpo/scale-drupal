<?php

/**
 * @file
 * migration.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function migration_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'configure basic auth'.
  $permissions['configure basic auth'] = array(
    'name' => 'configure basic auth',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'basic_auth',
  );

  return $permissions;
}
