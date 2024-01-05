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
 * 1 - Refractor toString windows function
 */
