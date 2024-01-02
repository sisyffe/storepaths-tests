#include <iostream>

#include "tests.h"

int main() {
    int testResult = 0x0;
    testResult |= testMacos();
    std::cout << std::endl;
    testResult |= testMacosCpp();
    return testResult;
}
