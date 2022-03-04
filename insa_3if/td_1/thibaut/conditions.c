#include <stdio.h>
int main()
{
    int val = 3;
    switch (val)
    {
    case 1:
    case 2:
        printf("Hello 2!\n");
        break;
    case 3:
        printf("Hello 3!\n");
    default:
        printf("Other Hello!\n");
    }
    return 0;
}