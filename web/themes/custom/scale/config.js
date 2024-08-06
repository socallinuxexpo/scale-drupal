/**
 * This config file is for gulp tasks and pertains only to the current theme (not a base theme)
 * */
const config = {
  tailwindjs: './tailwind.config.js',
  port: 9050,
  imagemin: {
    png: [0.7, 0.7], // range between min (0) and max (1) as quality - 70% with current values for png images,
    jpeg: 70, // % of compression for jpg, jpeg images
  },
};

// tailwind plugins
const plugins = {
  typography: true,
  forms: true,
  containerQueries: true,
  'postcss-import': {},
};

// base folder paths
const basePaths = ['src', 'dist'];

// folder assets paths
const folders = ['css', 'js', 'img', 'fonts', 'third-party'];

const paths = {
  root: __dirname + '/',
  templates: __dirname + '/templates',
  components: __dirname + '/components',
  preprocess: __dirname + '/preprocess',
  config: __dirname + '/tailwind'
};

// Generate paths
basePaths.forEach((base) => {
  paths[base] = {
    base: `./${base}`,
  };
  folders.forEach((folderName) => {
    const toCamelCase = folderName.replace(/\b-([a-z])/g, (_, c) =>
      c.toUpperCase(),
    );
    paths[base][toCamelCase] = `./${base}/${folderName}`;
  });
});

module.exports = {
  config,
  plugins,
  paths,
};
