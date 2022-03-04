#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dynamicCharArray {
    char* array;
    size_t size;
    size_t maxSize;
} dCharArray;

typedef struct Person {
    char tel[11];
    char* name;
} Person;

void printPersonRegister(Person* givenRegister, size_t sizeRegister) {
    for(int i=0; i<sizeRegister; i++) {
        printf("Name: %s, Tel: %s\r\n", givenRegister[i].name, givenRegister[i].tel);
    }
}

char* copyArrayWithOptimisedSize(char* givenArray) {
    //char* array = (char*) malloc(sizeof(char));
    int i = 0;
    int size = strlen(givenArray);
    char* array = (char*) malloc(sizeof(char)*strlen(givenArray));
    strcpy(array, givenArray); // destination, source
    char currentChar;
    return array;
}

int main() {
    size_t SIZE_REGISTER = 3;
    Person registerPerson[SIZE_REGISTER];

    //char* currentName = (char*) malloc(sizeof(char));
    char currentName[100];
    char currentTel[11]; // string + '\O'
    for(int i=0; i<SIZE_REGISTER; i++) {
        printf("Name is : ");
        scanf("%s", currentName);
        printf("Given Name : %s\r\n", currentName);
        printf("Tel is : ");
        scanf("%s", currentTel);
        printf("Given tel: %s\r\n", currentTel);

        Person* currentPerson = (Person*) malloc(sizeof(Person));
        currentPerson->name = copyArrayWithOptimisedSize(currentName);
        strcpy(currentPerson->tel, currentTel);
        registerPerson[i] = *currentPerson;
    }
    printPersonRegister(registerPerson, SIZE_REGISTER);

    return 0;
}
