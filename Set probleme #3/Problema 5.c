#include <stdio.h>

int main()
{
    int v[100], u[100] = {0}, n, i, j, k, l = 0;

    printf("Citeste n: ");
    scanf("%d", &n);

    printf("Tasteaza elementele vectorului: ");
    for(i = 0; i < n; i++)
        scanf("%d", &v[i]);

    for(i = 0; i < n; i++)
    {
        k = 1;
        for(j = 0; j < i; j++)
            if(v[i] == v[j] && i != j)
                k = 0;
        if(k == 1)
            u[l++] = v[i];
    }

    printf("Noul vector este:\n");
    for(i = 0; i < l; i++)
        printf("%d ", u[i]);

    return 0;
}
