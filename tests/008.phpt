--TEST--
Collection flip
--SKIPIF--
<?php if (!extension_loaded("collection")) print "skip"; ?>
--FILE--
<?php
$array = new Collection(2, [
	"Hello",
	"World"
]);

var_dump($array->flip());
?>
--EXPECT--
object(Collection)#2 (2) {
  [0]=>
  string(5) "World"
  [1]=>
  string(5) "Hello"
}




