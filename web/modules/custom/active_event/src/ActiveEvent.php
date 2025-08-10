<?php

namespace Drupal\active_event;

use Drupal\Core\Config\ConfigFactoryInterface;
use Drupal\Core\Routing\RouteMatchInterface;
use Drupal\node\NodeInterface;
use Psr\Log\LoggerInterface;

class ActiveEvent {

  /**
   * The config factory.
   *
   * @var \Drupal\Core\Config\ConfigFactoryInterface
   */
  protected $configFactory;

  /**
   * The route match service.
   *
   * @var \Drupal\Core\Routing\RouteMatchInterface
   */
  protected $routeMatch;

  /**
   * The logger channel.
   *
   * @var \Psr\Log\LoggerInterface
   */
  protected $logger;

  /**
   * Constructs an ActiveEvent object.
   *
   * @param  \Drupal\Core\Config\ConfigFactoryInterface  $config_factory
   *   The config factory.
   * @param  \Drupal\Core\Routing\RouteMatchInterface  $route_match
   *   The route match service.
   */
  public function __construct(
    ConfigFactoryInterface $config_factory,
    RouteMatchInterface $route_match,
    LoggerInterface $logger
  ) {
    $this->configFactory = $config_factory;
    $this->routeMatch = $route_match;
    $this->logger = $logger;
  }

  /**
   * This method retrieves the active event ID from the site configuration.
   *
   * @see /admin/config/system/site-information
   * */
  public function getActiveEventId() {
    return $this->configFactory
        ->get('active_event.settings')
        ->get('active_event') ?: NULL;
  }

  /**
   * Returns the ID of the currently active event based on the context of the
   * current node.
   *
   * This method checks if the current node has a field that references an event
   * and returns that event's ID if available. If not, it falls back to the
   * active event ID configured in site settings.
   *
   * @return string|null
   *   The active event ID or NULL if not found.
   */
  public function getActiveEventIdFromContext() {
    // Try to get the event from the current node's field_scale_event field
    $node = $this->getCurrentNode();
    if ($node && $node->hasField('field_scale_event')) {
      $event_field = $node->get('field_scale_event');
      if (!$event_field->isEmpty()) {
        // Get the target ID from the entity reference field
        $event_id = $event_field->target_id;
        if ($event_id) {
          return $event_id;
        }
      }
    }


    $id = $this->getActiveEventId();
    if ($id) {
      return $id;
    } else {
      $this->logger->warning('No active event ID found in context or configuration.');
      return NULL;
    }
  }

  /**
   * Gets the current node from the route.
   *
   * @return \Drupal\node\NodeInterface|null
   *   The current node or NULL if not on a node page.
   */
  public function getCurrentNode() {
    // Check if we're on a node page
    if ($this->routeMatch->getRouteName() == 'entity.node.canonical') {
      $node = $this->routeMatch->getParameter('node');
      if ($node instanceof NodeInterface) {
        return $node;
      }
    }

    // Check if we're on a node revision page
    if ($this->routeMatch->getRouteName() == 'entity.node.revision') {
      $node = $this->routeMatch->getParameter('node_revision');
      if ($node instanceof NodeInterface) {
        return $node;
      }
    }

    return NULL;
  }

}