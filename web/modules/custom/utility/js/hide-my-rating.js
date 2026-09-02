/**
 * @file
 * Adds a checkbox to the votes report that hides the My Rating column.
 *
 * This is cosmetic. The values are still present in the page, so it hides the
 * column from a room, not from a person who looks at the source.
 */

(function (Drupal) {
  'use strict';

  var KEY = 'scale.hideMyRating';

  /**
   * Reads the stored preference, tolerating browsers that block storage.
   */
  function isHidden() {
    try {
      return localStorage.getItem(KEY) === '1';
    }
    catch (e) {
      return false;
    }
  }

  /**
   * Stores the preference, tolerating browsers that block storage.
   */
  function remember(hidden) {
    try {
      localStorage.setItem(KEY, hidden ? '1' : '0');
    }
    catch (e) {
      // A session-only toggle is still useful, so carry on.
    }
  }

  Drupal.behaviors.hideMyRating = {
    attach: function () {
      var view = document.querySelector('.view-session-votes');

      if (!view) {
        return;
      }

      // Runs on every attach, so the column stays hidden after an AJAX sort
      // replaces the table.
      document.body.classList.toggle('hide-my-rating', isHidden());

      // Rebuilt whenever it is missing, since an AJAX response replaces the
      // view wrapper the control sits in.
      if (document.getElementById('hide-my-rating')) {
        return;
      }

      // Sits between the filter card and the table. Keeping it out of the
      // exposed form matters: controls in there change which rows you see,
      // and this one only changes how they look.
      var anchor = view.querySelector('.view-content');

      var wrapper = document.createElement('div');
      wrapper.className = 'hide-my-rating-toggle';

      var input = document.createElement('input');
      input.type = 'checkbox';
      input.id = 'hide-my-rating';
      input.checked = isHidden();

      var label = document.createElement('label');
      label.htmlFor = 'hide-my-rating';
      label.textContent = Drupal.t('Hide My Rating');

      input.addEventListener('change', function () {
        remember(input.checked);
        document.body.classList.toggle('hide-my-rating', input.checked);
      });

      wrapper.appendChild(input);
      wrapper.appendChild(label);

      if (anchor) {
        anchor.parentNode.insertBefore(wrapper, anchor);
      }
      else {
        // Themes are free to drop that wrapper, so fall back to sitting above
        // the view rather than not rendering at all.
        view.parentNode.insertBefore(wrapper, view);
      }
    }
  };
})(Drupal);
