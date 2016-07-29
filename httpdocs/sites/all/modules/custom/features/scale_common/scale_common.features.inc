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
    'label' => 'logo_large',
    'effects' => array(
      6 => array(
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
