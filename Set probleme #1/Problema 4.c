#include <stdio.h>
#include <float.h>
#include <limits.h>

int main()
{
    printf("%d %d\n", sizeof(char), SCHAR_MAX);
    printf("%d %d\n", sizeof(unsigned char), UCHAR_MAX);
    printf("%d %d\n", sizeof(int), INT_MAX);
    printf("%d %d\n", sizeof(unsigned int), UINT_MAX);
    printf("%d %d\n", sizeof(long int), LONG_MAX);
    printf("%d %d\n", sizeof(unsigned long int), ULONG_MAX);
    printf("%d %d\n", sizeof(float), FLT_MAX);
    printf("%d %d\n", sizeof(double), DBL_MAX);
    printf("%d %d\n", sizeof(long double), LDBL_MAX);

    return 0;
}
