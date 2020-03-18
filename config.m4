PHP_ARG_ENABLE(collection, whether to enable collection support,
[  --enable-collection           Enable collection support])

if test "$PHP_COLLECTION" != "no"; then
  PHP_NEW_EXTENSION(collection, collection.c object.c iterator.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
