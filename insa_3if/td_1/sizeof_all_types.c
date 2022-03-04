#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {

    printf("The number of bits in a byte %d\n", CHAR_BIT);

    printf("The sizeof char %ld\n", sizeof(char));
    printf("The minimum value of CHAR = %d\n", CHAR_MIN);
    printf("The maximum value of CHAR = %d\n", CHAR_MAX);
    printf("The minimum value of SIGNED CHAR = %d\n", SCHAR_MIN);
    printf("The maximum value of SIGNED CHAR = %d\n", SCHAR_MAX);
    printf("The maximum value of UNSIGNED CHAR = %d\n", UCHAR_MAX);
    
    printf("The sizeof short %ld\n", sizeof(short));
    printf("The minimum value of SHORT INT = %d\n", SHRT_MIN);
    printf("The maximum value of SHORT INT = %d\n", SHRT_MAX);
    printf("The maximum value of UNSIGNED SHORT INT %d\n", USHRT_MAX);

    printf("The sizeof int %ld\n", sizeof(int));
    printf("The minimum value of INT = %d\n", INT_MIN);
    printf("The maximum value of INT = %d\n", INT_MAX);
    printf("The maximum value of UNSIGNED INT %d\n", UINT_MAX);

    printf("The sizeof int %ld\n", sizeof(long));
    printf("The minimum value of LONG = %ld\n", LONG_MIN);
    printf("The maximum value of LONG = %ld\n", LONG_MAX);
    printf("The maximum value of unsigned long int %ld\n", ULONG_MAX);

    printf("The sizeof long long = %ld\n", sizeof(long long));
    printf("The maximum value of long long min %lld\n", LLONG_MIN);
    printf("The maximum value of long long max %lld\n", LLONG_MAX);

    printf("The sizeof unsigned long long = %ld\n", sizeof(unsigned long long));
    printf("The maximum value of unsigned long long max %lld\n", ULLONG_MAX);

    printf("the sizeof float = %ld\n", sizeof(float));
    printf("The maximum value of float = %f\n", FLT_MAX);
    printf("The minimum value of float = %f\n", FLT_MIN);

    printf("the sizeof double = %ld\n", sizeof(double));
    printf("The maximum value of double = %f\n", DBL_MAX);
    printf("The minimum value of double = %f\n", DBL_MIN);

    printf("the sizeof long double = %ld\n", sizeof(long double));
    printf("The maximum value of long double = %Lf\n", LDBL_MAX);
    printf("The minimum value of long double = %Lf\n", LDBL_MIN);
  
   return(0);
}
