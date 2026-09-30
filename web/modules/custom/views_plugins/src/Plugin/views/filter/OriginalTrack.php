<?php

namespace Drupal\views_plugins\Plugin\views\filter;

use Drupal\views\Plugin\views\filter\InOperator;

/**
 * Filters track suggestions by the track the talk was in.
 *
 * Issue #222 asks for one "Original Track" filter: the track a talk was moved
 * out of once a suggestion is accepted, and the talk's current track before
 * that. Two fields, so the match is a subquery per case rather than a join.
 *
 * An accepted suggestion with no old track recorded falls back to the current
 * track, so the filter matches what the Original track column displays.
 *
 * @ingroup views_filter_handlers
 *
 * @ViewsFilter("original_track")
 */
class OriginalTrack extends InOperator {

  /**
   * {@inheritdoc}
   *
   * Only "is one of" is offered, since query() always matches a list.
   */
  public function operators() {
    return [
      'in' => [
        'title' => $this->t('Is one of'),
        'short' => $this->t('in'),
        'method' => 'opSimple',
        'values' => 1,
      ],
    ];
  }

  /**
   * {@inheritdoc}
   *
   * Every track, not just the active ones, because the list reaches back to
   * older events. The exposed form groups them, see views_plugins.module.
   */
  public function getValueOptions() {
    if (isset($this->valueOptions)) {
      return $this->valueOptions;
    }

    $storage = \Drupal::entityTypeManager()->getStorage('taxonomy_term');

    $tids = $storage->getQuery()
      ->accessCheck(TRUE)
      ->condition('vid', 'session_track')
      ->sort('name')
      ->execute();

    $this->valueOptions = [];

    foreach ($storage->loadMultiple($tids) as $tid => $term) {
      $this->valueOptions[$tid] = $term->label();
    }

    return $this->valueOptions;
  }

  /**
   * {@inheritdoc}
   */
  public function query() {
    $tids = array_values(array_filter((array) $this->value));

    // No track chosen means no condition, so the view behaves as it would
    // without this filter.
    if (!$tids) {
      return;
    }

    $this->ensureMyTable();

    $this->query->addWhereExpression(
      $this->options['group'],
      "{$this->tableAlias}.nid IN (
        SELECT accepted.entity_id
        FROM {node__field_swap_status} accepted
        INNER JOIN {node__field_old_track} moved_from ON moved_from.entity_id = accepted.entity_id
        WHERE accepted.field_swap_status_value = 'accepted'
          AND moved_from.field_old_track_target_id IN (:original_tids[])
        UNION
        SELECT open.entity_id
        FROM {node__field_swap_status} open
        INNER JOIN {node__field_talk} talk ON talk.entity_id = open.entity_id
        INNER JOIN {node__field_session_track} current_track ON current_track.entity_id = talk.field_talk_target_id
        LEFT JOIN {node__field_old_track} recorded ON recorded.entity_id = open.entity_id
        WHERE (open.field_swap_status_value <> 'accepted' OR recorded.field_old_track_target_id IS NULL)
          AND current_track.field_session_track_target_id IN (:original_tids[])
      )",
      [':original_tids[]' => $tids]
    );
  }

}
