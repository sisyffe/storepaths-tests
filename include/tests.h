#ifndef STOREPATHS_TESTS_TEST_H_
#define STOREPATHS_TESTS_TEST_H_

#include <storepaths/common.h>

// Define the app name for tests
#define APP_NAME "test-app"
#if defined(STOREPATHS_OS_OSX) && !defined(STOREPATHS_USING_POSIX_IMPL_FOR_OSX)
#  define BUNDLE_IDENTIFIER "org.testing.test-app"
#else
#  define BUNDLE_IDENTIFIER APP_NAME
#endif

// Chhose platform config file. This should not be done if you use the file it returns
#if defined(STOREPATHS_OS_LINUX) || defined(STOREPATHS_USING_POSIX_IMPL_FOR_OSX)
#  define GET_PLATFORM_CONFIG_FILE getPosixConfigFile
#elif defined(STOREPATHS_OS_WINDOWS)
#  define GET_PLATFORM_CONFIG_FILE getWindowsConfigFile
#elif defined(STOREPATHS_OS_OSX) && !defined(STOREPATHS_USING_POSIX_IMPL_FOR_OSX)
#  define GET_PLATFORM_CONFIG_FILE getOsxConfigFile
#endif

#define STR_OR_ERROR(string) strlen(string) ? string : "ERROR"

STOREPATHS_C_LINKAGE

// C tests
int testCommon(void);

// C++ tests
int testCommonCpp(void);

STOREPATHS_C_LINKAGE_END

#ifndef __cplusplus
#  define PATHINFO PathInfo
#else
#  define PATHINFO storepaths::PathInfo
#endif

static inline const char* getMessage(const PATHINFO* info) {
    if (info->bufferTooSmall)
        return " does not fit";
    if (!info->found)
        return " could not be determined";
    if (info->mkdirReturnCode != 0)
        return " could not be created";
    return "";
}

#endif //STOREPATHS_TESTS_TEST_H_
