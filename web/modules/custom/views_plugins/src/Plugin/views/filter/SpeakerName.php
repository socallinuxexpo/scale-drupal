<?php

namespace Drupal\views_plugins\Plugin\views\filter;

use Drupal\views\Plugin\views\filter\StringFilter;

/**
 * Filters content by the name of any of its referenced speakers.
 *
 * Uses a subquery rather than a relationship, which would return one row per
 * speaker and duplicate sessions that have several.
 *
 * @ingroup views_filter_handlers
 *
 * @ViewsFilter("speaker_name")
 */
class SpeakerName extends StringFilter {

  /**
   * {@inheritdoc}
   *
   * Only "contains" is offered, since query() always builds a LIKE match.
   */
  public function operators() {
    return [
      'contains' => [
        'title' => $this->t('Contains'),
        'short' => $this->t('contains'),
        'method' => 'opContains',
        'values' => 1,
      ],
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function query() {
    $value = trim((string) $this->value);

    // No search term means no condition, so the view behaves as it would
    // without this filter.
    if ($value === '') {
      return;
    }

    $this->ensureMyTable();

    $this->query->addWhereExpression(
      $this->options['group'],
      "{$this->tableAlias}.nid IN (
        SELECT sr.entity_id
        FROM {node__field_speakers_ref} sr
        INNER JOIN {node_field_data} s ON s.nid = sr.field_speakers_ref_target_id
        WHERE s.title LIKE :speaker_name
      )",
      [':speaker_name' => '%' . $this->connection->escapeLike($value) . '%']
    );
  }

}
