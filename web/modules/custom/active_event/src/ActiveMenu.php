<?php

namespace Drupal\active_event;

use Drupal\Core\Config\ConfigFactoryInterface;
use Psr\Log\LoggerInterface;

class ActiveMenu {

  /**
   * The config factory.
   *
   * @var \Drupal\Core\Config\ConfigFactoryInterface
   */
  protected $configFactory;

  /**
   * The logger channel.
   *
   * @var ActiveEvent
   */
  protected $activeEvent;

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
   */
  public function __construct(ConfigFactoryInterface $config_factory, ActiveEvent $active_event, LoggerInterface $logger) {
    $this->configFactory = $config_factory;
    $this->activeEvent = $active_event;
    $this->logger = $logger;
  }

  /**
   * Returns the active event menu name.
   *
   * TODO: Add logs
   *
   * @return string|null
   *   The machine name of the active event menu, or NULL if not set.
   */
  public function getActiveEventMenuName(): ?string {
    $event_id = $this->activeEvent->getActiveEventIdFromContext();

    if (!$event_id) {
      return NULL;
    }

    $menu_name = $this->getMenuNameByEventId($event_id);

    if ($menu_name && $this->menuExists($menu_name)) {
      return $menu_name;
    }

    return NULL;
  }

  /**
   * Gets the menu name for a given event ID.
   *
   * @param  string  $event_id
   *   The event ID to search for.
   *
   * @return string|null
   *   The menu name (key) or NULL if not found.
   */
  public function getMenuNameByEventId($event_id) {
    // Get all menu configurations
    $config_names = $this->configFactory->listAll('system.menu.');

    foreach ($config_names as $config_name) {
      $config = $this->configFactory->get($config_name);
      $menu_event_id = $config->get('event');

      if ($menu_event_id == $event_id) {
        // Extract menu machine name from config name
        $menu_name = str_replace('system.menu.', '', $config_name);
        // Only return if menu actually exists
        if ($this->menuExists($menu_name)) {
          return $menu_name;
        }
      }
    }

    $this->logger->warning('No active event ID found in context or configuration.');
    return NULL;
  }

  /**
   * Check if a menu exists.
   *
   * @param  string  $menu_name
   *   The menu machine name.
   *
   * @return bool
   *   TRUE if menu exists, FALSE otherwise.
   */
  protected function menuExists($menu_name) {
    if (empty($menu_name)) {
      return FALSE;
    }

    $menu_storage = \Drupal::entityTypeManager()->getStorage('menu');
    $menu = $menu_storage->load($menu_name);
    if ($menu === NULL) {
      $this->logger->warning('Menu with machine name "@menu_name" does not exist.', ['@menu_name' => $menu_name]);
    }
    return $menu !== NULL;
  }

}