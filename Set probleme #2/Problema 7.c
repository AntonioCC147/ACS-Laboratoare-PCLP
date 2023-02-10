#include <stdio.h>

int main()
{
    int n;

    printf("Introduceti de la tastatura un numar natural: ");

    do
    {
        scanf("%d", &n);
        if(n < 0)
            printf("Un numar natural nu poate fi negativ.\n");
    }while(n < 0);

    return 0;
}
