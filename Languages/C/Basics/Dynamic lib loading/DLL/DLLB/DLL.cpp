#define DLL_EXPORT
#include "DLL.h"
#include <iostream>

void DLL::helloWorld(void) 
{
    std::cout << "Hello world" << std::endl;
    std::cout << "Factorial(10): " << factorial(10) << std::endl;
}

int DLL::multiply(int x, int y) 
{
    return - (x * y);
}

int DLL::factorial(int n) 
{
    // P = n(n-1)(n-2)(n-3)(n-4)...
    int value = 1;
    for (int i = 1; i <= n; i++)
        value *= i;
    return value;
}
