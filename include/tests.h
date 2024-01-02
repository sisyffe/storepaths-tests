#ifndef LIBCFGPATH_TESTS_TEST_H_
#define LIBCFGPATH_TESTS_TEST_H_

#include "libcfgpath/common.h"

#define APPNAME "myapp"

LIBCFGPATH_C_LINKAGE()

// C tests
int testMacos(void);

// C++ tests
int testMacosCpp(void);

LIBCFGPATH_C_LINKAGE_END()

#endif //LIBCFGPATH_TESTS_TEST_H_
