#include <stdio.h>

int verificare(int L[], int dim)
{
    for(int i = 1; i < dim - 1; i++)
        if(L[i-1] >= L[i] && L[i] <= L[i+1])
            return 0;
        else if(L[i-1] <= L[i] && L[i] >= L[i+1])
            return 0;
        else if(L[i-1] == L[i])
            return 0;

    return 1;
}

int main()
{
	int a[10][10], n, m, i, j, k = 0;

	scanf("%d%d", &n, &m);

	for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &a[i][j]);

    int a_nou[10][10];

    for(i = 0; i < n; i++)
        if(verificare(a[i], m) == 1)
        {
            for(j = 0; j < m; j++)
                a_nou[k][j] = a[i][j];
            k++;
        }

    for(i = 0; i < k; i++)
    {
        for(j = 0; j < m; j++)
            printf("%d ", a_nou[i][j]);
        printf("\n");
    }

	return 0;
}
