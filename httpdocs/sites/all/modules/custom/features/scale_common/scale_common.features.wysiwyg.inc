<?php

/**
 * @file
 * scale_common.features.wysiwyg.inc
 */

/**
 * Implements hook_wysiwyg_default_profiles().
 */
function scale_common_wysiwyg_default_profiles() {
  $profiles = array();

  // Exported profile: filtered_html.
  $profiles['filtered_html'] = array(
    'format' => 'filtered_html',
    'editor' => 'tinymce',
    'settings' => array(
      'theme' => 'advanced',
      'language' => 'en',
      'buttons' => array(
        'default' => array(
          'bold' => 1,
          'italic' => 1,
          'bullist' => 1,
          'numlist' => 1,
          'link' => 1,
          'unlink' => 1,
          'image' => 1,
          'styleselect' => 1,
        ),
        'media' => array(
          'media' => 1,
        ),
        'drupal' => array(
          'media' => 1,
        ),
      ),
      'verify_html' => 1,
      'preformatted' => 0,
      'convert_fonts_to_spans' => 1,
      'remove_linebreaks' => 0,
      'apply_source_formatting' => 1,
      'paste_auto_cleanup_on_paste' => 1,
      'css_setting' => 'theme',
      'css_path' => '',
      'theme_advanced_statusbar_location' => 'bottom',
      'theme_advanced_toolbar_location' => 'top',
      'theme_advanced_toolbar_align' => 'left',
      'theme_advanced_blockformats' => 'p,address,pre,h2,h3,h4,h5,h6,div',
      'theme_advanced_styles' => 'Image align left=left-image
Image align right=right-image',
      'theme_advanced_resizing' => 1,
    ),
    'preferences' => array(
      'add_to_summaries' => FALSE,
      'default' => 1,
      'show_toggle' => 1,
      'user_choose' => 1,
      'version' => '3.5.7',
    ),
    'name' => 'formatfiltered_html',
    'rdf_mapping' => array(),
  );

  return $profiles;
}
