#include <stdio.h>

int main()
{
    float val1, val2, val3;

    scanf("%f%f", &val1, &val2);

    //a)
    printf("%.3f %.3f\n", val1, val2);
    printf("%.5f %.5f\n", val1, val2);
    printf("%.2f %.2f\n", val1, val2);

    //b)
    printf("%e %e\n", val1, val2);

    //c)
    printf("%d\n", val1+val2);
    //Programul va afisa drept rezultat un numar care nu reprezinta nici pe departe suma dintre cele 2 valori.

    //d)
    scanf("%d", &val3);
    printf("%f\n", val3);
    //Programul nu va retine numarul corect si deci, la o posibila afisare vor aparea pe ecran anumite simboluri, sau alte valori.

    //e)
    printf("%4.3f", 5.);

    return 0;
}
