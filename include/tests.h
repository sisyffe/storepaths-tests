#ifndef LIBCFGPATH_TESTS_TEST_H_
#define LIBCFGPATH_TESTS_TEST_H_

#include "libcfgpath/common.h"

#define APPNAME "test-app"

LIBCFGPATH_C_LINKAGE()

// C tests
int testCommon(void);

// C++ tests
int testCommonCpp(void);

LIBCFGPATH_C_LINKAGE_END()

#endif //LIBCFGPATH_TESTS_TEST_H_
