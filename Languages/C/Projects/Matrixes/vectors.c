// Playing around with vectors in C
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"


int main(void) {
    // Matrix A
    printf("== Matrix A ==\n");
    float sourceA[4][4] = {
        {7,4,2,0},
        {6,3,-1,2},
        {4,6,2,5},
        {8,2,-7,1}
    };
    Matrix newA = createMatrix(4,4);
    copyMatrix(newA,4,4,sourceA);
    showMatrix(newA);
    float det = findDeterminant(newA);
    printf("Determinant of matrix: %.0lf\n", det);

    // Matrix B
    printf("== Matrix B ==\n");
    float sourceB[4][2] = {
        {1,2},
        {5,6},
        {7,8},
        {10,5}
    };
    Matrix newB = createMatrix(4,2);
    copyMatrix(newB,4,2,sourceB);
    showMatrix(newB);

    // Matrix AxB
    printf("== AxB ==\n");
    Matrix multAB = multiplyMatrix(newA,newB);
    showMatrix(multAB);

    // Testing row reduction //
    // Matrix C
    printf("== Matrix C ==\n");
    Matrix newC = createMatrix(3,3);
    float sourceC[3][3] = {
        {-1,2,1},
        {1,-1,0},
        {3,-2,1}
    };
    copyMatrix(newC,3,3,sourceC);
    showMatrix(newC);
    // Matrix D
    printf("== Matrix D ==\n");
    Matrix newD = createMatrix(3,1);
    float sourceD[3][1] = {4,1,8};
    copyMatrix(newD,3,1,sourceD);
    showMatrix(newD);
    // (C|D)
    printf("== Augmented matrix (C|D) ==\n");
    Matrix augCD = createAugMatrix(newC,newD);
    showMatrix(augCD);
    printf("== Reduced Row Eschelon (C|D) ==\n");
    reduceMatrix(augCD);
    showMatrix(augCD);

    // Getting an inverse
    printf("== 3x3 identity matrix ==\n");
    Matrix identity = createMatrix(2,2);
    float identitySource[2][2] = {
        {1,0},
        {0,1},
    };
    copyMatrix(identity,2,2,identitySource);
    showMatrix(identity);
    printf("== Original matrix ==\n");
    Matrix newE = createMatrix(2,2);
    float sourceE[2][2] = {
        {3,3.5},
        {3.2,3.6}
    };
    copyMatrix(newE,2,2,sourceE);
    showMatrix(newE);
    printf("== Augmented matrix for inverse ==\n");
    Matrix inverse = createAugMatrix(newE,identity);
    showMatrix(inverse);
    printf("== Solving for inverse ==\n");
    reduceMatrix(inverse);
    showMatrix(inverse);

    // Free matrixes
    freeMatrix(newA);
    freeMatrix(newB);
    freeMatrix(multAB);
    freeMatrix(newC);
    freeMatrix(newD);
    freeMatrix(augCD);
    freeMatrix(identity);
    freeMatrix(newE);
    freeMatrix(inverse);

    return 0;
}