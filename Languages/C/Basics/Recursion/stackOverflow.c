// Simulating a stackoverflow
#include <stdio.h>
#include <stdlib.h>

void foo(void) {
    unsigned long long x;
    foo();
}

int main(void) {
    foo();

    return 0;
}