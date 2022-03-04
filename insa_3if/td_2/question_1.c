#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

int globalA = 10;
int globalB = 20;

void swapVar(int a,int b) {
    int temp = a;
    a=b;
    b=temp;
}

void swapVarByPointers(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int tpStrcmp(const char *s1, const char *s2) {
    int i = 0;
    int ecart = 0;
    while(s1[i] != '\0' && s2[i] != '\0' && ecart == 0) {
        ecart = s1[i] - s2[i];
        printf("ecart = %d\r\n", ecart);
        i++;
    }
    if(s1[i] == '\0') return -s2[i]; // s1 - s2 => -s2 since '\0' = 0
    if(s2[i] == '\0') return s1[i]; // s1 - s2 => s1 since '\0' = 0
    return ecart;
}

int intAPowerIntB(int a, int b) {
    // b is considered positive !
    if(b == 0) return 1;
    if(a == 0) return 0;
    int sum = a;
    for(int i = 0; i<(b - 1); i++) sum *= a; // b-1 since we start at sum = a
    return sum;
}

int tpAtoi(const char *str) {
    int i = 0;
    int sum = 0;
    char currentChar = 'a';
    int strSize = strlen(str);
    int isNegative = 0;

    // check for "-" sign
    if(str[0] == '-') {
        i = 1;
        strSize = strSize - 1;
        isNegative = 1;
    }

    while (currentChar != '\0') {
        currentChar = str[i];
        // check if char represents a number && if it is not '\0'
        if((currentChar > 57 || currentChar < 48) && currentChar != '\0') return 0; 
        sum += (currentChar - 48)*intAPowerIntB(10, strSize - 1 - i);
        printf("sum = %d, strSize - 1 - i = %d\r\n", sum, strSize - 1 - i);
        i++;
    }

    if(isNegative) sum = -sum; 
    return sum;
}

int numberOfDigitsConsideredPositive(const int number) {
    int nbDigits = 0;
    int quotient = number;
    // if number is negative, consider it positive anyway
    if(quotient < 0) quotient = -quotient;
    while(quotient != 0) {
        quotient /= 10;
        nbDigits++;
    }
    return nbDigits;
}

char* tpItoa(int number) { // -10293
    int isNegative = 0;
    int remainder = number;
    int i=0;
    int strSize = numberOfDigitsConsideredPositive(number) + 1; // +1 for the '\0' char
    char string[strSize];

    if(number < 0) {
        // NB : add a digit space if the number is negative to represent the "-" sign
        isNegative = 1;
        string[0] = '-';
        strSize++;
        i++;
    }

    while(i < strSize - 1 - isNegative) {
        int digit = (int) number / intAPowerIntB(10, strSize - 2 - isNegative); // -2 : '\0', index start at 0
        printf("digit = %d\r\n", digit);
        string[i] = digit + 48;
        i++;
    }
    string[strSize - 1] = '\0';

    printf("%s", string);
}

int main() {
    double varD = 13.12;

    printf("valeur de valD = %lf\r\n", varD);
    printf("addresse de valD = %p\r\n", &varD);

    double* pointeurD = &varD;

    *pointeurD = 1.0;

    printf("valeur de valD = %lf\r\n", varD);
    printf("addresse de valD = %p\r\n", &varD);
    printf("valeur pointé par pointeurD = %f\r\n", *pointeurD);
    printf("valeur de pointeurD = %p\r\n", pointeurD);
    printf("addresse de pointeurD = %p\r\n", &pointeurD);

    // Q4 - quand on affecte aucune valeur à un pointeur, on obtient une variable de la RAM
    /* WARN : essayer d'afficher la valeur de pointeurSansValeur peut renvoyer une erreur
    en effet il contient une valeur au pif qui peut être protégé dans la mémoire */

    int* pointeurSansValeur;

    //printf("valeur pointé par pointeurSansValeur = %d\r\n", *pointeurSansValeur);
    printf("valeur de pointeurSansValeur = %p\r\n", pointeurSansValeur);
    printf("addresse de pointeurSansValeur = %p\r\n", &pointeurSansValeur);

    // Q5-6
    float varF = 3.14f;
    float* pointerF = &varF;
    void* genericPointer = NULL;

    printf("**** Q5 ***** \r\n");
    printf("valeur de varF = %f\r\n", varF);
    printf("addresse de varF = %p\r\n", &varF);
    printf("sizeof varF = %lu\r\n", sizeof(varF));
    printf("valeur pointé par pointerF = %f\r\n", *pointerF);
    printf("valeur de pointerF = %p\r\n", pointerF);
    printf("addresse de pointerF = %p\r\n", &pointerF);
    printf("sizeof pointerF = %lu\r\n", sizeof(pointerF));
    printf("sizeof genericPointer = %lu\r\n", sizeof(genericPointer));

    // Q7-10
    printf("**** Q7-10 ***** \r\n");
    int tab[10]; // allocated in the Stack, not the Heap
    
    printf("*** parcours index 0 -> 9 \r\n");
    for(int i = 0; i<10; i++) {
        printf("adresse de tab (case %d) = %p ou %p\r\n", i, &tab[i], tab + i);
        tab[i] = i;
        printf("valeur de tab (case %d) = %d ou %d\r\n", i, tab[i], *(tab + i));
    }

    printf("*** parcours index 9 -> 0 \r\n");
    for(int i = 9; i>=0; i--) {
        printf("adresse de tab (case %d) = %p ou %p\r\n", i, &tab[i], tab + i);
        tab[i] = i;
        printf("valeur de tab (case %d) = %d ou %d\r\n", i, tab[i], *(tab + i));
    }

    // Q11-12
    printf("**** Q11 ***** \r\n");
    double tab2[10] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10};
    double* pointerTab2 = tab2;
    void* pointerVoidTab2 = tab2;

    printf("affichage tab2 avec pointerTab2\r\n");
    for(int i = 0; i<10; i++) {
        printf("adresse de tab2 (case %d) = %p ou %p\r\n", i, &pointerTab2[i], pointerTab2 + i);
        tab[i] = i;
        printf("valeur de tab2 (case %d) = %lf ou %lf\r\n", i, pointerTab2[i], *(pointerTab2 + i));
    }

    printf("affichage tab2 avec pointerVoidTab2\r\n");
    // a cast to the right type is necessary hence making its use really painful
    /* our tab2 has 10 valeurs however it is possible to read memory box 11 since we are in
    the Stack where 4Mb of data are reserved. */
    for(int i = 0; i<11; i++) {
        printf("adresse de tab2 (case %d) = %p ou %p\r\n", i, &((double*)pointerVoidTab2)[i], pointerVoidTab2 + i);
        tab[i] = i;
        printf("valeur de tab2 (case %d) = %lf ou %lf\r\n", i, ((double*) pointerVoidTab2)[i], *((double*)pointerVoidTab2 + i));
    }

    // Q13
    printf("**** Q13 ***** \r\n");
    // able to acces data which are not from the right array
    int tab3[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tab4[10] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    printf("accès 15ème valeur de tab3 = %d ou %d\r\n", tab3[15], *(tab3 + 15));
    for(int i = 0; i<20; i++) {
        printf("adresse de tab3 (case %d) = %p ou %p\r\n", i, &tab3[i], tab3 + i);
        tab[i] = i;
        printf("valeur de tab3 (case %d) = %d ou %d\r\n", i, tab3[i], *(tab3 + i));
    }

    // Q14
    printf("**** Q14 ***** \r\n");
    double matrix1[10][2];

    for(int i=0; i<10; i++) {
        for(int j=0; j<2; j++) {
            printf("adresse matrix[%d][%d] = %p   ", i, j, &matrix1[i][j]);
        }
        printf("\r\n");
    }
    /* adresse matrix[i][j] = 0x7ffe9abea660   adresse matrix[i][j] = 0x7ffe9abea668
    addresses are incremented by 8 BYTES == 64 bits !*/

    // Q15
    printf("**** Q15 ***** \r\n");

    double tab5[20];
    for(int i = 0; i<20; i++) {
        printf("adresse de tab5 (case %d) = %p ou %p\r\n", i, &tab5[i], tab5 + i);
    }
    
    // Q16-18
    printf("**** Q16-17***** \r\n");

    // on passe une copie de variables (les valeurs de a et b) même globales !
    int stackA = 10;
    int stackB = 20;

    // un swap en envoyant les valeur de variables n'affecte pas ces variables
    swapVar(stackA, stackA);
    printf("stackA = %d, stackB = %d\r\n", stackA, stackA);

    swapVar(globalA, globalB);
    printf("globalA = %d, globalB = %d\r\n", globalA, globalB);
    
    // un swap en envoyant l'adresses des variables en tant que pointeurs va modifier 
    // ces variables
    swapVarByPointers(&stackA, &stackB);
    swapVarByPointers(&globalA, &globalB);
    printf("stackA = %d, stackB = %d\r\n", stackA, stackA);
    printf("globalA = %d, globalB = %d\r\n", globalA, globalB);

    // Q19-21
    printf("**** Q19 ***** \r\n");

    // WARN : la taille d'une string est fixée lors de sa déclaration
    // une string est un tableau de constante prédéfinie, tableau statique !
    // déclarer des strings : char* str = "mdr" => char str[4] =>  "mdr" + '\0' 

    char* myString = "<-_->";

    for(int i = 0; i< strlen(myString); i++) {
        printf("%c", *(myString + i));
    }
    printf("\r\n");
    for(int i = 0; i< strlen(myString); i++) {
        printf("%c", myString[i]);
    }
    printf("\r\n");

    // Q22
    printf("**** Q22 ***** \r\n");

    char* string1 = "aaaa";
    char* string2 = "aaaaa";
    char* string3 = "abc";

    printf("test string1 < string2 (?<0) = %d\r\n", tpStrcmp(string1, string2));
    printf("test string1 = string1 (?=0) = %d\r\n", tpStrcmp(string1, string1));
    printf("test string3 > string1 (?>0) = %d\r\n", tpStrcmp(string3, string1));

    // Q23
    printf("**** Q23 ***** \r\n");

    printf("test 10^3 = %d\r\n", intAPowerIntB(10, 3));
    char* string4 = "102932";
    char* string5 = "-3764";
    printf("102932 = %d\r\n", tpAtoi(string4));
    printf("-3764 = %d\r\n", tpAtoi(string5));

    // Q24
    printf("**** Q24 ***** \r\n");

    int integer1 = 12838;
    int integer2 = -938;
    printf("12838 = ");
    tpItoa(integer1);
    printf("\r\n");
    printf("-938 = ");
    tpItoa(integer1);  
    printf("\r\n");
    return 0;
}
