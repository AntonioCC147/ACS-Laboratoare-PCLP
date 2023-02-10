#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AUTOMOBIL{
    char marca[25], carburant, model[15];
    struct data{
        int luna, an;
    }d;
}A;

void citire(A V[], int *n){
    FILE *fis = fopen("fisier7.1", "wb");
    if(fis == NULL){ printf("Fisierul nu poate fi deschis!"); exit(1); }

    printf("Citeste un numar de la tastatura: "); scanf("%d", n); getchar();

    for(int i = 0; i < *n; i++){
        printf("\n# Automobil %d:\n", i+1);
        printf("Marca: "); gets(V[i].marca);
        printf("Carburant (B / M): "); scanf("%c", &V[i].carburant); getchar();
        printf("Model (berlina / break / decapotabila): "); gets(V[i].model);
        printf("Luna: "); scanf("%d", &V[i].d.luna);
        printf("An: "); scanf("%d", &V[i].d.an); getchar();
        fwrite(&V[i], sizeof(A), 1, fis);
    }

    fclose(fis);
}

void adaugare(A V[], int *n){
    FILE *fis = fopen("fisier7.1", "ab");
    if(fis == NULL){ printf("Fisierul nu poate fi deschis!"); exit(1); }

    printf("Tastati in continuare autovehicule. Daca nu mai doriti introducerea unor date, tastati 0 la marca.\n");
    while(1){
        printf("\n# Automobil %d:\n", *n+1);
        printf("Marca: "); gets(V[*n].marca);
        if(strcmp(V[*n].marca, "0") == NULL) break;
        printf("Carburant (B / M): "); scanf("%c", &V[*n].carburant); getchar();
        printf("Model (berlina / break / decapotabila): "); gets(V[*n].model);
        printf("Luna: "); scanf("%d", &V[*n].d.luna);
        printf("An: "); scanf("%d", &V[*n].d.an); getchar();
        fwrite(&V[*n], sizeof(A), 1, fis);
        (*n)++;
    }

    fclose(fis);
}

int gasire(A V[], int n, char marca[25], char carburant){
    for(int i = 0; i < n; i++){
        if(strcmp(V[i].marca, marca) == 0 && V[i].carburant == carburant)
            return 1;
    }

    return 0;
}
void creare(A V[], int n, A Auto5[], int *n1){
    *n1 = 0;

    for(int i = 0; i < n; i++)
        if(V[i].d.an <= 2018)
            Auto5[(*n1)++] = V[i];
}

void ordonare(A Auto5[], int n1){
    A aux;

    for(int i = 0; i < n1 - 1; i++)
        for(int j = i + 1; j < n1; j++)
            if(Auto5[i].d.an > Auto5[j].d.an){
                aux = Auto5[i]; Auto5[i] = Auto5[j]; Auto5[j] = aux;
            }

    for(int i = 0; i < n1 - 1; i++)
        for(int j = i + 1; j < n1; j++)
            if(Auto5[i].d.an == Auto5[j].d.an && Auto5[i].d.luna > Auto5[j].d.luna){
                aux = Auto5[i]; Auto5[i] = Auto5[j]; Auto5[j] = aux;
            }

    FILE *fis = fopen("fisier7.2", "wb");
    if(fis == NULL){ printf("Fisierul nu poate fi deschis!"); exit(1); }

    for(int i = 0; i < n1; i++)
        fread(&Auto5[i], sizeof(A), 1, fis);

    fclose(fis);
}

void afisare(A V[], int n, int an){
    for(int i = 0; i < n; i++)
        if(strcmp(V[i].model, "decapotabila") == 0 && V[i].d.an == an)
            printf("Marca: %s; Carburant: %c; Model: %s; Luna: %d; An: %d;\n", V[i].marca, V[i].carburant, V[i].model, V[i].d.luna, V[i].d.an);
}

int main()
{
    A V[10]; FILE *fis; int n;

    citire(V, &n);

    adaugare(V, &n);

    char marca[25], carburant;
    printf("\nTastati o marca: "); gets(marca);
    printf("Tastati un tip de carburant (B / M): "); scanf("%c", &carburant); getchar();
    gasire(V, n, marca, carburant);

    A Auto5[10]; int n1;
    creare(V, n, Auto5, &n1);

    ordonare(Auto5, n1);

    int an;
    printf("\nTastati un an de la tastatura: "); scanf("%d", &an);
    afisare(V, n, an);

	return 0;
}
