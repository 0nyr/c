#include <stdio.h>

void f(int n) {
    if(n > 10) {
        printf("%d est grand\r\n", n);
    }
}

int main() {
    int tab[] = { 1, 11, 2, 22, 3, 33 };
    int i;

    for (i = 0; i < 6; i++) {
        f(tab[i]);
    }

    return 0;
}
