<?php

namespace Drupal\session_enhancements\Access;

use Drupal\Core\Access\AccessResult;
use Drupal\Core\Access\AccessCheckInterface;
use Drupal\Core\Session\AccountInterface;
use Symfony\Component\Routing\Route;

/**
 * Access checker for view_mode_page routes - requires 'access review pages' permission.
 */
class ViewModePageAccessChecker implements AccessCheckInterface {

  /**
   * {@inheritdoc}
   */
  public function applies(Route $route) {
    return $route->hasRequirement('_view_mode_page_access');
  }

  /**
   * Checks access for view_mode_page routes - requires 'access review pages' permission.
   *
   * @param \Drupal\Core\Session\AccountInterface $account
   *   The user account to check access for.
   *
   * @return \Drupal\Core\Access\AccessResultInterface
   *   The access result.
   */
  public function access(AccountInterface $account) {
    // Check if the user has the 'access review pages' permission.
    if ($account->hasPermission('access review pages')) {
      return AccessResult::allowed()->addCacheContexts(['user.permissions']);
    }
    
    return AccessResult::forbidden('Access denied. You need permission to access review pages.')
      ->addCacheContexts(['user.permissions']);
  }

}
