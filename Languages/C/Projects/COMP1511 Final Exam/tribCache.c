#include <stdio.h>
#define MAX_CACHE 1000
#define big_t unsigned long long

int currentTribCache = 0;
big_t tribCache[] = {0};

big_t trib(int n);

int main(void) {
    for(int i = 0; i < 200; i ++) {
        printf("%d: %llu\n", i, trib(i));
    }

    return 0;
}

big_t trib(int n) {
    if(n >= 1 && n <= 3) {
        return 1;
    }

    if(n <= currentTribCache) {
        return tribCache[n];
    }
    
    
    big_t tribTemp = trib(n-1) + trib(n-2) + trib(n-3);
    tribCache[n] = tribTemp;
    if(currentTribCache < n) {
        currentTribCache = n;
    }
    return tribTemp;
}