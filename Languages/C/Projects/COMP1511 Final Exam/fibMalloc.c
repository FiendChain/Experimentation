// Using malloc to create an array of pointers to
// store all the fibonnaci numbers
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Toggle settings
#define PRINT_ALL_FIB   0
#define FREE_FIB_MEM    1

// Definition of big_t
#define PRINT_BIG_T     "%llu"
#define PRINT_ALL_BIG_T "%0*llu"
typedef unsigned long long big_t;

// Store a large number
typedef struct {
    big_t *number;
    int totalBlocks;
} bignum_t;

// Caching array
bignum_t **fibCache;
int cacheIndex = 0;

// Determining block size (done at main)
big_t maxSize;
int maxDigit;

// Function prototypes
bignum_t *addBigNum(bignum_t *x, bignum_t *y);
bignum_t *fibonnaci(int n);
bignum_t *createSeedFib(big_t n);
void printBigNum(bignum_t *n);

// Main function
int main(int argc, char *argv[]) {
    // Get using command line if possible
    int fibNum;
    if(argc == 1) {
        printf("Enter the desired fibonacci number: ");
        scanf("%d", &fibNum);
    } else {
        fibNum = atoi(argv[1]);
    }

    // Allocating memory to the array
    fibCache = (bignum_t **)malloc((fibNum + 3) * sizeof(bignum_t *));

    // Seed the fibonnaci sequence
    fibCache[0] = createSeedFib(0);
    fibCache[1] = createSeedFib(1);
    fibCache[2] = createSeedFib(1);
    cacheIndex = 2;

    // Determine max block size
    size_t totalBytes = sizeof(big_t);
    maxDigit = (int)((8*totalBytes)/3.32);
    maxSize = pow(10, maxDigit);

    int startTime = time(NULL);
    for(int i = 0; i <= fibNum; i ++) {
        // Get fibonnaci number
        fibonnaci(i);
        // Print it
        if(PRINT_ALL_FIB) {
            printf("[%d]:", i);
            printBigNum(fibonnaci(i));
        }
        // Free useless fibonnaci numbers
        if(FREE_FIB_MEM && i >= 5) {
            free(fibCache[i-5]->number);
            free(fibCache[i-5]);
            fibCache[i-5] = NULL;
        }
    }
    int endTime = time(NULL);
    int duration = endTime - startTime;
    printf("Took %d seconds to get %d fibonnaci numbers!\n", duration, fibNum);
    printf("[%d]:", fibNum);
    printBigNum(fibonnaci(fibNum));
    
    // Free all memory
    for(int i = 0; i <= fibNum; i ++) {
        if(fibCache[i] != NULL) {
            free(fibCache[i]->number);
            free(fibCache[i]);
        }
    }
    free(fibCache);

    return 0;
}

// Add two big numbers
bignum_t *addBigNum(bignum_t *x, bignum_t *y) {
    // Determine if block size needs to be increased
    // by looking at the last index
    int sumBlockTotal;
    int xBlockTotal = x->totalBlocks;
    int yBlockTotal = y->totalBlocks;
    // Case 1: Same size and overflow occurs at addition
    if((xBlockTotal == yBlockTotal) && (x->number[xBlockTotal] + y->number[yBlockTotal] >= maxSize)) {
            sumBlockTotal = xBlockTotal + 1;
    // Case 2: x >= y
    } else if(xBlockTotal >= yBlockTotal) {
        sumBlockTotal = xBlockTotal;
    // Case 3: x < y
    } else {
        sumBlockTotal = yBlockTotal;
    }

    // Creating the number now
    bignum_t *sum = malloc(sizeof(bignum_t));
    assert(sum != NULL);
    sum->number = malloc((sumBlockTotal+1) * sizeof(big_t));
    assert(sum->number != NULL);
    sum->totalBlocks = sumBlockTotal;
    big_t carry = 0;
    for(int i = 0; i <= sumBlockTotal; i ++) {
        // Get value of the current index
        big_t xValue = 0;
        big_t yValue = 0;
        if(i <= xBlockTotal) xValue = x->number[i];
        if(i <= yBlockTotal) yValue = y->number[i];
        // Get index value for the sum
        big_t indexValue = xValue + yValue + carry;
        // Reset carry
        carry = 0;
        // Increase carry until indexValue falls within range
        while(indexValue >= maxSize) {
            indexValue -= maxSize;
            carry ++;
        }
        // Equate this to block in sum
        sum->number[i] = indexValue;
    }

    // Check if there was enough blockspace
    if(carry != 0) {
        printf("Not enough block space!\n");
        exit(1);
    }

    return sum;
}

// Recursive fibonnaci function
bignum_t *fibonnaci(int n) {
    // Check if cache already has number
    if(n <= cacheIndex) return fibCache[n];
    // Otherwise create number and add to cache
    bignum_t *sum = addBigNum(fibonnaci(n-1), fibonnaci(n-2));
    fibCache[n] = sum;
    if(n > cacheIndex) cacheIndex = n;
    return sum;
}

// Create bignum_t within big_t
bignum_t *createSeedFib(big_t n) {
    bignum_t *seed = malloc(sizeof(bignum_t));
    seed->totalBlocks = 0;
    seed->number = malloc(sizeof(big_t));
    seed->number[0] = n;

    return seed;
}

// Print a bignum_t
void printBigNum(bignum_t *n) {
    // Print first block
    printf(PRINT_BIG_T, n->number[n->totalBlocks]);
    // Print other blocks
    for(int i = n->totalBlocks-1; i >= 0; i --) {
        printf(PRINT_ALL_BIG_T, maxDigit, n->number[i]);
    }
    printf("\n");
}
