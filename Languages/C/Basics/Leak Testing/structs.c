#include <stdio.h>
#include <stdlib.h>
 
typedef struct {
    int *array;
    int x;
} Block;

Block *makeBlock(int x, int len) {
    Block *new = (Block*)malloc(sizeof(Block));
    if(new == NULL) {
        perror("Not enough memory for Block malloc!");
        exit(EXIT_FAILURE);
    }
    new->x = x;
    new->array = (int*)calloc(len, sizeof(int));
    if(new->array == NULL) {
        perror("Not enough memory for Block array malloc!");
        exit(EXIT_FAILURE);
    }
    return new;
}

void freeBlock(Block *b) {
    free(b->array);
    free(b);
}

int main(int argc, char *argv[]) {
    printf("Making blocks\n");
    long totalBlocks = 10;
    Block **blocks;
    blocks = (Block**)calloc(totalBlocks, sizeof(Block*));
    for(long i = 0; i < totalBlocks; i++) {
        blocks[i] = makeBlock(i, 10*i);
    }

    printf("Freeing blocks\n");
    for(long i = 0; i < totalBlocks; i++) {
        // free(blocks[i]);
        freeBlock(blocks[i]);
    }
    free(blocks);

    Block *temp = makeBlock(1, 10);
    freeBlock(temp);
    

    return EXIT_SUCCESS;
}