#include <stdio.h>

int main()
{
    unsigned n;

    scanf("%u", &n);

    printf("%u %u %u\n", n-1, n, n+1);
    printf("%u \n%u\n%u", n-1, n, n+1);

    return 0;
}
