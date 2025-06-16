<?php

namespace Drupal\allowed_taxonomy\Plugin\Field\FieldWidget;

use Drupal\Core\Entity\FieldableEntityInterface;
use Drupal\Core\Field\Plugin\Field\FieldWidget\OptionsSelectWidget;

/**
 * Plugin implementation of the 'grouped_taxonomy_select' widget.
 *
 * @FieldWidget(
 *   id = "grouped_taxonomy_select",
 *   label = @Translation("Grouped taxonomy select"),
 *   field_types = {
 *     "entity_reference"
 *   }
 * )
 */
class GroupedTaxonomySelectWidget extends OptionsSelectWidget {

  /**
   * {@inheritdoc}
   */
  protected function getOptions(FieldableEntityInterface $entity) {
    if (!isset($this->options)) {
      $handler_settings = $this->fieldDefinition->getSetting('handler_settings');
      $vocabularies = isset($handler_settings['target_bundles']) ? $handler_settings['target_bundles'] : [];

      $active_options = [];
      $inactive_options = [];

      foreach ($vocabularies as $vocabulary) {
        $terms = \Drupal::entityTypeManager()
          ->getStorage('taxonomy_term')
          ->loadByProperties(['vid' => $vocabulary]);

        foreach ($terms as $term) {
          $active_value = $term->get('field_active')->value;
          $option_key = $term->id();
          $option_label = $term->getName();

          if ($active_value) {
            $active_options[$option_key] = $option_label;
          } else {
            $inactive_options[$option_key] = $option_label;
          }
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

    return $this->options;
  }
}