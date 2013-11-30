<?php
/**
 * @file
 * scale_common.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function scale_common_taxonomy_default_vocabularies() {
  return array(
    'scale_event' => array(
      'name' => 'SCALE event',
      'machine_name' => 'scale_event',
      'description' => 'Which SCALE event a piece of content belongs to',
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
