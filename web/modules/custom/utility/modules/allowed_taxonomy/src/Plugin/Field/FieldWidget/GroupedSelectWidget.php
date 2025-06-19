<?php

namespace Drupal\allowed_taxonomy\Plugin\Field\FieldWidget;

use Drupal\Core\Entity\FieldableEntityInterface;
use Drupal\Core\Field\Plugin\Field\FieldWidget\OptionsSelectWidget;
use Drupal\Core\Form\FormStateInterface;

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
   * {@inheritdoc}
   */
  protected function supportsGroups() {
    return TRUE;
  }

  /**
   * {@inheritdoc}
   */
  protected function getOptions(FieldableEntityInterface $entity) {
    if (!isset($this->options)) {
      $handler_settings = $this->fieldDefinition->getSetting('handler_settings');
      $bundles = isset($handler_settings['target_bundles']) ? $handler_settings['target_bundles'] : [];

      foreach ($bundles as $bundle) {
        if ($bundle === 'event') {
          $this->getGroupedEntityOptions($bundle);
        } else {
          $this->getGroupedTaxonomyOptions($bundle);
        }
      }
    }

    return $this->options;
  }

  protected function getGroupedEntityOptions($bundle) {
    $active_options = [];
    $inactive_options = [];

    $items = \Drupal::entityTypeManager()
      ->getStorage('node')
      ->loadByProperties(['type' => $bundle]);

    foreach ($items as $item) {
      if(!$item->hasField('field_event_date')) {
        continue;
      }

      // If field_event_date start date is in the past, return active (true)
      $active_value = $item->get('field_event_date')->value > date('Y-m-d');
      $option_key = $item->id();
      $option_label = $item->label();

      if ($active_value) {
        $active_options[$option_key] = $option_label;
      } else {
        $inactive_options[$option_key] = $option_label;
      }
    }

    $this->options = [];
    if (!empty($active_options)) {
      $this->options['Active'] = $active_options;
    }
    if (!empty($inactive_options)) {
      $this->options['Inactive'] = $inactive_options;
    }
  }

  protected function getGroupedTaxonomyOptions($bundle) {
    $active_options = [];
    $inactive_options = [];

    $items = \Drupal::entityTypeManager()
      ->getStorage('taxonomy_term')
      ->loadByProperties(['vid' => $bundle]);

    foreach ($items as $item) {
      if(!$item->hasField('field_active')) {
        continue;
      }
      $active_value = $item->get('field_active')->value;
      $option_key = $item->id();
      $option_label = $item->getName();

      if ($active_value) {
        $active_options[$option_key] = $option_label;
      } else {
        $inactive_options[$option_key] = $option_label;
      }
    }

    $this->options = [];
    if (!empty($active_options)) {
      $this->options['Active'] = $active_options;
    }
    if (!empty($inactive_options)) {
      $this->options['Inactive'] = $inactive_options;
    }
  }

  /**
   * {@inheritdoc}
   */
  public function massageFormValues(array $values, array $form, FormStateInterface $form_state) {
    return $values[0][0]["target_id"];
  }
}

