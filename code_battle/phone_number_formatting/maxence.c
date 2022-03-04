#include <stdio.h>
int main(){char S[10];scanf("%[^\n]", S);char O[99]="(###) ###-####";for(int i=0;i<10;i++){if(i<3) O[i+1] = S[i]; else if (i<6) O[i+3] = S[i]; else O[i+4] = S[i];}printf("%s\n",O);}