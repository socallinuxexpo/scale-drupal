<?php

namespace Drupal\Tests\utility\Unit;

use Drupal\Core\Entity\EntityTypeInterface;
use Drupal\Core\Session\AccountInterface;
use Drupal\Tests\UnitTestCase;
use Drupal\utility\Plugin\views\field\MyRatingViewsField;
use Drupal\views\Plugin\views\query\Sql;
use Drupal\views\ResultRow;
use Drupal\views\ViewEntityInterface;
use Drupal\views\ViewExecutable;

/**
 * Tests the My Rating views field.
 *
 * @coversDefaultClass \Drupal\utility\Plugin\views\field\MyRatingViewsField
 *
 * @group utility
 */
class MyRatingViewsFieldTest extends UnitTestCase {

  /**
   * The fields the handler added to the view query.
   *
   * @var array
   */
  protected $addedFields = [];

  /**
   * The sorts the handler added to the view query.
   *
   * @var array
   */
  protected $orderBy = [];

  /**
   * Builds a My Rating field handler wired to a mocked node view.
   *
   * @param int $uid
   *   The ID of the user viewing the report.
   *
   * @return \Drupal\utility\Plugin\views\field\MyRatingViewsField
   *   The handler under test.
   */
  protected function buildHandler($uid = 7) {
    $storage = $this->createMock(ViewEntityInterface::class);
    $storage->method('get')->willReturnMap([
      ['base_table', 'node_field_data'],
      ['base_field', 'nid'],
    ]);

    $entity_type = $this->createMock(EntityTypeInterface::class);
    $entity_type->method('id')->willReturn('node');

    $view = $this->createMock(ViewExecutable::class);
    $view->storage = $storage;
    $view->method('getBaseEntityType')->willReturn($entity_type);

    $query = $this->createMock(Sql::class);
    $query->method('getTableInfo')->willReturn(['alias' => 'node_field_data']);
    $query->method('addField')->willReturnCallback(
      function ($table, $field, $alias = '', $params = []) {
        $this->addedFields[] = [
          'table' => $table,
          'field' => $field,
          'alias' => $alias,
          'params' => $params,
        ];
        return $alias ?: $field;
      }
    );
    $query->method('addOrderBy')->willReturnCallback(
      function ($table, $field = NULL, $order = 'ASC', $alias = '', $params = []) {
        $this->orderBy[] = [
          'table' => $table,
          'field' => $field,
          'order' => $order,
          'alias' => $alias,
        ];
      }
    );

    $account = $this->createMock(AccountInterface::class);
    $account->method('id')->willReturn($uid);

    $handler = new MyRatingViewsField([], 'my_rating', [], $account);
    $handler->view = $view;
    $handler->query = $query;
    $handler->options = ['id' => 'my_rating', 'group_type' => 'group'];
    $handler->field = 'my_rating';

    return $handler;
  }

  /**
   * The vote has to be in the view query for the column to be sortable.
   *
   * @covers ::query
   */
  public function testQuerySelectsTheCurrentUsersVote() {
    $handler = $this->buildHandler(7);
    $handler->query();

    $this->assertCount(1, $this->addedFields);
    $field = reset($this->addedFields);

    // A formula, so it has no table of its own.
    $this->assertNull($field['table']);
    $this->assertSame('my_rating', $field['alias']);
    $this->assertSame('my_rating', $handler->field_alias);

    // Correlated on the row being listed, and capped at a single row.
    $this->assertStringContainsString('{votingapi_vote}', $field['field']);
    $this->assertStringContainsString('MAX(v.value)', $field['field']);
    $this->assertStringContainsString('v.entity_id = node_field_data.nid', $field['field']);

    // The reviewer and the entity type are bound, never interpolated.
    $this->assertSame([
      ':my_rating_user' => 7,
      ':my_rating_entity_type' => 'node',
    ], $field['params']['placeholders']);
    $this->assertStringContainsString('v.user_id = :my_rating_user', $field['field']);
    $this->assertStringContainsString('v.entity_type = :my_rating_entity_type', $field['field']);
  }

  /**
   * Clicking the column header sorts on the vote, not on a missing column.
   *
   * @covers ::query
   */
  public function testColumnClickSortsOnTheVote() {
    $handler = $this->buildHandler();
    $handler->query();
    $handler->clickSort('desc');

    $this->assertTrue($handler->clickSortable());
    $this->assertSame([
      [
        'table' => NULL,
        'field' => NULL,
        'order' => 'desc',
        'alias' => 'my_rating',
      ],
    ], $this->orderBy);
  }

  /**
   * The rating is rendered from the row the query already returned.
   *
   * @covers ::render
   */
  public function testRenderShowsTheVoteAsAPercentage() {
    $handler = $this->buildHandler();
    $handler->query();

    $this->assertSame(
      ['#markup' => '80%'],
      $handler->render(new ResultRow(['my_rating' => '80.0000']))
    );
    $this->assertSame(
      ['#markup' => '62.5%'],
      $handler->render(new ResultRow(['my_rating' => '62.5']))
    );
  }

  /**
   * A row the current user has not voted on stays empty.
   *
   * @covers ::render
   */
  public function testRenderIsEmptyWithoutAVote() {
    $handler = $this->buildHandler();
    $handler->query();

    $this->assertSame(
      ['#markup' => ''],
      $handler->render(new ResultRow([]))
    );
  }

}
