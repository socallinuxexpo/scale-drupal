const plugin = require('tailwindcss/plugin');

module.exports = plugin(function({ addBase, addComponents, theme }) {
  addBase({

    // Define default btn styles here
    ':root': {
      '--menu-padding': theme('spacing.3') + ' ' + theme('spacing.5'),
      '--menu-item-padding': theme('spacing.2') + ' ' + theme('spacing.4'),
      '--menu-item-font-size': theme('fontSize.lg'),
      '--menu-item-hover-color': theme('colors.primary.400'),
      '--menu-item-color': theme('colors.white.DEFAULT'),
      '--menu-item-active-color': theme('colors.primary.500'),
    },
  });

  addComponents({
    'ul.menu': {
      '@apply flex': {},
      'padding': 'var(--menu-padding)',

      '.menu-item': {
        '@apply inline-block relative': {},
        'color': 'var(--menu-item-color)',
        'font-size': 'var(--menu-item-font-size)',
        'a': {
          '@apply inline-block': {},
          'padding': 'var(--menu-item-padding)',
          'color': 'inherit',
        },
        '&:hover': {
          '@apply menu-item--hover': {},
        },
        '&:has(.is-active)': {
          '@apply menu-item--active': {},
        }
      },
    },
    '.menu-item--underline': {
      '&:before': {
        'content': '""',
        'position': 'absolute',
        'width': '22px',
        'border-bottom': '4px solid var(--menu-item-color)',
        'bottom': '0',
        'left': '50%',
        'transform': 'translateX(-50%)',
        '@apply rounded': {},
      },
    },
    '.menu-item--hover': {
      '@apply menu-item--underline': {},
      '--menu-item-color': theme('colors.primary.400'),
    },
    '.menu-item--active': {
      '@apply menu-item--underline': {},
      '--menu-item-color': theme('colors.primary.500'),
    },

  })

});
