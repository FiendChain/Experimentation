#ifndef _CAPTCHA_H
#define _CAPTCHA_H

#define CAPTCHA_SIZE 16

#include "matrixes.h"

Matrix *cropPBM(Matrix *m);
Matrix *getSizedPBM(char filename[MAX_FILENAME]);
Matrix *readPBM(char filename[MAX_FILENAME]);
Matrix *scalePBM(Matrix *m);
void printPBM(Matrix *m);

#endif