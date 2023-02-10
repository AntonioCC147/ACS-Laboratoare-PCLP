#include <stdio.h>

int main()
{
	int v[100], n, i, p, aux;

    printf("Citeste n: ");
    scanf("%d", &n);

    printf("Tasteaza elementele vectorului: ");
    for(i = 0; i < n; i++)
        scanf("%d", &v[i]);

    printf("Citeste p: ");
    scanf("%d", &p);

    //Permutarea spre dreapta
    while(p)
    {
        aux = v[n-1];
        for(i = n - 2; i >= 0; i--)
            v[i+1] = v[i];
        v[0] = aux;
        p--;
    }

    printf("Noul vector:\n");
    for(i = 0; i < n; i++)
        printf("%d ", v[i]);

    /*Permutarea spre stanga
    while(p)
    {
        aux = v[0];
        for(i = 0; i < n; i++)
            v[i] = v[i+1];
        v[n-1] = aux;
        p--;
    }

    printf("Noul vector:\n");
    for(i = 0; i < n; i++)
        printf("%d ", v[i]);
    */

	return 0;
}
