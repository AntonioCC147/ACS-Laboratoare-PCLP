#include <stdio.h>

void poz_min(int v[], int n, int min[], int *k)
{
    int minim = v[0], i; *k = 0;

    for(i = 0; i < n; i++)
        if(v[i] < minim)
            minim = v[i];

    for(i = 0; i < n; i++)
        if(v[i] == minim)
            min[(*k)++] = i;
}

int main()
{
	int v[10], n1, i, min[10], n2;

	scanf("%d", &n1);
	for(i = 0; i < n1; i++)
        scanf("%d", &v[i]);

    poz_min(v, n1, min, &n2);

    for(i = 0; i < n2; i++)
        printf("%d ", min[i]);

	return 0;
}
