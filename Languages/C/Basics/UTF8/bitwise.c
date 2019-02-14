// Testing bitwise operators
#include <stdio.h>
#include <stdlib.h>

void printBits(unsigned int num) {
    unsigned int bitmask = 1u << 7;
    for(int i = 0; i < 8; i++) {
        if((num & bitmask) == bitmask) printf("1");
        else printf("0");
        bitmask >>= 1;
    }
    printf("\n");
}

int main(void) {
    // Create a set of bits and start shifting
    unsigned int num = 1u << 4; // 00010000 (shifted 4 bits left)
    printf("Original bits:  "); printBits(num);
    printf("Shifted left:   "); printBits(num << 1);    // Left shift
    printf("Shifted right:  "); printBits(num >> 1);    // Right shift
    printf("Inverse bits:   "); printBits(~num);        // Inverse
    // Testing OR. AND and XOR bitwise operators
    unsigned int a = 1000, b = 2000;
    printf("Bits a: "); printBits(a);
    printf("Bits b: "); printBits(b);
    printf("a | b : "); printBits(a | b);   // OR
    printf("a & b : "); printBits(a & b);   // AND  
    printf("a ^ b : "); printBits(a ^ b);   // XOR

    return 0;
}
