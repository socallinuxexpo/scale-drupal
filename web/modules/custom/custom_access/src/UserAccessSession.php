<?php

namespace Drupal\custom_access;

use Drupal\node\NodeInterface;
use Drupal\Core\Session\AccountInterface;
use Drupal\Core\Access\AccessResult;

class UserAccessSession {

  public function checkAccess(NodeInterface $node, $operation, AccountInterface $account) {
    if ($node->getType() !== 'session') {
      return AccessResult::neutral();
    }

    if ($operation == 'view') {
      if ($node->getOwner()->id() == $account->id()) {
        return AccessResult::allowed()->cachePerUser();
      }
    }

    if ($operation == 'update') {
      if ($node->hasField('field_speakers_ref') && !$node->get('field_speakers_ref')
          ->isEmpty()) {
        foreach ($node->get('field_speakers_ref')
          ->referencedEntities() as $speaker_node) {
          if ($speaker_node->hasField('field_user_account') && !$speaker_node->get('field_user_account')
              ->isEmpty()) {
            foreach ($speaker_node->get('field_user_account')
              ->referencedEntities() as $user) {
              if ($user->id() == $account->id()) {
                return AccessResult::allowed()->cachePerUser();
              }
            }
          }
        }
      }
    }

    return AccessResult::neutral();
  }

}
