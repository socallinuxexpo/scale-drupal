<?php
//$current_theme = variable_get('theme_default','none');
//dpm($current_theme);
?>
<header role="banner" id="page-header">
  <div class="container">
    <div class="row">
      <div class="visible-phone small-site-logo">
        <a href="/"><img src="<?php print '/' . drupal_get_path('theme', 'scale16x') . '/img/16x_logo_sm.png'; ?>" alt="SCALE 16x logo"></a>
      </div>
      <div id="site-logo" class="span6 offset3 hidden-phone">
        <a href="/"><img src="<?php print '/' . drupal_get_path('theme', 'scale16x') . '/img/16x_logo_lg.png'; ?>" alt="SCALE 16x logo"></a>
      </div>
    </div>
  </div>
</header>
<div class="container">
  <header id="navbar" class="navbar">
    <div class="navbar-inner">
      <div class="hidden-phone">
        <?php print render($page['header']); ?>
      </div>
      <!-- .btn-navbar is used as the toggle for collapsed navbar content -->
      <a class="btn btn-navbar" data-toggle="collapse" data-target=".nav-collapse">
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
      </a>

      <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
        <div class="nav-collapse collapse">
          <nav role="navigation">
            <?php if (!empty($primary_nav)): ?>
              <?php print render($primary_nav); ?>
            <?php endif; ?>
            <?php if (!empty($secondary_nav)): ?>
              <?php print render($secondary_nav); ?>
            <?php endif; ?>
            <?php if (!empty($page['navigation'])): ?>
              <?php print render($page['navigation']); ?>
            <?php endif; ?>
          </nav>
        </div>
      <?php endif; ?>
    </div>
  </header> <!-- /#header -->
</div>

<div class="main-container container">

  <div class="row">

      <?php if (!empty($page['highlighted'])): ?>
        <div class="span12 highlighted"><?php print render($page['highlighted']); ?></div>
      <?php endif; ?>
  </div>

  <div class="row-fluid">
    <?php if (!empty($page['sidebar_first'])): ?>
      <aside class="span3 hidden-phone" role="complementary">
        <?php $sidebar_first = render($page['sidebar_first']); ?>
        <?php print render($sidebar_first); ?>
      </aside>  <!-- /#sidebar-first -->
    <?php endif; ?>

    <section class="main <?php print _bootstrap_content_span($columns); ?>">
      <a id="main-content"></a>
      <?php print render($title_prefix); ?>
      <?php if (!empty($title)): ?>
        <h1 class="page-header"><span class="page-header-content"><?php print $title; ?></span></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php print $messages; ?>
      <?php if (!empty($tabs)): ?>
        <?php print render($tabs); ?>
      <?php endif; ?>
      <?php if (!empty($page['help'])): ?>
        <div class="well"><?php print render($page['help']); ?></div>
      <?php endif; ?>
      <?php if (!empty($action_links)): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php print render($page['content']); ?>
    </section>

    <?php if (!empty($page['sidebar_first'])): ?>
      <aside class="span3 visible-phone" role="complementary">
        <?php print render($sidebar_first); ?>
      </aside>  <!-- /#sidebar-first -->
    <?php endif; ?>

    <?php if (!empty($page['sidebar_second'])): ?>
      <aside class="span3" role="complementary">
        <?php print render($page['sidebar_second']); ?>
      </aside>  <!-- /#sidebar-second -->
    <?php endif; ?>

  </div>
</div>
<footer class="footer container">
  <?php print render($page['footer']); ?>
</footer>
