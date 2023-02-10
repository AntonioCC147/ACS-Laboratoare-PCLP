#include <stdio.h>

int main()
{
    int n, aux, inv = 0;

    scanf("%d", &n);

    aux = n;

    while(aux)
    {
        inv = (inv * 10) + (aux % 10);
        aux = aux / 10;
    }

    n = inv;

    while(n)
    {
        printf("%d ", n%10);
        n = n / 10;
    }

    return 0;
}
