import colors from 'tailwindcss/colors';
import { generateColorTintsAndShades } from './tailwind/lib/color.functions';
import { abstract_colors, shades } from './tailwind/colors.config';
import { component__btn } from './tailwind/components/btn';
import { generateContrastColors } from './tailwind/lib/contrast.functions';

const typography = require('./tailwind/typography');
const layout = require('./tailwind/layout');
const component__menu = require('./tailwind/components/menu');

/** @type {import('tailwindcss').Config} */
module.exports = {
  content: [
    '!node_modules',
    './{components,templates,preprocess}/**/*.{twig,php,inc}',
    './src/**/*.{scss,js}',
  ],
  safelist: [
    {
      pattern: /^btn/,
      variants: ['hover', 'focus'],
    },
    { pattern: /^views-grid-/ },
    { pattern: /^container-/ },
  ],
  theme: {
    contrast: ({ theme }) => ({ ...generateContrastColors(theme('colors')) }),
    colors: ({ theme }) => {
      return {
        ...colors,
        ...generateColorTintsAndShades(abstract_colors, shades),
      };
    },
    fontFamily: {
      'sans': ['"Outfit"', 'sans-serif'],
      'body': ['"Outfit"', 'sans-serif'],
    },
    extend: {},
    debug: ({ theme }) => {
      // console.log('test', theme('fontSize'));
      // console.log('COLORS', theme('contrast'));
      // console.log('colors', theme('colors.slate'));
      // console.log('contrast', theme('contrast.slate'));
      // console.log('COLORS', theme('contrast.primary'));
      // console.log('COMPONENTS', theme('components'));
      // console.log('tabsUnderline', theme('components.tabsUnderline'));
    },
  },
  plugins: [
    layout,
    typography,
    component__menu,
    component__btn,
  ],
};

