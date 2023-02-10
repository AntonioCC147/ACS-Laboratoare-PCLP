#include <stdio.h>

int main()
{
    int v[100], n, i, j, aux, verif1 = 1, verif2 = 1;

    printf("Citeste n: ");
    scanf("%d", &n);

    printf("Tasteaza elementele vectorului: ");
    for(i = 0; i < n; i++)
        scanf("%d", &v[i]);

    for(i = 0; i < n; i++)
        for(j = i + 1; j < n; j++)
            if(v[i] > v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }

    for(i = 1; i < n; i++)
        if(v[i] != v[0])
            verif1 = 0;

    for(i = 0; i < n; i++)
        if(v[i] == v[i+1])
            verif2 = 0;

    if(verif1 == 1)
        printf("Toate elementele tabloului sunt egale.");
    else if(verif2 == 1)
        printf("Toate elementele tabloului sunt diferite.");
    else
        printf("Oarecare.");

    return 0;
}
