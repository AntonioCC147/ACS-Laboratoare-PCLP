#include <stdio.h>

int main()
{
    int v[10], n, i, poz[10], p;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &v[i]);

    scanf("%d", &p);

    for(i = 0; i < p; i++)
        scanf("%d", &poz[i]);

    for(i = 0; i < p; i++)
        printf("%d ", v[poz[i]]);

	return 0;
}
