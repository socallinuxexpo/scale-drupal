<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php $row_num = 0; ?>
<div class="featured-presentation-row">
<?php foreach ($rows as $id => $row): ?>
  <?php if ($row_num == 3) : ?>
    </div><div class="featured-presentation-row">
  <?php endif; ?>
  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
    <?php print $row; ?>
  </div>
  <?php $row_num++; ?>
<?php endforeach; ?>
</div>
