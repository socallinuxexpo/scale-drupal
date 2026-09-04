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
     *
     * Selects the viewing user's vote as a formula so the column can be sorted
     * on. Views orders by whatever field_alias holds, so the value has to be
     * part of the query rather than fetched per row in render().
     */
    public function query() {
        $base_table = $this->view->storage->get('base_table');
        $base_field = $this->view->storage->get('base_field');

        // MAX() keeps this to one value per session, so a reviewer with more
        // than one vote row on a session cannot duplicate the listing row.
        $expression = "(SELECT MAX(v.value)
          FROM {votingapi_vote} v
          WHERE v.entity_id = $base_table.$base_field
            AND v.entity_type = :my_rating_entity_type
            AND v.user_id = :my_rating_uid)";

        $this->field_alias = $this->query->addField(NULL, $expression, 'my_rating', [
            'placeholders' => [
                ':my_rating_entity_type' => 'node',
                ':my_rating_uid' => $this->currentUser->id(),
            ],
        ]);
    }

    /**
     * {@inheritdoc}
     */
    public function render(ResultRow $values) {
        $value = $this->getValue($values);

        // No vote on this session, so the cell stays blank as it did before.
        if ($value === NULL || $value === '') {
            return '';
        }

        return ['#markup' => $value . '%'];
    }

}
