#include "tests.h"

int main() {
    int testResult = 0x0;
    testResult |= testMacos();
    testResult |= testMacosCpp();
    return testResult;
}
