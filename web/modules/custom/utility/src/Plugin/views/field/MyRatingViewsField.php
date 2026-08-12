<?php

namespace Drupal\utility\Plugin\views\field;

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
     * The current user.
     *
     * @var \Drupal\Core\Session\AccountInterface
     */
    protected $currentUser;

    /**
     * Constructs a MyRatingViewsField object.
     */
    public function __construct(array $configuration, $plugin_id, $plugin_definition, AccountInterface $current_user) {
        parent::__construct($configuration, $plugin_id, $plugin_definition);
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
          $container->get('current_user')
        );
    }

    /**
     * {@inheritdoc}
     */
    public function query() {
        $base_table = $this->view->storage->get('base_table');
        $base_field = $this->view->storage->get('base_field');
        $table_info = $this->query->getTableInfo($base_table);
        $base_alias = $table_info['alias'] ?? $base_table;

        // Only the current user's own vote counts, and vote IDs are only unique
        // within an entity type, so limit the lookup to the type this view
        // lists.
        $placeholders = [':my_rating_user' => $this->currentUser->id()];
        $conditions = "v.user_id = :my_rating_user AND v.entity_id = $base_alias.$base_field";
        if ($entity_type = $this->view->getBaseEntityType()) {
            $placeholders[':my_rating_entity_type'] = $entity_type->id();
            $conditions .= ' AND v.entity_type = :my_rating_entity_type';
        }

        // Fetching the vote as part of the view query is what makes the column
        // click sortable: the table style sorts on a field's alias, so the
        // value has to be in the query. MAX() keeps the sub-select to one row
        // per result even where several votes were recorded for the same user
        // and entity.
        $this->field_alias = $this->query->addField(
          NULL,
          "(SELECT MAX(v.value) FROM {votingapi_vote} v WHERE $conditions)",
          'my_rating',
          ['placeholders' => $placeholders]
        );
    }

    /**
     * {@inheritdoc}
     */
    public function render(ResultRow $values) {
        $rating = $this->getValue($values);

        // Rows the current user has not voted on stay empty
        if ($rating === NULL || $rating === '') {
            return ['#markup' => ''];
        }

        // The vote value is stored as a float, so drop any trailing zeroes the
        // database returns before adding the percentage sign
        return [
          '#markup' => (float) $rating . '%',
        ];
    }

}
