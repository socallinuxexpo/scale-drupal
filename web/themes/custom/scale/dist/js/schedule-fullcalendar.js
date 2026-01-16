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
            end: validRangeEnd,
          };

          // Determine minHeight based on number of timeRange slots
          // Each slot is 30 minutes and each event is 73px tall
          const timeSlots = settings.schedule.timeRange ? settings.schedule.timeRange.slots : 32;
          const dayViewHeight = timeSlots * 100;
          console.log('Calculated calendar height:', dayViewHeight);

          // Calculate width for Full Schedule view based on number of tracks/resources
          const uniqueTracks = new Set();
          if (settings.schedule.tracks) {
            settings.schedule.tracks.forEach(track => {
              if (track && typeof track.id !== 'undefined' && track.id !== null && track.id !== '') {
                uniqueTracks.add(track.id);
              }
            });
          }
          console.log('Unique tracks:', Array.from(uniqueTracks));
          // const numberOfTracks = settings.schedule.tracks ? settings.schedule.tracks.length : 8;
          const numberOfTracks = uniqueTracks ? uniqueTracks.length : 8;
          console.log('Number of tracks:', numberOfTracks);
          const timelineWidth = Math.max(numberOfTracks * 50, 50); // Minimum 1200px, 150px per track

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
            expandRows: true,
            nowIndicator: true,
            displayEventTime: false,
            // height: dayViewHeight,
            height: 'auto',
            // height: '100%',
            // eventMinHeight: 90,
            // eventShortHeight: 90,
            // slotMinHeight: 100,
            // contentHeight: 'auto',

            initialDate: initialDate,
            validRange: validRange,
            weekends: true,
            hiddenDays: [],

            // Header Toolbar
            headerToolbar: {
              left: 'prev,next',
              center: 'title',
              right: 'resourceTimeGridDay,resourceTimeline,listWeek',
            },
            buttonText: {
              resourceTimeline: 'Full Schedule',
              listWeek: 'List View',
              day: 'Day View',
            },

            // Slot - Use dynamic time range based on actual sessions
            slotMinTime: settings.schedule.timeRange ? settings.schedule.timeRange.start : '08:00:00',
            slotMaxTime: settings.schedule.timeRange ? settings.schedule.timeRange.end : '23:59:59',
            slotLabelInterval: '00:30',
            slotLabelFormat: {
              hour: 'numeric',
              minute: '2-digit',
              omitZeroMinute: false,
              meridiem: 'short',
            },

            dayMaxEvents: true,
            dayMinWidth: 100,
            resources: settings.schedule.tracks,
            events: settings.schedule.agenda,

            // View-specific options
            views: {
              resourceTimeGridDay: {
                // height: dayViewHeight
              },
              resourceTimeline: {
                slotMinWidth: 120, // Minimum width for each time slot
                resourceAreaWidth: '20%', // Width of the resource area (track names)
                contentHeight: 'auto',
                aspectRatio: null, // Allow custom width control
              },
            },

            // Update URL when date changes
            datesSet: function (dateInfo) {
              // Get the current date being displayed
              const currentDate = dateInfo.start.toISOString().split('T')[0];

              // Update URL to reflect current date
              updateURLWithDate(currentDate);
            },

            // Apply dynamic dimensions when switching to views
            viewDidMount: function (info) {
              if (info.view.type === 'resourceTimeline') {
                calendar.setOption('height', 'auto');
              } else if (info.view.type === 'resourceTimeGridDay') {
                calendar.setOption('height', dayViewHeight);
              } else {
                calendar.setOption('height', 'auto');
              }
            },

            // Event output - view-specific content
            eventContent: function (arg) {
              let customHtml = document.createElement('div');
              const viewType = arg.view.type;

              // Different content based on view type
              switch (viewType) {
                // case 'resourceTimeGridDay':
                //   // Compact vertical layout for day view
                //   customHtml.innerHTML = `
                //     <div class="p-2">
                //       <div class="text-xs">${arg.event.extendedProps.range_str}</div>
                //       <a href="${arg.event.extendedProps.url}" class="inline-block text-inherit hover:text-inherit hover:underline flex gap-1">
                //         <div class="font-semibold text-sm">${arg.event.extendedProps.speakers}</div>
                //         <div>|</div>
                //         <div class="text-sm">
                //           ${arg.event.title}
                //         </div>
                //       </a>
                //     </div>
                //   `;
                //   break;
                case 'resourceTimeline':
                  // Horizontal layout for timeline view - time is already shown on timeline
                  customHtml.innerHTML = `
                    <a 
                      href="${arg.event.extendedProps.url}" 
                      class="text-inherit hover:text-inherit hover:underline p-1 flex flex-col h-full justify-center overflow-hidden"
                    >
                      <div class="text-sm leading-tight">${arg.event.title}</div>
                      <div class="font-semibold text-sm mb-1">${arg.event.extendedProps.speakers}</div>
                    </a>
                  `;
                  break;

                case 'listWeek':
                  // Minimal layout for list view - list already shows time and date
                  customHtml.innerHTML = `
                    <a 
                      href="${arg.event.extendedProps.url}" 
                      class="text-inherit hover:text-inherit hover:underline p-1 flex flex-col h-full justify-center overflow-hidden"
                    >
                      <div class="text-xs">${arg.event.extendedProps.range_str}</div>
                      <div class="text-sm leading-tight">${arg.event.title}</div>
                      <div class="font-semibold text-sm mb-1">${arg.event.extendedProps.speakers}</div>
                    </a>
                  `;
                  break;

                default:
                  // Fallback to original layout
                  customHtml.innerHTML = `
                    <a 
                      href="${arg.event.extendedProps.url}" 
                      class="text-inherit hover:text-inherit hover:underline p-1 flex flex-col h-full justify-center overflow-hidden"
                    >
                      <div class="text-xs leading-tight">${arg.event.title}</div>
                      <div class="font-semibold text-xs mb-1">${arg.event.extendedProps.speakers}</div>
                    </a>
                  `;
              }

              return { domNodes: [customHtml] };
            },
          });
          calendar.render();

        }

      });
    },
  };
})(Drupal, jQuery);
