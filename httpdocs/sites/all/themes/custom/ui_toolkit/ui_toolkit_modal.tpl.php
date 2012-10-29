  <a class="btn" onclick="jQuery('#modal-<?php print $counter; ?>').modal();">
    <?php print $button; ?>
  </a>

  <div class="modal hide" id="modal-<?php print $counter; ?>">
    <div class="modal-header">
      <button type="button" class="close" data-dismiss="modal">×</button>
      <h3><?php print $title; ?></h3>
    </div>
    <div class="modal-body">
      <?php print $content; ?>
    </div>
  </div>