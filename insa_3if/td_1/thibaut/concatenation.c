#include <stdio.h>
#include <string.h>
int main()
{
    char dest[20] = "Hello";
    char src[20] = "World";
    strncat(dest, src, 3);
    printf("%s\n", dest);
    strncat(dest, src, 20);
    printf("%s\n", dest);
    return 0;
}