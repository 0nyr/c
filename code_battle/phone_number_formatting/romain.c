#include <stdio.h>
int main(){char S[10];scanf("%[^\n]", S);printf("(%.3s) %.3s-%.4s", &S[0],&S[3],&S[6]);return 0;}