#include <stdio.h>

int main()
{
	int m[10][10], n, i, j, c1, c2, l1, l2, aux;

    printf("Citeste n: ");
    scanf("%d", &n);

    printf("Tasteaza elementele matricei: ");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &m[i][j]);

    //Modificare pe coloane
    printf("Citeste c1: ");
    scanf("%d", &c1);
    printf("Citeste c2: ");
    scanf("%d", &c2);

    for(i = 0; i < n; i++)
    {
        aux = m[i][c1];
        m[i][c1] = m[i][c2];
        m[i][c2] = aux;
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }

    /*Modificare pe linii
    printf("Citeste l1: ");
    scanf("%d", &l1);
    printf("Citeste l2: ");
    scanf("%d", &l2);

    for(j = 0; j < n; j++)
    {
        aux = m[l1][j];
        m[l1][j] = m[l2][j];
        m[l2][j] = aux;
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
    */

	return 0;
}
