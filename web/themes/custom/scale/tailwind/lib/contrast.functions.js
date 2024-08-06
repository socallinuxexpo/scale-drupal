/**
 * This file is a utility file used for generating tints and shades of color
 * You will never use functions in this file, directly.
 *
 * To configure what colors, as well as their tints/shades, modify colors.config.js.
 * */

function _hexToRgb(hex) {
  let bigint = parseInt(hex.substring(1), 16);
  let r = (bigint >> 16) & 255;
  let g = (bigint >> 8) & 255;
  let b = bigint & 255;
  return [r, g, b];
}

function _luminance(hex) {
  let rgb = _hexToRgb(hex);
  let normalized = rgb.map((c) => {
    c /= 255;
    return c <= 0.03928 ? c / 12.92 : Math.pow((c + 0.055) / 1.055, 2.4);
  });
  return 0.2126 * normalized[0] + 0.7152 * normalized[1] + 0.0722 * normalized[2];
}

/**
 * The higher, the more strict
 * */
function _contrastRatio(lum1, lum2) {
  let ratio = lum1 > lum2
    ? (lum1 + 0.05) / (lum2 + 0.05)
    : (lum2 + 0.05) / (lum1 + 0.05);
  return ratio / 21;
}

/**
 * Given a background hex color, this function will return an AA-compliant hex code to be used as a foreground
 * For example, given a background color of #000000, #ffffff will be returned.
 * */
function _getForegroundColor(hexBackgroundColor) {
  let backgroundLum = _luminance(hexBackgroundColor);
  let blackLum = _luminance("#000000");
  let whiteLum = _luminance("#ffffff");
  let blackContrast = _contrastRatio(backgroundLum, blackLum);
  let whiteContrast = _contrastRatio(backgroundLum, whiteLum);

  if (blackContrast >= 0.2143) {
    return '#000000'
  } else if (whiteContrast >= 0.2143) {
    return '#ffffff'
  } else {
    return '#ffffff'
  }
}

/**
 * Generates an object of contrast colors mapped to your abstract colors.
 * This function allows you to add a text-contrast-{primary} to components with background colors.
 *
 * Expects an array like this:
 * const array = [
 *   primary: [
 *     50: #123456
 *     100: #123456
 *   ],
 *   secondary: [
 *     50: #123456
 *     100: #123456
 *   ]
 * ]
 *
 * TODO: instead of this generating either black or white, generate a shade, lighter or darker, until it complies
 * */
export function generateContrastColors(color_shades_array) {
  let contrast_colors = {};
  for (const color in color_shades_array) {
    const shades = color_shades_array[color];
    contrast_colors[color] = {};
    for (const shade in shades) {
      const hex = shades[shade];
      contrast_colors[color][shade] = _getForegroundColor(hex);
    }
  }
  return contrast_colors;
}
