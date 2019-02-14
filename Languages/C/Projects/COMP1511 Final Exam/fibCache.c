#include <stdio.h>
#define MAX_CACHE 1000
#define big_t unsigned long long

int currentFibCache = 0;
big_t fibCache[] = {0};

big_t fib(int n);

int main(void) {
    for(int i = 0; i < 200; i ++) {
        printf("%d: %llu\n", i, fib(i));
    }

    return 0;
}

big_t fib(int n) {
    if(n == 1 || n == 2) {
        return 1;
    }

    if(n <= currentFibCache) {
        return fibCache[n];
    }
    
    
    big_t fibTemp = fib(n-1) + fib(n-2);
    fibCache[n] = fibTemp;
    if(currentFibCache < n) {
        currentFibCache = n;
    }
    return fibTemp;
}