<?php

/**
 * Implements theme_preprocess_HOOK().
 */
function scale_preprocess_node__speaker__profile_card(&$variables) {
//  $variables['container_width'] = theme_get_setting('container_width') ?? 'container mx-auto px-5';

  /** @var \Drupal\node\Entity\Node $ndoe */
  $node = $variables["elements"]["#node"];

  // Load the image field items.
  $field_image_items = $node->get('field_profile_photo')->getValue();
  $image_render_array = [];

  // Iterate through each image item to build the render array.
  foreach ($field_image_items as $item) {
    // Load the file entity using the file ID (fid).
    $file = \Drupal\file\Entity\File::load($item['target_id']);

    // Generate the URL for the image with the custom image style.
    $image_uri = $file->getFileUri();
//    $image_url = \Drupal\image\Entity\ImageStyle::load('medium')->buildUrl($image_uri);

    // Build the render array for this image.
    $image_render_array[] = [
      '#theme' => 'responsive_image',
      '#responsive_image_style_id' => 'speaker_profile_image',
      '#uri' => $image_uri,
      '#alt' => $item['alt'] ?? '',
      '#title' => $item['title'] ?? '',
      '#attributes' => [
        'class' => ['rounded-full'],
      ],
    ];
  }

  // Add the render array to the node variables.
  $variables['content']['profile_image'] = $image_render_array;
}
