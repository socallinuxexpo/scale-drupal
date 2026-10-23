/**
 * @file
 * Keeps a sponsor logo's alt text defaulted to the sponsor's Title.
 *
 * Fills the box when it appears after an upload, and mirrors the Title into
 * it while typing. Only ever writes to a box that is empty or still holds
 * what this script last put there, so alt text typed by hand - or set
 * deliberately on an existing sponsor - is never overwritten.
 */

(function (Drupal) {
  'use strict';

  var TITLE = '[name="title[0][value]"]';
  var ALT = '[name="field_sponsor_logo[0][alt]"]';

  var written = null;

  /**
   * Writes the Title into the alt box, unless somebody else owns it.
   */
  function sync(title) {
    var alt = document.querySelector(ALT);
    var previous = written;

    // Tracked even with no box to write to, so a Title typed before the
    // upload still matches the box that appears afterwards.
    written = title.value.trim();

    if (!alt || (alt.value !== '' && alt.value !== previous)) {
      return;
    }

    alt.value = written;
  }

  Drupal.behaviors.sponsorLogoAlt = {
    attach: function () {
      var title = document.querySelector(TITLE);

      if (!title) {
        return;
      }

      // Seeded once so that editing a sponsor whose alt was customised leaves
      // it alone: that alt matches neither an empty box nor this value.
      if (written === null) {
        written = title.value.trim();
      }

      // The box only exists after an upload, and attach runs again when that
      // upload replaces this part of the form - which is where it gets filled.
      sync(title);

      if (title.dataset.sponsorLogoAltBound) {
        return;
      }

      title.dataset.sponsorLogoAltBound = '1';

      title.addEventListener('input', function () {
        sync(title);
      });
    }
  };
})(Drupal);
