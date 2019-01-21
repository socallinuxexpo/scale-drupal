<?php

/**
 * @file
 * scale_presentation.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function scale_presentation_default_rules_configuration() {
  $items = array();
  $items['rules_notification_of_new_presentation'] = entity_import('rules_config', '{ "rules_notification_of_new_presentation" : {
      "LABEL" : "Notification of new presentation",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "presentation" : "presentation" } }
          }
        }
      ],
      "DO" : [
        { "mail" : {
            "to" : "kapadia@socallinuxexpo.org,rgolan+cfp@superconcentrated.com",
            "subject" : "A new [site:name] presentation, [node:title], has been created.",
            "message" : "[node:author] has submitted a presentation, [node:title], for [site:name].\\r\\n\\r\\n[node:url]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
