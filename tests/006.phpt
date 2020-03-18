--TEST--
Collection casting to array
--SKIPIF--
<?php if (!extension_loaded("collection")) print "skip"; ?>
--FILE--
<?php
$array = new Collection(2, [
	"Hello",
	"World"
]);

var_dump((array) $array);
?>
--EXPECT--
array(2) {
  [0]=>
  string(5) "Hello"
  [1]=>
  string(5) "World"
}



