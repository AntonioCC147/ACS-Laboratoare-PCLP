#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct magazin{
    char denumire[25];
    int nr_Produse;
    struct{
        char nume_Firma[25];
        int cantitate;
        float pret;
    }p[20];
}produs;

typedef struct lisa_cumparaturi{
    char denumire[25];
    int cantitate;
}LISTA;

void functie1(produs entitate){
    produs aux;

    for(int i = 0; i < entitate.nr_Produse - 1; i++)
        for(int j = i + 1; j < entitate.nr_Produse; j++)
            if(entitate.p[i].cantitate > entitate.p[j].cantitate){
                aux.p[0].cantitate = entitate.p[i].cantitate; entitate.p[i].cantitate = entitate.p[j].cantitate; entitate.p[j].cantitate = aux.p[0].cantitate;
            }
}

void functie2(char denumire[25], int cantitate, produs *satisfacator, int *ID, int *gasit){
    FILE *fis = fopen("magazin.dat", "rb");
    if(fis == NULL){ printf("Fisierul nu poate fi deschis!"); exit(1); }

    fseek(fis, 0L, SEEK_END);
    int n = ftell(fis) / sizeof(produs);
    fseek(fis, 0L, SEEK_SET);

    produs M[50];
    fread(M, sizeof(produs), n, fis);
    fclose(fis);

    *gasit = 0; int i, j;
    for(i = 0; i < n; i++)
        if(strcmp(M[i].denumire, denumire) == 0){
            *gasit = 1; functie1(M[i]);

            float pret_minim = 0.0; *ID = 0;
            for(j = 0; j < M[i].nr_Produse; j++)
                if(M[i].p[j].cantitate >= cantitate){
                    *satisfacator = M[i]; pret_minim = M[i].p[j].pret; *ID = j; break;
                }

            for(j = 0; j < M[i].nr_Produse; j++)
                if(M[i].p[j].cantitate >= cantitate && M[i].p[j].pret < pret_minim){
                    *satisfacator = M[i]; pret_minim = M[i].p[j].pret; *ID = j;
                }

            if(pret_minim == 0.0) *gasit = 0;
            break;
        }
}

int main()
{
    FILE *fis = fopen("lista.txt", "rt");
    if(fis == NULL){ printf("Fisierul nu poate fi deschis!"); exit(1); }

    LISTA L[25]; int n = 0;

    while(!feof(fis)){
        fscanf(fis, "%s%d", &L[n].denumire, &L[n].cantitate); n++;
    }

    fclose(fis);

    fis = fopen("bon.dat", "wb");
    if(fis == NULL){ printf("Fisierul nu poate fi deschis!"); exit(1); }

    produs satisfacator; int gasit, ID; float cost = 0.0;
    for(int i = 0; i < n; i++){
        functie2(L[i].denumire, L[i].cantitate, &satisfacator, &ID, &gasit);
        if(gasit == 1){
            fwrite(&satisfacator.denumire, sizeof(char), 1, fis); fwrite(&satisfacator.p[ID].nume_Firma, sizeof(char), 1, fis);
            fwrite(&satisfacator.p[ID].cantitate, sizeof(int), 1, fis);
            float cost_prod = satisfacator.p[ID].cantitate * satisfacator.p[ID].pret; fwrite(&cost_prod, sizeof(float), 1, fis);
            cost = cost + cost_prod;
        }
        else{
            int val;
            do{
                printf("Produsul %s nu se gaseste in magazin sau nu este suficient stoc disponibil.\n", L[i].denumire);
                printf("Daca doriti sa renuntati, apasati 0, altfel, apasati 1: "); scanf("%d", &val); getchar();
            }while(val != 0 && val != 1);
            if(val == 0) exit(1);
        }
    }

    printf("\nCostul total al produselor cumparate este: %.2f.", cost);

    fclose(fis);

	return 0;
}
