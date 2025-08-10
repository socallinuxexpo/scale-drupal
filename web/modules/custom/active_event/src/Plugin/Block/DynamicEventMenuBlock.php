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
            'fallback_menu' => 'main',
            'menu' => 'main', // Set a default menu to prevent issues
          ] + parent::defaultConfiguration();
    }

    /**
     * {@inheritdoc}
     */
    public function blockForm($form, FormStateInterface $form_state) {
        $form = parent::blockForm($form, $form_state);

        // Override the menu selection to show it's automatically determined
        $form['menu']['#description'] = $this->t('The menu will be automatically determined based on the active event from the current node\'s field_scale_event field, or the global active event configuration. If no menu is associated with the active event, the fallback menu will be used.');
        $form['menu']['#disabled'] = TRUE;

        // Add fallback menu selection
        $menu_storage = \Drupal::entityTypeManager()->getStorage('menu');
        $menus = $menu_storage->loadMultiple();
        $menu_options = [];
        foreach ($menus as $menu_id => $menu) {
            $menu_options[$menu_id] = $menu->label();
        }

        $form['fallback_menu'] = [
          '#type' => 'select',
          '#title' => $this->t('Fallback menu'),
          '#description' => $this->t('This menu will be displayed if no menu is associated with the active event.'),
          '#options' => $menu_options,
          '#default_value' => $this->configuration['fallback_menu'],
          '#weight' => -10,
        ];

        return $form;
    }

    /**
     * {@inheritdoc}
     */
    public function blockSubmit($form, FormStateInterface $form_state) {
        parent::blockSubmit($form, $form_state);
        $this->configuration['fallback_menu'] = $form_state->getValue('fallback_menu');
    }

    /**
     * {@inheritdoc}
     */
    public function build() {
        $menu_name = $this->getActiveEventMenu();

        // Validate that the menu exists before trying to use it
        if ($menu_name && $this->menuExists($menu_name)) {
            // Set the menu in configuration so parent::build() can use it
            $this->configuration['menu'] = $menu_name;
            return parent::build();
        }

        return [];
    }

    /**
     * Check if a menu exists.
     *
     * @param string $menu_name
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
        return $menu !== NULL;
    }

    /**
     * Gets the current node from the route.
     *
     * @return \Drupal\node\NodeInterface|null
     *   The current node or NULL if not on a node page.
     */
    protected function getCurrentNode() {
        $route_match = \Drupal::routeMatch();

        // Check if we're on a node page
        if ($route_match->getRouteName() == 'entity.node.canonical') {
            $node = $route_match->getParameter('node');
            if ($node instanceof NodeInterface) {
                return $node;
            }
        }

        // Check if we're on a node revision page
        if ($route_match->getRouteName() == 'entity.node.revision') {
            $node = $route_match->getParameter('node_revision');
            if ($node instanceof NodeInterface) {
                return $node;
            }
        }

        return NULL;
    }

    /**
     * Gets the active event ID from current node or configuration.
     *
     * @return string|null
     *   The active event ID or NULL if not found.
     */
    protected function getActiveEventId() {
        // First, try to get the event from the current node's field_scale_event field
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

        // Fallback to the global active event configuration
        return \Drupal::config('active_event.settings')->get('active_event');
    }

    /**
     * Gets the menu associated with the active event.
     *
     * @return string|null
     *   The menu machine name or NULL if not found.
     */
    protected function getActiveEventMenu() {
        $active_event_id = $this->getActiveEventId();

        if (!$active_event_id) {
            // No active event found, return fallback menu
            $fallback = $this->configuration['fallback_menu'] ?? NULL;
            if ($fallback && $this->menuExists($fallback)) {
                return $fallback;
            }
            return NULL;
        }

        // Create a cache ID that includes the event ID for proper cache segregation
        $cid = 'active_event:menu_mapping:' . $active_event_id;

        // Try to get from cache first
        if ($cache = \Drupal::cache()->get($cid)) {
            $menu_name = $cache->data;
        } else {
            $menu_name = $this->getMenuForEvent($active_event_id);
            // Cache for 1 hour
            \Drupal::cache()->set($cid, $menu_name, time() + 3600, ['config:system.menu']);
        }

        if ($menu_name && $this->menuExists($menu_name)) {
            return $menu_name;
        }

        // Return fallback menu if configured and it exists
        $fallback = $this->configuration['fallback_menu'] ?? NULL;
        if ($fallback && $this->menuExists($fallback)) {
            return $fallback;
        }

        return NULL;
    }

    /**
     * Gets the menu machine name for a specific event ID.
     *
     * @param string $event_id
     *   The event ID.
     *
     * @return string|null
     *   The menu machine name or NULL if not found.
     */
    protected function getMenuForEvent($event_id) {
        // Get all menu configurations
        $config_factory = \Drupal::configFactory();
        $config_names = $config_factory->listAll('system.menu.');

        foreach ($config_names as $config_name) {
            $config = $config_factory->get($config_name);
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

        return NULL;
    }

    /**
     * Builds a mapping of event IDs to menu machine names.
     *
     * @return array
     *   Array mapping event IDs to menu machine names.
     */
    protected function buildMenuMapping() {
        $mapping = [];

        // Get all menu configurations
        $config_factory = \Drupal::configFactory();
        $config_names = $config_factory->listAll('system.menu.');

        foreach ($config_names as $config_name) {
            $config = $config_factory->get($config_name);
            $event_id = $config->get('event');

            if ($event_id) {
                // Extract menu machine name from config name
                $menu_name = str_replace('system.menu.', '', $config_name);
                // Only include if menu actually exists
                if ($this->menuExists($menu_name)) {
                    $mapping[$event_id] = $menu_name;
                }
            }
        }

        return $mapping;
    }

    /**
     * {@inheritdoc}
     */
    public function getCacheTags() {
        $tags = parent::getCacheTags();

        // Add cache tags for active event configuration
        $tags = Cache::mergeTags($tags, ['config:active_event.settings']);

        // Add cache tags for the current node if we're on a node page
        $node = $this->getCurrentNode();
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
        $contexts = Cache::mergeContexts($contexts, ['url.path']);

        return $contexts;
    }

    /**
     * {@inheritdoc}
     */
    public function getDerivativeId() {
        // Return the active event menu name so SystemMenuBlock can use it
        // for cache contexts and other operations
        return $this->getActiveEventMenu() ?: $this->configuration['fallback_menu'];
    }

}