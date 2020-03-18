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

#ifndef PHP_COLLECTION_H
#define PHP_COLLECTION_H

extern zend_module_entry collection_module_entry;
#define phpext_collection_ptr &collection_module_entry

#define PHP_COLLECTION_VERSION "0.0.1"
#define PHP_COLLECTION_EXTNAME "collection"

#ifdef ZTS
#include "TSRM.h"
#endif

#if defined(ZTS) && defined(COMPILE_DL_COLLECTION)
ZEND_TSRMLS_CACHE_EXTERN();
#endif

#endif  /* PHP_COLLECTION_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
