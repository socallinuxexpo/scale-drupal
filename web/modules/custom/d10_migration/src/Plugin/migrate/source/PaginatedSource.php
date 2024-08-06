<?php

namespace Drupal\d10_migration\Plugin\migrate\source;

use Drupal\migrate\Plugin\migrate\source\SourcePluginBase;

abstract class PaginatedSource extends SourcePluginBase {

  protected int $currentPage = 0;

  protected int $totalPages = 0;

  /**
   * Initialize the iterator with the first page of results.
   */
  public function initializeIterator(): \ArrayIterator {
    $items = [];
    $response = $this->fetchPage($this->currentPage);
    $this->totalPages = $response['pager']['pages'];

    // If the data is not empty, process it and calculate total pages.
    if (!empty($response['nodes'])) {
      $items = array_merge($items, $response['nodes']);

      // Fetch remaining pages.
      while ($this->currentPage < $this->totalPages - 1) {
        $this->currentPage++;

        $response = $this->fetchPage($this->currentPage);
        if (!empty($response['nodes'])) {
          $items = array_merge($items, $response['nodes']);
        }
      }
    }

    return new \ArrayIterator($items);
  }

  /**
   * Fetch a single page of results from the JSON feed.
   *
   * @param int $page
   *   The current page number to fetch.
   *
   * @return array
   *   The decoded JSON response as an associative array.
   */
  protected function fetchPage(int $page): array {
    //    \Drupal::logger('d10_migration')
    //      ->debug("Fetching page @page of @pages; Requested @req", [
    //        '@page' => $this->currentPage,
    //        '@pages' => $this->totalPages,
    //        '@req' => $page,
    //      ]);
    $client = \Drupal::service('d10_migration.client');
    return $client->get($this->endpoint, ['page' => $page]);
  }

  /**
   * {@inheritdoc}
   */
  public function count($refresh = FALSE) {
    $response = $this->fetchPage(0);
    return $response['pager']['count'];
  }

}
