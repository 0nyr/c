#include <stdio.h>
#include <stdlib.h>
#include "memoryTextFile.h"

void writeMtfToStorage(Mtf* mtf) {
    FILE* stream = fopen(mtf->filepath, "w+");

    for(int i=0; i<mtf->filled; i++) {
        fputc(mtf->data[i], stream);
    }
}

void readMtfToTerminal(Mtf* mtf) {
    for(int i=0; i<mtf->filled; i++) {
        fputc(mtf->data[i], stdout);
    }
    printf("mtf->filled = %d\r\n", mtf->filled);
}

void replaceCharAtPositionInMtf(Mtf* mtf, int givenChar, int offset) {
    if(offset < 0 || offset > mtf->size) return;
    mtf->data[offset] = givenChar;
}

void insertInMtf(Mtf* mtf, int givenChar) {
    printf("filled = %d", mtf->filled);
    printf("size = %d", mtf->size);
    if(mtf->filled >= mtf->size) {
        mtf->size *= 2;
        mtf->data = (int*) realloc(mtf->data, mtf->size*sizeof(int));
    }
    mtf->data[mtf->filled - 1] = givenChar;
    mtf->filled++;
}
