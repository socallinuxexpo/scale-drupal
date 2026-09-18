<?php

/**
 * Merges duplicate session track terms and fixes two encoded track names.
 *
 *   drush php:script migrate-duplicate-tracks.php                      (dry run)
 *   drush php:script migrate-duplicate-tracks.php -- --live            (writes)
 *   drush php:script migrate-duplicate-tracks.php -- --live --limit=5  (writes 5 sessions, stops)
 *
 * Issue #178. Three tracks exist twice, so filtering by one only ever returns
 * part of its history. Sessions move onto the surviving term and the emptied
 * one is deleted. Two more terms have the same encoding problem but nothing to
 * merge into, so those are renamed.
 *
 * Every move is logged to track-migration-log.csv as nid,old_tid,new_tid.
 */

use Drupal\node\Entity\Node;
use Drupal\taxonomy\Entity\Term;

$live = in_array('--live', $extra ?? [], TRUE) || in_array('--live', $_SERVER['argv'] ?? [], TRUE);

// --limit=N stops after N sessions.
$limit = 0;
foreach (array_merge($extra ?? [], $_SERVER['argv'] ?? []) as $arg) {
  if (str_starts_with($arg, '--limit=')) {
    $limit = (int) substr($arg, 8);
  }
}

// Names are checked before anything is touched, so a reused id stops the run.
$merges = [
  ['from' => 2447, 'from_name' => 'Systems &amp; Infrastructure',   'to' => 2396, 'to_name' => 'Systems & Infrastructure'],
  ['from' => 6581, 'from_name' => 'Kernel &amp; Low Level Systems', 'to' => 4294, 'to_name' => 'Kernel & Low Level Systems'],
  ['from' => 4568, 'from_name' => 'SunSecCon',                      'to' => 6583, 'to_name' => 'SunSecCon'],
];

$renames = [
  ['tid' => 3331, 'from_name' => 'Legal &amp; Licensing', 'to_name' => 'Legal & Licensing'],
  ['tid' => 4055, 'from_name' => 'Coder&#039;s Corner',   'to_name' => "Coder's Corner"],
];

$log_path = 'track-migration-log.csv';
$moved = 0;
$errors = [];

// Lets a dry run report what would be left without re-counting.
$counts = [];

print $live ? "LIVE RUN, changes will be written\n\n" : "DRY RUN, nothing will be changed\n\n";

/**
 * Loads a term and confirms it still has the name we expect.
 */
function scale_check_term($tid, $expected_name, array &$errors) {
  $term = Term::load($tid);

  if (!$term) {
    $errors[] = "term $tid does not exist";
    return NULL;
  }

  if ($term->getName() !== $expected_name) {
    $errors[] = "term $tid is named '{$term->getName()}', expected '$expected_name'";
    return NULL;
  }

  return $term;
}

/**
 * Returns the node ids of every session pointing at a term.
 */
function scale_sessions_on_term($tid) {
  return \Drupal::entityQuery('node')
    ->accessCheck(FALSE)
    ->condition('type', 'session')
    ->condition('field_session_track.target_id', $tid)
    ->execute();
}

// Check everything first, so a bad id stops the run instead of half applying it.
foreach ($merges as $merge) {
  scale_check_term($merge['from'], $merge['from_name'], $errors);
  scale_check_term($merge['to'], $merge['to_name'], $errors);
}

foreach ($renames as $rename) {
  // Either name passes, so the script survives being run again.
  $term = Term::load($rename['tid']);

  if (!$term) {
    $errors[] = "term {$rename['tid']} does not exist";
  }
  elseif (!in_array($term->getName(), [$rename['from_name'], $rename['to_name']], TRUE)) {
    $errors[] = "term {$rename['tid']} is named '{$term->getName()}', expected '{$rename['from_name']}'";
  }
}

if ($errors) {
  print "PREFLIGHT FAILED, nothing was changed:\n";
  foreach ($errors as $error) {
    print "  - $error\n";
  }
  return;
}

print "Preflight passed, all eight terms found with the expected names.\n\n";

$log = $live ? fopen($log_path, 'a') : NULL;

foreach ($merges as $merge) {
  $nids = scale_sessions_on_term($merge['from']);
  $counts[$merge['from']] = ['total' => count($nids), 'processed' => 0];
  print "{$merge['from_name']} ({$merge['from']}) -> {$merge['to_name']} ({$merge['to']}): " . count($nids) . " sessions\n";

  foreach ($nids as $nid) {
    if ($limit && $moved >= $limit) {
      print "  reached --limit=$limit, stopping\n";
      break 2;
    }

    if (!$live) {
      $counts[$merge['from']]['processed']++;
      $moved++;
      continue;
    }

    $node = Node::load($nid);

    if (!$node) {
      print "  could not load node $nid, skipped\n";
      continue;
    }

    $node->set('field_session_track', $merge['to']);

    // Saving moderated content in code can drop it back to the default state,
    // so write the current state back explicitly.
    if ($node->hasField('moderation_state')) {
      $node->set('moderation_state', $node->get('moderation_state')->value);
    }

    $node->save();
    fwrite($log, "$nid,{$merge['from']},{$merge['to']}\n");
    $counts[$merge['from']]['processed']++;
    $moved++;
  }
}

if ($log) {
  fclose($log);
}

print "\n" . ($live ? "Moved" : "Would move") . " $moved sessions.\n";

if ($live && $moved) {
  print "Wrote $log_path.\n";
}

// Renames touch no sessions. The term keeps its id, so anything pointing at it
// still works.
print "\n";

if ($limit) {
  print "skipping renames, --limit means this is a test run\n";
}

foreach ($renames as $rename) {
  if ($limit) {
    break;
  }

  $term = Term::load($rename['tid']);

  if ($term->getName() === $rename['to_name']) {
    print "rename {$rename['tid']}: already '{$rename['to_name']}', nothing to do\n";
    continue;
  }

  print "rename {$rename['tid']}: '{$rename['from_name']}' -> '{$rename['to_name']}'\n";

  if ($live) {
    $term->setName($rename['to_name']);
    $term->save();
  }
}

// Only delete a term once it is empty, so a partial run never removes one.
print "\n";

foreach ($merges as $merge) {
  // Live runs can ask the database. Dry runs have moved nothing, so work out
  // what would be left from the tally.
  $tally = $counts[$merge['from']] ?? ['total' => 0, 'processed' => 0];
  $remaining = $live
    ? count(scale_sessions_on_term($merge['from']))
    : $tally['total'] - $tally['processed'];

  if ($remaining > 0) {
    print "keeping term {$merge['from']}, would still have $remaining sessions on it\n";
    continue;
  }

  print ($live ? "deleting" : "would delete") . " empty term {$merge['from']} ({$merge['from_name']})\n";

  if ($live) {
    Term::load($merge['from'])->delete();
  }
}

print "\nDone. Run drush cr afterwards.\n";
