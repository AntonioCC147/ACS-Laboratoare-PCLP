#include <stdio.h>

void permut(float v[], int n)
{
    int i; float aux;

    aux = v[n-1];
    for(i = n - 1; i >= 0; i--)
        v[i] = v[i-1];
    v[0] = aux;
}

int main()
{
	float M[10][10]; int n, m, i, j;

	scanf("%d%d", &n, &m);

	for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%f", &M[i][j]);

    for(i = 0; i < n; i++)
    {
        j = i;
        while(j)
        {
            permut(M[i], m);
            j--;
        }
    }

	for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            printf("%.f ", M[i][j]);
        printf("\n");
    }

	return 0;
}
