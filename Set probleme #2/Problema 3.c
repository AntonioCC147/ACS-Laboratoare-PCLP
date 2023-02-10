#include <stdio.h>

int main()
{
    int numar, OK = 1;

    scanf("%d", &numar);

    for(int div = 2; div <= numar / 2; div++)
        if(numar % div == 0)
            OK = 0;

    if(OK == 1)
        printf("Numarul este prim.");
    else
        printf("Numar nu este prim.");

    return 0;
}
