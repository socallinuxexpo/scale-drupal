<?php

namespace Drupal\views_plugins\Plugin\views\style;

use Drupal\Core\Form\FormStateInterface;
use Drupal\views\Plugin\views\style\StylePluginBase;

/**
 * Style plugin to render views using the SwiperJS library.
 *
 * @ingroup views_style_plugins
 *
 * @ViewsStyle(
 *   id = "swiper_js",
 *   title = @Translation("SwiperJS"),
 *   help = @Translation("Uses the SwiperJS library."),
 *   theme = "views_swiperjs",
 *   display_types = {"normal"}
 * )
 */
class SwiperJS extends StylePluginBase {

  /**
   * Does this Style plugin allow Row plugins?
   *
   * @var bool
   */
  protected $usesRowPlugin = TRUE;

  /**
   * Does the Style plugin support grouping of rows?
   *
   * @var bool
   */
  protected $usesGrouping = FALSE;

  /**
   * {@inheritdoc}
   */
  protected function defineOptions() {
    $options = parent::defineOptions();
    $options['slidesPerView'] = ['default' => 1];
    $options['navigation'] = ['default' => TRUE];
    $options['pagination'] = ['default' => FALSE];
    $options['scrollbar'] = ['default' => FALSE];
    $options['spaceBetween'] = ['default' => 0];
    $options['marquee'] = ['default' => FALSE];
    $options['loop'] = ['default' => FALSE];
    return $options;
  }

  /**
   * {@inheritdoc}
   */
  public function buildOptionsForm(&$form, FormStateInterface $form_state) {
    parent::buildOptionsForm($form, $form_state);
    $form['slidesPerView'] = [
      '#title' => $this->t('Slides Per View'),
      '#description' => $this->t('Number of slides per view.'),
      '#type' => 'textfield',
      '#default_value' => $this->options['slidesPerView'],
    ];
    $form['spaceBetween'] = [
      '#title' => $this->t('Space Between Slides'),
      '#description' => $this->t('Distance between slides in px.'),
      '#type' => 'textfield',
      '#default_value' => $this->options['spaceBetween'],
    ];
    $form['navigation'] = [
      '#title' => $this->t('Enable Navigation'),
      '#description' => $this->t('Enable navigation for the SwiperJS slider.'),
      '#type' => 'checkbox',
      '#default_value' => $this->options['navigation'],
    ];
    $form['pagination'] = [
      '#title' => $this->t('Enable Pagination'),
      '#description' => $this->t('Enable pagination for the SwiperJS slider.'),
      '#type' => 'checkbox',
      '#default_value' => $this->options['pagination'],
    ];
    $form['scrollbar'] = [
      '#title' => $this->t('Enable Scrollbar'),
      '#description' => $this->t('Enable scrollbar for the SwiperJS slider.'),
      '#type' => 'checkbox',
      '#default_value' => $this->options['scrollbar'],
    ];
    $form['marquee'] = [
      '#title' => $this->t('Marquee-style'),
      '#description' => $this->t('Enable the Swiper to scroll, continuously, like a marquee.'),
      '#type' => 'checkbox',
      '#default_value' => $this->options['marquee'],
    ];
    $form['loop'] = [
      '#title' => $this->t('Loop'),
      '#description' => $this->t('Enable loop for the SwiperJS slider.'),
      '#type' => 'checkbox',
      '#default_value' => $this->options['loop'],
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function render() {
    //  Get view dom id
    $view_uuid = $this->view->dom_id;

    // Add custom unique random class to the view
    $classes = [
      'swiper-view',
      'swiper-view-' . $view_uuid
    ];
    $this->view->element['#attributes']['class'][] = implode(' ', $classes);

    // Adds buildOptionsForm submitted data to drupalSettings
    $this->view->element['#attached']['drupalSettings']['views_plugins']['swiper_js'][$view_uuid] = [
      'view_uuid' => $view_uuid,
      'options' => [
        'slidesPerView' => $this->options['slidesPerView'],
        'navigation' => $this->options['navigation'],
        'pagination' => $this->options['pagination'],
        'scrollbar' => $this->options['scrollbar'],
        'spaceBetween' => $this->options['spaceBetween'],
        'marquee' => $this->options['marquee'],
        'loop' => $this->options['loop'],
      ]
    ];

    // Attach the SwiperJS library.
    $this->view->element['#attached']['library'][] = 'views_plugins/views_swiper';

    // Render the view normally.
    return parent::render();
  }

}
