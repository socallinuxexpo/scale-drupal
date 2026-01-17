<?php

namespace Drupal\session_enhancements\Routing;

use Drupal\Core\Routing\RouteSubscriberBase;
use Symfony\Component\Routing\RouteCollection;

/**
 * Listens to the dynamic route events.
 */
class RouteSubscriber extends RouteSubscriberBase {

  /**
   * {@inheritdoc}
   */
  protected function alterRoutes(RouteCollection $collection) {
    // Alter the view_mode_page.display_entity route to use our custom access checker.
    if ($route = $collection->get('view_mode_page.display_entity')) {
      // Get current requirements and remove the permission requirement.
      $requirements = $route->getRequirements();
      unset($requirements['_permission']);
      
      // Add our custom access checker requirement.
      $requirements['_view_mode_page_access'] = 'TRUE';
      
      // Set the updated requirements.
      $route->setRequirements($requirements);
    }
  }

}
