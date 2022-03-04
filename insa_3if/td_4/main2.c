#include <stdio.h>
#include <stdlib.h>
#include "memoryTextFile.h"

void write20Lines40UnderscoresInMtf(Mtf* mtf) {
    for(int i=0; i<20; i++) {
        for(int j=0; j<40; j++) {
            //mtf->data[41*i + j -1] = '_'; // WARN : 40 chars + \n = 41 chars/line
            insertInMtf(mtf, '_');
        }
        //mtf->data[41*i -1] = '\n';
        insertInMtf(mtf, '\n');
    }
}

void question6(Mtf* mtf) {
    int givenChar = 'a';
    long givenOffset = 0;

    while(givenChar != 'q') {
        readMtfToTerminal(mtf);

        char tmpChar;
        printf("give a char : ");
        scanf(" %c", &tmpChar); // ☢️  WARN : use a whitespace before first input
        givenChar = (int) tmpChar;
        printf("give an offset : ");
        scanf("%li", &givenOffset);

        replaceCharAtPositionInMtf(mtf, givenOffset, givenOffset);
    }

    writeMtfToStorage(mtf);
}

int main(int argc, char **argv) {
    
    int mtf1Size = 10;
    Mtf mtf1 = {
        .filepath = "test_out_2.txt",
        .data = (int*) malloc(sizeof(int)*mtf1Size),
        .size = mtf1Size,
        .filled = 0
    };

    write20Lines40UnderscoresInMtf(&mtf1);
    question6(&mtf1);

    return 0;
}

