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
 * 1 - Add state and runtime dirs (https://specifications.freedesktop.org/basedir-spec/basedir-spec-latest.html)
 * 2 - Move osx files:
 *         Move cache folder to Library/Caches
 *         Move config file to Library/Preferences
 */
