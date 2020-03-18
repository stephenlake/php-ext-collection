--TEST--
Collection properties
--SKIPIF--
<?php if (!extension_loaded("collection")) print "skip"; ?>
--FILE--
<?php
$array = new Collection(1);

var_dump($array->property);
?>
--EXPECTF--
Fatal error: Uncaught Exception: properties on Collection objects are not allowed in %s:4
Stack trace:
#0 {main}
  thrown in %s on line 4





