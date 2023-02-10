#include <stdio.h>

void citeste(int v[], int n)
{
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
}

void adaugare(int v1[], int v2[], int n1, int n2)
{
    for(int i = 0; i < n2; i++)
        v1[n1+i] = v2[i];
}

int main()
{
	int n1, n2, i;

	scanf("%d%d", &n1, &n2);

	int *v1 = (int *)malloc(n1 * sizeof(int));
    int *v2 = (int *)malloc(n2 * sizeof(int));

    if(v1 == NULL || v2 == NULL)
    {
        printf("Alocare esuata");
        exit(1);
    }

    citeste(v1, n1); citeste(v2, n2);

    if(n1 > n2)
    {
        v1 = (int *)realloc(v1, (n1 + n2) * sizeof(int));
        adaugare(v1, v2, n1, n2);
        for(i = 0; i < n1 + n2; i++)
            printf("%d ", v1[i]);
    }
    else
    {
        v2 = (int *)realloc(v2, (n2 + n1) * sizeof(int));
        adaugare(v2, v1, n2, n1);
        for(i = 0; i < n2 + n1; i++)
            printf("%d ", v2[i]);
    }

	return 0;
}
