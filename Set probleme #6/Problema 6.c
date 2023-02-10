#include <stdio.h>

void eliminare(int v[], int *n)
{
    int prim = v[0], i, j;

    for(i = 0; i < *n; i++)
        if(v[i] == prim)
        {
            for(j = i; j < *n; j++)
                v[j] = v[j+1];
            (*n)--; i--;
        }
}

int main()
{
	int v[10], n, i;

	scanf("%d", &n);
	for(i = 0; i < n; i++)
        scanf("%d", &v[i]);

    eliminare(v, &n);

	for(i = 0; i < n; i++)
        printf("%d ", v[i]);

	return 0;
}
