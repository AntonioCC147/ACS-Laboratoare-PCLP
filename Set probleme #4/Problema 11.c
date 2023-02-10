#include <stdio.h>

int main()
{
	int a[10][10], n, i, j, k, aux;

	scanf("%d", &n);

	for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    ///Ordonarea crescatoare a liniilor:
    /**
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            for(k = j + 1; k < n; k++)
                if(a[i][j] > a[i][k])
                {
                    aux = a[i][j];
                    a[i][j] = a[i][k];
                    a[i][k] = aux;
                }
    **/

    ///Ordonarea descrescatoare a liniilor:
    /**
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            for(k = j + 1; k < n; k++)
                if(a[i][j] < a[i][k])
                {
                    aux = a[i][j];
                    a[i][j] = a[i][k];
                    a[i][k] = aux;
                }
    **/

    ///Ordonarea crescatoare a coloanelor:
    /**
    for(j = 0; j < n; j++)
        for(i = 0; i < n; i++)
            for(k = i + 1; k < n; k++)
                if(a[i][j] > a[k][j])
                {
                    aux = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = aux;
                }
    **/

    ///Ordonarea descrescatoare a coloanelor:
    /**
    for(j = 0; j < n; j++)
        for(i = 0; i < n; i++)
            for(k = i + 1; k < n; k++)
                if(a[i][j] < a[k][j])
                {
                    aux = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = aux;
                }
    **/

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

	return 0;
}
