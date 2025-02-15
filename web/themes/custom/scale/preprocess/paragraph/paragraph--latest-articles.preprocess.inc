<?php

/**
 * Implements theme_preprocess_HOOK().
 */
function scale_preprocess_paragraph__latest_articles(&$variables) {
  // Load the event selected
  $event_id = $variables["event"]["id"];

  // Load view and pass event node nid as argument
  $view = \Drupal\views\Views::getView('latest_articles');
  $view->setDisplay('summary_cards');
  $view->setArguments([$event_id]);
  $view->preExecute();
  $view->execute();

  $variables['preprocessor']['latest_articles'] = $view->buildRenderable();
}
