#include "captcha.h"
#include "matrixes.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// get pbm for nn
Matrix *getSizedPBM(char filename[MAX_FILENAME])
{
    Matrix *raw = readPBM(filename);
    Matrix *cropped = cropPBM(raw);
    Matrix *scaled = scalePBM(cropped);
    Matrix *reshaped = reshapeMatrix(scaled, 1, CAPTCHA_SIZE*CAPTCHA_SIZE);
    #ifdef DEBUG
    printf("raw:\n");       printPBM(raw);      printf("\n");
    printf("cropped:\n");   printPBM(cropped);  printf("\n");
    printf("scaled:\n");    printPBM(scaled);   printf("\n");
    printf("reshaped:\n");  printPBM(reshaped); printf("\n");
    #endif
    freeMatrix(raw);
    freeMatrix(cropped);
    freeMatrix(scaled);
    return reshaped;
}

// print pbm as int
void printPBM(Matrix *m)
{
    assert(m != NULL && m->arr != NULL);
    printf("Dim = %dx%d\n", m->row, m->col);
    for(int row = 0; row < m->row; row++)
    {
        assert(m->arr[row] != NULL);
        printf("[");
        for(int col = 0; col < m->col; col++)
        {
            printf("%d", (int)m->arr[row][col]);
            if(col != m->col-1) printf(",");
        }
        printf("]\n");
    }
}


// read pbm as raw
Matrix *readPBM(char filename[MAX_FILENAME])
{
    FILE *fp = fopen(filename, "r");
    assert(fp != NULL);
    int width, height;
    if(fscanf(fp, "P1\n%d %d\n", &width, &height) == 2);
    else 
    {
        printf("Couldn't read %s!", filename);
        exit(EXIT_FAILURE);
    }
    Matrix *new = makeMatrix(height, width, NULL);
    assert(new != NULL);
    char c;
    for(int row = 0; row < height; row++)
    {
        for(int col = 0; col < width; col++)
        {
            fscanf(fp, "%c", &c);
            if(c != '\n')
            {
                new->arr[row][col] = c - '0';
            }
            else
            {
                col--;
                continue;
            }
        }
    }
    fclose(fp);

    return new;
}

// crop a matrix
Matrix *cropPBM(Matrix *m)
{
    assert(m != NULL);
    int startRow = 0, startCol = 0, 
        endCol = m->col, endRow = m->row;
    // get start row
    for(int row = 0, flag = 0; row < m->row && !flag; row++)
    {
        for(int col = 0; col < m->col; col++)
        {
            if((int)m->arr[row][col] == 1)
            {
                startRow = row;
                flag = 1;
                break;
            }
        }
    }
    // get end row
    for(int row = m->row-1, flag = 0; row >= 0 && !flag; row--)
    {
        for(int col = 0; col < m->col; col++)
        {
            if((int)m->arr[row][col] == 1)
            {
                endRow = row;
                flag = 1;
                break;
            }
        }
    }
    // get start col
    for(int col = 0, flag = 0; col < m->col && !flag; col++) 
    {
        for(int row = 0; row < m->row; row++)
        {
            if((int)m->arr[row][col] == 1)
            {
                startCol = col;
                flag = 1;
                break;
            }
        }
    }
    // get end col
    for(int col = m->col-1, flag = 0; col >= 0 && !flag; col--) 
    {
        for(int row = 0; row < m->row; row++)
        {
            if((int)m->arr[row][col] == 1)
            {
                endCol = col;
                flag = 1;
                break;
            }
        }
    }
    // get new cropped matrix
    int width = endCol - startCol + 1;
    int height = endRow - startRow + 1;
    Matrix *new = makeMatrix(height, width, NULL);
    assert(new != NULL);
    for(int row = 0; row < new->row; row++)
    {
        for(int col = 0; col < new->col; col++)
        {
            new->arr[row][col] = m->arr[row+startRow][col+startCol];
        }
    }
    return new;
}

// scale a matrix (lossy method)
Matrix *scalePBM(Matrix *m)
{
    assert(m != NULL && m->row != 0 && m->col != 0);
    // get scaling
    float rowScale = m->row / (float)CAPTCHA_SIZE;
    float colScale = m->col / (float)CAPTCHA_SIZE;
    Matrix *new = makeMatrix(CAPTCHA_SIZE, CAPTCHA_SIZE, NULL);
    assert(new != NULL);
    // write to array
    for(int row = 0; row < CAPTCHA_SIZE; row++)
    {
        for(int col = 0; col < CAPTCHA_SIZE; col++)
        {
            new->arr[row][col] = m->arr[(int)(row*rowScale)][(int)(col*colScale)];
        }
    }
    return new;
}