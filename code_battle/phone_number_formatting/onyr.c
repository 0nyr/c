#include <stdio.h> 
char* f(char* s, char* r)
{
    r[0]='(';r[4]=')';
    r[5]=' ';r[9]='-';
    int c=0;
    for(int i=0;i<14;i++){
        if((i>0 && i<4)||(i>5 && i<9)||(i>9)){
            r[i]=s[c];
            c++;
        }
    }
    return r;
}
int main()
{
    char S[10];
    char r[14];
    scanf("%[^\n]", S);
    printf("%s\n",f(S, r));
    return 0;
}