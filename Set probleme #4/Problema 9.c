#include <stdio.h>

int main()
{
	int v[10], n, i, j;

	scanf("%d", &n);

	scanf("%d", &v[0]); i = 1;

	do{
        scanf("%d", &v[i]);

        if(v[i] < v[i-1])
            printf("Introduceti numerele in ordine crescatoare: ");
        else
            i++;

	}while(i < n);

	int nr;

	scanf("%d", &nr); n++;

	for(i = 0; i < n; i++)
        if(v[i] > nr)
        {
            for(j = n; j > i; j--)
                v[j] = v[j-1];
            v[i] = nr;
            i = n;
        }

    for(i = 0; i < n; i++)
        printf("%d ", v[i]);

	return 0;
}
