(function (Drupal, $) {
  Drupal.behaviors.fullCalendarInit = {
    attach: function (context, settings) {
      once('fullCalendarInit', '.fullCalendar', context).forEach(function (element) {

        // TODO: Add ability to filter by category
        // @see https://chatgpt.com/c/678ed2fa-dc2c-8006-8170-a8094bfcfe23

        const calendarEl = element;

        if (calendarEl) {

          // Ensure the end date is inclusive by adding one day
          const validRangeEnd = new Date(settings.schedule.range.end);
          validRangeEnd.setDate(validRangeEnd.getDate() + 1);
          const validRangeEndStr = validRangeEnd.toISOString().split('T')[0];

          const validRange = {
            start: settings.schedule.range.start,
            end: validRangeEndStr
          };

          const calendar = new FullCalendar.Calendar(calendarEl, {
            schedulerLicenseKey: 'CC-Attribution-NonCommercial-NoDerivatives',
            // plugins: ['ResourceTimeGrid'],
            initialView: 'resourceTimeGridDay',
            filterResourcesWithEvents: true,
            height: '100%',
            expandRows: true,
            nowIndicator: true,
            displayEventTime: false,

            initialDate: settings.schedule.range.start,
            validRange: validRange,

            // Header Toolbar
            headerToolbar: {
              left: 'prev,next',
              center: 'title',
              right: 'resourceTimeGridDay,resourceTimeline,listWeek'
            },
            buttonText: {
              resourceTimeline: 'Full Schedule',
              listWeek: 'List View',
              day: 'Day View'
            },

            // Slot
            slotMinTime: '08:00:00',
            slotLabelInterval: '00:30',
            slotLabelFormat: {
              hour: 'numeric',
              minute: '2-digit',
              omitZeroMinute: false,
              meridiem: 'short'
            },

            dayMaxEvents: true,
            dayMinWidth: 300,
            resources: settings.schedule.tracks,
            events: settings.schedule.agenda,

            // Event output
            eventContent: function(arg) {
              let customHtml = document.createElement('div');
              customHtml.innerHTML = `
                <div class="p-2">
                  <div class="text-xs">${arg.event.extendedProps.range_str}</div>
                  <div class="font-semibold">${arg.event.extendedProps.speakers}</div>
                  <div class="">
                    <a href="${arg.event.extendedProps.url}" class="text-inherit hover:text-inherit hover:underline">${arg.event.title}</a>
                  </div>
                </div>
              `;
              return { domNodes: [customHtml] };
            }
          });
          calendar.render();

        }

      });
    },
  };
})(Drupal, jQuery);
