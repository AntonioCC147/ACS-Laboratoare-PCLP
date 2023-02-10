#include <stdio.h>

int main()
{
	int a[10], b[10], c[20] = {0}, n, m, i, j, k;

	scanf("%d", &n);

	for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

	scanf("%d", &m);

	for(j = 0; j < m; j++)
        scanf("%d", &b[j]);

    i = j = k = 0;

    while(i < n || j < m)
    {
        if(a[i] % 2 == 0) i++;
        if(b[i] % 2 == 0) j++;

        if(a[i] < b[j])
        {
            c[k++] = a[i];
            i++;
        }
        else
        {
            c[k++] = b[j];
            j++;
        }
    }

    for(i = 0; i < k; i++)
        printf("%d ", c[i]);

	return 0;
}
