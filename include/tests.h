#include "libcfgpath/common.h"

#define APPNAME "myapp"

// C tests
LIBCFGPATH_IF_CPP()

int testMacos(void);

LIBCFGPATH_IF_CPP_END()

// C++ tests
#ifdef __cplusplus

int testMacosCpp();

#endif
