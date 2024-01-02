#include <iostream>
#include <iomanip>

#include "tests.h"

#include "libcfgpath/cfgpath.h"

LIBCFGPATH_C_LINKAGE()

int testMacosCpp() {
    std::cout << "Running test-macos-cpp" << std::endl;
    
    auto configFolder = getConfigFolder(APPNAME);
    auto dataFolder = getFolder(DATA_FOLDER, APPNAME);
    auto cacheFolder = getCacheFolder(APPNAME);
    auto configFile = getFile(CONFIG_FILE, APPNAME);

    std::cout << "Config folder: " << std::quoted(configFolder) << std::endl;
    std::cout << "Data folder: "   << std::quoted(dataFolder) << std::endl;
    std::cout << "Cache folder: "  << std::quoted(cacheFolder) << std::endl;
    std::cout << "Config file: "   << std::quoted(configFile) << std::endl;

    std::cout << "Done test-macos-cpp" << std::endl;

    return EXIT_SUCCESS;
}

LIBCFGPATH_C_LINKAGE_END()
