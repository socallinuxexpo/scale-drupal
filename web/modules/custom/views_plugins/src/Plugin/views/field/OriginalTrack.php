<?php

namespace Drupal\views_plugins\Plugin\views\field;

use Drupal\node\NodeInterface;
use Drupal\views\Plugin\views\field\FieldPluginBase;
use Drupal\views\ResultRow;

/**
 * Displays the track a talk was in, for a track suggestion.
 *
 * A recorded old track wins, otherwise the talk's current track. Issue #222
 * freezes the old track once a decision is made, so an undecided suggestion
 * follows the talk and a decided one keeps the track it was decided against.
 *
 * The matching filter is in Plugin/views/filter/OriginalTrack.php. Both have
 * to answer the same question or the column and the filter disagree.
 *
 * @ingroup views_field_handlers
 *
 * @ViewsField("original_track")
 */
class OriginalTrack extends FieldPluginBase {

  /**
   * {@inheritdoc}
   */
  public function query() {
    // Nothing to add. The track comes from the row's entity in render().
  }

  /**
   * {@inheritdoc}
   */
  public function clickSortable() {
    return TRUE;
  }

  /**
   * {@inheritdoc}
   *
   * Sorts on the track's name. A term id would order rows by the order the
   * tracks happened to be created in, which means nothing to a reader.
   */
  public function clickSort($order) {
    $this->ensureMyTable();

    // Two scalar subqueries rather than five joins, the same shape the filter
    // uses. COALESCE applies the same fallback as render().
    $name = "COALESCE(
      (SELECT recorded.name
         FROM {node__field_old_track} moved_from
         INNER JOIN {taxonomy_term_field_data} recorded ON recorded.tid = moved_from.field_old_track_target_id
         WHERE moved_from.entity_id = {$this->tableAlias}.nid
         LIMIT 1),
      (SELECT live.name
         FROM {node__field_talk} suggestion
         INNER JOIN {node__field_session_track} current_track ON current_track.entity_id = suggestion.field_talk_target_id
         INNER JOIN {taxonomy_term_field_data} live ON live.tid = current_track.field_session_track_target_id
         WHERE suggestion.entity_id = {$this->tableAlias}.nid
         LIMIT 1)
    )";

    // A row with no track either way sorts last, whichever way the column is
    // sorted, rather than wherever the database happens to put nulls.
    $this->query->addOrderBy(NULL, "($name) IS NULL", 'ASC', 'original_track_empty');
    $this->query->addOrderBy(NULL, $name, $order, 'original_track_name');
  }

  /**
   * {@inheritdoc}
   */
  public function render(ResultRow $values) {
    $suggestion = $values->_entity ?? NULL;

    if (!$suggestion instanceof NodeInterface) {
      return '';
    }

    if ($suggestion->hasField('field_old_track') && !$suggestion->get('field_old_track')->isEmpty()) {
      $recorded = $suggestion->get('field_old_track')->entity;

      return $recorded ? $recorded->label() : '';
    }

    $talk = $suggestion->hasField('field_talk') ? $suggestion->get('field_talk')->entity : NULL;

    if (!$talk instanceof NodeInterface || !$talk->hasField('field_session_track')) {
      return '';
    }

    $live = $talk->get('field_session_track')->entity;

    return $live ? $live->label() : '';
  }

}
