#include <iostream>
#include <iomanip>

#include "tests.h"

#include "libcfgpath/cfgpath.h"

LIBCFGPATH_C_LINKAGE()

int testCommonCpp() {
    std::cout << "Running test-common-cpp" << std::endl;
    
    auto [configFolder, configFolderOk] = libcfgpath::getConfigFolder(APPNAME);
    auto [dataFolder, dataFolderOk] = libcfgpath::getFolder(DATA_FOLDER, APPNAME);
    auto [cacheFolder, cacheFolderOk] = libcfgpath::getCacheFolder(APPNAME);
    auto configFile = libcfgpath::getFile(CONFIG_FILE, APPNAME);

    std::cout << "Config folder" << (configFolderOk ? "" : " failed to be created") << ": "
        << std::quoted(configFolder) << std::endl;
    std::cout << "Data folder" << (dataFolderOk ? "" : " failed to be created") << ": "
        << std::quoted(dataFolder) << std::endl;
    std::cout << "Cache folder" << (cacheFolderOk ? "" : " failed to be created") << ": "
        << std::quoted(cacheFolder) << std::endl;
    std::cout << "Config file: " << std::quoted(configFile) << std::endl;

    std::cout << "Done test-common-cpp" << std::endl;

    return EXIT_SUCCESS;
}

LIBCFGPATH_C_LINKAGE_END()
