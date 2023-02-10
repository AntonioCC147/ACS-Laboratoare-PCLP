#include <stdio.h>

int main()
{
    int V[10], n, i, cresc = 1, descr = 1, consta = 1;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &V[i]);

    for(i = 1; i < n; i++)
    {
        if(V[i-1] >= V[i])
            cresc = 0;
        if(V[i-1] <= V[i])
            descr = 0;
        if(V[i-1] != V[i])
            consta = 0;
    }

    if(cresc == 1)
        printf("Sirul de numere este crescator.");
    else if(descr == 1)
        printf("Sirul de numere este descrescator.");
    else if(consta == 1)
        printf("Sirul de numere este constant.");
    else
        printf("Sirul de numere este unul oarecare.");

	return 0;
}
