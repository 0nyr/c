#include <stdio.h>
#include <string.h>

int main() {
    char dest[20]="Hello";
    char src[20]="World";

    strncat(dest,src,3); // concatenate first 3 chars of src after dest
    printf("%s\n",dest);
    strncat(dest,src,20); // concatenate first 20 chars of src after dest
    printf("%s\n",dest);

    return 0;
}
