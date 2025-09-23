<?php

namespace Drupal\utility\Plugin\views\field;

use Drupal\Core\Database\Connection;
use Drupal\Core\Session\AccountInterface;
use Drupal\views\Plugin\views\field\FieldPluginBase;
use Drupal\views\ResultRow;
use Symfony\Component\DependencyInjection\ContainerInterface;
use Drupal\Core\Plugin\ContainerFactoryPluginInterface;

/**
 * A handler to provide a custom field based on user-specific database query.
 *
 * @ingroup views_field_handlers
 *
 * @ViewsField("my_rating")
 */
class MyRatingViewsField extends FieldPluginBase implements ContainerFactoryPluginInterface {

    /**
     * The database connection.
     *
     * @var \Drupal\Core\Database\Connection
     */
    protected $database;

    /**
     * The current user.
     *
     * @var \Drupal\Core\Session\AccountInterface
     */
    protected $currentUser;

    /**
     * Constructs a MyRatingViewsField object.
     */
    public function __construct(array $configuration, $plugin_id, $plugin_definition, Connection $database, AccountInterface $current_user) {
        parent::__construct($configuration, $plugin_id, $plugin_definition);
        $this->database = $database;
        $this->currentUser = $current_user;
    }

    /**
     * {@inheritdoc}
     */
    public static function create(ContainerInterface $container, array $configuration, $plugin_id, $plugin_definition) {
        return new static(
          $configuration,
          $plugin_id,
          $plugin_definition,
          $container->get('database'),
          $container->get('current_user')
        );
    }

    /**
     * {@inheritdoc}
     */
    public function query() {
        // No query changes needed since we're doing our own database query
    }

    /**
     * {@inheritdoc}
     */
    public function render(ResultRow $values) {
        // Get the current user ID
        $current_user_id = $this->currentUser->id();

        // Get the entity from the current row
        $entity = $values->_entity;
        if (!$entity) {
            return ['#markup' => ''];
        }

        // Perform your custom database query
        $query = $this->database->select('votingapi_vote', 'v')
          ->fields('v', ['value'])
          ->condition('v.entity_id', $entity->id())
          ->condition('v.user_id', $current_user_id)
          ->execute();

        $result = $query->fetchField();

        // Return the rendered output
        if ($result !== FALSE) {
            return [
              '#markup' => $result . '%',
            ];
        }

//        return ['#markup' => 'No rating'];
    }

}