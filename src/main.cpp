#include <iostream>

#include "tests.h"

int main() {
    int testResult = 0x0;
    testResult |= testCommon();
    std::cout << std::endl;
    testResult |= testCommonCpp();
    return testResult;
}
