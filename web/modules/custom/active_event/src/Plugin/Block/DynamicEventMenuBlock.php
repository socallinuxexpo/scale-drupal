<?php

namespace Drupal\active_event\Plugin\Block;

use Drupal\system\Plugin\Block\SystemMenuBlock;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Cache\Cache;
use Drupal\node\NodeInterface;

/**
 * Provides an 'Active Event Menu' block.
 *
 * @Block(
 *   id = "active_event_menu_block",
 *   admin_label = @Translation("Active Event Menu"),
 *   category = @Translation("Active Event"),
 * )
 */
class DynamicEventMenuBlock extends SystemMenuBlock {

  /**
   * {@inheritdoc}
   */
  public function defaultConfiguration() {
    return [
        'menu' => 'main', // Set a default menu to prevent issues
      ] + parent::defaultConfiguration();
  }

  /**
   * {@inheritdoc}
   */
  public function build() {
    /** @var \Drupal\active_event\ActiveMenu $service */
    $service = \Drupal::service('active_event.menu');
    $menu_name = $service->getActiveEventMenuName();

    // Validate that the menu exists before trying to use it
    if ($menu_name) {
      // Set the menu in configuration so parent::build() can use it
      $this->configuration['menu'] = $menu_name;
      return parent::build();
    }

    return [];
  }

  /**
   * {@inheritdoc}
   */
  public function getCacheTags() {
    $tags = parent::getCacheTags();

    // Add cache tags for active event configuration
    $tags = Cache::mergeTags($tags, ['config:active_event.settings']);

    // Add cache tags for the current node if we're on a node page
    /** @var \Drupal\active_event\ActiveEvent $service */
    $service = \Drupal::service('active_event.event');
    $node = $service->getCurrentNode();
    if ($node) {
      $tags = Cache::mergeTags($tags, $node->getCacheTags());
    }

    // Add menu configuration cache tags
    $tags = Cache::mergeTags($tags, ['config:system.menu']);

    return $tags;
  }

  /**
   * {@inheritdoc}
   */
  public function getCacheContexts() {
    $contexts = parent::getCacheContexts();

    // Add URL context since the menu depends on the current node
    return Cache::mergeContexts($contexts, ['url.path']);
  }

  /**
   * {@inheritdoc}
   */
  public function getDerivativeId() {
    // Return the active event menu name so SystemMenuBlock can use it
    // for cache contexts and other operations
    /** @var \Drupal\active_event\ActiveMenu $service */
    $service = \Drupal::service('active_event.menu');
    return $service->getActiveEventMenuName() ?: [];
  }

}