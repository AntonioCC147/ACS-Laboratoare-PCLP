#include <stdio.h>

int main()
{
    int v[100], n, i;

    printf("Citeste n: ");
    scanf("%d", &n);

    printf("Tasteaza elementele vectorului: ");
    for(i = 0; i < n; i++)
        scanf("%d", &v[i]);

    //a)
    int prag;

    printf("Citeste pragul: ");
    scanf("%d", &prag);

    for(i = 0; i < n; i++)
        if(v[i] > prag)
            printf("Valoarea %d depaseste pragul. Aceasta se afla pe pozitia %d.\n", v[i], i+1);

    //b)
    printf("Valorile ce se afla pe pozitiile pare sunt: ");
    for(i = 0; i < n; i++)
        if((i + 1) % 2 == 0)
            printf("%d ", v[i]);
    printf("\n");

    //c)
    int j, k = 0;

    for(i = 0; i < n; i++)
        if(v[i] == 0)
        {
            for(j = i; j < n - 1; j++)
                v[j] = v[j+1];
            i--; n--; k = 1;
        }

    if(k == 1)
    {
        printf("Noul tablou este: ");
            for(i = 0; i < n; i++)
                printf("%d ", v[i]);
        printf("\n");
    }
    else
        printf("Taboul nu contine nicio valoare nula.\n");

    //d)
    int div, nr_div;

    for(i = 0; i < n; i++)
    {
        nr_div = 0;
        for(div = 2; div <= v[i] / 2; div++)
            if(v[i] % div == 0)
                nr_div++;
        v[i] = nr_div;
    }

    printf("Noul tablou este: ");
        for(i = 0; i < n; i++)
            printf("%d ", v[i]);

    return 0;
}
