#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_DIRNAME 100
#define MAX_ARGNAME 100


typedef struct {
    char dir[MAX_DIRNAME];
    char *args[MAX_ARGNAME];
} CommandString;


int main(int argc, char *argv[]) {
    CommandString list[5] = {
        {"/bin/ls", {"/bin/ls", "-la"}},
    };
    execv(list[0].dir, list[0].args);
    char input[100] = {0};
    fgets(input, 100, stdout);
    //printf("Got: %s\n", input);

    return EXIT_SUCCESS;
}