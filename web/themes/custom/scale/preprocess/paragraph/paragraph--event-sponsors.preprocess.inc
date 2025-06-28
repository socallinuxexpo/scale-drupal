<?php

use Drupal\Core\Database\Database;
use Drupal\node\Entity\Node;

/**
 * Implements theme_preprocess_HOOK().
 */
function scale_preprocess_paragraph__event_sponsors(&$variables) {
  $output = [];

  /** @var \Drupal\paragraphs\Entity\Paragraph $paragraph */
  $paragraph = $variables["elements"]["#paragraph"];

  // Load the event selected
  $event_id = $variables["event"]["id"] ?? '';

  $layout = $paragraph->get('field_layout')->value;

  if ($layout === 'marquee') {
    // Load view and pass event node nid as argument
    $view = \Drupal\views\Views::getView('event_sponsors');
    $view->setDisplay('swiper');
    $view->setArguments([$event_id]);
    $view->preExecute();
    $view->execute();

    $output[] = $view->buildRenderable();
  }

  if ($layout === 'grouped_grid') {
    // Get events by sponsor tier

    // TODO: Write a Service to get this
    $vocabulary = 'sponsor_tier';

    // Build the entity query to fetch term IDs from the specified vocabulary.
    $query = \Drupal::entityQuery('taxonomy_term')
      ->accessCheck(TRUE)
      ->condition('vid', $vocabulary);

    // Execute the query to get the term IDs.
    $term_ids = $query->execute();
    $terms = \Drupal\taxonomy\Entity\Term::loadMultiple($term_ids);

    foreach ($terms as $term) {
      // Build the entity query to fetch Sponsor nodes.
      $query = \Drupal::entityQuery('node')
        ->accessCheck(TRUE)
        ->condition('type', 'sponsor')
        ->condition('field_scale_event', $event_id)
        ->condition('field_sponsor_tier', $term->id());

      // Execute the query and load the Sponsor nodes.
      $nids = $query->execute();

      if (empty($nids)) {
        continue;
      }

      $nids_str = implode('+', $nids);

      $args = [$nids_str, $event_id];

      // Load view and pass event node nid as argument
      $view = \Drupal\views\Views::getView('event_sponsors');
      $view->setDisplay('grouped_grid');
      $view->setArguments($args);
      $view->preExecute();
      $view->execute();

      // Add the rendered view to the output array.
      $output[] = [
        'group' => $term->label(),
        'view' => $view->buildRenderable(),
      ];
    }
  }

  $variables['preprocessor'] = [
    'layout' => $layout,
    'content' => $output,
  ];
}
