<?php

echo "Running drush state:set system.maintenance_mode 1.\n";
passthru('drush state:set system.maintenance_mode 1');

echo "Running drush deploy:hook.\n";
passthru('drush deploy');

echo "Running drush state:set system.maintenance_mode 0.\n";
passthru('drush state:set system.maintenance_mode 0');
