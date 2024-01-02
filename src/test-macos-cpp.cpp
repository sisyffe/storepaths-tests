#include <iostream>

#include "tests.h"

extern "C" {
    int testMacosCpp() {
        std::cout << "Running test-macos-cpp" << std::endl;
        return EXIT_SUCCESS;
    }
}

