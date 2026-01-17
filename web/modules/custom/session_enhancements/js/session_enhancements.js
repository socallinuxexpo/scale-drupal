(function ($, Drupal, once) {
  'use strict';

  Drupal.behaviors.sessionEnhancements = {
    attach: function (context, settings) {
      // Only run once per page load
      once('session-enhancements', 'form[id*="node-session"]', context).forEach(function (form) {
        var $form = $(form);
        var $startDateField = $form.find('input[name*="field_time_slot"][name*="[value][date]"]');
        var $startTimeField = $form.find('input[name*="field_time_slot"][name*="[value][time]"]');
        var $endDateField = $form.find('input[name*="field_time_slot"][name*="[end_value][date]"]');
        var $endTimeField = $form.find('input[name*="field_time_slot"][name*="[end_value][time]"]');

        // Auto-populate end date when start date changes
        $startDateField.on('change', function () {
          var startDate = $(this).val();
          if (startDate && !$endDateField.val()) {
            $endDateField.val(startDate);
          }
        });

        // Auto-populate end time when start time changes (add 1 hour)
        $startTimeField.on('change', function () {
          var startTime = $(this).val();
          if (startTime && !$endTimeField.val()) {
            var timeParts = startTime.split(':');
            if (timeParts.length >= 2) {
              var hours = parseInt(timeParts[0], 10);
              var minutes = parseInt(timeParts[1], 10);
              
              // Add 1 hour
              hours += 1;
              if (hours >= 24) {
                hours = 0;
              }
              
              // Format the time (ensure two digits)
              var endTime = String(hours).padStart(2, '0') + ':' + String(minutes).padStart(2, '0');
              $endTimeField.val(endTime);
            }
          }
        });

        // Remove seconds from time inputs by setting step to 60
        $startTimeField.attr('step', '60');
        $endTimeField.attr('step', '60');
        
        // Also ensure the time format doesn't include seconds
        $startTimeField.on('input', function () {
          var value = $(this).val();
          if (value && value.length > 5) {
            // Remove seconds if they exist (format HH:MM:SS -> HH:MM)
            $(this).val(value.substring(0, 5));
          }
        });
        
        $endTimeField.on('input', function () {
          var value = $(this).val();
          if (value && value.length > 5) {
            // Remove seconds if they exist (format HH:MM:SS -> HH:MM)
            $(this).val(value.substring(0, 5));
          }
        });
      });
    }
  };

})(jQuery, Drupal, once);
