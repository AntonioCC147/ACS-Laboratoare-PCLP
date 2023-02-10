#include <stdio.h>

int main()
{
    int n, nr, i, S = 0;

    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        scanf("%d", &nr);
        S = S + nr;
    }

    float Ma;

    Ma = (float)S / n;

    printf("%.3f", Ma);

    return 0;
}
