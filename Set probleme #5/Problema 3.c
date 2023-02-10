#include <stdio.h>

void analiza(int n1, int n2, int n3, char *rez)
{
    if(n1 < n2 && n2 < n3)
        *rez = 'C';
    else if(n1 > n2 && n2 > n3)
        *rez = 'D';
    else if(n1 == n2 && n2 == n3)
        *rez = 'I';
    else
        *rez = 'N';
}

int main()
{
    int n, i, nr1, nr2, nr3; char rezultat;

    printf("Cate seturi de numere doriti sa verificati? ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        printf("Tastati setul cu numarul %d: ", i);
        scanf("%d%d%d", &nr1, &nr2, &nr3);

        analiza(nr1, nr2, nr3, &rezultat);
        printf("Rezultatul setului %d este: %c.\n", i, rezultat);
    }

	return 0;
}
