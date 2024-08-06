<?php

use Drupal\Core\Database\Database;
use Drupal\node\Entity\Node;

/**
 * Implements theme_preprocess_HOOK().
 */
function scale_preprocess_paragraph__featured_speakers(&$variables) {
  /** @var \Drupal\paragraphs\Entity\Paragraph $paragraph */
  $paragraph = $variables["elements"]["#paragraph"];

  // Load the event selected
  $event_node = $paragraph->get('field_event')->referencedEntities()[0];

  $speaker_ids = $event_node->get('field_featured_speakers')->referencedEntities();
  array_walk($speaker_ids, function(&$speaker) {
    $speaker = $speaker->id();
  });


  $speaker_args = implode('+', $speaker_ids);

  // Load view and pass event node nid as argument
  $view = \Drupal\views\Views::getView('featured_speakers');
  $view->setDisplay('swiper');
  $view->setArguments([$speaker_args]);
  $view->preExecute();
  $view->execute();

  $variables['content']['speakers'] = $view->buildRenderable();
}
