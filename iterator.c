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

/* {{{ */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_collection_object.h"

/* {{{ */
typedef struct _php_collection_iterator_t {
								zend_object_iterator it;
								zval collection;
								zend_long pos;
} php_collection_iterator_t; /* }}} */

/* {{{ */
static php_collection_iterator_dtor(php_collection_iterator_t *pi) {
								zval_ptr_dtor(&pi->collection);
}

static int php_collection_iterator_validate(php_collection_iterator_t *pi) {
								php_collection_t *pl = PHP_COLLECTION_FETCH_FROM(Z_OBJ(pi->collection));

								return (pi->pos < pl->size) ? SUCCESS : FAILURE;
}

static zval* php_collection_iterator_current_data(php_collection_iterator_t *pi) {
								php_collection_t *pl = PHP_COLLECTION_FETCH_FROM(Z_OBJ(pi->collection));

								return &pl->data[pi->pos];
}

static void php_collection_iterator_current_key(php_collection_iterator_t *pi, zval *key) {
								ZVAL_LONG(key, pi->pos);
}

static void php_collection_iterator_move_forward(php_collection_iterator_t *pi) {
								pi->pos++;
}

static zend_object_iterator_funcs php_collection_iterator_funcs = {
								(void (*)(zend_object_iterator *))php_collection_iterator_dtor,
								(int (*)(zend_object_iterator *))php_collection_iterator_validate,
								(zval* (*)(zend_object_iterator *))php_collection_iterator_current_data,
								(void (*)(zend_object_iterator *, zval *))php_collection_iterator_current_key,
								(void (*)(zend_object_iterator *))php_collection_iterator_move_forward
}; /* }}} */

/* {{{ */
zend_object_iterator* php_collection_iterator(zend_class_entry *ce, zval *collection, int by_ref) {
								php_collection_iterator_t *pi = (php_collection_iterator_t*) emalloc(sizeof(php_collection_iterator_t));

								zend_iterator_init((zend_object_iterator*) pi);

								pi->pos = 0;
								pi->it.funcs = &php_collection_iterator_funcs;

								ZVAL_COPY(&pi->collection, collection);

								return (zend_object_iterator*) pi;
} /* }}} */
