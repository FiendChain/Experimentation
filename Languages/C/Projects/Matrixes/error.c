// For debugging errors
#include <stdio.h>
#include <stdlib.h>

void printError(char *operation, char *type, int terminate) {
    fprintf(stderr, "%s could not be completed! ", operation);
    fprintf(stderr, "Error type: [%s]\n", type);
    if(terminate) {
        fprintf(stderr, "Breaking out of execution!\n");
        exit(EXIT_FAILURE);
    }
}