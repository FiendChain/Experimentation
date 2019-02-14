#include <stdio.h>

int add_int(int a, int b) 
{
    // can modify dll without recompiling main.exe
    printf("Added something to the dll without recompiling main program!\n");
    return a + b;
}

int sub_int(int a, int b)
{
    return a - b;
}

int mult_int(int a, int b)
{
    return a * b;
}