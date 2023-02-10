#include <stdio.h>

void consecutive(int v[], int n, int *nr)
{
    *nr = 0;

    for(int i = 1; i < n; i++)
        if(v[i-1] < v[i])
            (*nr)++;
}

int main()
{
	int v[10], n, nr, i;

	scanf("%d", &n);
	for(i = 0; i < n; i++)
        scanf("%d", &v[i]);

    consecutive(v, n, &nr);

    printf("%d", nr);

	return 0;
}
