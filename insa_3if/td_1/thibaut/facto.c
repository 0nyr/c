#include <stdio.h>
int main()
{
    int tab[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int res = 1;
    for(int i = 1;i< 11;i++)
    {
        res *= i;
    }
    printf("10! = %d", res);
    return 0;
}