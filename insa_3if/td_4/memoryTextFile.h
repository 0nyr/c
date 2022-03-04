#include <stdio.h>
#include <stdlib.h>

typedef struct memoryTextFile {
    char* filepath;
    int* data;  // tableau de char (en fait des int pour l'UTF-8)
    int filled;
    int size;
} Mtf;

void writeMtfToStorage(Mtf* mtf);

void readMtfToTerminal(Mtf* mtf);

void replaceCharAtPositionInMtf(Mtf* mtf, int givenChar, int offset);

void insertInMtf(Mtf* mtf, int givenChar);
