// Returning a struct for tidier code
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char charCount[26];
    int totalVowels;
    int totalConsonants;
    int totalRepeats;
    int isPalindrome;
} stringAnalysis_t;

int checkPalindrome(char *string) {
    int stringLength = strlen(string) - 1;
    for(int i = 0; i < stringLength; i ++) {
        if(tolower(string[i]) != tolower(string[stringLength - i])) {
            return 0;
        }
    }
    return 1;
}

int checkVowel(char c) {
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    int totalVowels = sizeof(vowels) / sizeof(char);
    for(int i = 0; i < totalVowels; i++) {
        if(c == vowels[i]) return 1;
    }
    return 0;
}

stringAnalysis_t analyseString(char *string) {
    int stringLength = strlen(string);
    stringAnalysis_t results = {{0}, 0, 0, 0, 0};
    for(int i = 0; i < stringLength; i++) {
        char c = tolower(string[i]);
        if(isalpha(c)) {
            int count = results.charCount[c - 'a']++;
            if(count > 0)       results.totalRepeats++;
            if(checkVowel(c))   results.totalVowels++;
            else                results.totalConsonants++;
        }
    }
    results.isPalindrome = checkPalindrome(string);

    return results;
}

void printStringAnalysis(stringAnalysis_t results) {
    printf("> Character count: ");
    for(int i = 0; i < 26; i++) {
        if(i % 4 == 0) printf("\n   ");
        else printf(" ");
        printf("[%c]:%d", i + 'a', results.charCount[i]);
    }
    printf("\n");
    printf("> Total vowels: %d\n",      results.totalVowels);
    printf("> Total consonants: %d\n",  results.totalConsonants);
    printf("> Total repeats: %d\n",     results.totalRepeats);
    if(results.isPalindrome)    printf("> String is a palindrome\n");
    else                        printf("> String is not a palindrome\n");
}

int main(int argc, char *argv[]) {
    stringAnalysis_t results = analyseString(argv[1]);
    printStringAnalysis(results);

    return 0;
}
