#include <stdio.h>
#include <string.h>

struct informatie
{
    char firma[25], produs[25];
    int cantitate;
};

int main()
{
	struct informatie V[6];

	int n, i;

	printf("Citeste numarul de firme pe care doriti sa le introduceti: ");
	scanf("%d", &n);

	for(i = 0; i < n; i++)
    {
        printf("Cititi datele despre firma cu numarul %d.\n", i+1); getchar();
        printf("Nume: "); gets(V[i].firma);
        printf("Produs: "); gets(V[i].produs);
        printf("Cantitate: "); scanf("%d", &V[i].cantitate);
    }

    ///a)
    char produs1[25], firma_max[25] = ""; int cant_max = 0;
    printf("Tastati produsul pe care doriti sa-l cautati: "); getchar(); gets(produs1);

	for(i = 0; i < n; i++)
        if(stricmp(V[i].produs, produs1) == 0)
            if(V[i].cantitate > cant_max)
            {
                cant_max = V[i].cantitate;
                strcpy(firma_max, V[i].firma);
            }

    if(cant_max == 0)
        printf("Nicio firma nu detine produsul cautat.\n");
    else
        printf("Firma care contine cel mai mult produsul cautat este %s.\n", firma_max);

    ///b)
    char produs2[25]; int cant = 0;
    printf("Tastati produsul al carei cantitate doriti sa o aflati: "); gets(produs2);

    for(i = 0; i < n; i++)
        if(stricmp(V[i].produs, produs2) == 0)
            cant = cant + V[i].cantitate;

    if(cant == 0)
        printf("Nicio firma nu detine produsul cautat.\n");
    else
        printf("Cantitatea totala a produsului cautat este %d.", cant);

	return 0;
}
