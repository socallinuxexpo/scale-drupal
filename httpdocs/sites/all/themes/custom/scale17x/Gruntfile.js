module.exports = function(grunt) {
  // Project configuration.
  grunt.initConfig({
    less: {
      options: {
        banner: '/* RG Gruntfile test. */',
      },
      development: {
        files: {
          "css/style.css": "less/style.less"
        }
      }
    },
    watch: {
      files: ['less/*.less'],
      tasks: ['less'],
    }
  });

  // Load the plugin that provides the "less" task.
  grunt.loadNpmTasks('grunt-contrib-less');

  // Load the plugin that provides the "watch" task.
  grunt.loadNpmTasks('grunt-contrib-watch');

  // Default task(s).
  grunt.registerTask('default', ['less']);

};
