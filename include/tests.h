#ifndef LIBCFGPATH_TESTS_TEST_H_
#define LIBCFGPATH_TESTS_TEST_H_

#include "libcfgpath/common.h"

// C or C++ specific
#ifdef __cplusplus
#else
#endif

// Define the app name for tests
#define APP_NAME "test-app"
#if defined(LIBCFGPATH_OS_OSX) && !defined(LIBCFGPATH_USING_POSIX_IMPL_FOR_OSX)
#  define BUNDLE_IDENTIFIER "org.testing.test-app"
#else
#  define BUNDLE_IDENTIFIER APP_NAME
#endif

// Chhose platform config file. This should not be done if you use the file it returns
#if defined(LIBCFGPATH_OS_LINUX) || defined(LIBCFGPATH_USING_POSIX_IMPL_FOR_OSX)
#  define GET_PLATFORM_CONFIG_FILE getPosixConfigFile
#elif defined(LIBCFGPATH_OS_WINDOWS)
#  define GET_PLATFORM_CONFIG_FILE getWindowsConfigFile
#elif defined(LIBCFGPATH_OS_OSX) && !defined(LIBCFGPATH_USING_POSIX_IMPL_FOR_OSX)
#  define GET_PLATFORM_CONFIG_FILE getOsxConfigFile
#endif

#define STR_OR_ERROR(string) strlen(string) ? string : "ERROR"

LIBCFGPATH_C_LINKAGE()

// C tests
int testCommon(void);

// C++ tests
int testCommonCpp(void);

LIBCFGPATH_C_LINKAGE_END()

static inline const char* getMessage(const PathInfo* info) {
    if (info->bufferTooSmall)
        return " does not fit";
    if (!info->found)
        return " could not be determined";
    if (info->mkdirReturnCode != 0)
        return " could not be created";
    return "";
}

#endif //LIBCFGPATH_TESTS_TEST_H_
