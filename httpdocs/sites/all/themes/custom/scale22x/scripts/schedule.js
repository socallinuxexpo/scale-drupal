(function ($) {

  Drupal.behaviors.scale_schedule = {
    attach: function(context, settings) {
      $(".room-schedule-empty", context).closest(".pane-room-schedule", context).hide();
    }
  };
})(jQuery);
