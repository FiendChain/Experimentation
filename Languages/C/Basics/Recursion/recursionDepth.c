// Testing recursion depth
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECURSION 10

void recursion(int n) {
    for(int i = 0; i < n; i++) {
        printf("-=>");
    }
    printf("[%d]\n", n);
    if(n >= MAX_RECURSION || n < 0) {
        return;
    } else {
        recursion(n+1);  
        recursion(n-1);
    }
}

int main(int argc, char **argv) {
    recursion(0);
    return 1;
} 