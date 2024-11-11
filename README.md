# SCALE Drupal Site

This is the repo for the SCALE Drupal site.

Deploying is generally done by Chef the first time, then, as desired,
update the git repo in `/home/drupal/scale-drupal`.

## Static files

When bootstrapping a new server, there is a bunch of static stuff that is
not in this repo you will need to copy over. That is, everything under
`/home/drupal/scale-drupal/httpdocs/sites/default/files`.
