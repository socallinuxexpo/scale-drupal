<?php

namespace Drupal\views_plugins\Plugin\views\field;

use Drupal\node\NodeInterface;
use Drupal\views\Plugin\views\field\FieldPluginBase;
use Drupal\views\ResultRow;

/**
 * Displays the email address of every speaker referenced by a session.
 *
 * @ingroup views_field_handlers
 *
 * @ViewsField("speaker_emails")
 */
class SpeakerEmails extends FieldPluginBase {

  /**
   * {@inheritdoc}
   *
   * The addresses are collected per row rather than selected in the query,
   * so there is no column for Views to sort on.
   */
  public function clickSortable() {
    return FALSE;
  }

  /**
   * {@inheritdoc}
   */
  public function query() {
    // Nothing to add. Speakers come from the row's entity in render().
  }

  /**
   * {@inheritdoc}
   */
  public function render(ResultRow $values) {
    $node = $values->_entity ?? NULL;

    if (!$node instanceof NodeInterface || !$node->hasField('field_speakers_ref')) {
      return '';
    }

    $emails = [];

    foreach ($node->get('field_speakers_ref')->referencedEntities() as $speaker) {
      if (!$speaker->hasField('field_email') || $speaker->get('field_email')->isEmpty()) {
        continue;
      }

      $email = trim((string) $speaker->get('field_email')->value);

      if ($email !== '') {
        $emails[] = $email;
      }
    }

    return implode(', ', $emails);
  }

}
