#include <stdio.h>

int main()
{
	int v[10], n, i;

	scanf("%d", &n);

	for(i = 0; i < n; i++)
        scanf("%d", &v[i]);

    ///a)
    int S = 0; float val_medie;

    for(i = 0; i < n; i++)
        S = S + v[i];

    val_medie = (float)S / n;

    for(i = 0; i < n; i++)
        if(val_medie == v[i])
        {
            printf("Valorea medie se gaseste in tablou.\n");
            i = n;
        }

    if(i != n + 1)
        printf("Valoarea nu se gaseste in tablou.\n");

    ///b)
    int minim = v[0], poz_minim;

    for(i = 1; i < n; i++)
        if(v[i] < minim)
        {
            minim = v[i];
            poz_minim = i + 1;
        }

    printf("Valoarea minima este %d si se afla pe pozitia %d.", minim, poz_minim);

	return 0;
}
