// Demonstrating the structure of UTF8 characters
#include "colouredText.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY_BIT ((unsigned long)0)
#define FIRST_BIT ((unsigned long)1)
#define LAST_BIT  (FIRST_BIT << 31)

typedef unsigned char Byte;

void showBits(Byte *utf);
Byte *stringToBits(char *string);
Byte *hexToBits(unsigned long hexVal);
int findTotalBits(unsigned long value);
int findTotalSize(int bits);

int main(void) {
    // Creating utf out of bits
    Byte *c = stringToBits("101001010101101");
    showBits(c);
    printf("%s\n", c);
    free(c);
    // Creating utf using symbols
    Byte *chinese = "你好";
    showBits(chinese);
    printf("%s\n", chinese);
    // Creating utf using hex code
    Byte *hexUTF = hexToBits(0xA7);
    showBits(hexUTF);
    printf("%s\n", hexUTF);
    free(hexUTF);
    // Print out several chinese characters
    FILE *fp = fopen("utf.txt", "w+");
    for(int i = 0, hexCode = 0x0; hexCode <= 0xFFFFF; i++, hexCode++) {
        hexUTF = hexToBits(hexCode);
        fprintf(fp, "%s", hexUTF);
        if(hexCode % 100 == 0) fprintf(fp, "\n");
        free(hexUTF);
    }
    printf("\n");
    fclose(fp);

    return 0;
}

// Shows bits in a Byte array
void showBits(Byte *utf) {
    for(int byte = 0; byte < strlen(utf); byte++) {
        Byte bitmask = 1u << 7;
        Byte headerFlag = 1;
        for(int bit = 0; bit < 8; bit++) {
            if(headerFlag) printf(GREEN);
            if(utf[byte] & bitmask) printf("1");
            else {printf("0"); headerFlag = 0;}
            printf(RESET);
            bitmask >>= 1;
        }
        if(byte < strlen(utf)-1) printf("|");
        else printf("\n");
    }
}

// Convert string into 8 wide bit string
Byte *stringToBits(char *string) {
    unsigned long hexVal = 0;
    for(int i = 0; i < strlen(string); i++) {
        hexVal <<= 1;
        if(string[i] == '1') hexVal |= 1u;
    }
    return hexToBits(hexVal);
}

// Convert a hex value into utf format
Byte *hexToBits(unsigned long hexVal) {
    hexVal &= (~EMPTY_BIT >> 11);
    int totalBits = findTotalBits(hexVal);
    int size = findTotalSize(totalBits);
    Byte *bits = calloc(size, sizeof(Byte));
    Byte lastBitmask = (~0) << (8-size);
    for(int i = 0, bitmask = lastBitmask; i < size; i++) {
        Byte extractedBits = hexVal >> (6*(size-i-1));
        extractedBits &= 0xFF >> 2;
        bits[i] = bitmask | extractedBits;
        bitmask = 1u << 7;
    }
    return bits;
}

int findTotalBits(unsigned long value) {
    int bitmask = LAST_BIT;
    for(int bits = 32; bits >= 0; bits--) {
        if((value & bitmask)) return bits;
        bitmask >>= 1;
    }
    return 0;
}

int findTotalSize(int bits) {
    if(bits <= 7)       return 1;
    else if(bits <= 11) return 2;
    else if(bits <= 16) return 3;
    return 4;
}