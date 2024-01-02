#include <iostream>

#include "tests.h"

int main() {
    int testResult = 0x0;
    testResult |= testMacos();
    std::cout << std::endl;
    testResult |= testMacosCpp();
    return testResult;
}

/*
 * TODOs:
 * 1 - To do: make mkdir_parent
 * 2 - To do implement mkdir_parent in data, config and cache folders
 */
