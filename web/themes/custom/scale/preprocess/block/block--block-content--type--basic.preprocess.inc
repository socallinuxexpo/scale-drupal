<?php

/**
 * Implements hook_preprocess_HOOK() for block templates.
 */
function scale_preprocess_block(&$variables) {
  // Check if the block is of the desired custom block type.
  if ($variables['base_plugin_id'] === 'block_content' && $variables['content']['#block_content']->bundle() === 'basic') {
    // Get the field value from the block entity.
    $block_content = $variables['content']['#block_content'];
    $color_field = $block_content->get('field_color')->value;

    // Pass it to the template.
    $variables['color'] = $color_field;
  }
}
