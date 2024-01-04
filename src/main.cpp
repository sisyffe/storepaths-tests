#include <iostream>

#include "tests.h"

int main() {
    int testResult = 0x0;
    testResult |= testCommon();
    std::cout << std::endl;
    testResult |= testCommonCpp();
    return testResult;
}

/*
 * TODOs:
 * 1 - Custom reservable string stream
 * 2 - Add C++ specific functions for conveneience by
 *     refractoring existing enum functions
 */
