#include <iostream>
#include <iomanip>
#include <cstring>

#include "storepaths/storepaths.h"

#include "tests.h"

STOREPATHS_C_LINKAGE

int testCommonCpp() {
    std::cout << "Running test-common-cpp" << std::endl;
    
    auto [configFolder, configFolderInfo] = storepaths::getConfigFolder(APP_NAME);
    auto [dataFolder, dataFolderInfo] = storepaths::getFolder(storepaths::DATA_FOLDER, APP_NAME);
    auto [cacheFolder, cacheFolderInfo] = storepaths::getCacheFolder(APP_NAME);
    auto [commonConfigFileDefault, commonConfigFileDefaultInfo] =
        storepaths::getFile(storepaths::COMMON_CONFIG_FILE, APP_NAME);
    auto [commonConfigFileYML, commonConfigFileYMLInfo] =
        storepaths::getFile(storepaths::COMMON_CONFIG_FILE, APP_NAME, "config", "yml");
    auto [configFile, configFileInfo] = storepaths::GET_PLATFORM_CONFIG_FILE(BUNDLE_IDENTIFIER);
#ifdef STOREPATHS_OS_OSX
    auto [posixCommonConfigFile, posixCommonConfigFileInfo] =
        storepaths::posix::getCommonConfigFile(APP_NAME, std::nullopt, "xml");
#endif

    std::cout << "Config folder" << getMessage(&configFolderInfo) << ": "
        << std::quoted(STR_OR_ERROR(configFolder.c_str())) << std::endl;
    std::cout << "Data folder" << getMessage(&dataFolderInfo) << ": "
        << std::quoted(STR_OR_ERROR(dataFolder.c_str())) << std::endl;
    std::cout << "Cache folder" << getMessage(&cacheFolderInfo) << ": "
        << std::quoted(STR_OR_ERROR(cacheFolder.c_str())) << std::endl;
    std::cout << "Common config file (Default)" << getMessage(&commonConfigFileDefaultInfo) << ": "
        << std::quoted(STR_OR_ERROR(commonConfigFileDefault.c_str())) << std::endl;
    std::cout << "Common config file (JSON)" << getMessage(&commonConfigFileYMLInfo) << ": "
        << std::quoted(STR_OR_ERROR(commonConfigFileYML.c_str())) << std::endl;
    std::cout << "Config file" << getMessage(&configFileInfo) << ": "
        << std::quoted(STR_OR_ERROR(configFile.c_str())) << std::endl;
#ifdef STOREPATHS_OS_OSX
    std::cout << "Posix common config file (XML)" << getMessage(&posixCommonConfigFileInfo) << ": "
        << std::quoted(STR_OR_ERROR(posixCommonConfigFile.c_str())) << std::endl;
#endif

    std::cout << "Done test-common-cpp" << std::endl;

    return EXIT_SUCCESS;
}

STOREPATHS_C_LINKAGE_END
