<?php

/**
 * Implements theme_preprocess_HOOK().
 */
function scale_preprocess_field(&$variables) {
  // Stark adds no class to CKEditor fields, so mark them for list styling.
  $text_types = ['text', 'text_long', 'text_with_summary'];
  if (in_array($variables['field_type'], $text_types)) {
    $variables['attributes']['class'][] = 'text-formatted';
  }
}
