#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"
#include "matrix.h"

// Matrix management
Matrix createMatrix(int row, int col) {
    Matrix new = (Matrix)malloc(sizeof(_matrix));
    new->matrix = (float**)calloc(row, sizeof(float*));
    for(int i = 0; i < row; i++) {
        new->matrix[i] = (float*)calloc(col, sizeof(float));
    }
    new->row = row;
    new->col = new->divCol = col;
    return new;
}

void copyMatrix(Matrix dest, int sRow, int sCol, float source[sRow][sCol]) {
    if(dest->row != sRow || dest->col != sCol) {
        printError("Copying matrix", "Invalid matrix dimensions!", 0);  
        return;
    }
    for(int row = 0; row < dest->row; row++) {
        for(int col = 0; col < dest->col; col++) {
            dest->matrix[row][col] = source[row][col];
        }
    }
}

// Show matrix properly
int findTotalDigits(int x) {
    int totalDigits = 1;
    int power = 10;
    while(abs(x) >= power) {
        totalDigits++;
        power *= 10;
    }
    if(x < 0) totalDigits++;
    return totalDigits;
}

int *getPadding(Matrix source) {
    int *paddingSize = calloc(source->col, sizeof(int));
    for(int col = 0; col < source->col; col++) {
        for(int row = 0; row < source->row; row++) {
            int totalDigits = findTotalDigits(source->matrix[row][col]);
            if(paddingSize[col] < totalDigits) paddingSize[col] = totalDigits;
        }
    }
    return paddingSize;
}

int findTotalDP(float x) {
    int totalDP = 0;
    if(x == 0) return totalDP;
    if(x < 0) x = -x;
    while(x < 1) {
        x *= 10;
        totalDP++;
    }
    float decimals = (int)x - x;
    if(decimals < 0) decimals = -decimals;
    if(decimals > 0.1) totalDP++;
    return totalDP;
}

int *getDP(Matrix source) {
    int *decimalPlaces = calloc(source->col, sizeof(int));
    for(int col = 0; col < source->col; col++) {
        for(int row = 0; row < source->row; row++) {
            int totalDP = findTotalDP(source->matrix[row][col]);
            if(decimalPlaces[col] < totalDP) decimalPlaces[col] = totalDP;
        }
    }
    return decimalPlaces;
}

void showMatrix(Matrix source) {
    int *paddingSize = getPadding(source);
    int *decimalPlaces = getDP(source);
    for(int row = 0; row < source->row; row++) {
        printf("| ");
        for(int col = 0; col < source->col; col++) {
            if(col == source->divCol) printf("| ");
            float value = source->matrix[row][col];
            printf("%*.*lf ", paddingSize[col], decimalPlaces[col], value);
        }
        printf("|\n");
    }
    free(paddingSize);
    free(decimalPlaces);
}

// Free matrix to prevent memory leaks
void freeMatrix(Matrix source) {
    for(int i = 0; i < source->row; i++) {
        free(source->matrix[i]);
    }
    free(source->matrix);
    free(source);
}

// Finding determinant of square matrix
int findDeterminant(Matrix source) {
    int det = 0;
    if(source->row != source->col || source->row <= 1) {
        printError("Finding determinant", "Non-square matrixes have no determinant", 0);
        return det;
    }
    // If 2x2 matrix, compute
    int size = source->row;
    if(size == 2) {
        det = source->matrix[0][0]*source->matrix[1][1];
        det -= source->matrix[0][1]*source->matrix[1][0];
        return det;
    }
    // Otherwise, break down into smaller matrixes
    for(int col = 0, power = 1; col < size; col++, power *= -1) {
        Matrix reducedMatrix = createMatrix(size-1,size-1);
        for(int sRow = 0; sRow < size-1; sRow++) {
            for(int sCol = 0, flag = 0; sCol < size; sCol++) {
                if(sCol != col) reducedMatrix->matrix[sRow][sCol-flag] = source->matrix[sRow+1][sCol];
                else flag = 1;
            }
        }
        det += power*source->matrix[0][col]*findDeterminant(reducedMatrix);
        freeMatrix(reducedMatrix);
    }
    return det;
}

// Multiplying two matrixes
Matrix multiplyMatrix(Matrix x, Matrix y) {
    // Check dimensions
    if(x->col != y->row) {
        printError("Multiplying matrixes", "Invalid matrix dimensions", 1);
    }
    // Created multiplied matrix
    Matrix new = createMatrix(x->row,y->col);
    for(int row = 0; row < x->row; row++) {
        for(int col = 0; col < y->col; col++) {
            // Dot product each row and column
            for(int i = 0; i < x->col; i++) {   
                new->matrix[row][col] += x->matrix[row][i] * y->matrix[i][col];
            }
        }
    }
    return new;
}

