#include <stdio.h>

int palindrom(int n)
{
    int aux = n, inv = 0;

    while(aux)
    {
        inv = inv * 10 + aux % 10;
        aux = aux / 10;
    }

    if(n == inv)
        return 1;
    else
        return 0;
}

int main()
{
    int numar;

    scanf("%d", &numar);

    printf("%d", palindrom(numar));

	return 0;
}
