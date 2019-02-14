typedef struct {
    float **matrix;
    int row;
    int col;
    int divCol; // Augmented matrix property
} _matrix;

typedef _matrix *Matrix;

// Basic matrix operations
Matrix createMatrix(int row, int col);
void copyMatrix(Matrix dest, int sRow, int sCol, float source[sRow][sCol]);
void freeMatrix(Matrix source);
void showMatrix(Matrix source);
int findDeterminant(Matrix source);
Matrix multiplyMatrix(Matrix x, Matrix y);

// Augmented matrixes and solving
Matrix createAugMatrix(Matrix x, Matrix y);
void reduceMatrix(Matrix source);
