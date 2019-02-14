#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int value;
    const char *string;
} KeyMap;

KeyMap fizzbuzzMap [] = {
    {3, "fizz"},
    {5, "buzz"},
};

int totalFizzbuzzMap = sizeof(fizzbuzzMap) / sizeof(KeyMap);

void fizzbuzz(int);
char *get_fizzbuzz_string(int);

void fizzbuzz(int num) {
    for (int i = 0; i < num; i++) {
        char *string = get_fizzbuzz_string(i);
        printf("%s\n", string);
        free(string);
    }
}

char *get_fizzbuzz_string(int num) {
    char *return_string = calloc(sizeof(char), 200);
    char buffer[200] = {0};
    int found_match = 0;
    for (int i = 0; i < totalFizzbuzzMap; i++) {
        int key = fizzbuzzMap[i].value;
        const char *string = fizzbuzzMap[i].string;
        if (num % key == 0) {
            snprintf(buffer, 200, "%s", string);
            strncat(return_string, buffer, 200);
            found_match = 1;
        }
    }
    if (!found_match) {
        snprintf(return_string, 200, "%d", num);
    }
    return return_string;
}

