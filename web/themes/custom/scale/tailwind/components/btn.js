const plugin = require('tailwindcss/plugin');

export const component__btn = plugin(function ({ addBase, addComponents, theme }) {

  addBase(
    {
      // Define default btn styles here
      ':root': {
        '--btn-padding': theme('spacing.3') + ' ' + theme('spacing.5'),
        '--btn-foreground': theme('contrast.primary.550'),
        '--btn-background': theme('colors.primary.500'),
        '--btn-hover-foreground': theme('contrast.primary.550'),
        '--btn-hover-background': theme('colors.primary.550'),
        '--btn-border-width': theme('border-4'),
        '--btn-border-color': 'transparent',
        '--btn-font-size': theme('fontSize.base')
      },
    }
  )

  addComponents({
    // Set default btn styles here
    '.btn': {
      '@apply rounded inline-block': {},
      'padding': 'var(--btn-padding)',
      'background-color': 'var(--btn-background)',
      'color': 'var(--btn-foreground)',
      'border-width': 'var(--btn-border-width)',
      'border-color': 'var(--btn-border-color)',
      'font-size': 'var(--btn-font-size)',
      '&:hover': {
        'color': 'var(--btn-hover-foreground)',
        'background-color': 'var(--btn-hover-background)',
      }
    },

    '.btn-white': {
      '--btn-background': theme('colors.white.500'),
      '--btn-foreground': theme('contrast.white.500'),
      '--btn-hover-foreground': 'inherit',
      '--btn-hover-background': theme('colors.muted.50'),
      '--tw-ring-color': theme('colors.muted.200'),
    },

    '.btn-black': {
      '--btn-foreground': theme('contrast.black.500'),
      '--btn-background': theme('colors.black.500'),
      '--btn-hover-foreground': theme('colors.white.500'),
      '--btn-hover-background': theme('colors.black.400'),
      '--tw-ring-color': theme('colors.black.200'),
    },

    '.btn-light': {
      '--btn-background': theme('colors.light.500'),
      '--btn-foreground': theme('contrast.light.500'),
      '--btn-hover-background': theme('colors.light.400'),
      '--tw-ring-color': theme('colors.light.700'),
    },

    '.btn-dark': {
      '--btn-background': theme('colors.dark.500'),
      '--btn-hover-foreground': theme('colors.white.500'),
      '--btn-hover-background': theme('colors.dark.400'),
      '--tw-ring-color': theme('colors.dark.200'),
    },

    '.btn-muted': {
      '--btn-background': theme('colors.muted.500'),
      '--btn-hover-foreground': theme('colors.white.500'),
      '--btn-hover-background': theme('colors.muted.600'),
      '--tw-ring-color': theme('colors.muted.200'),
    },

    '.btn-primary': {
      '--btn-foreground': theme('contrast.primary.550'),
      '--btn-background': theme('colors.primary.500'),
      '--btn-hover-foreground': theme('contrast.primary.550'),
      '--btn-hover-background': theme('colors.primary.400'),
      '--tw-ring-color': theme('colors.primary.200'),
    },

    '.btn-secondary': {
      '--btn-background': theme('colors.secondary.500'),
      '--btn-foreground': theme('contrast.secondary.500'),
      '--btn-hover-background': theme('colors.secondary.400'),
      '--tw-ring-color': theme('colors.secondary.200'),
    },

    '.btn-success': {
      '--btn-background': theme('colors.success.500'),
      '--btn-foreground': theme('contrast.success.500'),
      '--btn-hover-background': theme('colors.success.400'),
      '--tw-ring-color': theme('colors.success.200'),
    },

    '.btn-warning': {
      '--btn-background': theme('colors.warning.500'),
      '--btn-foreground': theme('contrast.warning.500'),
      '--btn-hover-background': theme('colors.warning.400'),
      '--tw-ring-color': theme('colors.warning.200'),
    },

    '.btn-danger': {
      '--btn-background': theme('colors.danger.500'),
      '--btn-hover-foreground': theme('colors.white.500'),
      '--btn-hover-background': theme('colors.danger.400'),
      '--tw-ring-color': theme('colors.danger.200'),
    },

    ///////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////
    // Outline Buttons

    '.btn-outline-white': {
      '--btn-background': 'transparent',
      '--btn-foreground': theme('colors.white.500'),
      '--btn-hover-foreground': theme('colors.black.500'),
      '--btn-hover-background': theme('colors.white.500'),
      '--btn-border-color': theme('colors.white.500'),
      '--tw-ring-color': theme('colors.muted.200'),
    },

    '.btn-outline-black': {
      '--btn-background': 'transparent',
      '--btn-foreground': theme('colors.black.500'),
      '--btn-hover-foreground': theme('colors.white.500'),
      '--btn-hover-background': theme('colors.black.500'),
      '--btn-border-color': theme('colors.black.500'),
      '--tw-ring-color': theme('colors.black.200'),
    },

    '.btn-outline-light': {
      '--btn-background': 'transparent',
      '--btn-foreground': theme('colors.light.500'),
      '--btn-hover-foreground': theme('colors.black.500'),
      '--btn-hover-background': theme('colors.light.500'),
      '--btn-border-color': theme('colors.light.500'),
      '--tw-ring-color': theme('colors.light.200'),
    },

    '.btn-outline-dark': {
      '--btn-background': 'transparent',
      '--btn-foreground': theme('colors.dark.500'),
      '--btn-hover-foreground': theme('colors.white.500'),
      '--btn-hover-background': theme('colors.dark.500'),
      '--btn-border-color': theme('colors.dark.500'),
      '--tw-ring-color': theme('colors.dark.200'),
    },

    '.btn-outline-muted': {
      '--btn-background': 'transparent',
      '--btn-foreground': theme('colors.muted.500'),
      '--btn-hover-foreground': theme('colors.white.500'),
      '--btn-hover-background': theme('colors.muted.500'),
      '--btn-border-color': theme('colors.muted.500'),
      '--tw-ring-color': theme('colors.muted.200'),
    },

    '.btn-outline-primary': {
      '--btn-background': 'transparent',
      '--btn-foreground': theme('colors.primary.500'),
      '--btn-hover-foreground': theme('colors.white.500'),
      '--btn-hover-background': theme('colors.primary.500'),
      '--btn-border-color': theme('colors.primary.500'),
      '--tw-ring-color': theme('colors.primary.200'),
    },

    '.btn-outline-secondary': {
      '--btn-background': 'transparent',
      '--btn-foreground': theme('colors.secondary.500'),
      '--btn-hover-foreground': theme('colors.black.500'),
      '--btn-hover-background': theme('colors.secondary.500'),
      '--btn-border-color': theme('colors.secondary.500'),
      '--tw-ring-color': theme('colors.secondary.200'),
    },

    '.btn-outline-success': {
      '--btn-background': 'transparent',
      '--btn-foreground': theme('colors.success.500'),
      '--btn-hover-foreground': theme('colors.black.500'),
      '--btn-hover-background': theme('colors.success.500'),
      '--btn-border-color': theme('colors.success.500'),
      '--tw-ring-color': theme('colors.success.200'),
    },

    '.btn-outline-warning': {
      '--btn-background': 'transparent',
      '--btn-foreground': theme('colors.warning.500'),
      '--btn-hover-foreground': theme('colors.black.500'),
      '--btn-hover-background': theme('colors.warning.500'),
      '--btn-border-color': theme('colors.warning.500'),
      '--tw-ring-color': theme('colors.warning.200'),
    },

    '.btn-outline-danger': {
      '--btn-background': 'transparent',
      '--btn-foreground': theme('colors.danger.500'),
      '--btn-hover-foreground': theme('colors.white.500'),
      '--btn-hover-background': theme('colors.danger.500'),
      '--btn-border-color': theme('colors.danger.500'),
      '--tw-ring-color': theme('colors.danger.200'),
    },

    ///////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////
    // Button Sizes

    '.btn-xs': {
      '--btn-padding': theme('spacing.3') + ' ' + theme('spacing.2'),
      '--btn-font-size': theme('fontSize.xs')
    },
    '.btn-sm': {
      '--btn-padding': theme('spacing.3') + ' ' + theme('spacing.3'),
      '--btn-font-size': theme('fontSize.sm')
    },
    '.btn-lg': {
      '--btn-padding': theme('spacing.5') + ' ' + theme('spacing.4'),
      '--btn-font-size': theme('fontSize.base')
    },
    '.btn-xl': {
      '--btn-padding': theme('spacing.6') + ' ' + theme('spacing.5'),
      '--btn-font-size': theme('fontSize.lg')
    },

  })
});
