<?php
function scale11x_js_alter(&$javascript) {
  $javascript['misc/jquery.js']['data'] = drupal_get_path('theme', 'scale11x').'/js/jquery.min.js';
  $javascript['misc/jquery.js']['version'] = '1.7.2';
}
