#include <stdio.h>

int main () {

    int  *ptr = NULL;
    int aVariable = 1;
    int *ptrNotNull = &aVariable;

    // succeeds if pointer is not null
    if(ptr) {
        printf("pointer ptr is not null\n");
    } else {
        printf("pointer ptr is null\n");
    }

    // succeeds if pointer is null
    if(!ptr) {
        printf("pointer ptr is null\n");
    } else {
        printf("pointer ptr is not null\n");
    }

    // succeeds if pointer is not null
    if(ptrNotNull) {
        printf("pointer ptrNotNull is not null\n");
    } else {
        printf("pointer ptrNotNull is null\n");
    }

    // succeeds if pointer is null
    if(!ptrNotNull) {
        printf("pointer ptrNotNull is null\n");
    } else {
        printf("pointer ptrNotNull is not null\n");
    }

    printf("The value of ptr is : %p\n", ptr  );
    printf("The value of ptrNotNull is : %p\n", ptrNotNull  );
    return 0;
}

