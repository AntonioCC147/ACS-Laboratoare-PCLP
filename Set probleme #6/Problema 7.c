#include <stdio.h>

void construct(unsigned a[], int n1, unsigned par[], int *n2, unsigned imp[], int *n3)
{
    *n2 = *n3 = 0;

    for(int i = 0; i < n1; i++)
        if(a[i] % 2 == 0)
            par[(*n2)++] = a[i];
        else
            imp[(*n3)++] = a[i];
}

int main()
{
	unsigned v[10], par[10], imp[10];
	int n1, n2, n3, i;

	scanf("%d", &n1);
	for(i = 0; i < n1; i++)
        scanf("%d", &v[i]);

    construct(v, n1, par, &n2, imp, &n3);

    for(i = 0; i < n2; i++)
        printf("%d ", par[i]);

    printf("\n");

    for(i = 0; i < n3; i++)
        printf("%d ", imp[i]);

	return 0;
}
