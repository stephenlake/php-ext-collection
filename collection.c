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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"

#include "php_collection.h"
#include "php_collection_object.h"

/* {{{ */
ZEND_BEGIN_ARG_INFO_EX(Collection_construct_arginfo, 0, 0, 1)
ZEND_ARG_TYPE_INFO(0, size, IS_LONG, 0)
ZEND_ARG_TYPE_INFO(0, data, IS_ARRAY, 1)
ZEND_END_ARG_INFO()

PHP_METHOD(Collection, __construct)
{
								zend_long size;
								HashTable *data = NULL;

								if (zend_parse_parameters(ZEND_NUM_ARGS(), "l|H", &size, &data) != SUCCESS) {
																return;
								}

								php_collection_construct(getThis(), size, data);
}
/* }}} */

/* {{{ */
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(Collection_count_arginfo, 0, 0, IS_LONG, 1)
ZEND_END_ARG_INFO()

PHP_METHOD(Collection, count)
{

								if (zend_parse_parameters_none() != SUCCESS) {
																return;
								}

								RETURN_LONG(php_collection_count(getThis()));
} /* }}} */

/* {{{ */
ZEND_BEGIN_ARG_INFO_EX(Collection_set_arginfo, 0, 0, 2)
ZEND_ARG_INFO(0, index)
ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

PHP_METHOD(Collection, offsetSet)
{
								zend_long index;
								zval *value;

								if (zend_parse_parameters(ZEND_NUM_ARGS(), "lz", &index, &value) != SUCCESS) {
																return;
								}

								php_collection_set(getThis(), index, value);
} /* }}} */

/* {{{ */
ZEND_BEGIN_ARG_INFO_EX(Collection_get_arginfo, 0, 0, 1)
ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

PHP_METHOD(Collection, offsetGet)
{
								zend_long index;

								if (zend_parse_parameters(ZEND_NUM_ARGS(), "l", &index) != SUCCESS) {
																return;
								}

								php_collection_get(getThis(), index, return_value);
} /* }}} */

/* {{{ */
ZEND_BEGIN_ARG_INFO_EX(Collection_unset_arginfo, 0, 0, 1)
ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

PHP_METHOD(Collection, offsetUnset)
{
								zend_long index;

								if (zend_parse_parameters(ZEND_NUM_ARGS(), "l", &index) != SUCCESS) {
																return;
								}

								php_collection_unset(getThis(), index);
} /* }}} */

/* {{{ */
ZEND_BEGIN_ARG_INFO_EX(Collection_exists_arginfo, 0, 0, 1)
ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

PHP_METHOD(Collection, offsetExists)
{
								zend_long index;

								if (zend_parse_parameters(ZEND_NUM_ARGS(), "l", &index) != SUCCESS) {
																return;
								}

								php_collection_exists(getThis(), index, return_value);
} /* }}} */

/* {{{ */
ZEND_BEGIN_ARG_INFO_EX(Collection_resize_arginfo, 0, 0, 1)
ZEND_ARG_TYPE_INFO(0, size, IS_LONG, 0)
ZEND_END_ARG_INFO()

PHP_METHOD(Collection, resize)
{
								zend_long resize;

								if (zend_parse_parameters(ZEND_NUM_ARGS(), "l", &resize) != SUCCESS) {
																return;
								}

								php_collection_resize(getThis(), resize);
} /* }}} */

/* {{{ */
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(Collection_flip_arginfo, 0, 0, IS_OBJECT, 1)
ZEND_END_ARG_INFO()

PHP_METHOD(Collection, flip)
{
								if (zend_parse_parameters_none() != SUCCESS) {
																return;
								}

								php_collection_flip(getThis(), return_value);
}
/* }}} */

/* {{{ */
zend_function_entry Collection_methods[] = {
								PHP_ME(Collection, __construct,  Collection_construct_arginfo, ZEND_ACC_PUBLIC)
								PHP_ME(Collection, count,        Collection_count_arginfo,     ZEND_ACC_PUBLIC)
								PHP_ME(Collection, offsetSet,    Collection_set_arginfo,  ZEND_ACC_PUBLIC)
								PHP_ME(Collection, offsetGet,    Collection_get_arginfo,  ZEND_ACC_PUBLIC)
								PHP_ME(Collection, offsetUnset,  Collection_unset_arginfo,     ZEND_ACC_PUBLIC)
								PHP_ME(Collection, offsetExists, Collection_exists_arginfo,    ZEND_ACC_PUBLIC)
								PHP_ME(Collection, resize,       Collection_resize_arginfo,    ZEND_ACC_PUBLIC)
								PHP_ME(Collection, flip,       Collection_flip_arginfo,      ZEND_ACC_PUBLIC)
								PHP_FE_END
}; /* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(collection)
{
								php_collection_init();

								return SUCCESS;
}
/* }}} */

/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(collection)
{
#if defined(COMPILE_DL_COLLECTION) && defined(ZTS)
								ZEND_TSRMLS_CACHE_UPDATE();
#endif
								return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(collection)
{
								php_info_print_table_start();
								php_info_print_table_header(2, "collection support", "enabled");
								php_info_print_table_end();
}
/* }}} */

/* {{{ collection_module_entry
 */
zend_module_entry collection_module_entry = {
								STANDARD_MODULE_HEADER,
								PHP_COLLECTION_EXTNAME,
								NULL,
								PHP_MINIT(collection),
								NULL,
								PHP_RINIT(collection),
								NULL,
								PHP_MINFO(collection),
								PHP_COLLECTION_VERSION,
								STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_COLLECTION
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE();
#endif
ZEND_GET_MODULE(collection)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
