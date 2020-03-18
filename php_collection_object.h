/*
 +----------------------------------------------------------------------+
 | Collection                                                           |
 +----------------------------------------------------------------------+
 | This source file is subject to version 3.01 of the PHP license,      |
 | that is bundled with this package in the file LICENSE, and is        |
 | available through the world-wide-web at the following url:           |
 | http://www.php.net/license/3_01.txt                                  |
 | If you did not receive a copy of the PHP license and are unable to   |
 | obtain it through the world-wide-web, please send a note to          |
 | license@php.net so we can mail you a copy immediately.               |
 +----------------------------------------------------------------------+
 | Author: Stephen Lake                                                 |
 +----------------------------------------------------------------------+
 */

/* $Id$ */
#ifndef HAVE_COLLECTION_OBJECT_H
#define HAVE_COLLECTION_OBJECT_H
/* {{{ */
typedef struct _php_collection_t {
								zval        *data;
								zend_long size;
								zend_object std;
} php_collection_t;

#define PHP_COLLECTION_FETCH_FROM(o) ((php_collection_t*) (((char*)o) - XtOffsetOf(php_collection_t, std)))
#define PHP_COLLECTION_FETCH(z)  PHP_COLLECTION_FETCH_FROM(Z_OBJ_P(z)) /* }}} */

/* {{{ */
zend_class_entry *Collection_ce; /* }}} */

/* {{{ */
void php_collection_init(void); /*}}} */

/* {{{ */
void php_collection_construct(zval *collection, zend_long size, HashTable *data);
zend_long php_collection_count(zval *collection);
void php_collection_set(zval *collection, zend_long index, zval *value);
void php_collection_get(zval *collection, zend_long index, zval *value);
void php_collection_unset(zval *collection, zend_long index);
void php_collection_exists(zval *collection, zend_long index, zval *return_value);
void php_collection_resize(zval *collection, zend_long resize);
void php_collection_flip(zval *collection, zval *retval); /* }}} */
#endif
