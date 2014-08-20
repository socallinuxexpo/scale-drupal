<?php
/**
 * @file
 * scale_speaker.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function scale_speaker_default_rules_configuration() {
  $items = array();
  $items['rules_grant_speaker_role'] = entity_import('rules_config', '{ "rules_grant_speaker_role" : {
      "LABEL" : "Grant speaker role",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_insert" : [], "user_update" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "account:field-is-speaker" ], "value" : 1 } }
      ],
      "DO" : [
        { "user_add_role" : { "account" : [ "account" ], "roles" : { "value" : { "5" : "5" } } } }
      ]
    }
  }');
  $items['rules_revoke_speaker_role'] = entity_import('rules_config', '{ "rules_revoke_speaker_role" : {
      "LABEL" : "Revoke speaker role",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_update" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "account:field-is-speaker" ], "value" : 0 } }
      ],
      "DO" : [
        { "user_remove_role" : { "account" : [ "account" ], "roles" : { "value" : { "5" : "5" } } } }
      ]
    }
  }');
  return $items;
}
