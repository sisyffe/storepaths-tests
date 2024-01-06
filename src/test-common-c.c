#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tests.h"

#include "libcfgpath/cfgpath.h"

#ifdef __cplusplus
#  error Cannot compile this test with with a C++ compiler
#endif

static const char* succeeded = "";
static const char* failed = " failed";

static inline const char* getMessage(const bool didSucceeded) {
    return didSucceeded ? succeeded : failed;
}

int testCommon(void) {
    puts("Running test-common");

    char* configFolder = malloc(MAX_PATH_LENGTH * sizeof(char));
    char* dataFolder = malloc(MAX_PATH_LENGTH * sizeof(char));
    char* cacheFolder = malloc(MAX_PATH_LENGTH * sizeof(char));
    char* configFile = malloc(MAX_PATH_LENGTH * sizeof(char));
    char* tooSmall = malloc(10 * sizeof(char));

    const bool configFolderOk = getConfigFolder(configFolder, MAX_PATH_LENGTH, APPNAME);
    const bool dataFolderOk = getDataFolder(dataFolder, MAX_PATH_LENGTH, APPNAME);
    const bool cacheFolderOk = getCacheFolder(cacheFolder, MAX_PATH_LENGTH, APPNAME);
    getConfigFile(configFile, MAX_PATH_LENGTH, APPNAME);
    const bool tooSmallOk = getConfigFolder(tooSmall, 10, APPNAME);

    printf("Config folder%s: %s\n", getMessage(configFolderOk), strlen(configFolder) ? configFolder : "ERROR");
    printf("Data folder%s: %s\n", getMessage(dataFolderOk), strlen(dataFolder) ? dataFolder : "ERROR");
    printf("Cache folder%s: %s\n", getMessage(cacheFolderOk), strlen(cacheFolder) ? cacheFolder : "ERROR");
    printf("Config file: %s\n", strlen(configFile) ? configFile : "ERROR");
    printf("Should be error%s: %s\n", getMessage(tooSmallOk), strlen(tooSmall) ? tooSmall : "ERROR");

    free(configFolder);
    free(dataFolder);
    free(cacheFolder);
    free(configFile);
    free(tooSmall);

    puts("Done test-common");
    return EXIT_SUCCESS;
}
