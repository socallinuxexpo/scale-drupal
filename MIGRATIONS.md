# Migrations

One off data migrations, newest first. Each section covers what ran, how to verify it,
and how to undo it.

## Social links migration, issue #242

Migrates legacy `field_twitter_profile` values into `field_social_media_links`.
Script: `migrate-twitter-to-social-links.php`.

**Status:** not yet run on production.
Once it has run everywhere the script can be deleted. Leave this section as the record
of what happened.

Safe to rerun. It skips speakers who already have that platform, so an interrupted run
is fixed by running it again. It does not delete anything, create node revisions, or
send email.

Writes to `paragraphs_item_field_data`, `paragraph__field_platform`,
`paragraph__field_url` and `node__field_social_media_links`. Leaves the old Twitter
field untouched.

### Prerequisites

- Plain PHP script run through drush. No migrate modules involved.
- The new field config has to be imported first (`drush cim`).
- The 7 platform options must exist in the `social_media_platforms` vocabulary. They're
  content, not config, so they don't arrive with a deploy and have to be created by
  hand on each environment: `X`, `Mastodon`, `Bluesky`, `LinkedIn`, `Facebook`,
  `Instagram`, `GitHub`. The script matches by name, so spelling must be exact.

```bash
drush php:eval "print implode(', ', array_column(\Drupal::entityTypeManager()->getStorage('taxonomy_term')->loadTree('social_media_platforms'), 'name'));"
```

- Run before removing `field_twitter_profile`. The script reads it.
- Check the CLI memory limit. The script loads all matching speakers in one pass.

```bash
drush php:eval "print ini_get('memory_limit') . PHP_EOL;"
```

### Execution

Run from the site root. The `--` is required.

```bash
# 1. back up, and note where new rows will start
drush sql:dump --gzip --result-file=../pre-social-migration.sql.gz
drush sql:query "SELECT MAX(id) FROM paragraphs_item_field_data"

# 2. dry run, changes nothing
drush php:script migrate-twitter-to-social-links.php

# 3. first 5, then check
drush php:script migrate-twitter-to-social-links.php -- --live --limit=5

# 4. the rest
drush php:script migrate-twitter-to-social-links.php -- --live
```

Nearly all should migrate. Skips should be in the low tens, mostly personal sites and
blogs. Stop at the dry run if it reports `RECOGNIZED BUT NO MATCHING TERM`, migrates
near zero, or skips hundreds. Nothing has changed at that point.

Some values were stored as `socallinuxexpo.org` URLs rather than the platform's. The
handle is still usable, so those get rebuilt as `x.com` links. The run reports how many.

Run it once more immediately before the deploy that removes the old field, to catch
anyone who filled it in since.

### Verification

```bash
drush sql:query "SELECT COUNT(*) FROM paragraphs_item_field_data WHERE type = 'social_media_link'"
```

Then open a few speaker profiles. Icons should render as platform logos. A generic
share symbol means the term name doesn't match the icon map in
`web/themes/custom/scale/templates/node/node--speaker.html.twig`.

### Rollback

Preferred, removes only what the run created.

Do this through Drupal, not by deleting rows in the database. Deleting rows directly
leaves speakers pointing at links that no longer exist. Through Drupal: load each
speaker, remove the links created above the ID from step 1, save, then delete those
links.

Full restore only if that fails.

```bash
drush sql:drop -y
gunzip < ../pre-social-migration.sql.gz | drush sql:cli
drush cr
```
