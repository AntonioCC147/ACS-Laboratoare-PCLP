#include <stdio.h>

int main()
{
	int v[10], n, i, j, aux, min, poz_min, max, poz_max;

	scanf("%d", &n);

	for(i = 0; i < n; i++)
        scanf("%d", &v[i]);

    min = max = v[0]; poz_min = poz_max = 0;

    for(i = 1; i < n; i++)
	{
	    if(v[i] < min)
        {
            min = v[i]; poz_min = i;
        }
        if(v[i] > max)
        {
            max = v[i]; poz_max = i;
        }
	}

	if(poz_min == poz_max - 1 || poz_min == poz_max + 1)
        printf("Nu se poate ordona.");
    else
    {
        for(i = poz_min; i < poz_max; i++)
            for(j = poz_min + 1; j < poz_max - 1; j++)
                if(v[i] < v[j])
                {
                    aux = v[i];
                    v[i] = v[j];
                    v[j] = aux;
                }

        for(i = 0; i < n; i++)
            printf("%d ", v[i]);
    }

	return 0;
}
