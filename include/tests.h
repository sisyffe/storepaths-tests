#include "libcfgpath/common.h"

#define APPNAME "myapp"

// C tests
LIBCFGPATH_CPP_CHECK()

int testMacos(void);

LIBCFGPATH_CPP_CHECK_END()

// C++ tests
#ifdef __cplusplus

int testMacosCpp(void);

#endif
