(function (Drupal, once) {
  'use strict';

  Drupal.behaviors.mobileMenu = {
    attach: function (context) {
      // Process the hamburger button once.
      once('mobile-menu', '.hamburger-toggle', context).forEach(function (toggleBtn) {
        var menuWrapper = document.getElementById('primary-menu-wrapper');
        var overlay = document.querySelector('.menu-overlay');

        if (!menuWrapper) {
          return;
        }

        // --- Inject submenu toggle buttons ---
        // Find all level-1 items that have a level-2 child menu.
        var parentItems = menuWrapper.querySelectorAll('li.menu__item--level-1');
        parentItems.forEach(function (li) {
          var submenu = li.querySelector('ul.menu--level-2');
          if (!submenu) {
            return;
          }

          // Create a toggle button for expanding/collapsing the submenu.
          var subToggle = document.createElement('button');
          subToggle.className = 'submenu-toggle';
          subToggle.setAttribute('aria-expanded', 'false');
          subToggle.setAttribute('aria-label', 'Toggle submenu');
          subToggle.innerHTML = '&#9660;'; // ▼ down arrow

          // Insert the toggle button before the submenu.
          li.insertBefore(subToggle, submenu);

          // Toggle submenu on click.
          subToggle.addEventListener('click', function (e) {
            e.preventDefault();
            e.stopPropagation();
            var isOpen = submenu.classList.contains('is-open');

            if (isOpen) {
              submenu.classList.remove('is-open');
              subToggle.setAttribute('aria-expanded', 'false');
            } else {
              submenu.classList.add('is-open');
              subToggle.setAttribute('aria-expanded', 'true');
            }
          });
        });

        // --- Hamburger open/close ---
        function openMenu() {
          menuWrapper.classList.add('is-open');
          toggleBtn.setAttribute('aria-expanded', 'true');
          toggleBtn.setAttribute('aria-label', 'Close menu');
          if (overlay) {
            overlay.classList.add('is-active');
          }
          document.body.style.overflow = 'hidden'; // Prevent background scroll
        }

        function closeMenu() {
          menuWrapper.classList.remove('is-open');
          toggleBtn.setAttribute('aria-expanded', 'false');
          toggleBtn.setAttribute('aria-label', 'Open menu');
          if (overlay) {
            overlay.classList.remove('is-active');
          }
          document.body.style.overflow = '';
        }

        toggleBtn.addEventListener('click', function () {
          var isExpanded = toggleBtn.getAttribute('aria-expanded') === 'true';
          if (isExpanded) {
            closeMenu();
          } else {
            openMenu();
          }
        });

        // Close menu when clicking the overlay.
        if (overlay) {
          overlay.addEventListener('click', closeMenu);
        }

        // Close menu on Escape key.
        document.addEventListener('keydown', function (e) {
          if (e.key === 'Escape' && menuWrapper.classList.contains('is-open')) {
            closeMenu();
            toggleBtn.focus();
          }
        });
      });
    }
  };

})(Drupal, once);