#include <stdio.h>

int main()
{
    int n, i, j, P, S = 0;

    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        P = 1;
        for(j = 1; j <= i; j++)
            P = P * j;
        S = S + P;
    }

    printf("S = %d", S);

    return 0;
}
