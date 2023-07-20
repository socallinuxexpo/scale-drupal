<?php

/**
 * @file
 * scale_themes.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function scale_themes_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'themekey_attributes';
  $strongarm->value = array(
    'comment:cid' => array(
      'description' => 'Comment: ID - The id of a comment (cid). See <a href="/admin/content/comment">admin/content/comment</a> for your published comments or <a href="/admin/content/comment/approval">admin/content/comment/approval</a> for comments awaiting approval',
      'page cache' => 1,
      'validator' => 'themekey_validator_ctype_digit',
    ),
    'drupal:base_path' => array(
      'description' => 'Drupal: Base path - If Drupal is installed in a subdirectory, the base path will be \'/[subdirectory]/\', otherwise just \'/\'.',
      'page cache' => 1,
    ),
    'drupal:get_q' => array(
      'description' => 'Drupal: $_GET[\'q\'] - Current value of Drupal\'s query parameter "q"',
      'page cache' => 1,
      'validator' => '',
    ),
    'drupal:is_front_page' => array(
      'description' => 'Drupal: Is front page - \'true\' if current page is front page, otherwise just \'false\'.',
      'page cache' => 1,
      'validator' => 'themekey_validator_string_boolean',
    ),
    'drupal:path' => array(
      'description' => 'Drupal: Drupal path like "node/add/story" or path alias with support for wildcards.<br />
Query parameters are stripped off before the path gets examined. P.e. "node/add/story?destination=node" becomes "node/add/story" first. If you want to access query parameters, have a look at the <strong>system:query_param</strong> property.<br />
Wildcard characters are "#" for numeric parts and "%" for all characters. To match conditions against a certain part, use an identifier with the wildcard. For example "comment/reply/#xyz" matches all paths with "comment/reply" and a numeric third argument. You can then specify conditions for every wildcard argument using the property "drupal:path:wildcard" and the identifier you choose ("xyz" in this example).<br />
These are the possible wildcard replacements for foo/bar/42/test.html:<pre>
foo/bar/42/test.html
foo/bar/42/%
foo/bar/42
foo/bar/%/test.html
foo/bar/%/%
foo/bar/%
foo/bar/#/test.html
foo/bar/#/%
foo/bar/#
foo/bar
foo/%/42/test.html
foo/%/42/%
foo/%/42
foo/%/%/test.html
foo/%/%/%
foo/%/%
foo/%/#/test.html
foo/%/#/%
foo/%/#
foo/%
foo
%/bar/42/test.html
%/bar/42/%
%/bar/42
%/bar/%/test.html
%/bar/%/%
%/bar/%
%/bar/#/test.html
%/bar/#/%
%/bar/#
%/bar
%/%/42/test.html
%/%/42/%
%/%/42
%/%/%/test.html
%/%/%/%
%/%/%
%/%/#/test.html
%/%/#/%
%/%/#
%/%
%
</pre>',
      'page cache' => 1,
      'validator' => 'themekey_validator_drupal_path',
    ),
    'drupal:path:wildcard' => array(
      'description' => 'Wildcard of "drupal:path". See explanation of "drupal:path" for details.',
      'page cache' => 1,
      'validator' => 'themekey_validator_wildcard',
    ),
    'drupal:path_is_admin' => array(
      'description' => 'Drupal: Path is admin - \'true\' if current page\'s path belongs to the admin section, otherwise just \'false\'.',
      'page cache' => 1,
      'validator' => 'themekey_validator_string_boolean',
    ),
    'node:body_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">body</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:body_summary' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">summary</em> of the field <em class="placeholder">body</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:body_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">body</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:changed' => array(
      'description' => 'Node: Changed date - The date when the node was last edited/updated, formatted as unix timestamp like "1248873565".',
      'page cache' => 1,
      'validator' => 'themekey_validator_ctype_digit',
    ),
    'node:changed_date' => array(
      'description' => 'Node: Changed date - The date without the time when the node was last edited/updated, formatted like "2009-12-24"',
      'page cache' => 1,
      'validator' => 'themekey_validator_date',
    ),
    'node:changed_date_time' => array(
      'description' => 'Node: Changed date - The date including the time when the node was last edited/updated, formatted like "2009-12-24 18:13:24"',
      'page cache' => 1,
      'validator' => 'themekey_validator_date_time',
    ),
    'node:created' => array(
      'description' => 'Node: Created date - The date when the node was created, formatted as unix timestamp like "1248873565".',
      'page cache' => 1,
      'validator' => 'themekey_validator_ctype_digit',
    ),
    'node:created_date' => array(
      'description' => 'Node: Created date - The date without the time when the node was created, formatted like "2009-12-24"',
      'page cache' => 1,
      'validator' => 'themekey_validator_date',
    ),
    'node:created_date_time' => array(
      'description' => 'Node: Created date - The date including the time when the node was created, formatted like "2009-12-24 18:13:24"',
      'page cache' => 1,
      'validator' => 'themekey_validator_date_time',
    ),
    'node:field_appropriate_for_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_appropriate_for</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_audience_tid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">tid</em> of the field <em class="placeholder">field_audience</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_audio_video_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_audio_video</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_audio_video_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_audio_video</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_author_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_author</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_author_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_author</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_blog_image_alt' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">alt</em> of the field <em class="placeholder">field_blog_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_blog_image_fid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">fid</em> of the field <em class="placeholder">field_blog_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_blog_image_height' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">height</em> of the field <em class="placeholder">field_blog_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_blog_image_title' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">title</em> of the field <em class="placeholder">field_blog_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_blog_image_width' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">width</em> of the field <em class="placeholder">field_blog_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_booth_number_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_booth_number</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_booth_number_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_booth_number</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_brief_description_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_brief_description</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_brief_description_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_brief_description</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_embed_code_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_embed_code</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_embed_code_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_embed_code</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_embed_code_video_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_embed_code_video</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_embed_code_video_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_embed_code_video</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_exhibitor_sponsor_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_exhibitor_sponsor</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_exhibitor_type_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_exhibitor_type</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_featured_speaker_uid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">uid</em> of the field <em class="placeholder">field_featured_speaker</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_item_type_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_item_type</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_logo_alt' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">alt</em> of the field <em class="placeholder">field_logo</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_logo_fid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">fid</em> of the field <em class="placeholder">field_logo</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_logo_height' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">height</em> of the field <em class="placeholder">field_logo</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_logo_title' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">title</em> of the field <em class="placeholder">field_logo</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_logo_website_alt' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">alt</em> of the field <em class="placeholder">field_logo_website</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_logo_website_fid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">fid</em> of the field <em class="placeholder">field_logo_website</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_logo_website_height' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">height</em> of the field <em class="placeholder">field_logo_website</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_logo_website_title' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">title</em> of the field <em class="placeholder">field_logo_website</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_logo_website_width' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">width</em> of the field <em class="placeholder">field_logo_website</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_logo_width' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">width</em> of the field <em class="placeholder">field_logo</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_long_abstract_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_long_abstract</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_long_abstract_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_long_abstract</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_message_to_reviewers_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_message_to_reviewers</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_message_to_reviewers_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_message_to_reviewers</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_notice_body_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_notice_body</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_notice_body_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_notice_body</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_notice_type_tid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">tid</em> of the field <em class="placeholder">field_notice_type</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_overflow_room_tid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">tid</em> of the field <em class="placeholder">field_overflow_room</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_page_image_alt' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">alt</em> of the field <em class="placeholder">field_page_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_page_image_fid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">fid</em> of the field <em class="placeholder">field_page_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_page_image_height' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">height</em> of the field <em class="placeholder">field_page_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_page_image_title' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">title</em> of the field <em class="placeholder">field_page_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_page_image_width' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">width</em> of the field <em class="placeholder">field_page_image</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_presentation_link_attributes' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">attributes</em> of the field <em class="placeholder">field_presentation_link</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_presentation_link_title' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">title</em> of the field <em class="placeholder">field_presentation_link</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_presentation_link_url' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">url</em> of the field <em class="placeholder">field_presentation_link</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_presentation_status_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_presentation_status</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_presentation_tags_tid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">tid</em> of the field <em class="placeholder">field_presentation_tags</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_presentation_to_upload_description' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">description</em> of the field <em class="placeholder">field_presentation_to_upload</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_presentation_to_upload_display' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">display</em> of the field <em class="placeholder">field_presentation_to_upload</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_presentation_to_upload_fid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">fid</em> of the field <em class="placeholder">field_presentation_to_upload</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_primary_email_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_primary_email</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_primary_email_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_primary_email</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_promo_file_description' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">description</em> of the field <em class="placeholder">field_promo_file</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_promo_file_display' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">display</em> of the field <em class="placeholder">field_promo_file</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_promo_file_fid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">fid</em> of the field <em class="placeholder">field_promo_file</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_pub_date_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_pub_date</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_pub_link_attributes' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">attributes</em> of the field <em class="placeholder">field_pub_link</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_pub_link_title' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">title</em> of the field <em class="placeholder">field_pub_link</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_pub_link_url' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">url</em> of the field <em class="placeholder">field_pub_link</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_pub_name_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_pub_name</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_pub_name_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_pub_name</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_publish_on_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_publish_on</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_ready_for_approval_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_ready_for_approval</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_release_date_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_release_date</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_room_tid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">tid</em> of the field <em class="placeholder">field_room</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_room_video_tid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">tid</em> of the field <em class="placeholder">field_room_video</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_scale_event_tid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">tid</em> of the field <em class="placeholder">field_scale_event</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_schedule_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_schedule</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_schedule_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_schedule</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_short_abstract_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_short_abstract</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_short_abstract_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_short_abstract</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_speaker_uid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">uid</em> of the field <em class="placeholder">field_speaker</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_specificatins_format' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">format</em> of the field <em class="placeholder">field_specificatins</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_specificatins_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_specificatins</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_sponsor_nid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">nid</em> of the field <em class="placeholder">field_sponsor</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_sponsor_type_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_sponsor_type</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_sponsor_website_attributes' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">attributes</em> of the field <em class="placeholder">field_sponsor_website</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_sponsor_website_title' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">title</em> of the field <em class="placeholder">field_sponsor_website</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_sponsor_website_url' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">url</em> of the field <em class="placeholder">field_sponsor_website</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_tags_tid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">tid</em> of the field <em class="placeholder">field_tags</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_time_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_time</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_time_value2' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value2</em> of the field <em class="placeholder">field_time</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_topic_tid' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">tid</em> of the field <em class="placeholder">field_topic</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_when_value' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value</em> of the field <em class="placeholder">field_when</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:field_when_value2' => array(
      'description' => 'Node: Field Value - The (simple scalar) value of the column <em class="placeholder">value2</em> of the field <em class="placeholder">field_when</em>. The value will be converted in its string representation.',
      'page cache' => 1,
    ),
    'node:language' => array(
      'description' => 'Node: Language - The code of the selected language of a node (formatted like "en" or "de") or "neutral". See <a href="/admin/config/language">admin/config/language</a> for the codes of your enabled languages',
      'page cache' => 1,
      'validator' => 'themekey_validator_language',
    ),
    'node:nid' => array(
      'description' => 'Node: ID - The id of a node (nid), can be found in the URL of the node, "node/23" or "node/23/edit" (23 = nid)',
      'page cache' => 1,
      'validator' => 'themekey_validator_ctype_digit',
    ),
    'node:promote' => array(
      'description' => 'Node: Promoted - If the node is promoted to the front page. Possible values are "0" for true and "1" for false.',
      'page cache' => 1,
      'validator' => 'themekey_validator_numeric_boolean',
    ),
    'node:sticky' => array(
      'description' => 'Node: Sticky - If the node is set "Sticky at top of lists". Possible values are "0" for true and "1" for false.',
      'page cache' => 1,
      'validator' => 'themekey_validator_numeric_boolean',
    ),
    'node:title' => array(
      'description' => 'Node: Title - The title of the node.',
      'page cache' => 1,
    ),
    'node:type' => array(
      'description' => 'Node: Type - The machine-readable content type of the node. See <a href="/admin/structure/types">admin/structure/types</a> for your content types (use column "Type"). Drupal default types are "page" and "story".',
      'page cache' => 1,
      'validator' => 'themekey_validator_node_type',
    ),
    'node:uid' => array(
      'description' => 'Node: User ID - The node author\'s user id (uid). The user id can be found in the URL of the user\'s profile page, "user/23" or "user/23/edit" (23 = uid). See <a href="/admin/user/user/list">admin/user/user/list</a> for your users.',
      'page cache' => 1,
      'validator' => 'themekey_validator_ctype_digit',
    ),
    'node:vid' => array(
      'description' => 'Node: The version id of a node (vid), mostly for internal use within ThemeKey. In most cases it\'s better to use node:nid within your rule chains.',
      'page cache' => 1,
      'validator' => 'themekey_validator_ctype_digit',
    ),
    'path:node_alias' => array(
      'description' => 'Path: Node alias - The path alias assigned to a node.',
      'page cache' => 1,
      'validator' => '',
    ),
    'system:cookie' => array(
      'description' => 'System: Cookie - Every single cookie and its value if present will be formatted like \'COOKIE_NAME=COOKIE_VALUE\'',
      'page cache' => 0,
    ),
    'system:date' => array(
      'description' => 'System: Date - Current time formatted as Y-m-d (example: 2009-12-24)',
      'page cache' => 2,
      'validator' => 'themekey_validator_date',
    ),
    'system:date_time' => array(
      'description' => 'System: Date Time - Current time formatted as Y-m-d H:i:s (example: 2009-12-24 18:30:10)',
      'page cache' => 2,
      'validator' => 'themekey_validator_date_time',
    ),
    'system:day_of_month' => array(
      'description' => 'System: Day of Month - Current day of the month formatted as 1 - 31',
      'page cache' => 2,
      'validator' => 'themekey_validator_day_of_month',
    ),
    'system:day_of_week' => array(
      'description' => 'System: Day of Week - Current day of the week formatted as three letters \'Mon\' through \'Sun\'',
      'page cache' => 2,
      'validator' => 'themekey_validator_day_of_week',
    ),
    'system:dummy' => array(
      'description' => 'System: Dummy - Dummy property. Value is always \'dummy\'',
      'page cache' => 1,
    ),
    'system:host' => array(
      'description' => 'System: HTTP_HOST - The hostname/domain of the site without http:// or https://, like "www.drupal.org" or "www.biologis.com"',
      'page cache' => 1,
      'validator' => 'themekey_validator_http_host',
    ),
    'system:http_header' => array(
      'description' => 'System: HTTP Header - Every single HTTP header and its value if present will be formatted like \'HEADER_NAME=HEADER_VALUE\'',
      'page cache' => 0,
    ),
    'system:https' => array(
      'description' => 'System: \'HTTPS\' - Set to \'true\' value if the script was queried through the HTTPS protocol, otherwise \'false\'.',
      'page cache' => 1,
      'validator' => 'themekey_validator_string_boolean',
    ),
    'system:month' => array(
      'description' => 'System: Month - Current month formatted as \'Jan\' through \'Dec\'',
      'page cache' => 2,
      'validator' => 'themekey_validator_month',
    ),
    'system:post' => array(
      'description' => 'System: POST - Every single POST value formatted like \'POST_VARIABLE_NAME=POST_VARIABLE_VALUE\'. Example: form_id=node_form. If the POST value is not a scalar but a complex type like array or object, the resulting string is formatted as \'POST_VARIABLE_NAME\' without a value.',
      'page cache' => 0,
    ),
    'system:query_param' => array(
      'description' => 'System: Query Parameter - Every single query parameter other than \'q\' and its value, if present. Note that values are url decoded. Example: \'?q=node&foo=bar&dummy&filter=tid%3A27\' will cause three entries \'foo=bar\', \'dummy\' and \'filter=tid:27\'. For \'q\', see property drupal:get_q.',
      'page cache' => 1,
    ),
    'system:query_string' => array(
      'description' => 'System: Query String - Complete query string except parameter \'q\'. Example: \'?q=node&foo=bar&dummy&filter=tid%3A27\' will result in \'foo=bar&dummy&filter=tid%3A27\'. For \'q\' see property drupal:get_q.',
      'page cache' => 1,
    ),
    'system:random' => array(
      'description' => 'System: Random - A random value that could be \'0\' or 1\'.',
      'page cache' => 0,
      'validator' => 'themekey_validator_numeric_boolean',
    ),
    'system:referer' => array(
      'description' => 'System: \'HTTP_REFERER\' - The address of the page (if any) which referred the user agent to the current page. This is set by the user agent. Not all user agents will set this, and some provide the ability to modify HTTP_REFERER as a feature. In short, it cannot really be trusted.',
      'page cache' => 0,
    ),
    'system:remote_ip' => array(
      'description' => 'System: \'REMOTE_ADDR\' - The IP address from which the user is viewing the current page.',
      'page cache' => 0,
      'validator' => 'themekey_validator_ip_address',
    ),
    'system:server_ip' => array(
      'description' => 'System: \'SERVER_ADDR\' - The IP address of the server under which the current script is executing.',
      'page cache' => 0,
      'validator' => 'themekey_validator_ip_address',
    ),
    'system:server_name' => array(
      'description' => 'System:  \'SERVER_NAME\' - The name of the server host under which the current script is executing. If the script is running on a virtual host, this will be the value defined for that virtual host.',
      'page cache' => 0,
    ),
    'system:server_port' => array(
      'description' => 'System: \'SERVER_PORT\' - The port on the server machine being used by the web server for communication. For default setups, this will be \'80\'; using SSL, for instance, will change this to whatever your defined secure HTTP port is.',
      'page cache' => 0,
      'validator' => 'themekey_validator_ctype_digit',
    ),
    'system:session' => array(
      'description' => 'System: Session - Every single session parameter and its value, if a value is present and a simple type (string, integer, boolean). Booleans are represented as integers; \'1\' as TRUE and \'0\' as FALSE.',
      'page cache' => 1,
    ),
    'system:time' => array(
      'description' => 'System: Time - Current time formatted as H:i:s (example: 18:30:10)',
      'page cache' => 2,
      'validator' => 'themekey_validator_time',
    ),
    'system:user_agent' => array(
      'description' => 'System: \'HTTP_USER_AGENT\' - Contents of the User-Agent: header from the current request, if there is one. This is a string denoting the user agent which is accessing the page. A typical example is: Mozilla/4.5 [en] (X11; U; Linux 2.2.9 i586).',
      'page cache' => 0,
    ),
    'system:user_browser' => array(
      'deprecated' => TRUE,
      'deprecated message' => 'Property system:user_browser is deprecated. Consider to use one of the new properties ThemeKey provides in combination with <a href="https://drupal.org/project/browscap">Browscap</a>, <a href="https://drupal.org/project/mobile_detect_api">Mobile Detect API</a>, or <a href="https://drupal.org/project/mobile_detect_api">Mobile Detect</a>.',
      'description' => 'System: Browser - Information about user\'s browser. Possible values: \'Blazer [VERSION]\', \'Internet Explorer [VERSION]\', \'Internet Explorer Mobile [VERSION]\', \'Mozilla Firefox [VERSION]\', \'Netscape [VERSION]\', \'Google Chrome [VERSION]\', \'Safari [VERSION]\', \'Galeon [VERSION]\', \'Konqueror [VERSION]\', \'Gecko based\', \'Opera [VERSION]\', \'Lynx [VERSION]\', \'Fennec [VERSION]\', \'Maemo [VERSION]\', \'unknown\'',
      'page cache' => 0,
    ),
    'system:user_browser_simplified' => array(
      'deprecated' => TRUE,
      'deprecated message' => 'Property system:user_browser_simplified is deprecated. Consider to use one of the new properties ThemeKey provides in combination with <a href="https://drupal.org/project/browscap">Browscap</a>, <a href="https://drupal.org/project/mobile_detect_api">Mobile Detect API</a>, or <a href="https://drupal.org/project/mobile_detect_api">Mobile Detect</a>.',
      'description' => 'System: Browser - Simplified information about user\'s browser. Possible values: \'Blazer\', \'Internet Explorer\', \'Internet Explorer Mobile\', \'Mozilla Firefox\', \'Netscape\', \'Google Chrome\', \'Safari\', \'Galeon\', \'Konqueror\', \'Gecko based\', \'Opera\', \'Lynx\', \'Fennec\', \'Maemo\', \'unknown\'',
      'page cache' => 0,
    ),
    'system:user_os' => array(
      'deprecated' => TRUE,
      'deprecated message' => 'Property system:user_os is deprecated. Consider to use one of the new properties ThemeKey provides in combination with <a href="https://drupal.org/project/browscap">Browscap</a>, <a href="https://drupal.org/project/mobile_detect_api">Mobile Detect API</a>, or <a href="https://drupal.org/project/mobile_detect_api">Mobile Detect</a>.',
      'description' => 'System: Operating System - Information about user\'s browser. Possible values: \'Windows XP\', \'Windows Vista\', \'Windows 98\', \'Windows 2000\', \'Windows 2003 server\', \'Windows NT\',  \'Windows ME\', \'Windows CE\', \'Windows ME\', \'Windows Phone\', \'iPhone\', \'iPad\', \'Mac OS X\', \'Macintosh\', \'Linux\', \'Free BSD\', \'Symbian\', \'webOS\', \'Android\', \'Blackberry\', \'unknown\'',
      'page cache' => 0,
    ),
    'system:user_os_simplified' => array(
      'deprecated' => TRUE,
      'deprecated message' => 'Property system:user_os_simplified is deprecated. Consider to use one of the new properties ThemeKey provides in combination with <a href="https://drupal.org/project/browscap">Browscap</a>, <a href="https://drupal.org/project/mobile_detect_api">Mobile Detect API</a>, or <a href="https://drupal.org/project/mobile_detect_api">Mobile Detect</a>.',
      'description' => 'System: Operating System - Simplified information about user\'s browser. Possible values: \'Windows\', \'Windows Phone\', \'iPhone\', \'iPad\', \'Mac OS X\', \'Macintosh\', \'Linux\', \'Free BSD\', \'Symbian\', \'webOS\', \'Android\', \'Blackberry\', \'unknown\'',
      'page cache' => 0,
    ),
    'taxonomy:name' => array(
      'description' => 'Taxonomy: Name - The term name (name) of a taxonomy term without support for translations.',
      'page cache' => 1,
      'validator' => '',
    ),
    'taxonomy:tid' => array(
      'description' => 'Taxonomy: Term - The term id (tid) of a taxonomy term.',
      'page cache' => 1,
      'validator' => 'themekey_validator_ctype_digit',
    ),
    'taxonomy:tid_and_childs' => array(
      'description' => 'Taxonomy: Term and its childs - The term id (tid) of a taxonomy term. If set, all child terms of this term will be used too.',
      'page cache' => 0,
      'validator' => 'themekey_validator_ctype_digit',
    ),
    'taxonomy:vid' => array(
      'description' => 'Taxonomy: Vocabulary - The vocabulary id (vid) of a taxonomy vocabulary. See <a href="/admin/structure/taxonomy">admin/structure/taxonomy</a> for your vocabularies.',
      'page cache' => 1,
      'validator' => 'themekey_validator_ctype_digit',
    ),
    'user:hostname' => array(
      'description' => 'User: Hostname - The user hostname property which is the IP address of client machine, adjusted for reverse proxy. Text from Drupal bootstrap.inc:
      If Drupal is behind a reverse proxy, we use the X-Forwarded-For header instead of $_SERVER[\'REMOTE_ADDR\'], which would be the IP address of the proxy server, and not the client\'s.',
      'page cache' => 0,
      'validator' => 'themekey_validator_http_host',
    ),
    'user:language' => array(
      'description' => 'User: Language - The language the user has set in the settings of his profile page.
      Format is the language code (for example "en" for English or "de" for German) that can be found on <a href="/admin/config/regional/language/overview">admin/config/regional/language/overview</a>.',
      'page cache' => 1,
      'validator' => 'themekey_validator_language',
    ),
    'user:name' => array(
      'description' => 'User: Name - The username of the user. See <a href="/admin/people/people">admin/people/people</a> for your users.',
      'page cache' => 1,
    ),
    'user:role' => array(
      'description' => 'User: Role - Defined user roles (examples: \'anonymous user\', \'authenticated user\')',
      'page cache' => 1,
      'validator' => 'themekey_validator_role',
    ),
    'user:uid' => array(
      'description' => 'User: ID - The id of the user (uid). The user id can be found in the URL of the users profile page, "user/23" or "user/23/edit" (23 = uid). See <a href="/admin/people/people">admin/people/people</a> for your users.',
      'page cache' => 1,
      'validator' => 'themekey_validator_ctype_digit',
    ),
    'views:human_name' => array(
      'description' => 'Views: Human Name - The (human readable) name of a view',
      'page cache' => 1,
    ),
    'views:machine_name' => array(
      'description' => 'Views: Machine Name - The machine name of a view',
      'page cache' => 1,
    ),
    'views:vid' => array(
      'description' => 'Views: VID - The vid of a view (vid)',
      'page cache' => 1,
      'validator' => 'themekey_validator_ctype_digit',
    ),
  );
  $export['themekey_attributes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'themekey_cron_rules_processed';
  $strongarm->value = array();
  $export['themekey_cron_rules_processed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'themekey_maps';
  $strongarm->value = array(
    0 => array(
      'callback' => 'themekey_comment_cid2nid',
      'dst' => 'node:nid',
      'src' => 'comment:cid',
    ),
    1 => array(
      'callback' => 'themekey_node_nid2changed',
      'dst' => 'node:changed',
      'src' => 'node:nid',
    ),
    2 => array(
      'callback' => 'themekey_node_nid2created',
      'dst' => 'node:created',
      'src' => 'node:nid',
    ),
    3 => array(
      'callback' => 'themekey_node_timestamp2datetime',
      'dst' => 'node:changed_date_time',
      'src' => 'node:changed',
    ),
    4 => array(
      'callback' => 'themekey_node_timestamp2datetime',
      'dst' => 'node:created_date_time',
      'src' => 'node:created',
    ),
    5 => array(
      'callback' => 'themekey_node_timestamp2date',
      'dst' => 'node:changed_date',
      'src' => 'node:changed',
    ),
    6 => array(
      'callback' => 'themekey_node_timestamp2date',
      'dst' => 'node:created_date',
      'src' => 'node:created',
    ),
    7 => array(
      'callback' => 'themekey_node_nid2language',
      'dst' => 'node:language',
      'src' => 'node:nid',
    ),
    8 => array(
      'callback' => 'themekey_node_nid2vid',
      'dst' => 'node:vid',
      'src' => 'node:nid',
    ),
    9 => array(
      'callback' => 'themekey_node_nid2promote',
      'dst' => 'node:promote',
      'src' => 'node:nid',
    ),
    10 => array(
      'callback' => 'themekey_node_nid2sticky',
      'dst' => 'node:sticky',
      'src' => 'node:nid',
    ),
    11 => array(
      'callback' => 'themekey_node_nid2type',
      'dst' => 'node:type',
      'src' => 'node:nid',
    ),
    12 => array(
      'callback' => 'themekey_node_nid2uid',
      'dst' => 'node:uid',
      'src' => 'node:nid',
    ),
    13 => array(
      'callback' => 'themekey_node_nid2title',
      'dst' => 'node:title',
      'src' => 'node:nid',
    ),
    14 => array(
      'callback' => 'themekey_node_get_q2type',
      'dst' => 'node:type',
      'src' => 'drupal:get_q',
    ),
    15 => array(
      'args' => array(
        'column' => 'tid',
        'field_name' => 'field_scale_event',
        'translatable' => '0',
        'type' => 'taxonomy_term_reference',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_scale_event_tid',
      'src' => 'node:nid',
    ),
    16 => array(
      'args' => array(
        'column' => 'value',
        'field_name' => 'field_publish_on',
        'translatable' => '0',
        'type' => 'datestamp',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_publish_on_value',
      'src' => 'node:nid',
    ),
    17 => array(
      'args' => array(
        'column' => 'value',
        'field_name' => 'body',
        'translatable' => '0',
        'type' => 'text_with_summary',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:body_value',
      'src' => 'node:nid',
    ),
    18 => array(
      'args' => array(
        'column' => 'summary',
        'field_name' => 'body',
        'translatable' => '0',
        'type' => 'text_with_summary',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:body_summary',
      'src' => 'node:nid',
    ),
    19 => array(
      'args' => array(
        'column' => 'format',
        'field_name' => 'body',
        'translatable' => '0',
        'type' => 'text_with_summary',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:body_format',
      'src' => 'node:nid',
    ),
    20 => array(
      'args' => array(
        'column' => 'fid',
        'field_name' => 'field_blog_image',
        'translatable' => '0',
        'type' => 'image',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_blog_image_fid',
      'src' => 'node:nid',
    ),
    21 => array(
      'args' => array(
        'column' => 'alt',
        'field_name' => 'field_blog_image',
        'translatable' => '0',
        'type' => 'image',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_blog_image_alt',
      'src' => 'node:nid',
    ),
    22 => array(
      'args' => array(
        'column' => 'title',
        'field_name' => 'field_blog_image',
        'translatable' => '0',
        'type' => 'image',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_blog_image_title',
      'src' => 'node:nid',
    ),
    23 => array(
      'args' => array(
        'column' => 'width',
        'field_name' => 'field_blog_image',
        'translatable' => '0',
        'type' => 'image',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_blog_image_width',
      'src' => 'node:nid',
    ),
    24 => array(
      'args' => array(
        'column' => 'height',
        'field_name' => 'field_blog_image',
        'translatable' => '0',
        'type' => 'image',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_blog_image_height',
      'src' => 'node:nid',
    ),
    25 => array(
      'args' => array(
        'column' => 'tid',
        'field_name' => 'field_tags',
        'translatable' => '0',
        'type' => 'taxonomy_term_reference',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_tags_tid',
      'src' => 'node:nid',
    ),
    26 => array(
      'args' => array(
        'column' => 'value',
        'field_name' => 'field_ready_for_approval',
        'translatable' => '0',
        'type' => 'list_boolean',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_ready_for_approval_value',
      'src' => 'node:nid',
    ),
    27 => array(
      'args' => array(
        'column' => 'uid',
        'field_name' => 'field_featured_speaker',
        'translatable' => '0',
        'type' => 'user_reference',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_featured_speaker_uid',
      'src' => 'node:nid',
    ),
    28 => array(
      'args' => array(
        'column' => 'tid',
        'field_name' => 'field_room',
        'translatable' => '0',
        'type' => 'taxonomy_term_reference',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_room_tid',
      'src' => 'node:nid',
    ),
    29 => array(
      'args' => array(
        'column' => 'tid',
        'field_name' => 'field_notice_type',
        'translatable' => '0',
        'type' => 'taxonomy_term_reference',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_notice_type_tid',
      'src' => 'node:nid',
    ),
    30 => array(
      'args' => array(
        'column' => 'value',
        'field_name' => 'field_notice_body',
        'translatable' => '0',
        'type' => 'text_long',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_notice_body_value',
      'src' => 'node:nid',
    ),
    31 => array(
      'args' => array(
        'column' => 'format',
        'field_name' => 'field_notice_body',
        'translatable' => '0',
        'type' => 'text_long',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_notice_body_format',
      'src' => 'node:nid',
    ),
    32 => array(
      'args' => array(
        'column' => 'tid',
        'field_name' => 'field_topic',
        'translatable' => '0',
        'type' => 'taxonomy_term_reference',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_topic_tid',
      'src' => 'node:nid',
    ),
    33 => array(
      'args' => array(
        'column' => 'value',
        'field_name' => 'field_time',
        'translatable' => '0',
        'type' => 'datetime',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_time_value',
      'src' => 'node:nid',
    ),
    34 => array(
      'args' => array(
        'column' => 'value2',
        'field_name' => 'field_time',
        'translatable' => '0',
        'type' => 'datetime',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_time_value2',
      'src' => 'node:nid',
    ),
    35 => array(
      'args' => array(
        'column' => 'fid',
        'field_name' => 'field_page_image',
        'translatable' => '0',
        'type' => 'image',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_page_image_fid',
      'src' => 'node:nid',
    ),
    36 => array(
      'args' => array(
        'column' => 'alt',
        'field_name' => 'field_page_image',
        'translatable' => '0',
        'type' => 'image',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_page_image_alt',
      'src' => 'node:nid',
    ),
    37 => array(
      'args' => array(
        'column' => 'title',
        'field_name' => 'field_page_image',
        'translatable' => '0',
        'type' => 'image',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_page_image_title',
      'src' => 'node:nid',
    ),
    38 => array(
      'args' => array(
        'column' => 'width',
        'field_name' => 'field_page_image',
        'translatable' => '0',
        'type' => 'image',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_page_image_width',
      'src' => 'node:nid',
    ),
    39 => array(
      'args' => array(
        'column' => 'height',
        'field_name' => 'field_page_image',
        'translatable' => '0',
        'type' => 'image',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_page_image_height',
      'src' => 'node:nid',
    ),
    40 => array(
      'args' => array(
        'column' => 'url',
        'field_name' => 'field_presentation_link',
        'translatable' => '0',
        'type' => 'link_field',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_presentation_link_url',
      'src' => 'node:nid',
    ),
    41 => array(
      'args' => array(
        'column' => 'title',
        'field_name' => 'field_presentation_link',
        'translatable' => '0',
        'type' => 'link_field',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_presentation_link_title',
      'src' => 'node:nid',
    ),
    42 => array(
      'args' => array(
        'column' => 'attributes',
        'field_name' => 'field_presentation_link',
        'translatable' => '0',
        'type' => 'link_field',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_presentation_link_attributes',
      'src' => 'node:nid',
    ),
    43 => array(
      'args' => array(
        'column' => 'fid',
        'field_name' => 'field_presentation_to_upload',
        'translatable' => '0',
        'type' => 'file',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_presentation_to_upload_fid',
      'src' => 'node:nid',
    ),
    44 => array(
      'args' => array(
        'column' => 'display',
        'field_name' => 'field_presentation_to_upload',
        'translatable' => '0',
        'type' => 'file',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_presentation_to_upload_display',
      'src' => 'node:nid',
    ),
    45 => array(
      'args' => array(
        'column' => 'description',
        'field_name' => 'field_presentation_to_upload',
        'translatable' => '0',
        'type' => 'file',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_presentation_to_upload_description',
      'src' => 'node:nid',
    ),
    46 => array(
      'args' => array(
        'column' => 'value',
        'field_name' => 'field_brief_description',
        'translatable' => '0',
        'type' => 'text',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_brief_description_value',
      'src' => 'node:nid',
    ),
    47 => array(
      'args' => array(
        'column' => 'format',
        'field_name' => 'field_brief_description',
        'translatable' => '0',
        'type' => 'text',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_brief_description_format',
      'src' => 'node:nid',
    ),
    48 => array(
      'args' => array(
        'column' => 'value',
        'field_name' => 'field_audio_video',
        'translatable' => '0',
        'type' => 'text_long',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_audio_video_value',
      'src' => 'node:nid',
    ),
    49 => array(
      'args' => array(
        'column' => 'format',
        'field_name' => 'field_audio_video',
        'translatable' => '0',
        'type' => 'text_long',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_audio_video_format',
      'src' => 'node:nid',
    ),
    50 => array(
      'args' => array(
        'column' => 'value',
        'field_name' => 'field_short_abstract',
        'translatable' => '0',
        'type' => 'text_long',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_short_abstract_value',
      'src' => 'node:nid',
    ),
    51 => array(
      'args' => array(
        'column' => 'format',
        'field_name' => 'field_short_abstract',
        'translatable' => '0',
        'type' => 'text_long',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_short_abstract_format',
      'src' => 'node:nid',
    ),
    52 => array(
      'args' => array(
        'column' => 'value',
        'field_name' => 'field_long_abstract',
        'translatable' => '0',
        'type' => 'text_long',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_long_abstract_value',
      'src' => 'node:nid',
    ),
    53 => array(
      'args' => array(
        'column' => 'format',
        'field_name' => 'field_long_abstract',
        'translatable' => '0',
        'type' => 'text_long',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_long_abstract_format',
      'src' => 'node:nid',
    ),
    54 => array(
      'args' => array(
        'column' => 'value',
        'field_name' => 'field_message_to_reviewers',
        'translatable' => '0',
        'type' => 'text_long',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_message_to_reviewers_value',
      'src' => 'node:nid',
    ),
    55 => array(
      'args' => array(
        'column' => 'format',
        'field_name' => 'field_message_to_reviewers',
        'translatable' => '0',
        'type' => 'text_long',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_message_to_reviewers_format',
      'src' => 'node:nid',
    ),
    56 => array(
      'args' => array(
        'column' => 'value',
        'field_name' => 'field_primary_email',
        'translatable' => '0',
        'type' => 'text',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_primary_email_value',
      'src' => 'node:nid',
    ),
    57 => array(
      'args' => array(
        'column' => 'format',
        'field_name' => 'field_primary_email',
        'translatable' => '0',
        'type' => 'text',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_primary_email_format',
      'src' => 'node:nid',
    ),
    58 => array(
      'args' => array(
        'column' => 'tid',
        'field_name' => 'field_presentation_tags',
        'translatable' => '0',
        'type' => 'taxonomy_term_reference',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_presentation_tags_tid',
      'src' => 'node:nid',
    ),
    59 => array(
      'args' => array(
        'column' => 'tid',
        'field_name' => 'field_audience',
        'translatable' => '0',
        'type' => 'taxonomy_term_reference',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_audience_tid',
      'src' => 'node:nid',
    ),
    60 => array(
      'args' => array(
        'column' => 'uid',
        'field_name' => 'field_speaker',
        'translatable' => '0',
        'type' => 'user_reference',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_speaker_uid',
      'src' => 'node:nid',
    ),
    61 => array(
      'args' => array(
        'column' => 'value',
        'field_name' => 'field_presentation_status',
        'translatable' => '0',
        'type' => 'list_text',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_presentation_status_value',
      'src' => 'node:nid',
    ),
    62 => array(
      'args' => array(
        'column' => 'tid',
        'field_name' => 'field_overflow_room',
        'translatable' => '0',
        'type' => 'taxonomy_term_reference',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_overflow_room_tid',
      'src' => 'node:nid',
    ),
    63 => array(
      'args' => array(
        'column' => 'value',
        'field_name' => 'field_appropriate_for',
        'translatable' => '0',
        'type' => 'list_text',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_appropriate_for_value',
      'src' => 'node:nid',
    ),
    64 => array(
      'args' => array(
        'column' => 'value',
        'field_name' => 'field_author',
        'translatable' => '0',
        'type' => 'text',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_author_value',
      'src' => 'node:nid',
    ),
    65 => array(
      'args' => array(
        'column' => 'format',
        'field_name' => 'field_author',
        'translatable' => '0',
        'type' => 'text',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_author_format',
      'src' => 'node:nid',
    ),
    66 => array(
      'args' => array(
        'column' => 'value',
        'field_name' => 'field_pub_date',
        'translatable' => '0',
        'type' => 'datestamp',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_pub_date_value',
      'src' => 'node:nid',
    ),
    67 => array(
      'args' => array(
        'column' => 'url',
        'field_name' => 'field_pub_link',
        'translatable' => '0',
        'type' => 'link_field',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_pub_link_url',
      'src' => 'node:nid',
    ),
    68 => array(
      'args' => array(
        'column' => 'title',
        'field_name' => 'field_pub_link',
        'translatable' => '0',
        'type' => 'link_field',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_pub_link_title',
      'src' => 'node:nid',
    ),
    69 => array(
      'args' => array(
        'column' => 'attributes',
        'field_name' => 'field_pub_link',
        'translatable' => '0',
        'type' => 'link_field',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_pub_link_attributes',
      'src' => 'node:nid',
    ),
    70 => array(
      'args' => array(
        'column' => 'value',
        'field_name' => 'field_pub_name',
        'translatable' => '0',
        'type' => 'text',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_pub_name_value',
      'src' => 'node:nid',
    ),
    71 => array(
      'args' => array(
        'column' => 'format',
        'field_name' => 'field_pub_name',
        'translatable' => '0',
        'type' => 'text',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_pub_name_format',
      'src' => 'node:nid',
    ),
    72 => array(
      'args' => array(
        'column' => 'value',
        'field_name' => 'field_release_date',
        'translatable' => '0',
        'type' => 'datestamp',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_release_date_value',
      'src' => 'node:nid',
    ),
    73 => array(
      'args' => array(
        'column' => 'value',
        'field_name' => 'field_item_type',
        'translatable' => '0',
        'type' => 'list_text',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_item_type_value',
      'src' => 'node:nid',
    ),
    74 => array(
      'args' => array(
        'column' => 'value',
        'field_name' => 'field_specificatins',
        'translatable' => '0',
        'type' => 'text',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_specificatins_value',
      'src' => 'node:nid',
    ),
    75 => array(
      'args' => array(
        'column' => 'format',
        'field_name' => 'field_specificatins',
        'translatable' => '0',
        'type' => 'text',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_specificatins_format',
      'src' => 'node:nid',
    ),
    76 => array(
      'args' => array(
        'column' => 'fid',
        'field_name' => 'field_promo_file',
        'translatable' => '0',
        'type' => 'file',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_promo_file_fid',
      'src' => 'node:nid',
    ),
    77 => array(
      'args' => array(
        'column' => 'display',
        'field_name' => 'field_promo_file',
        'translatable' => '0',
        'type' => 'file',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_promo_file_display',
      'src' => 'node:nid',
    ),
    78 => array(
      'args' => array(
        'column' => 'description',
        'field_name' => 'field_promo_file',
        'translatable' => '0',
        'type' => 'file',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_promo_file_description',
      'src' => 'node:nid',
    ),
    79 => array(
      'args' => array(
        'column' => 'value',
        'field_name' => 'field_embed_code',
        'translatable' => '0',
        'type' => 'text_long',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_embed_code_value',
      'src' => 'node:nid',
    ),
    80 => array(
      'args' => array(
        'column' => 'format',
        'field_name' => 'field_embed_code',
        'translatable' => '0',
        'type' => 'text_long',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_embed_code_format',
      'src' => 'node:nid',
    ),
    81 => array(
      'args' => array(
        'column' => 'fid',
        'field_name' => 'field_logo',
        'translatable' => '0',
        'type' => 'image',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_logo_fid',
      'src' => 'node:nid',
    ),
    82 => array(
      'args' => array(
        'column' => 'alt',
        'field_name' => 'field_logo',
        'translatable' => '0',
        'type' => 'image',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_logo_alt',
      'src' => 'node:nid',
    ),
    83 => array(
      'args' => array(
        'column' => 'title',
        'field_name' => 'field_logo',
        'translatable' => '0',
        'type' => 'image',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_logo_title',
      'src' => 'node:nid',
    ),
    84 => array(
      'args' => array(
        'column' => 'width',
        'field_name' => 'field_logo',
        'translatable' => '0',
        'type' => 'image',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_logo_width',
      'src' => 'node:nid',
    ),
    85 => array(
      'args' => array(
        'column' => 'height',
        'field_name' => 'field_logo',
        'translatable' => '0',
        'type' => 'image',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_logo_height',
      'src' => 'node:nid',
    ),
    86 => array(
      'args' => array(
        'column' => 'value',
        'field_name' => 'field_when',
        'translatable' => '0',
        'type' => 'datestamp',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_when_value',
      'src' => 'node:nid',
    ),
    87 => array(
      'args' => array(
        'column' => 'value2',
        'field_name' => 'field_when',
        'translatable' => '0',
        'type' => 'datestamp',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_when_value2',
      'src' => 'node:nid',
    ),
    88 => array(
      'args' => array(
        'column' => 'nid',
        'field_name' => 'field_sponsor',
        'translatable' => '0',
        'type' => 'node_reference',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_sponsor_nid',
      'src' => 'node:nid',
    ),
    89 => array(
      'args' => array(
        'column' => 'value',
        'field_name' => 'field_schedule',
        'translatable' => '0',
        'type' => 'text_long',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_schedule_value',
      'src' => 'node:nid',
    ),
    90 => array(
      'args' => array(
        'column' => 'format',
        'field_name' => 'field_schedule',
        'translatable' => '0',
        'type' => 'text_long',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_schedule_format',
      'src' => 'node:nid',
    ),
    91 => array(
      'args' => array(
        'column' => 'fid',
        'field_name' => 'field_logo_website',
        'translatable' => '0',
        'type' => 'image',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_logo_website_fid',
      'src' => 'node:nid',
    ),
    92 => array(
      'args' => array(
        'column' => 'alt',
        'field_name' => 'field_logo_website',
        'translatable' => '0',
        'type' => 'image',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_logo_website_alt',
      'src' => 'node:nid',
    ),
    93 => array(
      'args' => array(
        'column' => 'title',
        'field_name' => 'field_logo_website',
        'translatable' => '0',
        'type' => 'image',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_logo_website_title',
      'src' => 'node:nid',
    ),
    94 => array(
      'args' => array(
        'column' => 'width',
        'field_name' => 'field_logo_website',
        'translatable' => '0',
        'type' => 'image',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_logo_website_width',
      'src' => 'node:nid',
    ),
    95 => array(
      'args' => array(
        'column' => 'height',
        'field_name' => 'field_logo_website',
        'translatable' => '0',
        'type' => 'image',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_logo_website_height',
      'src' => 'node:nid',
    ),
    96 => array(
      'args' => array(
        'column' => 'value',
        'field_name' => 'field_exhibitor_type',
        'translatable' => '0',
        'type' => 'list_text',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_exhibitor_type_value',
      'src' => 'node:nid',
    ),
    97 => array(
      'args' => array(
        'column' => 'value',
        'field_name' => 'field_booth_number',
        'translatable' => '0',
        'type' => 'text',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_booth_number_value',
      'src' => 'node:nid',
    ),
    98 => array(
      'args' => array(
        'column' => 'format',
        'field_name' => 'field_booth_number',
        'translatable' => '0',
        'type' => 'text',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_booth_number_format',
      'src' => 'node:nid',
    ),
    99 => array(
      'args' => array(
        'column' => 'value',
        'field_name' => 'field_exhibitor_sponsor',
        'translatable' => '0',
        'type' => 'list_text',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_exhibitor_sponsor_value',
      'src' => 'node:nid',
    ),
    100 => array(
      'args' => array(
        'column' => 'url',
        'field_name' => 'field_sponsor_website',
        'translatable' => '0',
        'type' => 'link_field',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_sponsor_website_url',
      'src' => 'node:nid',
    ),
    101 => array(
      'args' => array(
        'column' => 'title',
        'field_name' => 'field_sponsor_website',
        'translatable' => '0',
        'type' => 'link_field',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_sponsor_website_title',
      'src' => 'node:nid',
    ),
    102 => array(
      'args' => array(
        'column' => 'attributes',
        'field_name' => 'field_sponsor_website',
        'translatable' => '0',
        'type' => 'link_field',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_sponsor_website_attributes',
      'src' => 'node:nid',
    ),
    103 => array(
      'args' => array(
        'column' => 'value',
        'field_name' => 'field_sponsor_type',
        'translatable' => '0',
        'type' => 'list_text',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_sponsor_type_value',
      'src' => 'node:nid',
    ),
    104 => array(
      'args' => array(
        'column' => 'tid',
        'field_name' => 'field_room_video',
        'translatable' => '0',
        'type' => 'taxonomy_term_reference',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_room_video_tid',
      'src' => 'node:nid',
    ),
    105 => array(
      'args' => array(
        'column' => 'value',
        'field_name' => 'field_embed_code_video',
        'translatable' => '0',
        'type' => 'text_long',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_embed_code_video_value',
      'src' => 'node:nid',
    ),
    106 => array(
      'args' => array(
        'column' => 'format',
        'field_name' => 'field_embed_code_video',
        'translatable' => '0',
        'type' => 'text_long',
      ),
      'callback' => 'themekey_node_nid2field_value',
      'dst' => 'node:field_embed_code_video_format',
      'src' => 'node:nid',
    ),
    107 => array(
      'callback' => 'themekey_path_nid2alias',
      'dst' => 'path:node_alias',
      'src' => 'node:nid',
    ),
    108 => array(
      'callback' => 'themekey_dummy2query_param',
      'dst' => 'system:query_param',
      'src' => 'system:dummy',
    ),
    109 => array(
      'callback' => 'themekey_dummy2cookie',
      'dst' => 'system:cookie',
      'src' => 'system:dummy',
    ),
    110 => array(
      'callback' => 'themekey_dummy2http_header',
      'dst' => 'system:http_header',
      'src' => 'system:dummy',
    ),
    111 => array(
      'callback' => 'themekey_dummy2post',
      'dst' => 'system:post',
      'src' => 'system:dummy',
    ),
    112 => array(
      'callback' => 'themekey_dummy2query_string',
      'dst' => 'system:query_string',
      'src' => 'system:dummy',
    ),
    113 => array(
      'callback' => 'themekey_dummy2date_time',
      'dst' => 'system:date_time',
      'src' => 'system:dummy',
    ),
    114 => array(
      'callback' => 'themekey_dummy2date',
      'dst' => 'system:date',
      'src' => 'system:dummy',
    ),
    115 => array(
      'callback' => 'themekey_dummy2month',
      'dst' => 'system:month',
      'src' => 'system:dummy',
    ),
    116 => array(
      'callback' => 'themekey_dummy2time',
      'dst' => 'system:time',
      'src' => 'system:dummy',
    ),
    117 => array(
      'callback' => 'themekey_dummy2day_of_week',
      'dst' => 'system:day_of_week',
      'src' => 'system:dummy',
    ),
    118 => array(
      'callback' => 'themekey_dummy2day_of_month',
      'dst' => 'system:day_of_month',
      'src' => 'system:dummy',
    ),
    119 => array(
      'callback' => 'themekey_dummy2user_browser',
      'dst' => 'system:user_browser',
      'src' => 'system:dummy',
    ),
    120 => array(
      'callback' => 'themekey_dummy2user_os',
      'dst' => 'system:user_os',
      'src' => 'system:dummy',
    ),
    121 => array(
      'callback' => 'themekey_user_browser2user_browser_simplified',
      'dst' => 'system:user_browser_simplified',
      'src' => 'system:user_browser',
    ),
    122 => array(
      'callback' => 'themekey_user_os2user_os_simplified',
      'dst' => 'system:user_os_simplified',
      'src' => 'system:user_os',
    ),
    123 => array(
      'callback' => 'themekey_dummy2session',
      'dst' => 'system:session',
      'src' => 'system:dummy',
    ),
    124 => array(
      'callback' => 'themekey_taxonomy_tid2vid',
      'dst' => 'taxonomy:vid',
      'src' => 'taxonomy:tid',
    ),
    125 => array(
      'callback' => 'themekey_taxonomy_tid2tid_and_parents',
      'dst' => 'taxonomy:tid_and_childs',
      'src' => 'taxonomy:tid',
    ),
    126 => array(
      'callback' => 'themekey_taxonomy_nid2tid',
      'dst' => 'taxonomy:tid',
      'src' => 'node:nid',
    ),
    127 => array(
      'callback' => 'themekey_taxonomy_tid2name',
      'dst' => 'taxonomy:name',
      'src' => 'taxonomy:tid',
    ),
    128 => array(
      'callback' => 'themekey_user_profile2theme',
      'dst' => 'themekey_ui:author_triggers_theme',
      'src' => 'profile:uid',
    ),
    129 => array(
      'callback' => 'themekey_views_getq2vid',
      'dst' => 'views:vid',
      'src' => 'drupal:get_q',
    ),
    130 => array(
      'callback' => 'themekey_views_getq2machine_name',
      'dst' => 'views:machine_name',
      'src' => 'drupal:get_q',
    ),
    131 => array(
      'callback' => 'themekey_views_getq2human_name',
      'dst' => 'views:human_name',
      'src' => 'drupal:get_q',
    ),
  );
  $export['themekey_maps'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'themekey_modules';
  $strongarm->value = array(
    0 => 'admin_menu',
    1 => 'comment',
    2 => 'node',
    3 => 'path',
    4 => 'system',
    5 => 'taxonomy',
    6 => 'user',
    7 => 'views',
  );
  $export['themekey_modules'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'themekey_paths';
  $strongarm->value = array(
    0 => array(
      'callbacks' => array(),
      'fit' => 21,
      'path' => 'node/#/revisions/#/view',
      'weight' => 10,
      'wildcards' => array(
        1 => 'node:nid',
        3 => 'node:vid',
      ),
    ),
    1 => array(
      'callbacks' => array(),
      'fit' => 12,
      'path' => 'comment/reply/#/#',
      'weight' => 3,
      'wildcards' => array(
        2 => 'node:nid',
        3 => 'comment:cid',
      ),
    ),
    2 => array(
      'callbacks' => array(),
      'fit' => 6,
      'path' => 'comment/reply/#',
      'weight' => 1,
      'wildcards' => array(
        2 => 'node:nid',
      ),
    ),
    3 => array(
      'callbacks' => array(),
      'fit' => 6,
      'path' => 'taxonomy/term/#',
      'weight' => 1,
      'wildcards' => array(
        2 => 'taxonomy:tid',
      ),
    ),
    4 => array(
      'callbacks' => array(),
      'fit' => 5,
      'path' => 'comment/#/edit',
      'weight' => 2,
      'wildcards' => array(
        1 => 'comment:cid',
      ),
    ),
    5 => array(
      'callbacks' => array(),
      'fit' => 5,
      'path' => 'comment/#/delete',
      'weight' => 2,
      'wildcards' => array(
        1 => 'comment:cid',
      ),
    ),
    6 => array(
      'callbacks' => array(),
      'fit' => 5,
      'path' => 'user/#/edit',
      'weight' => 2,
      'wildcards' => array(
        1 => 'profile:uid',
      ),
    ),
    7 => array(
      'callbacks' => array(),
      'fit' => 2,
      'path' => 'comment/#',
      'weight' => 1,
      'wildcards' => array(
        1 => 'comment:cid',
      ),
    ),
    8 => array(
      'callbacks' => array(),
      'fit' => 2,
      'path' => 'node/#',
      'weight' => 1,
      'wildcards' => array(
        1 => 'node:nid',
      ),
    ),
    9 => array(
      'callbacks' => array(),
      'fit' => 2,
      'path' => 'user/#',
      'weight' => 1,
      'wildcards' => array(
        1 => 'profile:uid',
      ),
    ),
  );
  $export['themekey_paths'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'themekey_properties';
  $strongarm->value = array(
    'comment:cid' => 'comment:cid',
    'drupal:base_path' => 'drupal:base_path',
    'drupal:get_q' => 'drupal:get_q',
    'drupal:is_front_page' => 'drupal:is_front_page',
    'drupal:path' => 'drupal:path',
    'drupal:path:wildcard' => 'drupal:path:wildcard',
    'drupal:path_is_admin' => 'drupal:path_is_admin',
    'node:body_format' => 'node:body_format',
    'node:body_summary' => 'node:body_summary',
    'node:body_value' => 'node:body_value',
    'node:changed' => 'node:changed',
    'node:changed_date' => 'node:changed_date',
    'node:changed_date_time' => 'node:changed_date_time',
    'node:created' => 'node:created',
    'node:created_date' => 'node:created_date',
    'node:created_date_time' => 'node:created_date_time',
    'node:field_appropriate_for_value' => 'node:field_appropriate_for_value',
    'node:field_audience_tid' => 'node:field_audience_tid',
    'node:field_audio_video_format' => 'node:field_audio_video_format',
    'node:field_audio_video_value' => 'node:field_audio_video_value',
    'node:field_author_format' => 'node:field_author_format',
    'node:field_author_value' => 'node:field_author_value',
    'node:field_blog_image_alt' => 'node:field_blog_image_alt',
    'node:field_blog_image_fid' => 'node:field_blog_image_fid',
    'node:field_blog_image_height' => 'node:field_blog_image_height',
    'node:field_blog_image_title' => 'node:field_blog_image_title',
    'node:field_blog_image_width' => 'node:field_blog_image_width',
    'node:field_booth_number_format' => 'node:field_booth_number_format',
    'node:field_booth_number_value' => 'node:field_booth_number_value',
    'node:field_brief_description_format' => 'node:field_brief_description_format',
    'node:field_brief_description_value' => 'node:field_brief_description_value',
    'node:field_embed_code_format' => 'node:field_embed_code_format',
    'node:field_embed_code_value' => 'node:field_embed_code_value',
    'node:field_embed_code_video_format' => 'node:field_embed_code_video_format',
    'node:field_embed_code_video_value' => 'node:field_embed_code_video_value',
    'node:field_exhibitor_sponsor_value' => 'node:field_exhibitor_sponsor_value',
    'node:field_exhibitor_type_value' => 'node:field_exhibitor_type_value',
    'node:field_featured_speaker_uid' => 'node:field_featured_speaker_uid',
    'node:field_item_type_value' => 'node:field_item_type_value',
    'node:field_logo_alt' => 'node:field_logo_alt',
    'node:field_logo_fid' => 'node:field_logo_fid',
    'node:field_logo_height' => 'node:field_logo_height',
    'node:field_logo_title' => 'node:field_logo_title',
    'node:field_logo_website_alt' => 'node:field_logo_website_alt',
    'node:field_logo_website_fid' => 'node:field_logo_website_fid',
    'node:field_logo_website_height' => 'node:field_logo_website_height',
    'node:field_logo_website_title' => 'node:field_logo_website_title',
    'node:field_logo_website_width' => 'node:field_logo_website_width',
    'node:field_logo_width' => 'node:field_logo_width',
    'node:field_long_abstract_format' => 'node:field_long_abstract_format',
    'node:field_long_abstract_value' => 'node:field_long_abstract_value',
    'node:field_message_to_reviewers_format' => 'node:field_message_to_reviewers_format',
    'node:field_message_to_reviewers_value' => 'node:field_message_to_reviewers_value',
    'node:field_notice_body_format' => 'node:field_notice_body_format',
    'node:field_notice_body_value' => 'node:field_notice_body_value',
    'node:field_notice_type_tid' => 'node:field_notice_type_tid',
    'node:field_overflow_room_tid' => 'node:field_overflow_room_tid',
    'node:field_page_image_alt' => 'node:field_page_image_alt',
    'node:field_page_image_fid' => 'node:field_page_image_fid',
    'node:field_page_image_height' => 'node:field_page_image_height',
    'node:field_page_image_title' => 'node:field_page_image_title',
    'node:field_page_image_width' => 'node:field_page_image_width',
    'node:field_presentation_link_attributes' => 'node:field_presentation_link_attributes',
    'node:field_presentation_link_title' => 'node:field_presentation_link_title',
    'node:field_presentation_link_url' => 'node:field_presentation_link_url',
    'node:field_presentation_status_value' => 'node:field_presentation_status_value',
    'node:field_presentation_tags_tid' => 'node:field_presentation_tags_tid',
    'node:field_presentation_to_upload_description' => 'node:field_presentation_to_upload_description',
    'node:field_presentation_to_upload_display' => 'node:field_presentation_to_upload_display',
    'node:field_presentation_to_upload_fid' => 'node:field_presentation_to_upload_fid',
    'node:field_primary_email_format' => 'node:field_primary_email_format',
    'node:field_primary_email_value' => 'node:field_primary_email_value',
    'node:field_promo_file_description' => 'node:field_promo_file_description',
    'node:field_promo_file_display' => 'node:field_promo_file_display',
    'node:field_promo_file_fid' => 'node:field_promo_file_fid',
    'node:field_pub_date_value' => 'node:field_pub_date_value',
    'node:field_pub_link_attributes' => 'node:field_pub_link_attributes',
    'node:field_pub_link_title' => 'node:field_pub_link_title',
    'node:field_pub_link_url' => 'node:field_pub_link_url',
    'node:field_pub_name_format' => 'node:field_pub_name_format',
    'node:field_pub_name_value' => 'node:field_pub_name_value',
    'node:field_publish_on_value' => 'node:field_publish_on_value',
    'node:field_ready_for_approval_value' => 'node:field_ready_for_approval_value',
    'node:field_release_date_value' => 'node:field_release_date_value',
    'node:field_room_tid' => 'node:field_room_tid',
    'node:field_room_video_tid' => 'node:field_room_video_tid',
    'node:field_scale_event_tid' => 'node:field_scale_event_tid',
    'node:field_schedule_format' => 'node:field_schedule_format',
    'node:field_schedule_value' => 'node:field_schedule_value',
    'node:field_short_abstract_format' => 'node:field_short_abstract_format',
    'node:field_short_abstract_value' => 'node:field_short_abstract_value',
    'node:field_speaker_uid' => 'node:field_speaker_uid',
    'node:field_specificatins_format' => 'node:field_specificatins_format',
    'node:field_specificatins_value' => 'node:field_specificatins_value',
    'node:field_sponsor_nid' => 'node:field_sponsor_nid',
    'node:field_sponsor_type_value' => 'node:field_sponsor_type_value',
    'node:field_sponsor_website_attributes' => 'node:field_sponsor_website_attributes',
    'node:field_sponsor_website_title' => 'node:field_sponsor_website_title',
    'node:field_sponsor_website_url' => 'node:field_sponsor_website_url',
    'node:field_tags_tid' => 'node:field_tags_tid',
    'node:field_time_value' => 'node:field_time_value',
    'node:field_time_value2' => 'node:field_time_value2',
    'node:field_topic_tid' => 'node:field_topic_tid',
    'node:field_when_value' => 'node:field_when_value',
    'node:field_when_value2' => 'node:field_when_value2',
    'node:language' => 'node:language',
    'node:nid' => 'node:nid',
    'node:promote' => 'node:promote',
    'node:sticky' => 'node:sticky',
    'node:title' => 'node:title',
    'node:type' => 'node:type',
    'node:uid' => 'node:uid',
    'node:vid' => 'node:vid',
    'path:node_alias' => 'path:node_alias',
    'system:cookie' => 'system:cookie',
    'system:date' => 'system:date',
    'system:date_time' => 'system:date_time',
    'system:day_of_month' => 'system:day_of_month',
    'system:day_of_week' => 'system:day_of_week',
    'system:dummy' => 'system:dummy',
    'system:host' => 'system:host',
    'system:http_header' => 'system:http_header',
    'system:https' => 'system:https',
    'system:month' => 'system:month',
    'system:post' => 'system:post',
    'system:query_param' => 'system:query_param',
    'system:query_string' => 'system:query_string',
    'system:random' => 'system:random',
    'system:referer' => 'system:referer',
    'system:remote_ip' => 'system:remote_ip',
    'system:server_ip' => 'system:server_ip',
    'system:server_name' => 'system:server_name',
    'system:server_port' => 'system:server_port',
    'system:session' => 'system:session',
    'system:time' => 'system:time',
    'system:user_agent' => 'system:user_agent',
    'system:user_browser' => 'system:user_browser',
    'system:user_browser_simplified' => 'system:user_browser_simplified',
    'system:user_os' => 'system:user_os',
    'system:user_os_simplified' => 'system:user_os_simplified',
    'taxonomy:name' => 'taxonomy:name',
    'taxonomy:tid' => 'taxonomy:tid',
    'taxonomy:tid_and_childs' => 'taxonomy:tid_and_childs',
    'taxonomy:vid' => 'taxonomy:vid',
    'user:hostname' => 'user:hostname',
    'user:language' => 'user:language',
    'user:name' => 'user:name',
    'user:role' => 'user:role',
    'user:uid' => 'user:uid',
    'views:human_name' => 'views:human_name',
    'views:machine_name' => 'views:machine_name',
    'views:vid' => 'views:vid',
  );
  $export['themekey_properties'] = $strongarm;

  return $export;
}
