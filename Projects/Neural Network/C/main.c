#include "matrixes.h"
#include "captcha.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

Matrix *synapse0;
Matrix *synapse1;

// func proto
double sigmoid(double x);
int getPrediction(Matrix *input);

int main(int argc, char *argv[])
{
    // get file to process
    if(argc < 2) 
    {
        printf("Usage: %s <directory>\n", argv[0]); 
        return EXIT_FAILURE;
    }
    // load synapses
    synapse0 = readMatrix("synapse-0.bin");
    synapse1 = readMatrix("synapse-1.bin");

    // start processing
    char filename[MAX_FILENAME] = {0};
    int total = 0;
    int correct = 0;
    for(int i = 0; i < 10; i++)
    {
        for(int var = 0; var < 100; var++)
        {
            sprintf(filename, "%s/%d_%02d.pbm", argv[1], i, var);
            FILE *fp = fopen(filename, "r");
            if(fp == NULL) {
                fclose(fp);
                continue;
            }
            fclose(fp);
            Matrix *input = getSizedPBM(filename);
            printf("[%s]\n", filename);
            int prediction = getPrediction(input);
            printf("Predicted: %d\n", prediction);
            total++;
            if(prediction == i) correct++;
            freeMatrix(input);
        }
    }
    printf("[Summary]\n");
    printf("Total: %d\n", total);
    printf("Correct: %d\n", correct);
    printf("Rate: %.2lf%%\n", 100 * correct / (float)total);
    

    // free synapses
    freeMatrix(synapse0);
    freeMatrix(synapse1);

    return EXIT_SUCCESS;
}

// processing functions
double sigmoid(double x)
{
    return 1/(1 + exp(-x));
}

int getPrediction(Matrix *input)
{
    int result = 0;
    float confidence = 0;
    // feed forward
    Matrix *hiddenLayer = multiplyMatrix(input, synapse0);
    applyFunction(hiddenLayer, &sigmoid);
    Matrix *output = multiplyMatrix(hiddenLayer, synapse1);
    applyFunction(output, &sigmoid);
    printf("Probabilities: "); printMatrix(output);
    // get result
    for(int i = 0; i < output->col; i++)
    {
        if(output->arr[0][i] > confidence)
        {
            confidence = output->arr[0][i];
            result = i;
        }
    }
    // freeing
    freeMatrix(hiddenLayer);
    freeMatrix(output);
    // get prediction
    return result;
}