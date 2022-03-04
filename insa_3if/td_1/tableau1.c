#include <stdio.h>
#include <stdlib.h>

int main() {
    int average;
    int * grades = (int*) malloc(sizeof(int) * 3);

    grades[0] = 80;
    grades[2] = 90;
    average = (grades[0] + grades[1] + grades[2]) / 3;
    printf("The average of the 3 grades is: %d\r\n", average);
    
    return 0;
}
