--TEST--
Collection basic operation
--SKIPIF--
<?php if (!extension_loaded("collection")) print "skip"; ?>
--FILE--
<?php
$array = new Collection(2);

$array[0] = "Hello";
$array[1] = "World";

var_dump($array, 
	isset($array[0]), 
	isset($array[1]));

unset($array[1]);

var_dump($array, 
	isset($array[0]), 
	isset($array[1]));

var_dump($array[-2]);

try {
	var_dump($array[-3]);
} catch(Exception $ex) { 
	echo $ex->getMessage(); 
}
?>
--EXPECT--
object(Collection)#1 (2) {
  [0]=>
  string(5) "Hello"
  [1]=>
  string(5) "World"
}
bool(true)
bool(true)
object(Collection)#1 (1) {
  [0]=>
  string(5) "Hello"
}
bool(true)
bool(false)
string(5) "Hello"
index -3 (-1) is OOB

