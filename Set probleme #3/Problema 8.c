#include <stdio.h>

int main()
{
	int a[10][10], m, n, b[10][10], p, q, i, j, k, c[10][10] = {0}, d[10][10] = {0};

    printf("Citeste m: ");
    scanf("%d", &m);
    printf("Citeste n: ");
    scanf("%d", &n);

    printf("Tasteaza elementele matricei a: ");
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Citeste p: ");
    scanf("%d", &p);
    printf("Citeste q: ");
    scanf("%d", &q);

    printf("Tasteaza elementele matricei b: ");
    for(i = 0; i < p; i++)
        for(j = 0; j < q; j++)
            scanf("%d", &b[i][j]);

    if(m != p || n != q)
        printf("Nu se poate efectua a + b.");
    else
    {
        for(i = 0; i < m; i++)
            for(j = 0; j < n; j++)
                c[i][j] = a[i][j] + b[i][j];

        printf("a+b=\n");
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
                printf("%d ", c[i][j]);
            printf ("\n");
        }
    }

    if(n != p)
        printf("Nu se poate efectua a + b.");
    else
    {
        for(i = 0; i < m; i++)
            for(j = 0; j < p; j++)
                for(k = 0; k < n; k++)
                    d[i][j] = d[i][j] + a[i][k] * b[k][j];

        printf("a*b=\n");
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
                printf("%d ", d[i][j]);
            printf ("\n");
        }
    }

	return 0;
}
