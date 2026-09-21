<?php

namespace Drupal\sessions\Form;

use Drupal\Core\Form\FormBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\Core\Url;
use Drupal\node\Entity\Node;
use Drupal\node\NodeInterface;

/**
 * Lets a reviewer suggest moving a talk to a different track.
 *
 * Shown on the talk's review page. Each reviewer has at most one open
 * suggestion per talk, so submitting again updates it rather than adding
 * another. Once a suggestion is accepted or rejected it is settled, and the
 * next submission starts a new one.
 */
class TrackSuggestionForm extends FormBase
{
    /**
     * {@inheritdoc}
     */
    public function getFormId()
    {
        return 'sessions_track_suggestion_form';
    }

    /**
     * {@inheritdoc}
     */
    public function buildForm(array $form, FormStateInterface $form_state, ?NodeInterface $talk = NULL)
    {
        // The talk's own track is left out, so it can't be suggested.
        $options = $this->activeTrackOptions($talk->get('field_session_track')->target_id);

        if (!$options) {
            $form['no_tracks'] = [
                '#markup' => $this->t('There are no other active tracks to suggest.'),
            ];
            return $form;
        }

        $existing = $this->openSuggestion($talk);

        $form['talk_id'] = [
            '#type' => 'value',
            '#value' => $talk->id(),
        ];

        $form['suggestion_id'] = [
            '#type' => 'value',
            '#value' => $existing ? $existing->id() : NULL,
        ];

        // Closed by default, since most reviewers won't use it on most talks.
        // Open if you already have a suggestion here, so you can see it. The
        // title says which, since you only ever have one to edit.
        $form['suggest'] = [
            '#type' => 'details',
            '#title' => $existing ? $this->t('Edit your track suggestion') : $this->t('Suggest a different track'),
            '#open' => (bool) $existing,
        ];

        $form['suggest']['suggested_track'] = [
            '#type' => 'select',
            '#title' => $this->t('Track'),
            '#options' => $options,
            '#empty_option' => $this->t('- Choose a track -'),
            '#default_value' => $existing ? $existing->get('field_suggested_track')->target_id : NULL,
            '#required' => TRUE,
        ];

        // The theme resets textarea borders, so without these it looks like
        // plain text. Only classes already in the compiled Tailwind CSS work.
        $form['suggest']['comment'] = [
            '#type' => 'textarea',
            '#title' => $this->t('Reason'),
            '#default_value' => $existing ? $existing->get('field_swap_comment')->value : '',
            '#rows' => 3,
            '#attributes' => ['class' => ['border', 'rounded', 'p-2']],
        ];

        $form['suggest']['actions']['#type'] = 'actions';
        $form['suggest']['actions']['submit'] = [
            '#type' => 'submit',
            '#value' => $existing ? $this->t('Update suggestion') : $this->t('Suggest track'),
        ];

        return $form;
    }

    /**
     * {@inheritdoc}
     */
    public function submitForm(array &$form, FormStateInterface $form_state)
    {
        $suggestion = NULL;

        if ($id = $form_state->getValue('suggestion_id')) {
            $suggestion = Node::load($id);

            // It may have been accepted or rejected since the form loaded. If
            // so, leave it alone and start a new one.
            if (!$suggestion || $suggestion->get('field_swap_status')->value !== 'suggested') {
                $suggestion = NULL;
            }
        }

        if (!$suggestion) {
            $suggestion = Node::create([
                'type' => 'track_suggestion',
                'field_talk' => $form_state->getValue('talk_id'),
            ]);
        }

        $suggestion->set('field_suggested_track', $form_state->getValue('suggested_track'));
        $suggestion->set('field_swap_comment', $form_state->getValue('comment'));
        $suggestion->save();

        $this->messenger()->addStatus($this->t('Suggestion saved.'));

        // Without this, saving lands on the talk's public page instead of the
        // review page. The comment form has the same fix in sessions.module.
        $talk = Node::load($form_state->getValue('talk_id'));
        if ($talk) {
            $form_state->setRedirectUrl(Url::fromUserInput($talk->toUrl()->toString() . '/review'));
        }
    }

    /**
     * Returns active tracks as options, sorted by name.
     *
     * @param int|string|null $exclude_tid
     *   A track to leave out, normally the one the talk is already in.
     *
     * @return array
     *   Track names keyed by term id.
     */
    protected function activeTrackOptions($exclude_tid): array
    {
        $storage = \Drupal::entityTypeManager()->getStorage('taxonomy_term');

        $tids = $storage->getQuery()
            ->accessCheck(TRUE)
            ->condition('vid', 'session_track')
            ->condition('field_active', 1)
            ->sort('name')
            ->execute();

        $options = [];

        foreach ($storage->loadMultiple($tids) as $tid => $term) {
            if ((string) $tid !== (string) $exclude_tid) {
                $options[$tid] = $term->label();
            }
        }

        return $options;
    }

    /**
     * Finds the current user's open suggestion for a talk, if there is one.
     *
     * @param \Drupal\node\NodeInterface $talk
     *   The talk being reviewed.
     *
     * @return \Drupal\node\NodeInterface|null
     *   The suggestion, or NULL if they have none still waiting on a decision.
     */
    protected function openSuggestion(NodeInterface $talk): ?NodeInterface
    {
        // Suggestions are unpublished, so skip the access check and rely on
        // the owner condition instead.
        $nids = \Drupal::entityTypeManager()->getStorage('node')->getQuery()
            ->accessCheck(FALSE)
            ->condition('type', 'track_suggestion')
            ->condition('field_talk', $talk->id())
            ->condition('uid', $this->currentUser()->id())
            ->condition('field_swap_status', 'suggested')
            ->sort('created', 'DESC')
            ->range(0, 1)
            ->execute();

        return $nids ? Node::load(reset($nids)) : NULL;
    }
}
