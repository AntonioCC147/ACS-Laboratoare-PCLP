#include <stdio.h>

void max_imp(int v[], int n, int *max)
{
    *max = v[0];

    for(int i = 1; i < n; i++)
        if(v[i] % 2 == 1 && v[i] > *max)
            *max = v[i];
}

int main()
{
	int v[10], n, maxim, i;

	scanf("%d", &n);
	for(i = 0; i < n; i++)
        scanf("%d", &v[i]);

    max_imp(v, n, &maxim);

    printf("%d", maxim);

	return 0;
}
