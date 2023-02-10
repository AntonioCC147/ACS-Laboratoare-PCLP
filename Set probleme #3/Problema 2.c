#include <stdio.h>

int main()
{
    int v[100], n, contor, p[100] = {0}, np = 0, i[100] = {0}, ni = 0;

    printf("Citeste n: ");
    scanf("%d", &n);

    printf("Tasteaza elementele vectorului: ");
    for(contor = 0; contor < n; contor++)
        scanf("%d", &v[contor]);

    for(contor = 0; contor < n; contor++)
        if(v[contor] % 2 == 0)
            p[np++] = v[contor];
        else
            i[ni++] = v[contor];

    printf("Tabloul ce contine elementele pare este:\n");
    for(contor = 0; contor < np; contor++)
        printf("%d ", p[contor]);

    printf("\nTabloul ce contine elementele pare este:");
    for(contor = 0; contor < ni; contor++)
        printf("%d ", i[contor]);

    return 0;
}
