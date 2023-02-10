#include <stdio.h>

void identice(int a[], int n1, int b[], int n2, int *k)
{
    int i, j, aux; *k;

    for(i = 0; i < n1; i++)
        for(j = i + 1; j < n1; j++)
            if(a[i] > a[j])
            {
                aux = a[i]; a[i] = a[j]; a[j] = aux;
            }

    for(i = 0; i < n2; i++)
        for(j = i + 1; j < n2; j++)
            if(b[i] > b[j])
            {
                aux = b[i]; b[i] = b[j]; b[j] = aux;
            }

    if(n1 == n2)
    {
        for(i = 0; i < n1; i++)
            if(a[i] != b[i])
            {
                *k = 0; i = n1;
            }
    }
    else
        *k = 0;
}

int main()
{
	int n1, m1, n2, m2, i, j, verif = 1;

	printf("Numarul de elementele ale lui M1: ");
	scanf("%d%d", &n1, &m1);

	int *M1 = (int *) malloc(n1 * m1 * sizeof(int));
	if(M1 == NULL)
	{
        printf("NU s-a putut aloca dinamic.");
        exit(1);
    }

	printf("Elementele matricei M1: ");
	for(i = 0; i < n1 * m1; i++)
            scanf("%d", &M1[i]);

	printf("Numarul de elementele ale lui M2: ");
	scanf("%d%d", &n2, &m2);

	int *M2 = (int *) malloc(n2 * m2 * sizeof(int));
	if(M2 == NULL)
	{
        printf("NU s-a putut aloca dinamic.");
        exit(1);
    }

	printf("Elementele matricei M2: ");
	for(i = 0; i < n2 * m2; i++)
            scanf("%d", &M2[i]);

    identice(M1, n1*m1, M2, n2*m2, &verif);

    if(verif == 0)
        printf("Nu sunt identice toate elementele.");
    else
        printf("Toate elementele sunt identice.");

	return 0;
}
