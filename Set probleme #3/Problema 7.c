#include <stdio.h>

int main()
{
	int a[10][10], n, i, j;

	printf("Citeste numarul n: ");
	scanf("%d", &n);

	printf("Citeste tabloul: ");
	for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    ///a)
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    ///b)
    ///Diagonala principala:
    printf("Elementele de pe diagonala principala sunt: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i][i]);
    printf("\n");

    ///Diagonala secundara:
    printf("Elementele de pe diagonala secundara sunt: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i][n-i-1]);
    printf("\n");

    ///c)
    ///Triunghiul superior:
    printf("Elementele triunghiului superior: ");
    for(i = 0; i < n; i++)
        for(j = i + 1; j < n; j++)
            printf("%d ", a[i][j]);
    printf("\n");

    ///Triunghiul superior:
    printf("Elementele triunghiului inferior: ");
    for(i = 0; i < n; i++)
        for(j = 0; j < i; j++)
            printf("%d ", a[i][j]);
    printf("\n");

    ///d)
    ///Conturul matricei:
    printf("Elementele de pe conturul matricei: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[0][i]);
    for(i = 1; i < n; i++)
        printf("%d ", a[i][n-1]);
    for(i = n - 2; i >= 0; i--)
        printf("%d ", a[n-1][i]);
    for(i = n - 2; i > 0; i--)
        printf("%d ", a[i][0]);
    printf("\n");

    ///Interiorul matricei:
    printf("Elementele din interiorul matricei: ");
    for(i = 1; i < n - 1; i++)
        for(j = 1; j < n - 1; j++)
            printf("%d ", a[i][j]);
    printf("\n");

    ///e)
    printf("Elementele afisate in spirala:\n");
    int l1 = 0, ln = n, c1 = 0, cn = n;

    while(n - 1)
    {
        for(i = c1; i < cn; i++)
            printf("%d ", a[l1][i]);
        l1++;
        for(i = l1; i < ln; i++)
            printf("%d ", a[i][cn-1]);
        cn--;
        for(i = cn - 1; i >= c1; i--)
            printf("%d ", a[ln-1][i]);
        ln--;
        for(i = ln - 1; i >= l1; i--)
            printf("%d ", a[i][c1]);
        c1++;
        n--;
    }

	return 0;
}
