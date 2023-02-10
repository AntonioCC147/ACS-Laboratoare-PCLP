#include <stdio.h>

void numere(int v[], int n, int *poz, int *neg, int *nule)
{
    *poz = *neg = *nule = 0;

    for(int i = 0; i < n; i++)
        if(v[i] == 0)
            (*nule)++;
        else if(v[i] > 0)
            (*poz)++;
        else
            (*neg)++;
}

int main()
{
	int v[10], n, i, poz, neg, nule;

	scanf("%d", &n);
	for(i = 0; i < n; i++)
        scanf("%d", &v[i]);

    numere(v, n, &poz, &neg, &nule);

    printf("In vector ser afla %d numere pozitive, %d numere negative si %d numere nule.", poz, neg, nule);

	return 0;
}
