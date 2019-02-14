#include "matrixes.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// make a matrix
Matrix *makeMatrix(int row, int col, double arr[row][col]) 
{
    // matrix struct
    Matrix *new = (Matrix *)malloc(sizeof(Matrix));
    assert(new != NULL);
    new->row = row, new->col = col;
    // matrix array
    new->arr = (double **)calloc(row, sizeof(double *));
    assert(new->arr != NULL);
    for(int i = 0; i < row; i++)
    {    
        new->arr[i] = (double *)calloc(col, sizeof(double));
        assert(new->arr[i] != NULL);
    }
    // empty array
    if(arr == NULL) return new;
    // write array
    for(int i = 0; i < row; i++) 
    {
        for(int j = 0; j < col; j++)
        {
            new->arr[i][j] = arr[i][j];
        }
    }

    return new;
}

// multiply two matrixes
Matrix *multiplyMatrix(Matrix *a, Matrix *b)
{
    assert(a != NULL && b != NULL);
    assert(a->col == b->row);
    // c = a*b
    Matrix *c = makeMatrix(a->row, b->col, NULL);
    // get dot product for each cell
    for(int row = 0; row < c->row; row++)
    {
        for(int col = 0; col < c->col; col++)
        {
            // get dot product
            for(int aCol = 0; aCol < a->col; aCol++)
            {
                c->arr[row][col] += a->arr[row][aCol] * b->arr[aCol][col];
            }
        }
    }
    return c;
}

// apply a function matrix
void applyFunction(Matrix *m, double (*func)(double))
{
    assert(m != NULL && func != NULL);
    for(int row = 0; row < m->row; row++)
    {
        for(int col = 0; col < m->col; col++)
        {
            m->arr[row][col] = func(m->arr[row][col]);
        }
    }
}

// reshape matrix
Matrix *reshapeMatrix(Matrix *m, int row, int col)
{
    // check params
    assert(m != NULL);
    assert(row != 0 && col != 0);
    assert(row*col == m->row*m->col); 
    // make reshape matrix
    Matrix *new = makeMatrix(row, col, NULL);
    assert(new != NULL);
    // reshape
    int mRow = 0, mCol = 0;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            new->arr[i][j] = m->arr[mRow][mCol];
            mCol++;
            if(mCol == m->col)
            {
                mCol = 0;
                mRow++;
            }
        }
    }

    return new; 
}


// print contents
void printMatrix(Matrix *m)
{
    assert(m != NULL && m->arr != NULL);
    for(int i = 0; i < m->row; i++)
    {
        assert(m->arr[i] != NULL);
        printf("[");
        for(int j = 0; j < m->col; j++)
        {
            printf("%.3lf", m->arr[i][j]);
            if(j != m->col-1) printf(",");
        }
        printf("]\n");
    }
}

// free matrix array and struct
void freeMatrix(Matrix *m)
{
    assert(m != NULL && m->arr != NULL);
    for(int i = 0; i < m->row; i++)
    {
        assert(m->arr[i] != NULL);
        free(m->arr[i]);
    }
    free(m->arr);
    free(m);
}


// save and read operations
void saveMatrix(Matrix *m, char filename[MAX_FILENAME]) 
{
    assert(m != NULL && m->arr != NULL);
    FILE *fp = fopen(filename, "w");
    assert(fp != NULL);
    assert(fwrite(&m->row, sizeof(int), 1, fp) == 1);
    assert(fwrite(&m->col, sizeof(int), 1, fp) == 1);
    for(int i = 0; i < m->row; i++)
    {
        assert(fwrite(m->arr[i], sizeof(double), m->col, fp) == m->col);
    }
    fclose(fp);
}

Matrix *readMatrix(char filename[MAX_FILENAME])
{
    // open file
    FILE *fp = fopen(filename, "r");
    assert(fp != NULL);
    // make matrix struct
    Matrix *new = (Matrix *)malloc(sizeof(Matrix));
    assert(new != NULL);
    // get dim
    assert(fread(&new->row, sizeof(int), 1, fp) == 1);
    assert(fread(&new->col, sizeof(int), 1, fp) == 1);
    // get arr
    new->arr = (double **)calloc(new->row, sizeof(double *));
    for(int i = 0; i < new->row; i++)
    {
        new->arr[i] = (double *)calloc(new->col, sizeof(double));
        assert(new->arr[i] != NULL);
    }
    assert(new->arr != NULL);
    for(int i = 0; i < new->row; i++)
    {
        assert(fread(new->arr[i], sizeof(double), new->col, fp) == new->col);
    }
    fclose(fp);

    return new;
}