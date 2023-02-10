#include <stdio.h>

int main()
{
	int v[10], n, i;

	scanf("%d", &n);

	for(i = 0; i < n; i++)
        scanf("%d", &v[i]);

    int secv = 1, secv_max = 1;

    for(i = 1; i < n; i++)
    {
        if(v[i-1] < v[i])
        {
            secv++;
            if(secv > secv_max)
                secv_max = secv;
        }
        else
            secv = 1;
    }

    printf("Cea mai lunga secventa este %d.", secv_max);

	return 0;
}
