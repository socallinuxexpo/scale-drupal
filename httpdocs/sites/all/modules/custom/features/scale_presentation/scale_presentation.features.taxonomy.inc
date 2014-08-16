<?php
/**
 * @file
 * scale_presentation.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function scale_presentation_taxonomy_default_vocabularies() {
  return array(
    'audience' => array(
      'name' => 'Audience level',
      'machine_name' => 'audience',
      'description' => 'Presentation Audience Types',
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
