<?php

/**
 * Migrates legacy field_twitter_profile values into field_social_media_links.
 *
 *   drush php:script migrate-twitter-to-social-links.php                      (dry run)
 *   drush php:script migrate-twitter-to-social-links.php -- --live            (writes)
 *   drush php:script migrate-twitter-to-social-links.php -- --live --limit=5  (writes 5, stops)
 *
 * Take a database backup first. Unrecognized URLs are skipped and reported. Safe to rerun.
 *
 * Most values get copied over as-is. The links pointing at socallinuxexpo.org get rebuilt as x.com URLs.
 *
 * Remove the old Twitter field and its template block or you end up with two of the same icon.
 */

$live = in_array('--live', $extra ?? [], TRUE) || in_array('--live', $_SERVER['argv'] ?? [], TRUE);

// --limit=N stops after N speakers, so the first run on prod can be a small one.
$limit = 0;
foreach (array_merge($extra ?? [], $_SERVER['argv'] ?? []) as $arg) {
  if (str_starts_with($arg, '--limit=')) {
    $limit = (int) substr($arg, 8);
  }
}

/**
 * Work out which platform a URL belongs to by pattern matching.
 * Returns the platform name and the url to save, or NULL if it isn't a social profile.
 */
function scale_detect_platform($uri) {
  $host = strtolower(parse_url($uri, PHP_URL_HOST) ?: '');
  $path = parse_url($uri, PHP_URL_PATH) ?: '';
  $seg = trim($path, '/');

  if ($host === '') {
    return NULL;
  }

  // Links to our own site, some with the @, some without. The handle allows us to rebuild as X.
  if (str_contains($host, 'socallinuxexpo.org')) {
    $handle = ltrim($seg, '@');
    // Some people put NA or none instead of leaving it blank.
    if (in_array(strtolower($handle), ['na', 'n-a', 'none'], TRUE)) {
      return NULL;
    }
    // Real X handles are letters, numbers and underscores, max 15 characters.
    if (preg_match('/^[A-Za-z0-9_]{1,15}$/', $handle)) {
      return ['platform' => 'X', 'uri' => 'https://x.com/' . $handle];
    }
    return NULL;
  }

  // Misspelled Twitter.
  if ($host === 'twiter.com' || $host === 'www.twiter.com') {
    return ['platform' => 'X', 'uri' => 'https://x.com/' . $seg];
  }

  // Bluesky: bsky.app, or handle domain like name.bsky.social.
  if ($host === 'bsky.app' || str_ends_with($host, '.bsky.social')) {
    return ['platform' => 'Bluesky', 'uri' => $uri];
  }

  // X / Twitter, including www. and mobile. subdomains.
  if (str_contains($host, 'twitter.com') || $host === 'x.com' || str_ends_with($host, '.x.com')) {
    return ['platform' => 'X', 'uri' => $uri];
  }

  if (str_contains($host, 'linkedin.com')) {
    return ['platform' => 'LinkedIn', 'uri' => $uri];
  }

  if (str_contains($host, 'facebook.com')) {
    return ['platform' => 'Facebook', 'uri' => $uri];
  }

  if (str_contains($host, 'instagram.com')) {
    return ['platform' => 'Instagram', 'uri' => $uri];
  }

  if (str_contains($host, 'github.com')) {
    return ['platform' => 'GitHub', 'uri' => $uri];
  }

  // Mastodon has no domain of its own, anyone can run an instance, so the only thing
  // to match on is the /@username path. That makes it a catch-all, so it goes last.
  // Ahead of the checks above it would also catch twitter.com/@handle.
  if (str_starts_with($path, '/@')) {
    return ['platform' => 'Mastodon', 'uri' => $uri];
  }

  return NULL;
}

$etm = \Drupal::entityTypeManager();
$node_storage = $etm->getStorage('node');
$term_storage = $etm->getStorage('taxonomy_term');

// Map platform names to their taxonomy term IDs.
$terms = [];
foreach ($term_storage->loadTree('social_media_platforms') as $t) {
  $terms[$t->name] = $t->tid;
}

$nids = \Drupal::entityQuery('node')
  ->condition('type', 'speaker')
  ->exists('field_twitter_profile')
  ->accessCheck(FALSE)
  ->execute();

$would = [];
$skip = [];
$migrated = 0;
$already_had = 0;
$no_term = [];
$rewritten = 0;

print "\n===== " . ($live ? 'LIVE RUN - WRITING DATA' : 'DRY RUN - NOTHING CHANGED') . ($limit ? " (stopping after $limit)" : '') . " =====\n\n";

foreach ($node_storage->loadMultiple($nids) as $node) {
  $uri = $node->field_twitter_profile->uri ?? '';
  if (!$uri) {
    continue;
  }

  $detected = scale_detect_platform($uri);

  if ($detected === NULL) {
    $host = strtolower(parse_url($uri, PHP_URL_HOST) ?: '(unparseable)');
    $skip[$host] = ($skip[$host] ?? 0) + 1;
    continue;
  }

  $platform = $detected['platform'];
  $store_uri = $detected['uri'];

  if (!isset($terms[$platform])) {
    $no_term[$platform] = ($no_term[$platform] ?? 0) + 1;
    continue;
  }

  // Don't add a second entry if the speaker already has this platform.
  $duplicate = FALSE;
  foreach ($node->get('field_social_media_links')->referencedEntities() as $existing) {
    $existing_tid = $existing->field_platform->target_id ?? NULL;
    if ($existing_tid == $terms[$platform]) {
      $duplicate = TRUE;
      break;
    }
  }

  if ($duplicate) {
    $already_had++;
    continue;
  }

  $would[$platform] = ($would[$platform] ?? 0) + 1;

  if ($store_uri !== $uri) {
    $rewritten++;
  }

  if ($live) {
    $paragraph = \Drupal\paragraphs\Entity\Paragraph::create([
      'type' => 'social_media_link',
      'field_platform' => ['target_id' => $terms[$platform]],
      'field_url' => ['uri' => $store_uri],
    ]);
    $paragraph->save();

    $node->get('field_social_media_links')->appendItem([
      'target_id' => $paragraph->id(),
      'target_revision_id' => $paragraph->getRevisionId(),
    ]);
    $node->save();

    $migrated++;
  }

  if ($limit && array_sum($would) >= $limit) {
    break;
  }
}

arsort($would);
arsort($skip);

print ($live ? "MIGRATED:\n" : "WOULD MIGRATE:\n");
foreach ($would as $platform => $n) {
  printf("  %-10s %d\n", $platform, $n);
}
print "  " . str_repeat('-', 16) . "\n";
printf("  %-10s %d\n", 'TOTAL', array_sum($would));

print "\n" . ($live ? "SKIPPED" : "WOULD SKIP") . " (not a social profile):\n";
foreach ($skip as $host => $n) {
  printf("  %-28s %d\n", $host, $n);
}
print "  " . str_repeat('-', 34) . "\n";
printf("  %-28s %d\n", 'TOTAL', array_sum($skip));

if ($no_term) {
  print "\nRECOGNIZED BUT NO MATCHING TERM (would need adding to the vocabulary):\n";
  foreach ($no_term as $platform => $n) {
    printf("  %-10s %d\n", $platform, $n);
  }
}

print "\nBroken links rebuilt as x.com URLs:    $rewritten\n";
print "Already had that platform, left alone: $already_had\n";
print "Total speakers with a Twitter value:   " . count($nids) . "\n";

if ($live) {
  print "Paragraphs created:                    $migrated\n";
}
else {
  print "\nNothing was changed. Re-run with -- --live to apply.\n";
}

if ($limit && array_sum($would) >= $limit) {
  print "\nStopped early at the limit of $limit. Re-run without --limit for the rest.\n";
}

print "\n";
