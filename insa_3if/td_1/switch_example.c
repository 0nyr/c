#include <stdio.h>

int main() {
    int val = 2;
    switch(val) {
        case 1: 
            break;
        case 2:
            printf("Hello 2!\n");
            break;
        case 3:
            printf("Hello 3!\n");
            break;
        default:
            printf("Other Hello!\n");
    }

    return 0;
}
