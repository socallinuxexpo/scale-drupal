const plugin = require('tailwindcss/plugin');

module.exports = plugin(function({ addBase, theme }) {
  const baseStyles = {
    h1: {
      fontFamily: theme('fontFamily.sans'),
      fontSize: theme('fontSize.7xl'),
      fontWeight: theme('fontWeight.bold'),
      lineHeight: theme('lineHeight.tight'),
    },
    h2: {
      fontFamily: theme('fontFamily.sans'),
      fontSize: theme('fontSize.3xl'),
      fontWeight: theme('fontWeight.bold'),
    },
    h3: {
      fontFamily: theme('fontFamily.sans'),
      fontSize: theme('fontSize.2xl'),
      fontWeight: theme('fontWeight.bold'),
    },
    p: {
      // fontFamily: theme('fontFamily.serif'),
      // fontSize: theme('fontSize.base'),
      // fontWeight: theme('fontWeight.normal'),
      marginBottom: theme('margin.4'),
    },
    body: {
      fontFamily: theme('fontFamily.body'),
      fontSize: theme('fontSize.base'),
      fontWeight: theme('fontWeight.normal'),
    },
    a: {
      color: theme('colors.primary.500'),
      textDecoration: 'none',
      '&:hover': {
        color: theme('colors.primary.600'),
      },
    }
  };

  addBase(baseStyles);

});
