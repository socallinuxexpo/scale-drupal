<?php
/**
 * @file
 * scale_notice.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function scale_notice_taxonomy_default_vocabularies() {
  return array(
    'schedule_special_items' => array(
      'name' => 'Schedule special items',
      'machine_name' => 'schedule_special_items',
      'description' => 'Break, lunch and other items to show up in the schedule.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
