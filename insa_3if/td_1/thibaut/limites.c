#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    printf("char:   %lu &   %d      &   %d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("uchar:  %lu &   %d      &   %d\n", sizeof(unsigned char), 0, UCHAR_MAX);
    printf("short:  %lu &   %d      &   %d\n", sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("ushort: %lu &   %d      &   %d\n", sizeof(short), 0, USHRT_MAX);
    printf("int:    %lu &   %d      &   %d\n", sizeof(int), INT_MIN, INT_MAX);
    printf("uint:   %lu &   %d      &   %u\n", sizeof(unsigned int), 0, UINT_MAX);
    printf("long:   %lu &   %ld     &   %ld\n", sizeof(long), LONG_MIN, LONG_MAX);
    printf("ulong:  %lu &   %d      &   %lu\n", sizeof(unsigned long), 0, ULONG_MAX);
    printf("llong:  %lu &   %llu    &   %llu\n", sizeof(long long), LLONG_MIN, LLONG_MAX);
    printf("ullong: %lu &   %d      &   %llu\n", sizeof(unsigned long long), 0, ULLONG_MAX);

    printf("float:   %lu &   %f      &   %f\n", sizeof(float), FLT_MIN, FLT_MAX);
    printf("double:   %lu &   %f      &   %f\n", sizeof(double), DBL_MIN, DBL_MAX);
    printf("ldouble:   %lu &   %Lf      &   %Lf\n", sizeof(long double), LDBL_MIN, LDBL_MAX);

    return 0;
}