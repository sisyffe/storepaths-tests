#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tests.h"

#include "libcfgpath/cfgpath.h"

LIBCFGPATH_C_LINKAGE()

int testCommon(void) {
    puts("Running test-common");

    char* configFolder = malloc(MAX_PATH_LENGTH * sizeof(char));
    char* dataFolder = malloc(MAX_PATH_LENGTH * sizeof(char));
    char* cacheFolder = malloc(MAX_PATH_LENGTH * sizeof(char));
    char* configFile = malloc(MAX_PATH_LENGTH * sizeof(char));
    char* tooSmall = malloc(10 * sizeof(char));

    getConfigFolder(configFolder, MAX_PATH_LENGTH, APPNAME);
    getFolder(DATA_FOLDER, dataFolder, MAX_PATH_LENGTH, APPNAME);
    getCacheFolder(cacheFolder, MAX_PATH_LENGTH, APPNAME);
    getFile(CONFIG_FILE, configFile, MAX_PATH_LENGTH, APPNAME);
    getConfigFolder(tooSmall, 10, APPNAME);

    printf("Config folder:    %s\n", strlen(configFolder) ? configFolder : "ERROR");
    printf("Data folder:      %s\n", strlen(dataFolder) ? dataFolder : "ERROR");
    printf("Cache folder:     %s\n", strlen(cacheFolder) ? cacheFolder : "ERROR");
    printf("Config file:      %s\n", strlen(configFile) ? configFile : "ERROR");
    printf("Should be error:  %s\n", strlen(tooSmall) ? tooSmall : "ERROR");

    free(configFolder);
    free(dataFolder);
    free(cacheFolder);
    free(configFile);
    free(tooSmall);

    puts("Done test-common");
    return EXIT_SUCCESS;
}

LIBCFGPATH_C_LINKAGE_END()
