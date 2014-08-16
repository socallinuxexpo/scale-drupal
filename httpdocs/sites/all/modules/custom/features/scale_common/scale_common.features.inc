<?php
/**
 * @file
 * scale_common.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function scale_common_image_default_styles() {
  $styles = array();

  // Exported image style: logo_large.
  $styles['logo_large'] = array(
    'name' => 'logo_large',
    'label' => 'logo_large',
    'effects' => array(
      6 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 250,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
