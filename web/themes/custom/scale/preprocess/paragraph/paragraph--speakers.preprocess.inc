<?php

use Drupal\Core\Database\Database;
use Drupal\node\Entity\Node;

/**
 * Implements theme_preprocess_HOOK().
 */
function scale_preprocess_paragraph__speakers(&$variables) {
  /** @var \Drupal\paragraphs\Entity\Paragraph $paragraph */
  $paragraph = $variables["elements"]["#paragraph"];

  // Load the event selected
  $event_node = $paragraph->get('field_event')->referencedEntities()[0];
  $event_id = $event_node->id();

  // TODO: Write a Service to get this
  $connection = Database::getConnection();

  $query = $connection->select('node__field_scale_events', 'fe');
  $query->addField('fs', 'field_speakers_ref_target_id');
  $query->distinct();
  $query->condition('fe.field_scale_events_target_id', $event_id);

  // Join the session nodes with the speakers field.
  $query->innerJoin('node__field_speakers_ref', 'fs', 'fs.entity_id = fe.entity_id');

  $result = $query->execute();
  $speaker_ids = $result->fetchCol();

  $speaker_args = implode('+', $speaker_ids);

  // Load view and pass event node nid as argument
  $view = \Drupal\views\Views::getView('event_speakers');
  $view->setDisplay('summary_cards');
  $view->setArguments([$speaker_args]);
  $view->preExecute();
  $view->execute();

  $variables['content']['speakers'] = $view->buildRenderable();
}
