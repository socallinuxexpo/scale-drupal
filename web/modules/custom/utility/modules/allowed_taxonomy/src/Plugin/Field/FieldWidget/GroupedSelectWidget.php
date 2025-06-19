<?php

namespace Drupal\allowed_taxonomy\Plugin\Field\FieldWidget;

use Drupal\Core\Entity\EntityTypeManagerInterface;
use Drupal\Core\Entity\FieldableEntityInterface;
use Drupal\Core\Field\Plugin\Field\FieldWidget\OptionsSelectWidget;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Routing\RouteMatchInterface;
use Symfony\Component\DependencyInjection\ContainerInterface;

/**
 * Plugin implementation of the 'grouped_select_widget' widget.
 *
 * @FieldWidget(
 *   id = "grouped_select_widget",
 *   label = @Translation("Grouped select (active/inactive)"),
 *   field_types = {
 *     "entity_reference"
 *   }
 * )
 */
class GroupedSelectWidget extends OptionsSelectWidget {

  /**
   * The entity type manager.
   */
  protected EntityTypeManagerInterface $entityTypeManager;

  /**
   * The route match service.
   */
  protected RouteMatchInterface $routeMatch;

  /**
   * {@inheritdoc}
   */
  public static function create(ContainerInterface $container, array $configuration, $plugin_id, $plugin_definition) {
    $instance = parent::create($container, $configuration, $plugin_id, $plugin_definition);
    $instance->entityTypeManager = $container->get('entity_type.manager');
    $instance->routeMatch = $container->get('current_route_match');
    return $instance;
  }

  /**
   * {@inheritdoc}
   */
  protected function supportsGroups(): bool {
    return TRUE;
  }

  /**
   * {@inheritdoc}
   */
  protected function getOptions(FieldableEntityInterface $entity): array {
    if (isset($this->options)) {
      return $this->options;
    }

    $this->options = [];
    $bundles = $this->getTargetBundles();

    foreach ($bundles as $bundle) {
      $options = $bundle === 'event'
        ? $this->getEventOptions()
        : $this->getTaxonomyOptions($bundle);

      $this->options = array_merge($this->options, $options);
    }

    return $this->options;
  }

  /**
   * Gets target bundles from field settings.
   */
  private function getTargetBundles(): array {
    $handler_settings = $this->fieldDefinition->getSetting('handler_settings');
    return $handler_settings['target_bundles'] ?? [];
  }

  /**
   * Gets grouped options for event entities.
   */
  private function getEventOptions(): array {
    $entities = $this->entityTypeManager
      ->getStorage('node')
      ->loadByProperties(['type' => 'event']);

    return $this->buildGroupedOptions($entities, function ($entity) {
      return $entity->hasField('field_event_date')
        && $entity->get('field_event_date')->value > date('Y-m-d');
    });
  }

  /**
   * Gets grouped options for taxonomy terms.
   */
  private function getTaxonomyOptions(string $bundle): array {
    $entities = $this->entityTypeManager
      ->getStorage('taxonomy_term')
      ->loadByProperties(['vid' => $bundle]);

    return $this->buildGroupedOptions($entities, function ($entity) {
      return $entity->hasField('field_active')
        && $entity->get('field_active')->value;
    });
  }

  /**
   * Builds grouped options array from entities.
   */
  private function buildGroupedOptions(array $entities, callable $isActiveCallback): array {
    $active = [];
    $inactive = [];
    $isEditForm = $this->routeMatch->getRouteName() === 'entity.node.edit_form';

    foreach ($entities as $entity) {
      $key = $entity->id();
      $label = method_exists($entity, 'getName') ? $entity->getName() : $entity->label();

      if ($isActiveCallback($entity)) {
        $active[$key] = $label;
      } elseif ($isEditForm) {
        $inactive[$key] = $label;
      }
    }

    return array_filter([
      'Active' => $active ?: null,
      'Inactive' => $inactive ?: null,
    ]);
  }

  /**
   * {@inheritdoc}
   */
  public function massageFormValues(array $values, array $form, FormStateInterface $form_state): string {
    return $values[0][0]['target_id'] ?? '';
  }
}