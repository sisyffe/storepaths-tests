#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tests.h"

#include "libcfgpath/cfgpath.h"

int testMacos(void) {
    puts("Running test-macos");

    char* configFolder = malloc(MAX_PATH_LENGTH * sizeof(char));
    char* dataFolder = malloc(MAX_PATH_LENGTH * sizeof(char));
    char* cacheFolder = malloc(MAX_PATH_LENGTH * sizeof(char));
    char* configFile = malloc(MAX_PATH_LENGTH * sizeof(char));
    char* tooSmall = malloc(10 * sizeof(char));

    getConfigFolder(configFolder, MAX_PATH_LENGTH, APPNAME);
    getDataFolder(dataFolder, MAX_PATH_LENGTH, APPNAME);
    getCacheFolder(cacheFolder, MAX_PATH_LENGTH, APPNAME);
    getConfigFile(configFile, MAX_PATH_LENGTH, APPNAME);
    getCacheFolder(tooSmall, 10, APPNAME);

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

    puts("Done test-macos");
    return EXIT_SUCCESS;
}
