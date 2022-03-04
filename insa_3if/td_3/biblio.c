#include <stdlib.h>
#include <stdio.h>

/* WARN : can't know what is after last memory box
could be NULL or something else, need to have size */
int sumArray(int* array, size_t size) {
    int sum = 0;
    for(int i=0; i<size; i++) {
        sum += *(array + i);
    }
    return sum;
}

int productArray(int* array, size_t size) {
    int prod = 1;
    for(int i=0; i<size; i++) {
        prod *= *(array + i);
    }
    return prod;
}

float averageArray(int* array, size_t size) {
    int sum = sumArray(array, size);
    float avg = sum/((float)size);
    return avg;
}

void printArray(int* array, size_t size) {
    for(int i=0; i<size; i++) {
        printf("array[%d] = %d\r\n", i, *(array + i));
    }
}
