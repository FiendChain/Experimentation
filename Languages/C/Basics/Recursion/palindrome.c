#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 100
#define MAX_WORD 100

typedef struct wordCount wordCount_t;
struct wordCount {
    char word[MAX_STRING];
    int count;
};

int checkPalindrome(char word[MAX_STRING]);
void getWord(char input[MAX_STRING * MAX_WORD], wordCount_t list[MAX_WORD]);
void addList(char word[MAX_STRING], wordCount_t list[MAX_WORD]);

int main(void) {
    char input[MAX_STRING * MAX_WORD] = {0};
    fgets(input, MAX_STRING * MAX_WORD, stdin);

    wordCount_t list[MAX_WORD];
    for(int i = 0; i < MAX_WORD; i ++) {
        for(int j = 0; j < MAX_STRING; j ++) {
            list[i].word[j] = 0;
        }
        list[i].count = 0;
    }

    getWord(input, list);

    printf("[");
    for(int i = 0; i < MAX_WORD && list[i].count != 0; i ++) {
        if(list[i].count != 0) {
            printf("""%s"":%d", list[i].word, list[i].count);
        }
        if(list[i+1].count != 0) {
            printf(", ");
        } 
    }
    printf("]");

    return 0;
}

void getWord(char input[MAX_STRING * MAX_WORD], wordCount_t list[MAX_WORD]) {
    char word[MAX_STRING] = {0};
    int end = 0;
    int flag = 0;
    int start = 0; 

    for(int i = 0; i < MAX_STRING * MAX_WORD; i ++) {
        if(isalpha(input[i]) && flag == 0) {
            flag = 1;
            start = i;
        }
        if(!isalpha(input[i]) && flag == 1) {
            end = i;
            flag = 0;
            int length = end - start;

            for(int index = 0; index <= length; index ++) {
                if(index == length) {
                    word[index] = 0;
                } else {
                    word[index] = tolower(input[start + index]);
                }
            }

            if(checkPalindrome(word)) {
                addList(word, list);
            }
        }
    }
}

int checkPalindrome(char word[MAX_STRING]) {
    int wordLength = 0;
    for(int i = 0; i < MAX_STRING && isalpha(word[i]); i ++) {
        wordLength ++;
    }
    for(int i = 0; i < wordLength / 2; i ++) {
        if(tolower(word[i]) != tolower(word[wordLength-i-1])) {
            return 0;
        }
    }
    return 1;
}

void addList(char word[MAX_STRING], wordCount_t list[MAX_WORD]) {
    for(int i = 0; i < MAX_WORD; i ++) {
        int status = !strcmp(list[i].word, word);
        if(status == 0 && list[i].count == 0) {
            strcpy(list[i].word, word);
            list[i].count ++;
            break;
        }
        if(status != 0) {
            list[i].count ++;
            break;
        }
    }
}

