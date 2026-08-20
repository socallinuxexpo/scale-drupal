# Contributing

Hi, and welcome! SCaLE happens once a year but the site is worked on year round, and contributions are welcome. The steps are:

1. Find an issue in [GitHub Issues](https://github.com/socallinuxexpo/scale-drupal/issues) and comment that you're taking it
2. Fork the repository and create a branch
3. Make your change
4. Test it locally
5. Open a pull request against `master`

The rest of this document covers each of those in detail.

## Setting up locally

You'll need [Docker](https://www.docker.com/products/docker-desktop/) and [Lando](https://docs.lando.dev/getting-started/installation.html). PHP, Composer, and the database all run in containers, so you don't need those installed. Working on the theme also needs [Node and npm](https://nodejs.org/), since the theme build runs outside the container.

Fork the repository on GitHub, then:

```bash
git clone git@github.com:<your-username>/scale-drupal.git
cd scale-drupal
git remote add upstream git@github.com:socallinuxexpo/scale-drupal.git
lando start
```

`origin` is your fork — where you push. `upstream` is the main repository — where you pull the latest from.

The site comes up at **https://scale10.lndo.site**.

### The database

You'll also need one. Dumps aren't distributed publicly — the database holds speaker and attendee personal data. Ask on the issue you're working on and we'll sort it out.

Once you have one:

```bash
gunzip -c <dumpfile>.mysql.gz > db-import-tmp.sql
lando db-import db-import-tmp.sql
rm db-import-tmp.sql
lando drush cim -y
lando drush cr
lando drush uli
```

`cim` brings the site's configuration in line with what's committed. `uli` prints a one-time login link.

Uploaded images won't appear locally. Everything under `web/sites/default/files` — sponsor logos, speaker photos, hero images — lives on the server and isn't in git or in database dumps. The site renders correctly apart from missing images.

### Useful commands

| Command | Description |
|---|---|
| `lando start` / `lando stop` | Start or stop the environment |
| `lando drush cr` | Rebuild caches — try this first when something looks wrong |
| `lando drush cim -y` | Import configuration from `config/` into the site |
| `lando drush cex -y` | Export configuration from the site into `config/` |
| `lando drush uli` | One-time admin login link |
| `lando drush status` | Check Drupal is bootstrapping and connected |

## Where changes go

Work lands in one of three places, depending on what the issue needs:

| The issue needs | You'll work in |
|---|---|
| A setting, field, view, or permission changed | `config/sync/` — YAML, no code |
| Different markup or styling | `web/themes/custom/scale/` — Twig, Sass |
| New behaviour or logic | `web/modules/custom/` — PHP |

**Configuration is code here.** In Drupal, the shape of a site — content types, fields, views, roles, permissions, form layouts — isn't written in PHP. It's configuration, edited through the admin UI and stored in the database. This project exports all of it to YAML under `config/sync/` and commits it, so many pull requests are readable YAML diffs rather than code.

There's real PHP too — custom Views plugins behind the talk review pages, session time slot logic, access control — so not everything is a YAML edit.

### Configuration changes

**1. Make the change** in the admin UI on your local site.

**2. Export it and read the diff.**

```bash
lando drush cex -y
git diff config/sync/
```

**3. Stage the files you meant to change, by name.**

```bash
git add config/sync/views.view.sessions.yml
```

Avoid running `git add .` here. Saving a form in the Drupal UI often exports defaults that were previously implicit, creating churn that makes pull requests difficult to review.

Always run `git status` or `git diff config/sync/` to inspect all generated files before staging. Note that new fields and entity configurations write multiple files that depend on each other. For example, a single new field creates two mandatory YAML files:

- `field.storage.node.field_social_media_links.yml` — the data type definition
- `field.field.node.speaker.field_social_media_links.yml` — the field instance on the bundle

Both must be committed together, or `lando drush cim` will fail for other contributors.

**4. Import it back** to confirm it applies cleanly:

```bash
lando drush cim -y
```

Note that the `config_ignore` module deliberately excludes some configuration from sync, so it can differ between environments: the active event setting, site name, mail settings, block placement, and menus. If a change never seems to reach production, check `config/sync/config_ignore.settings.yml` first.

### Theme changes

The theme uses Gulp, Sass, and Tailwind.

```bash
cd web/themes/custom/scale
npm run dev      # watch and rebuild
npm run build    # production build
```

Edit `src/`, never `dist/`. `dist/` is generated output, but it *is* committed — so if your change touches compiled CSS or JS, run `npm run build` and include the rebuilt files.

Twig templates under `templates/` aren't compiled and can be edited directly. They take effect on reload, or after `lando drush cr`.

### Module changes

Custom PHP lives in `web/modules/custom/`. Run `lando drush cr` after editing, then test the page or form the issue is about.

## Testing your change

There's no automated test suite, so testing means verifying it yourself before opening a pull request. Confirm the behaviour the issue describes works, and check you haven't changed anything you didn't intend to — for configuration changes, that means reading the diff before you stage.

In the pull request, describe what you did to verify it. "Sorted by track and confirmed alphabetical order" tells a reviewer far more than "fixed."

## Branches and commits

Branch off an up-to-date `master`, and name the branch after the issue:

```bash
git checkout master
git pull upstream master
git checkout -b issue-230
```

Reference the issue number in commit messages so history is easy to trace back:

```
#230: Add moderation state to the sessions export
```

## Opening a pull request

Push your branch to your fork and open a pull request against `master`. Reference the issue number in the description.

Keep pull requests to one issue where you can. Configuration-only changes make good first contributions.

Someone on the web team will review it. Once it's approved it can be merged. You don't need production access — deploying is handled separately.

## Things that surprise people

**Caches explain most confusion.** If a change isn't showing up, `lando drush cr` before debugging anything else.

**Why are there Pantheon files?** `pantheon.yml`, `pantheon.upstream.yml`, and `upstream-configuration/` are left over from a Pantheon-hosted sandbox used during the Drupal 7 → 10 migration. The site is not hosted on Pantheon. `upstream-configuration/` can't simply be deleted — `composer.json` requires it as a local path package.
