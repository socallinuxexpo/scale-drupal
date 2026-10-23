<?php

namespace Drupal\sessions\Plugin\EntityReferenceSelection;

use Drupal\Core\Entity\Attribute\EntityReferenceSelection;
use Drupal\Core\Entity\Plugin\EntityReferenceSelection\DefaultSelection;
use Drupal\Core\StringTranslation\TranslatableMarkup;

/**
 * Selection handler for the talk a track suggestion points at.
 *
 * Extends DefaultSelection rather than NodeSelection, which limits references
 * to published nodes for anyone without 'bypass node access'. Talks are
 * unpublished until they are confirmed, so that rule blocks reviewers and
 * session editors from deciding any swap during the review window.
 */
#[EntityReferenceSelection(
  id: "sessions:talk",
  label: new TranslatableMarkup("Talk selection"),
  entity_types: ["node"],
  group: "sessions",
  weight: 0,
)]
class TalkSelection extends DefaultSelection {
}
