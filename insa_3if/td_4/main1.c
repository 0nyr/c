#include <stdio.h>
#include <stdlib.h>

//#define TRACES

#ifdef TRACES
#define debug(expression) (printf("%s:%d -> " #expression "\n", __FILE__, __LINE__))
#define debugd(expression) (printf("%s:%d -> " #expression " = %d\n", __FILE__, __LINE__, (expression)))
#define debugld(expression) (printf("%s:%d -> " #expression " = %ld\n", __FILE__, __LINE__, (expression)))
#define debugtv(exp, var) (printf("[%s:%d] " #exp "\r\n", __FILE__, __LINE__, (var)))
#else
#define debug(expression) ((void)0)
#define debugd(expression) ((void)0)
#define debugld(expression) ((void)0)
#define debugtv(exp, var) ((void)0)
#endif

void write20Lines40Underscores(FILE* stream) {
    fseek(stream, 0, SEEK_SET);
    for(int i=0; i<20; i++) {
        for(int j=0; j<40; j++) {
            fputc('_', stream);
        }
        fputc('\n', stream);
    }
    fseek(stream, 0, SEEK_SET);
}

void replaceCharAtPosition(FILE* stream, char givenChar, long offset) {
    debug("replaceCharAtPosition()");
    debugd(givenChar);
    debugld(offset);
    if(offset > 40*20) return;
    fseek(stream, offset, SEEK_SET);
    if(fgetc(stream) != '\n') {
        fputc(givenChar, stream);
    } else {
        fseek(stream, offset+1, SEEK_SET);
        fputc(givenChar, stream);
    }
}

void readFileToStdout(FILE* stream1, FILE* stream2) {
    fseek(stream1, 0, SEEK_SET);
    while(!feof(stream1)) {
        char currentChar = fgetc(stream1);
        if(!feof(stream1)) {
            fputc(currentChar, stream2);
            fputc(currentChar, stdout);
        }
    }
    printf("\r\n");
}

void readFileToTerminal(FILE* stream1) {
    debug("readFileToTerminal()");
    fseek(stream1, 0, SEEK_SET);
    while(!feof(stream1)) {
        char currentChar = fgetc(stream1);
        if(currentChar == EOF) break;
        if(!feof(stream1)) {
            fputc(currentChar, stdout);
            //printf("%c", currentChar);
        }
    }
    printf("\r\n");
}

void question6(FILE* stream) {
    char givenChar = 'a';
    long givenOffset = 0;

    while(givenChar != 'q') {
        readFileToTerminal(stream);

        printf("give a char : ");
        scanf(" %c", &givenChar); // ☢️ WARN : use a whitespace before first input
        debugtv("given char = %c", givenChar);
        printf("give an offset : ");
        scanf("%ld", &givenOffset);
        debugtv("given offset = %ld", givenOffset);
        // printf("\r\n");  WARN : do not use, the scanf ENTER create a \n

        replaceCharAtPosition(stream, givenChar, givenOffset);
    }
}

int main(int argc, char **argv) {
    FILE* stream1;
    FILE* stream2;

    // get inputs
    if(argc > 1) {
        stream1 = fopen(argv[1], "r");
    } else {
        stream1 = fopen("test_file_1.txt", "r");
    }

    if(argc > 2) {
        stream2 = fopen(argv[2], "w+");
    } else {
        stream2 = fopen("test_out_1.txt", "w+");
    }

    //readFileToStdout(stream1, stream1);
    write20Lines40Underscores(stream2);
    //readFileToTerminal(stream2);

    question6(stream2);

    // close
    fclose(stream1);
    fclose(stream2);

    return 0;
}


