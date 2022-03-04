#include <stdio.h>
int main()
{
    int val = 1000;
    if (val == 1000)
        printf("Vous êtes dans le mille !");
    else if (val < 1000)
    {
        printf("Valeur beaucoup trop petite");
        if (val < 100)
            printf("Valeur beaucoup trop petite");
    }
    else
    {
        printf("Valeur trop grande !");
        if (val > 10000)
            printf("Valeur beaucoup trop grande !");
    }
    return 0;
}