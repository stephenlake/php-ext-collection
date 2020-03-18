--TEST--
Collection gc
--SKIPIF--
<?php if (!extension_loaded("collection")) print "skip"; ?>
--FILE--
<?php 
$array = new Collection(3);

$array[0] = "Hello";
$array[1] = "World";
$array[2] = $array;

var_dump($array);
?>
--EXPECT--
object(Collection)#1 (3) {
  [0]=>
  string(5) "Hello"
  [1]=>
  string(5) "World"
  [2]=>
  *RECURSION*
}


