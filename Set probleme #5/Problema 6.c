#include <stdio.h>

int analiza(int nr, int *nr_Nou)
{
    int p = 1, verif = 0; *nr_Nou = 0;

    while(nr)
    {
        if(nr % 2 == 0)
        {
            *nr_Nou = *nr_Nou + p * (nr % 10);
            p = p * 10; verif = 1;
        }
        nr = nr / 10;
    }

    return verif;
}

int main()
{
    int nr, k;

    scanf("%d", &nr);

    if(analiza(nr, &k) == 1)
        printf("Numarul nou obtinut este %d.", k);
    else
        printf("Numarul nu contine cifre pare.");

	return 0;
}
