<div id="carousel-<?php print $counter; ?>" class="carousel slide">
  <!-- Carousel items -->
  <div class="carousel-inner">

  <?php
    $i = 0;
    foreach ($images as $image) {
      print '<div class="item ' . ($i == 0 ? 'active' : '')  . '">';
      print '<img src="' . (is_array($image) ? $image['file'] : $image) . '"/>';

      if (!empty($image['title'])) {
        print '<div class="carousel-caption"><h4>' . $image['title'] . '</h4></div>';
      }
      print '</div>';

      $i++;
    }
  ?>
  </div>

  <!-- Carousel nav -->
  <a class="carousel-control left" href="#carousel-<?php print $counter; ?>" data-slide="prev">&lsaquo;</a>
  <a class="carousel-control right" href="#carousel-<?php print $counter; ?>" data-slide="next">&rsaquo;</a>
</div>
