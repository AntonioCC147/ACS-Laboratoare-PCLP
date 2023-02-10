#include <stdio.h>

void cifre(int n, int *nr_cifre, int *cif1, int *cif2, int *cif3)
{
    int aux = n; *nr_cifre = 0; *cif1 = *cif2 = *cif3 = -1;

    while(aux)
    {
        *nr_cifre=*nr_cifre+1; aux = aux / 10;
    }

    if(n < 10) *cif1 = n % 10;
    else if(n < 100){ *cif2 = n % 10; *cif1 = n / 10 % 10; }
    else{ *cif3 = n % 10; *cif2 = n / 10 % 10; *cif1 = n / 100; }
}

int main()
{
	int nr, nr_cif, c1, c2, c3;

	do{
        scanf("%d", &nr);
        if(nr > 999)
            printf("Introduceti un numar intreg format din 3 cifre: ");
    }while(nr > 999);


	cifre(nr, &nr_cif, &c1, &c2, &c3);

	if(nr < 10)
        printf("Numarul are %d cifre, aceasta fiind %d.", nr_cif, c1);
    else if(nr < 100)
        printf("Numarul are %d cifre, aceseta fiind %d si %d.", nr_cif, c1, c2);
    else
        printf("Numarul are %d cifre, aceseta fiind %d, %d si %d.", nr_cif, c1, c2, c3);

	return 0;
}
