<!-- Modified by Ron Golan for SCALE 11x -->
<!-- Header -->
<div id="header" class="container">

  <div class="row">
    <div class="span12">

      <div id="branding">
        <img class="hidden-phone-portrait" src="/<?php print drupal_get_path('theme', 'ui_toolkit'); ?>/img/11x_knob100.png">
        <img class="region-header" src="/<?php print drupal_get_path('theme', 'ui_toolkit'); ?>/img/11x_knob100.png">
        <img class="region-header" src="/<?php print drupal_get_path('theme', 'ui_toolkit'); ?>/img/11x_knob100.png">
        <img src="/<?php print drupal_get_path('theme', 'ui_toolkit'); ?>/img/scale11x-logo60.png">
      </div>

      <div id="header-region">
        <?php print render($page['header']); ?>
      </div>
    </div>
  </div>

  <!-- Primary Nav -->
  <div id="menu" class="row">
    <div class="span12">
            <?php print render($page['search_top']); ?>
      <div class="navbar hidden-desktop">
        <div class="navbar-inner">
          <div class="container">

            <!-- .btn-navbar is used as the toggle for collapsed navbar content -->
            <button type="button" class="btn btn-navbar" data-toggle="collapse" data-target=".nav-collapse">
              <span class="icon-bar"></span>
              <span class="icon-bar"></span>
              <span class="icon-bar"></span>
            </button>
            <!-- Everything you want hidden at 940px or less, place within here -->
            <div class="nav-collapse">
              <!-- .nav, .navbar-search, .navbar-form, etc -->
              <?php print ui_toolkit_nav('main-menu'); ?>
              <?php //print render($page['primary_menu']); ?>
            </div>

            <?php //print render($page['search_top']); ?>

          </div>
        </div>
      </div>
    </div>
  </div>
  <!-- /Primary Nav -->


</div>
<!-- /Header -->


<!-- Page container -->
<div class="container page-container">

  <div class="row">
    <!-- Radio top -->
    <div id="radio-top" class="span8 offset3">
        <?php print render($page['radio_top']); ?>
    </div>
    <!-- /Radio top -->
  </div>

  <div id="content-row" class="row">

    <!-- Left sidebar -->
    <?php if ($page['left']): ?>
      <div id="sidebar-left" class="span3 sidebar-area">
        <?php print render($page['left']); ?>
      </div>
    <?php endif; ?>
    <!-- /Left sidebar -->

    <!-- Featured -->
    <div id="featured" class="span8">
      <div class="row">
        <?php print render($page['featured']); ?>
      </div>
    </div>
    <!-- /Featured -->

    <!-- radio-display -->
    <div id="radio-display" class="span8">
    <div class="row">
    <!-- Content area -->
    <div class="span<?php print $content_span; ?>" id="content-area">

    <?php if ($messages): ?>
      <div id="messages">
        <div class="section clearfix">
          <?php print $messages; ?>
        </div>
      </div> <!-- /.section, /#messages -->
    <?php endif; ?>

    <?php print render($title_prefix); ?>

    <?php if ($title): ?>
      <h1 class="page-title">
        <?php print $title; ?>
      </h1>
    <?php endif; ?>

    <?php print render($title_suffix); ?>

    <?php if ($tabs): ?>
      <div class="tabs">
        <?php print render($tabs); ?>
      </div>
    <?php endif; ?>

    <?php print render($page['help']); ?>

    <?php if ($action_links): ?>
      <ul class="action-links">
        <?php print render($action_links); ?>
      </ul>
    <?php endif; ?>

    <?php print render($page['content']); ?>

    </div>
    <!-- /Content area -->


    <!-- Right sidebar -->
    <?php if ($page['right']): ?>
      <div id="sidebar-right" class="span3 sidebar-area">
        <?php print render($page['right']); ?>
      </div>
    <?php endif; ?>
    <!-- /Right sidebar -->
    </div>
    </div>
    <!-- /radio-display -->

  </div><!-- /row -->

  <div class="row">
    <!-- Radio bottom -->
    <div id="radio-bottom" class="span8 offset3">
        <?php print render($page['radio_bottom']); ?>
        <div id="perf">
          <img src="/sites/all/themes/custom/ui_toolkit/img/perf_750.png">
        </div>
    </div>
    <!-- /Radio bottom -->
  </div>


</div> <!-- /Page container -->


<!-- Footer -->
<div id="footer" class="container">
  <div class="container">
    <?php print render($page['footer']); ?>
  <p>&nbsp;</p>
  </div>
</div>
<!-- /Footer -->

