#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    return EXIT_SUCCESS;
}

void quickSort(int n, int arr[n])
{
    partition(0, n, arr);
}

void partition(int start, int end, int *arr)
{
    int pivotIndex = (start+end)/2;
    int pivot = arr[pivotIndex];
    for(int i = start; i < end; i++)
    {
        
    }
}