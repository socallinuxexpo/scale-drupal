(function (Drupal, $) {
  Drupal.behaviors.fullCalendarInit = {
    attach: function (context, settings) {
      once('fullCalendarInit', '.fullCalendar', context).forEach(function (element) {

        // TODO: Add ability to filter by category
        // @see https://chatgpt.com/c/678ed2fa-dc2c-8006-8170-a8094bfcfe23

        const calendarEl = element;

        if (calendarEl) {

          // Ensure the end date is inclusive by setting to end of day
          const validRangeEnd = new Date(settings.schedule.range.end + 'T23:59:59');

          const validRange = {
            start: settings.schedule.range.start,
            end: validRangeEnd
          };

          // Check for date parameter in URL
          function getDateFromURL() {
            const urlParams = new URLSearchParams(window.location.search);
            const dateParam = urlParams.get('date');

            if (dateParam) {
              // Validate the date is within our valid range
              const requestedDate = new Date(dateParam);
              const startDate = new Date(settings.schedule.range.start);
              const endDate = new Date(settings.schedule.range.end);

              if (requestedDate >= startDate && requestedDate <= endDate) {
                return dateParam;
              }
            }

            return settings.schedule.range.start;
          }

          // Function to update URL with current date
          function updateURLWithDate(date) {
            const url = new URL(window.location);
            url.searchParams.set('date', date);
            window.history.replaceState({}, '', url);
          }

          // Function to generate a shareable link for a specific date
          function generateShareableLink(date) {
            const url = new URL(window.location);
            url.searchParams.set('date', date);
            return url.toString();
          }

          // Make the function available globally for external use
          window.generateCalendarLink = generateShareableLink;

          const initialDate = getDateFromURL();

          const calendar = new FullCalendar.Calendar(calendarEl, {
            schedulerLicenseKey: 'CC-Attribution-NonCommercial-NoDerivatives',
            // plugins: ['ResourceTimeGrid'],
            initialView: 'resourceTimeGridDay',
            filterResourcesWithEvents: true,
            height: '100%',
            expandRows: true,
            nowIndicator: true,
            displayEventTime: false,

            initialDate: initialDate,
            validRange: validRange,
            weekends: true,
            hiddenDays: [],

            // Debug: Log the valid range to console
            viewDidMount: function(info) {
              console.log('FullCalendar validRange:', validRange);
              console.log('Current view:', info.view.type);
              console.log('View start:', info.view.currentStart);
              console.log('View end:', info.view.currentEnd);
            },

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

            // Slot - Use dynamic time range based on actual sessions
            slotMinTime: settings.schedule.timeRange ? settings.schedule.timeRange.start : '08:00:00',
            slotMaxTime: settings.schedule.timeRange ? settings.schedule.timeRange.end : '23:59:59',
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

            // Update URL when date changes
            datesSet: function(dateInfo) {
              // Get the current date being displayed
              const currentDate = dateInfo.start.toISOString().split('T')[0];
              
              // Update URL to reflect current date
              updateURLWithDate(currentDate);
            },

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
