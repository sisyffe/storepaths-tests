#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "libcfgpath/cfgpath.h"

#include "tests.h"

#ifdef __cplusplus
#  error Cannot compile this test with with a C++ compiler
#endif

int testCommon(void) {
    puts("Running test-common");

    char* configFolder = malloc(MAX_PATH_LENGTH * sizeof(char));
    char* dataFolder = malloc(MAX_PATH_LENGTH * sizeof(char));
    char* cacheFolder = malloc(MAX_PATH_LENGTH * sizeof(char));
    char* jsonConfigFile = malloc(MAX_PATH_LENGTH * sizeof(char));
    char* configFile = malloc(MAX_PATH_LENGTH * sizeof(char));
    char* tooSmall = malloc(10 * sizeof(char));

    const PathInfo configFolderInfo = getConfigFolder(configFolder, MAX_PATH_LENGTH, APP_NAME);
    const PathInfo dataFolderInfo = getDataFolder(dataFolder, MAX_PATH_LENGTH, APP_NAME);
    const PathInfo cacheFolderInfo = getCacheFolder(cacheFolder, MAX_PATH_LENGTH, APP_NAME);
    const PathInfo jsonConfigFileInfo = getJSONConfigFile(jsonConfigFile, MAX_PATH_LENGTH,
        APP_NAME, "config");
    const PathInfo configFileInfo = GET_PLATFORM_CONFIG_FILE(configFile, MAX_PATH_LENGTH,
        BUNDLE_IDENTIFIER, NULL);
    const PathInfo tooSmallInfo = getConfigFolder(tooSmall, 10, APP_NAME);

    printf("Config folder%s: %s\n", getMessage(&configFolderInfo), STR_OR_ERROR(configFolder));
    printf("Data folder%s: %s\n", getMessage(&dataFolderInfo), STR_OR_ERROR(dataFolder));
    printf("Cache folder%s: %s\n", getMessage(&cacheFolderInfo), STR_OR_ERROR(cacheFolder));
    printf("JSON config file%s: %s\n", getMessage(&jsonConfigFileInfo), STR_OR_ERROR(jsonConfigFile));
    printf("Config file%s: %s\n", getMessage(&configFileInfo), STR_OR_ERROR(configFile));
    printf("Should be error%s: %s\n", getMessage(&tooSmallInfo), STR_OR_ERROR(tooSmall));

    free(configFolder);
    free(dataFolder);
    free(cacheFolder);
    free(configFile);
    free(tooSmall);

    puts("Done test-common");
    return EXIT_SUCCESS;
}
