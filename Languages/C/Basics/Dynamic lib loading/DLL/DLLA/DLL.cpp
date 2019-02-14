#define DLL_EXPORT
#include "DLL.h"
#include <iostream>

void DLL::helloWorld(void) {
    std::cout << "Hello world" << std::endl;
}

int DLL::multiply(int x, int y) {
    return x * y;
}
