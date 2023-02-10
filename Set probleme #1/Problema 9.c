#include <stdio.h>

int main()
{
    int a, b, x;

    scanf("%d%d", &a, &b);

    x = a; a = b; b = x;

    printf("a=%d\nb=%d\n", a, b);
    printf("media=%.2f", (float)(a+b)/2);

    return 0;
}
