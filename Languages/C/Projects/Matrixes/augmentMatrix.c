#include <stdio.h>
#include <stdlib.h>
#include "error.h"
#include "matrix.h"

#define NON_LEADING -1

// Create an augmented matrix
Matrix createAugMatrix(Matrix x, Matrix y) {
    if(x->row != y->row) {
        printError("Creating augmented matrix", "Rows do not match", 1);
    }
    Matrix new = createMatrix(x->row,x->col+y->col);
    new->divCol = x->col;
    for(int row = 0; row < x->row; row++) {
        for(int col = 0; col < x->col; col++) {
            new->matrix[row][col] = x->matrix[row][col];
        }
        for(int col = 0; col < y->col; col++) {
            new->matrix[row][col+x->col] = y->matrix[row][col];
        }
    }
    return new;
}

// Convert near zero floating point to zero
void roundToZero(float *value) {
    inline float absFloat(float val) {
        if(val < 0) return -val;
        else return val;
    }
    if(absFloat(*value) < 0.0001) *value = 0;
}

// Normalise all rows
void normaliseMatrix(Matrix source) {
    for(int row = 0; row < source->row; row++) {
        float leadCoefficient = 0;
        for(int col = 0; col < source->col; col++) {
            if(source->matrix[row][col] != 0) {
                leadCoefficient = source->matrix[row][col];
                break;
            }
        }
        if(leadCoefficient != 0) {
            for(int col = 0; col < source->col; col++) {
                source->matrix[row][col] /= leadCoefficient;
                roundToZero(&(source->matrix[row][col]));
            }
        }
    }
}

// Row swapping
void swapRows(Matrix source, int rowA, int rowB) {
    if(source->row <= rowA || source->row <= rowB) {
        printError("Row swap operation", "Out of Bounds", 1);
        return;
    }
    for(int col = 0; col < source->col; col++) {
        float temp = source->matrix[rowA][col];
        source->matrix[rowA][col] = source->matrix[rowB][col];
        source->matrix[rowB][col] = temp;
    }
}

// Subtract rows
void subtractRow(Matrix source, int rowA, int rowB) {
    if(source->row <= rowA || source->row <= rowB) {
        printError("Row subtraction", "Out of Bounds", 1);
        return;
    }
    for(int col = 0; col < source->col; col++) {
        source->matrix[rowA][col] -= source->matrix[rowB][col];
        roundToZero(&(source->matrix[rowA][col]));
    }
}

// Check what column the row is leading
int checkLeadColumn(Matrix source, int row) {
    if(source->row <= row) {
        printError("Checking column leading for row", "Out of Bounds", 1);
        return NON_LEADING;
    }
    for(int col = 0; col < source->col; col++) {
        float value = source->matrix[row][col];
        if(value != 0) return col;
    }
    return NON_LEADING;
}

// Start reducing the rows
void reduceMatrix(Matrix source) {
    // Normalise first
    normaliseMatrix(source);
    // Find rows to subtract
    for(int col = 0; col < source->divCol; col++) {
        int subRow = 0, subFlag  = 0;
        for(int row = 0; row < source->row; row++) {
            // Check if leading rows can be subtracted for column
            float value = source->matrix[row][col];
            int leadCol = checkLeadColumn(source, row);
            if(value != 0 && col == leadCol) {
                if(!subFlag) {
                    subRow = row;
                    subFlag = 1;
                } else {
                    subFlag = 0;
                    subtractRow(source, row, subRow);
                    row = -1;   // Becomes 0 after row++ in for loop
                }
            }
        }
        normaliseMatrix(source);
    }
    // Turn row-eschelon into reduced-row eschelon form
    for(int col = 0; col < source->divCol; col++) {
        int subRow = 0, subFlag = 0;
        float scalarValue = 0;
        for(int row = 0; row < source->row; row++) {
            // Get row that needs to be reduced
            float value = source->matrix[row][col];
            int leadCol = checkLeadColumn(source, row);
            if(value != 0 && col != leadCol && !subFlag) {
                scalarValue = value;    // Multiply this to row that can reduce it
                subRow = row;           // Keep this for later
                subFlag = 1;
            // Find a row that can reduce it
            } else if(value == 1 && col == leadCol && subFlag) {
                for(int sCol = 0; sCol < source->col; sCol++) {
                    source->matrix[subRow][sCol] -= scalarValue * source->matrix[row][sCol];
                    roundToZero(&(source->matrix[subRow][sCol]));
                }
                row = subRow;
                subFlag = 0;
            }
        }
    }
}