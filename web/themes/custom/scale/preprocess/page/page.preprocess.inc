<?php

/**
 * Implements theme_preprocess_HOOK().
 */
function scale_preprocess_page(&$variables) {
  $variables['#attached']['library'][] = 'scale/mobile-menu';
}