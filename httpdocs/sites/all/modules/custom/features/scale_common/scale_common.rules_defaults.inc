<?php
/**
 * @file
 * scale_common.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function scale_common_default_rules_configuration() {
  $items = array();
  $items['rules_re'] = entity_import('rules_config', '{ "rules_re" : {
      "LABEL" : "Ready for approval email",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert" : [], "node_update" : [] },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : {
                "blog" : "blog",
                "special_event" : "special_event",
                "sponsor" : "sponsor"
              }
            }
          }
        },
        { "AND" : [] },
        { "NOT node_is_published" : { "node" : [ "node" ] } },
        { "AND" : [] },
        { "data_is" : { "data" : [ "node:field-ready-for-approval" ], "value" : 1 } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "larry@socallinuxexpo.org",
            "subject" : "A [site:slogan] Sponsor\\/Exhibitor or Blog Post, [node:title], is ready for approval",
            "message" : "Please visit [node:url] to review the submitted content. Once you think it\\u0027s ready for publication, please check the published box.",
            "from" : "rgolan@superconcentrated.com",
            "language" : [ "" ]
          }
        },
        { "drupal_message" : { "message" : "An email has been sent asking for review of this content." } }
      ]
    }
  }');
  return $items;
}
