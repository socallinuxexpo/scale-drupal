(function ($, Drupal, once) {
  Drupal.behaviors.myModuleBehavior = {
    attach: function (context, settings) {
      once('viewsSwiper', '.swiper-view', context).forEach(function (element) {
        const instances = drupalSettings.views_plugins.swiper_js;

        const initSwiper = (element, options) => {
          // Configure autoplay if enabled
          const autoplay_options = options.autoplay ? {
            delay: parseInt(options.autoplayDelay) || 3000,
            disableOnInteraction: false,
            pauseOnMouseEnter: true,
          } : false;

          const swiper = new Swiper($(element).find('.swiper')[0], {
            // Optional parameters
            // direction: 'vertical',
            slidesPerView: 2.5,
            loop: options.loop === 1,
            spaceBetween: options.spaceBetween,

            // Autoplay configuration
            autoplay: autoplay_options,

            breakpoints: {
              // when window width is >= 678px
              678: {
                slidesPerView: options.slidesPerView ? options.slidesPerView / 2 : 2.5,
              },
              1024: {
                slidesPerView: options.slidesPerView ?? 2.5,
              },
            },

            // If we need pagination
            pagination: options.pagination ? {
              el: '.swiper-pagination',
            } : false,

            // Navigation arrows
            navigation: options.navigation ? {
              prevEl: '.swiper-control-prev',
              nextEl: '.swiper-control-next',
            } : false,

            // And if we need scrollbar
            scrollbar: options.scrollbar ? {
              el: '.swiper-scrollbar',
            } : false,
          });
        };

        for (const instance in instances) {
          if ($(element).hasClass('swiper-view-' + instances[instance].view_uuid)) {
            const options = instances[instance].options;
            initSwiper(element, options);
          }
        }

      });
    },
  };
})(jQuery, Drupal, once);
