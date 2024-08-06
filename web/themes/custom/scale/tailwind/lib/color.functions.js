function _generateTintAndShade(hex, percent) {
  // Ensure the percent is between -100 and 100
  if (percent > 100 || percent < -100) {
    throw new Error('Percent must be between -100 and 100');
  }

  // Ensure the hex code is valid
  if (!/^#([0-9a-fA-F]{3}|[0-9a-fA-F]{6})$/i.test(hex)) {
    throw new Error('Invalid hex code');
  }

  // If short form hex is used (#RGB), expand it to long form (#RRGGBB)
  if (hex.length === 4) {
    hex = '#' + hex[1] + hex[1] + hex[2] + hex[2] + hex[3] + hex[3];
  }

  // Extract the RR, GG, BB components in decimal
  let red = parseInt(hex.slice(1, 3), 16);
  let green = parseInt(hex.slice(3, 5), 16);
  let blue = parseInt(hex.slice(5, 7), 16);

  // Adjust the components by the percentage
  if (percent > 0) {
    // Tint: blend with white
    red += ((255 - red) * percent) / 100;
    green += ((255 - green) * percent) / 100;
    blue += ((255 - blue) * percent) / 100;
  } else {
    // Shade: blend with black
    percent = Math.abs(percent);
    red = (red * (100 - percent)) / 100;
    green = (green * (100 - percent)) / 100;
    blue = (blue * (100 - percent)) / 100;
  }

  // Convert back to hexadecimal and ensure 2 characters
  red = Math.round(red).toString(16).padStart(2, '0');
  green = Math.round(green).toString(16).padStart(2, '0');
  blue = Math.round(blue).toString(16).padStart(2, '0');

  return `#${red}${green}${blue}`;
}

/**
 * Generates an object of colors, tints, and shades.
 * This function loops your abstract_colors and automatically generates a shade based on your shades array.
 *
 * color_array: object
 * Example:
 * {
 *   'muted': '#ff5a00',
 *   'primary': '#26ff00',
 * }
 *
 * shades: array
 * Example:
 * [
 *   50,
 *   100,
 *   200,
 *   950,
 * ];
 *
 * Example response:
 * {
 *   primary: {
 *     DEFAULT: #123456,
 *     100: #123456,
 *     200: #123456,
 *   },
 *   secondary: {
 *     DEFAULT: #123456,
 *     100: #123456,
 *     200: #123456,
 *   }
 * }
 * */
export function generateColorTintsAndShades(color_array, shades) {
  let tintsAndShades = [];

  // Loop over theme colors
  for (const color in color_array) {
    const hex = color_array[color];

    // Set default value for this color
    tintsAndShades[color] = { DEFAULT: hex };
    // tintsAndShades[color] = { };

    // Loop over the shades chosen
    for (const item in shades) {
      const shade = shades[item];
      // To generate a shade, we must turn convert our values from 1-1000 format to -100-100 (percent) format
      const percent = 100 - (shade * 0.2);

      // Set shade values for this color
      tintsAndShades[color][shade] = _generateTintAndShade(hex, percent);
      // const newHex = _generateTintAndShade(hex, percent);
      // tintsAndShades[color][shade] = 'var(--' + newHex + ')';
    }
  }
  // console.log(tintsAndShades);
  return tintsAndShades;
}
