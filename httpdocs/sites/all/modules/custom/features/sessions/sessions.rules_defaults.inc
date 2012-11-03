<?php
/**
 * @file
 * sessions.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function sessions_default_rules_configuration() {
  $items = array();
  $items['rules_notification_of_new_presentation'] = entity_import('rules_config', '{ "rules_notification_of_new_presentation" : {
      "LABEL" : "Notification of new presentation",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "presentation" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "presentation" : "presentation" } }
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "kapadia@socallinuxexpo.org,rgolan@superconcentrated.com",
            "subject" : "A new SCALE 11x presentation, [node:title], has been created",
            "message" : "[node:author] has submitted a presentation, [node:title], for SCALE 11x.",
            "from" : "rgolan+scale11x@superconcentrated.com",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
