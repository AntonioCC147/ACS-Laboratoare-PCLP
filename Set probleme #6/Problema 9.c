#include <stdio.h>

int main()
{
	int a[10][10], m, n, i, j, S = 0, maxim = 0, L, C;

	scanf("%d%d", &m, &n);

	for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

	for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
        {
            S = S + a[i][j];
            if(S > maxim)
            {
                maxim = S;
                L = i; C = j;
            }
        }

    printf("Suma maxima se gaseste pana la linia %d si coloana %d.", L, C);

	return 0;
}
