#include <stdio.h>
int facto(int n)
{
    if (n<1)
        return 1;
    else return n*facto(n-1);
}
int main()
{
    printf("1! = %i\n", facto(1));
    printf("3! = %i\n", facto(3));
    printf("5! = %i\n", facto(5));
    return 0;
}