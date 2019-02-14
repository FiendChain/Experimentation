// Finishing that bishop question
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8
#define MAX_MOVES 8

#define INVALID -1
#define USED 1
#define FREE 0

typedef struct _point point_t;
struct _point {
    char x;
    char y;
};

typedef struct _bishop bishop_t;
struct _bishop {
    char moves;
    point_t pos[MAX_MOVES];
};

point_t getTarget(char input[]) {
    point_t target;
    target.x = input[0] - 'A';
    target.y = input[1] - '1';

    if(target.x >= SIZE || target.x < 0 || target.y >= SIZE || target.y < 0) {
        printf("Enter valid target for %dx%d board\n", SIZE, SIZE);
        exit(1);
    }

    return target;
}

void printArray(char board[SIZE][SIZE]) {
    // Print header
    printf(" ");
    for(char c = 'A'; c < 'A' + SIZE; c ++) {
        printf(" %c ", c);
    }
    printf("\n");
    // Printing rest of board
    int current;
    for(int row = 0; row < SIZE; row ++) {
        // Print row number
        printf("%d", row + 1);
        // Print the row
        for(int col = 0; col < SIZE; col ++) {
            current = board[col][row];
            if(current != FREE) {
                printf("[%d]", current);
            } else {
                printf(" %d ", current);
            }
        }
        printf("\n");
    }
}

void copyArray(char copy[SIZE][SIZE], char source[SIZE][SIZE]) {
    for(int row = 0; row < SIZE; row ++) {
        for(int col = 0; col < SIZE; col ++) {
            copy[row][col] = source[row][col];
        }
    }
}

bishop_t *move(int x, int y, point_t *target, char board[SIZE][SIZE], int depth) {
    // Check if in range
    if(x >= SIZE || x < 0 || y >= SIZE || y < 0) return NULL;
    // Check if current location is already taken
    if(board[x][y] == USED) return NULL;
    // Check if recursion depth has been reached
    if(depth > MAX_MOVES) return NULL;
    // Check if target has been reached
    if(x == target -> x && y == target -> y) {
        bishop_t *new = malloc(sizeof(bishop_t));
        new -> moves = 0;
        new -> pos[new -> moves].x = x;
        new -> pos[new -> moves].y = y;
        new -> moves ++;
        return new;
    }
    // Otherwise update board
    board[x][y] = USED;
    // Copy board 8 times
    char copy[8][SIZE][SIZE];
    for(int i = 0; i < 8; i ++) {
        copyArray(copy[i], board);
        if(copy[i] == NULL) {
            printf("Copy %d could not be allocated!\n", i);
            exit(1);
        }
    }
    bishop_t *try[8];
    try[0] = move(x+1, y+2, target, copy[0], depth+1);
    try[1] = move(x-1, y+2, target, copy[1], depth+1);
    try[2] = move(x+1, y-2, target, copy[2], depth+1);
    try[3] = move(x-1, y-2, target, copy[3], depth+1);
    try[4] = move(x+2, y+1, target, copy[4], depth+1);
    try[5] = move(x-2, y+1, target, copy[5], depth+1);
    try[6] = move(x+2, y-1, target, copy[6], depth+1);
    try[7] = move(x-2, y-1, target, copy[7], depth+1);

    // Find the smallest move that isnt invalid
    char leastMoves = MAX_MOVES;
    int bestTry = INVALID;
    for(int i = 0; i < 8; i ++) {
        if(try[i] != NULL && try[i] -> moves < leastMoves) {
            bestTry = i;
            leastMoves = try[i] -> moves;
        }
    }
    // Free up suboptimal and invalid moves
    for(int i = 0; i < 8; i ++) {
        if(try[i] != NULL && i != bestTry) {
            free(try[i]);
        }
    }
    // Check if a valid move could be found, if not return an invalid bishop
    if(bestTry == INVALID) return NULL;
    // Get that try and add current move
    char currentMoves = try[bestTry] -> moves;
    try[bestTry] -> pos[currentMoves].x = x;
    try[bestTry] -> pos[currentMoves].y = y;
    try[bestTry] -> moves ++;

    return try[bestTry];
}

int main(int argc, char *argv[]) {
    // Argument check
    if(argc != 3) {
        printf("Usage: %s <Start> <Target>\n", argv[0]);
        exit(1);
    }

    // Create new board
    char board[SIZE][SIZE];
    for(int row = 0; row < SIZE; row ++) {
        for(int col = 0; col < SIZE; col ++) {
            board[row][col] = FREE;
        }
    }
    // Get target
    point_t start = getTarget(argv[1]);
    point_t target = getTarget(argv[2]);

    // Run function now
    bishop_t *best = move(start.x, start.y, &target, board, 0);

    // Get result
    if(best -> moves != INVALID) {
        printf("Lowest moves: %d\n", best -> moves);
        for(int i = best -> moves - 1; i >= 0; i --) {
            char posX = best -> pos[i].x;
            char posY = best -> pos[i].y;
            char moves = best -> moves;
            printf("Move [%d] => %c%d\n", moves - i, 'A' + posX, posY + 1);
            board[posX][posY] = moves - i;
        }
        printArray(board);
    } else {
        printf("A path below %d moves could not be found\n", MAX_MOVES);
    }
    
    // Free memory
    free(best);

    return 0;
}

