<?php

namespace Drupal\hero_block\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Plugin\ContainerFactoryPluginInterface;
use Drupal\node\Entity\Node;
use Symfony\Component\DependencyInjection\ContainerInterface;
use Drupal\Core\Routing\RouteMatchInterface;
use Drupal\Core\Entity\EntityTypeManagerInterface;

/**
 * Provides a block that displays rendered fields from the current node.
 *
 * @Block(
 *   id = "hero_block",
 *   admin_label = @Translation("Hero Block"),
 *   category = @Translation("Custom")
 * )
 */
class HeroBlock extends BlockBase {

  /**
   * {@inheritdoc}
   */
  public function build() {
    if ($node = \Drupal::routeMatch()->getParameter('node')) {
      return [
        '#theme' => 'hero_block',
        '#node' => $node,
        '#title' => $node->getTitle(),
        '#cache' => [
          'contexts' => ['route'],
        ],
      ];
    }
  }

}
