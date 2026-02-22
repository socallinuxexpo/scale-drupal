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
      $view = \Drupal\views\Views::getView('event_sponsors');
      $view->setDisplay('grouped_grid');
      $view->setArguments([$event_id]);
      $view->preExecute();
      $view->execute();

      $output[] = $view->buildRenderable();
  }

  $variables['preprocessor'] = [
    'layout' => $layout,
    'content' => $output,
  ];
}
