--TEST--
Collection initial data
--SKIPIF--
<?php if (!extension_loaded("collection")) print "skip"; ?>
--FILE--
<?php 
$array = new Collection(3, [
	"Hello",
	"World"
]);

$array[2] = ["Hello", "World"];

var_dump($array);
?>
--EXPECT--
object(Collection)#1 (3) {
  [0]=>
  string(5) "Hello"
  [1]=>
  string(5) "World"
  [2]=>
  array(2) {
    [0]=>
    string(5) "Hello"
    [1]=>
    string(5) "World"
  }
}


