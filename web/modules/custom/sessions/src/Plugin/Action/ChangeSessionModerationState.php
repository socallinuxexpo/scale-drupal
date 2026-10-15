<?php

namespace Drupal\sessions\Plugin\Action;

use Drupal\Component\Datetime\TimeInterface;
use Drupal\Core\Access\AccessResult;
use Drupal\Core\Action\Attribute\Action;
use Drupal\Core\Action\Plugin\Action\EntityActionBase;
use Drupal\Core\Entity\EntityChangedInterface;
use Drupal\Core\Entity\EntityTypeManagerInterface;
use Drupal\Core\Entity\RevisionLogInterface;
use Drupal\Core\Entity\TranslatableRevisionableInterface;
use Drupal\Core\Session\AccountInterface;
use Drupal\Core\StringTranslation\TranslatableMarkup;
use Drupal\content_moderation\ModerationInformationInterface;
use Drupal\content_moderation\StateTransitionValidationInterface;
use Symfony\Component\DependencyInjection\ContainerInterface;

/**
 * Moves a session to a moderation state in bulk.
 *
 * One plugin covers every review decision; each is a separate action config
 * entity setting its own target_state. See system.action.session_*.
 *
 * A talk is only changed if the target state is reachable from where it is
 * now, matching what the edit form offers. Mixed selections are expected, so
 * anything that can't make the move is named rather than silently skipped.
 */
#[Action(
  id: 'session_change_moderation_state',
  label: new TranslatableMarkup('Change session status'),
  type: 'node',
)]
class ChangeSessionModerationState extends EntityActionBase {

  /**
   * The moderation information service.
   *
   * @var \Drupal\content_moderation\ModerationInformationInterface
   */
  protected $moderationInfo;

  /**
   * The state transition validation service.
   *
   * @var \Drupal\content_moderation\StateTransitionValidationInterface
   */
  protected $transitionValidation;

  /**
   * The current user.
   *
   * @var \Drupal\Core\Session\AccountInterface
   */
  protected $currentUser;

  /**
   * The time service.
   *
   * @var \Drupal\Component\Datetime\TimeInterface
   */
  protected $time;

  /**
   * {@inheritdoc}
   */
  public function __construct(
    array $configuration,
    $plugin_id,
    $plugin_definition,
    EntityTypeManagerInterface $entity_type_manager,
    ModerationInformationInterface $moderation_info,
    StateTransitionValidationInterface $transition_validation,
    AccountInterface $current_user,
    TimeInterface $time,
  ) {
    parent::__construct($configuration, $plugin_id, $plugin_definition, $entity_type_manager);
    $this->moderationInfo = $moderation_info;
    $this->transitionValidation = $transition_validation;
    $this->currentUser = $current_user;
    $this->time = $time;
  }

  /**
   * {@inheritdoc}
   */
  public static function create(ContainerInterface $container, array $configuration, $plugin_id, $plugin_definition) {
    return new static(
      $configuration,
      $plugin_id,
      $plugin_definition,
      $container->get('entity_type.manager'),
      $container->get('content_moderation.moderation_information'),
      $container->get('content_moderation.state_transition_validation'),
      $container->get('current_user'),
      $container->get('datetime.time'),
    );
  }

  /**
   * {@inheritdoc}
   */
  public function defaultConfiguration() {
    return ['target_state' => ''];
  }

  /**
   * {@inheritdoc}
   *
   * Content moderation writes the new revision, but a programmatic save skips
   * the node form that normally stamps it. Everything below compensates for
   * that; without it the trail credits the speaker at their submission time.
   */
  public function execute($entity = NULL) {
    if ($entity) {
      $entity->set('moderation_state', $this->configuration['target_state']);

      if ($entity instanceof RevisionLogInterface) {
        $entity->setRevisionUserId($this->currentUser->id());
        $entity->setRevisionCreationTime($this->time->getRequestTime());
        $entity->setRevisionLogMessage((string) $this->t('Status changed in bulk from the votes page.'));
      }

      // moderation_state is computed, so Drupal detects no field change and
      // never sets this flag - and the Revisions tab lists only revisions that
      // have it. Without this the revision exists but is invisible.
      if ($entity instanceof TranslatableRevisionableInterface) {
        $entity->setRevisionTranslationAffected(TRUE);
      }

      // Same cause: ChangedItem::preSave() only bumps the changed time on a
      // detected field change, so "Last saved" would still show whenever
      // someone last edited the talk by hand.
      if ($entity instanceof EntityChangedInterface) {
        $entity->setChangedTime($this->time->getRequestTime());
      }

      $entity->save();
    }
  }

  /**
   * {@inheritdoc}
   *
   * Covers both halves of "can this happen": permission to edit the talk, and
   * whether the workflow allows this move from its current state. Views calls
   * this per talk, so one that can't move is named in an error and left alone.
   */
  public function access($object, ?AccountInterface $account = NULL, $return_as_object = FALSE) {
    $account = $account ?: \Drupal::currentUser();

    // Deciding in bulk is a separate permission from deciding at all -
    // reviewers keep every transition they have on the edit form.
    $result = AccessResult::allowedIfHasPermission($account, 'bulk change session status');

    if ($result->isAllowed()) {
      $result = $result->andIf($object->access('update', $account, TRUE));
    }

    if ($result->isAllowed()) {
      $result = $result->andIf(
        AccessResult::allowedIf($this->targetStateIsReachable($object, $account))
          ->addCacheableDependency($object)
      );
    }

    return $return_as_object ? $result : $result->isAllowed();
  }

  /**
   * Checks whether this action's target state can be reached from where the
   * talk is now.
   *
   * getValidTransitions() already filters by the user's transition
   * permissions, so this answers "is this move allowed, for this person, from
   * this state" in one step.
   *
   * @param object $entity
   *   The entity being checked.
   * @param \Drupal\Core\Session\AccountInterface $account
   *   The user the move would be performed as.
   *
   * @return bool
   *   TRUE if the move is allowed.
   */
  protected function targetStateIsReachable($entity, AccountInterface $account) {
    if (!$this->moderationInfo->isModeratedEntity($entity)) {
      return FALSE;
    }

    $target = $this->configuration['target_state'];

    foreach ($this->transitionValidation->getValidTransitions($entity, $account) as $transition) {
      if ($transition->to()->id() === $target) {
        return TRUE;
      }
    }

    return FALSE;
  }

}
