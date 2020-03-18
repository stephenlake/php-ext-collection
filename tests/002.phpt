--TEST--
Collection resize
--SKIPIF--
<?php if (!extension_loaded("collection")) print "skip"; ?>
--FILE--
<?php 
$array = new Collection(2);

$array[0] = "Hello";
$array[1] = "World";

var_dump($array);

$array->resize(1);

var_dump($array);
?>
--EXPECT--
object(Collection)#1 (2) {
  [0]=>
  string(5) "Hello"
  [1]=>
  string(5) "World"
}
object(Collection)#1 (1) {
  [0]=>
  string(5) "Hello"
}

