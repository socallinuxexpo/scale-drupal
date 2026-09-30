<?php

namespace Drupal\active_event\EventSubscriber;

use Drupal\Core\Url;
use Symfony\Component\HttpFoundation\RedirectResponse;
use Symfony\Component\HttpKernel\KernelEvents;
use Symfony\Component\HttpKernel\Event\RequestEvent;
use Symfony\Component\EventDispatcher\EventSubscriberInterface;

class SessionsExportDefaultEvent implements EventSubscriberInterface {

  protected $activeEventService;

  public function __construct($active_event_service) {
    $this->activeEventService = $active_event_service;
  }

  public static function getSubscribedEvents() {
    return [
      KernelEvents::REQUEST => ['onRequest', 31],
      // run after routing (higher = later)
    ];
  }

  public function onRequest(RequestEvent $event) {
    if (!$event->isMainRequest()) {
      return;
    }

    $request = $event->getRequest();

    // Admin views that should open on the active event. Views page routes are
    // "view.{view_id}.{display_id}", and each one's event filter must use the
    // identifier "event".
    $routes = [
      'view.sessions.admin',
      'view.track_swaps.page_1',
    ];

    $route = $request->attributes->get('_route');
    if (!in_array($route, $routes, TRUE)) {
      return;
    }

    // If the query already has an 'event', do nothing.
    if ($request->query->has('event') && $request->query->get('event') !== '') {
      return;
    }

    // Get your default.
    $active_id = $this->activeEventService->getActiveEventId();
    if (!$active_id) {
      return;
    }

    // Build redirect URL with ?event=<id> while preserving any other query params.
    $query = $request->query->all();
    $query['event'] = $active_id;

    $url = Url::fromRoute($route, [], ['query' => $query])
      ->toString();
    $event->setResponse(new RedirectResponse($url, 302));
  }

}
