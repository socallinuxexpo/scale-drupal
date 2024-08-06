const plugin = require('tailwindcss/plugin');

module.exports = plugin(function({ addBase, addComponents, theme }) {

  addComponents({
    '.container-fluid': {
      '@apply w-full': {},
    },
    '.container-fixed': {
      '@apply container mx-auto': {},
    },
    '.container-fluid-fixed': {
      '@apply w-full': {},
      '> *': {
        '@apply container mx-auto': {},
      }
    },

    '.p-component': {
      '@apply p-7': {}
    },
    '.px-component': {
      '@apply px-7': {}
    }
  })

});
