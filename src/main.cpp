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
 * 1 - implement windows
 * 2 - custom string stream
 * 3 - cpp namespace & refractor enum functions
 */
