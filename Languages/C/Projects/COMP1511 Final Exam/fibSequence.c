// Computing the fibonacci sequence to extremely large numbers
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define big_t unsigned long long
#define TOTAL_BLOCKS 1000

void printArray(big_t array[TOTAL_BLOCKS]);
void copyArray(big_t destination[TOTAL_BLOCKS], big_t source[TOTAL_BLOCKS]);

int main(void) {
    big_t x[TOTAL_BLOCKS];
    big_t y[TOTAL_BLOCKS];
    big_t z[TOTAL_BLOCKS];
    big_t temp[TOTAL_BLOCKS];
    for(int i = 0; i < TOTAL_BLOCKS; i ++) {
        x[i] = 0;
        y[i] = 0;
        z[i] = 0;
        temp[i] = 0;
    }

    // [2^(8*totalBytes)]/4 = 10^maxpower
    // 2^3.32 = 10
    // 2^(8*totalBytes) = 4*[2^(3.32*maxPower)]
    // 2^(8*totalBytes) = 2^2 * 2^(3.32*maxPower)
    // 8*totalBytes = 2 + 3.32*maxPower
    // maxPower = (8*totalBytes - 2)/3.32
    int totalBytes = sizeof(big_t);
    int maxPower = (8*totalBytes - 2) / 3.32;
    big_t maxBlock = pow(10, maxPower);

    x[0] = 1;
    y[0] = 1;
    z[0] = 1;

    int totalRecursion;
    printf("Enter total recursions: ");
    scanf("%d", &totalRecursion);

    for(int current = 3; current < totalRecursion; current ++) {
        copyArray(temp, z);
        int carry = 0;
        for(int i = 0; i < TOTAL_BLOCKS; i ++) {
            big_t index = z[i] + y[i] + x[i] + carry;
            carry = 0;
            while(index > maxBlock) {
                index -= maxBlock;
                carry ++;
            }
            z[i] = index;
        }
        copyArray(x, y);
        copyArray(y, temp);
    }

    printArray(z);

    return 0;
}

void copyArray(big_t destination[TOTAL_BLOCKS], big_t source[TOTAL_BLOCKS]) {
    for(int i = 0; i < TOTAL_BLOCKS; i ++) {
        destination[i] = source[i];
    }
}

void printArray(big_t array[TOTAL_BLOCKS]) {
    int printFlag = 0;
    for(int i = TOTAL_BLOCKS - 1; i >= 0; i --) {
        if(printFlag == 0 && array[i] != 0) {
            printFlag = 1;
        }
        if(printFlag == 1) {
            printf("%llu", array[i]);
        }
    }
    printf("\n");
}