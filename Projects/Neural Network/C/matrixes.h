#ifndef _MATRIXES_H_
#define _MATRIXES_H_

#define MAX_FILENAME 100

typedef struct {
    int row;
    int col;
    double **arr;
} Matrix;

Matrix *makeMatrix(int row, int col, double arr[row][col]); 
Matrix *multiplyMatrix(Matrix *a, Matrix *b);
Matrix *readMatrix(char filename[MAX_FILENAME]);
Matrix *reshapeMatrix(Matrix *m, int row, int col);
void applyFunction(Matrix *m, double (*func)(double));
void freeMatrix(Matrix *m);
void printMatrix(Matrix *m);
void saveMatrix(Matrix *m, char filename[MAX_FILENAME]);

#endif 