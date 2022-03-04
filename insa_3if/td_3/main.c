#include <stdio.h>
#include <biblio.h>
/* echo 1 2 3 2 1 2 3 33 2 | valgrind ./main */

typedef struct dynamicIntArray {
    int* array;
    size_t size;
    size_t maxSize;
} dIntArray;

typedef struct arrayAllocatedVariables {
    void** array; // array of pointers
    size_t size;
} arrAllVar;
arrAllVar allVarAllocated = {NULL, 0};

dIntArray getDataForProblem() {
    int* array = (int*) malloc(sizeof(int));
    int currentMaxSize = 1;
    int currentValue;
    int i=0;
    while(1) {
        int nbtokens = scanf("%d", &currentValue);
        if(nbtokens != 1 || feof(stdin)) break;
        if(i + 1 > currentMaxSize) {
            // réallocation du double d'espace si nécessaire
            int* newArray = (int*) malloc(sizeof(int)*(2*currentMaxSize));
            currentMaxSize = 2*currentMaxSize;
            for(int j=0; j<i; j++) {
                *(newArray + j) = *(array + j);
            }
            free(array);
            array = newArray;
        }
        *(array + i) = currentValue;
        i++;
    }
    allVarAllocated.array = malloc(sizeof(void*));
    allVarAllocated.array[0] = array;
    allVarAllocated.size = 1;
    return (dIntArray) {array, i, currentMaxSize};
}

void printDynamicArray(dIntArray dArr) {
    for(int i=0; i<dArr.size; i++) {
        printf("dArr[%d] = %d\r\n", i, *(dArr.array + i));
    }
}

void freeAllMemory() {
    for(int i=0; i<allVarAllocated.size; i++) {
        free(allVarAllocated.array[i]);
    }
}

int main() {
    int array1[8] = {10, 5, 5, 10, 5, 6, 4, 5};
    int array2[10];
    
    dIntArray dArr1 = getDataForProblem();
    printDynamicArray(dArr1);

    freeAllMemory();
    
    /*
    for (int i=0; i<10; i++) {
        scanf("%d", &currentValue);
        *(dynamArray1 + i) = currentValue;
    }
    printArray(array2, 10);

    printf("sumArray = %d\r\n", sumArray(array2, 8));
    printf("productArray = %d\r\n", productArray(array2, 8));
    printf("averageArray = %f\r\n", averageArray(array2, 8));*/

    return 0;
}
