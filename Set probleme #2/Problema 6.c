#include <stdio.h>

int main()
{
    int n, poz = 0, neg = 0;

    scanf("%d", &n);

    while(n)
    {
        if(n > 0)
            poz++;
        else
            neg++;
        scanf("%d", &n);
    }

    printf("S-au citit %d numere pozitive si %d numere negative.", poz, neg);

    /**
    float n; int poz = 0, neg = 0;

    scanf("%f", &n);

    while(n != 0)
    {
        if(n > 0)
            poz++;
        else
            neg++;
        scanf("%f", &n);
    }

    printf("S-au citit %d numere pozitive si %d numere negative.", poz, neg);
    **/

    return 0;
}
