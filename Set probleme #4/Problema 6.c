#include <stdio.h>

int main()
{
	int a[10][10], n, i, j, max, min;

	scanf("%d", &n);

	for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    min = max = a[0][0];

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
        {
            if(a[i][j] < min)
                min = a[i][j];
            if(a[i][j] > max)
                max = a[i][j];
        }

    for(i = 0; i < n; i++)
    {
        a[i][i] = max;
        a[i][n-i-1] = min;
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

	return 0;
}
