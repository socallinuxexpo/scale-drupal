<?php

namespace Drupal\custom_access;

use Drupal\node\NodeInterface;
use Drupal\Core\Session\AccountInterface;
use Drupal\Core\Access\AccessResult;

class UserAccessSpeaker {

  public function checkAccess(NodeInterface $node, $operation, AccountInterface $account) {
    if ($node->getType() !== 'speaker') {
      return AccessResult::neutral();
    }

    if ($operation !== 'update') {
      return AccessResult::neutral();
    }

    if ($node->hasField('field_user_account') && !$node->get('field_user_account')->isEmpty()) {
      foreach ($node->get('field_user_account')->referencedEntities() as $user) {
        if ($user->id() == $account->id()) {
          return AccessResult::allowed()->cachePerUser();
        }
      }
    }

    return AccessResult::neutral();
  }

}
