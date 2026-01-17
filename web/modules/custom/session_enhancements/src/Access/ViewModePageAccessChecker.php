<?php

namespace Drupal\session_enhancements\Access;

use Drupal\Core\Access\AccessResult;
use Drupal\Core\Access\AccessCheckInterface;
use Drupal\Core\Session\AccountInterface;
use Symfony\Component\Routing\Route;

/**
 * Access checker for view_mode_page routes - requires administrator role.
 */
class ViewModePageAccessChecker implements AccessCheckInterface {

  /**
   * {@inheritdoc}
   */
  public function applies(Route $route) {
    return $route->hasRequirement('_view_mode_page_access');
  }

  /**
   * Checks access for view_mode_page routes - requires administrator role.
   *
   * @param \Drupal\Core\Session\AccountInterface $account
   *   The user account to check access for.
   *
   * @return \Drupal\Core\Access\AccessResultInterface
   *   The access result.
   */
  public function access(AccountInterface $account) {
    // Check if the user has the administrator role.
    $user_roles = $account->getRoles();
    $has_admin_role = in_array('administrator', $user_roles);
    
    if ($has_admin_role) {
      return AccessResult::allowed()->addCacheContexts(['user.roles']);
    }
    
    return AccessResult::forbidden('Access restricted to administrators.')
      ->addCacheContexts(['user.roles']);
  }

}
