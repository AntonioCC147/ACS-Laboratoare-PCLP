#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ANGAJAT{
    char nume[50], firma[25];
    int varsta;
    struct{
        int nr_Ang;
        char localitate[25];
    }f;
}A;

typedef struct FIRME_LOCALITATE{
    char nume[50], firma[25];
}F;

void adaugare(A V[], int *n){
    FILE *fis = fopen("fisier8.1", "ab");
    if(fis == NULL){ printf("Fisierul nu poate fi deschis!"); exit(1); }

    printf("\nCiteste angajati in continuare. Daca doresti sa nu mai introduci, apasa tasta 0.\n");

    while(1){
        printf("\n# Angajat %d:\n", *n+1);
        printf("Nume: "); gets(V[*n].nume);
        if(strcmp(V[*n].nume, "0") == 0) break;
        printf("Varsta: "); scanf("%d", &V[*n].varsta); getchar();
        printf("Numele firmei: "); gets(V[*n].firma);
        printf("Numarul de angajati al firmei: "); scanf("%d", &V[*n].f.nr_Ang); getchar();
        printf("Localitatea din care este firma: "); gets(V[*n].f.localitate);
        fwrite(&V[*n], sizeof(A), 1, fis);
        (*n)++;
    }

    fclose(fis);
}

void gasire(A V[], int n){
    FILE *fis = fopen("fisier8.1", "rb"); if(fis == NULL){ printf("Fisierul nu poate fi deschis!"); exit(1); }
    fseek(fis, 0L, SEEK_END);
    n = ftell(fis) / sizeof(A);
    fseek(fis, 0L, SEEK_SET);
    fread(V, sizeof(A), n, fis);
    fclose(fis);

    A aux[10]; F L;

    for(int i = 0; i < n; i++)
        aux[i] = V[i];

    for(int i = 0; i < n; i++)
        if(strcmp(aux[i].f.localitate, "0") != 0){
            FILE *fis = fopen(aux[i].f.localitate, "wb"); if(fis == NULL){ printf("Fisierul nu poate fi deschis!"); exit(1); }
            strcpy(L.nume, V[i].nume); strcpy(L.firma, V[i].firma);
            fwrite(&L, sizeof(F), 1, fis);
            for(int j = i + 1; j < n; j++)
                if(strcmp(V[i].f.localitate, V[j].f.localitate) == 0){
                    strcpy(V[j].f.localitate, "0");
                    strcpy(L.nume, V[j].nume); strcpy(L.firma, V[j].firma);
                    fwrite(&L, sizeof(F), 1, fis);
                }
            fclose(fis);
        }
}

void ordonare(A V[], int n){
    FILE *fis = fopen("fisier8.1", "rb"); if(fis == NULL){ printf("Fisierul nu poate fi deschis!"); exit(1); }
    fseek(fis, 0L, SEEK_END);
    n = ftell(fis) / sizeof(A);
    fseek(fis, 0L, SEEK_SET);
    fread(V, sizeof(A), n, fis);
    fclose(fis);

    A aux;

    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if(V[i].f.nr_Ang > V[j].f.nr_Ang){
                aux = V[i]; V[i] = V[j]; V[j] = aux;
            }

    fis = fopen("fisier8.2", "wb"); if(fis == NULL){ printf("Fisierul nu poate fi deschis!"); exit(1); }
    fwrite(V, sizeof(A), n, fis);
    fclose(fis);
}

void ident_angaj(A V[], int *n, int Poz[]){
    FILE *fis = fopen("fisier8.1", "rb"); if(fis == NULL){ printf("Fisierul nu poate fi deschis!"); exit(1); }
    fseek(fis, 0L, SEEK_END);
    *n = ftell(fis) / sizeof(A);
    fseek(fis, 0L, SEEK_SET);
    fread(V, sizeof(A), *n, fis);
    fclose(fis);

    float S = 0.0, media;

    for(int i = 0; i < *n; i++)
        S = S + V[i].varsta;
    media = S / (*n);

    for(int i = 0; i < *n; i++)
        if(V[i].varsta < media)
            Poz[i] = 1;
}

void ident_firma(A V[], int n, int *max){
    FILE *fis = fopen("fisier8.1", "rb"); if(fis == NULL){ printf("Fisierul nu poate fi deschis!"); exit(1); }
    fseek(fis, 0L, SEEK_END);
    n = ftell(fis) / sizeof(A);
    fseek(fis, 0L, SEEK_SET);
    fread(V, sizeof(A), n, fis);
    fclose(fis);

    *max = 0;

    for(int i = 0; i < n; i++)
        if(V[i].f.nr_Ang > *max)
            *max = V[i].f.nr_Ang;
}

int main()
{
	FILE *fis = fopen("fisier8.1", "wb"); if(fis == NULL){ printf("Fisierul nu poate fi deschis!"); exit(1); }

	A V[10]; int n;

	printf("Citeste cati angajati doresti sa introduci de la tastatura: "); scanf("%d", &n); getchar();

	for(int i = 0; i < n; i++){
        printf("\n# Angajat %d:\n", i+1);
        printf("Nume: "); gets(V[i].nume);
        printf("Varsta: "); scanf("%d", &V[i].varsta); getchar();
        printf("Numele firmei: "); gets(V[i].firma);
        printf("Numarul de angajati al firmei: "); scanf("%d", &V[i].f.nr_Ang); getchar();
        printf("Localitatea din care este firma: "); gets(V[i].f.localitate);
	}

    fwrite(V, sizeof(A), n, fis);
    fclose(fis);

    int meniu;
	while(1){
        printf("\nDaca doresti sa mai adaugi persoane, tasteaza 1.\n");
        printf("Daca doresti sa gasesti toti angajatii din aceeasi localitate, tasteaza 2.\n");
        printf("Daca doresti sa ordonezi crescator firmele in functie de numarul de angajati, tasteaza 3.\n");
        printf("Daca doresti sa identifici angajatii cu varsta mai mica decat media, tasteaza 4.\n");
        printf("Daca doresti sa identifici firma cu cei mai multi angajati, tasteaza 5.\n");
        printf("Daca doresti sa inchizi meniul, tasteaza 0.\n");
        printf("Optiune: "); scanf("%d", &meniu); getchar();
        if(meniu == 1) adaugare(V, &n);
        else if(meniu == 2) gasire(V, n);
        else if(meniu == 3) ordonare(V, n);
        else if(meniu == 4){
            A Angaj; int Poz[10] = {0}, i; ident_angaj(V, &n, Poz);
            fis = fopen("fisier8.1", "rb"); if(fis == NULL){ printf("Fisierul nu poate fi deschis!"); exit(1); }
            printf("\nAngajati cu varsta mai mica decat media de varsta a tuturor angajatiilor:\n");
            for(i = 0; i < n; i++)
                if(Poz[i] == 1){
                    fseek(fis, sizeof(A) * i, SEEK_SET);
                    fread(&Angaj, sizeof(A), 1, fis);
                    printf("Nume: %s; Firma: %s; Varsta: %d;\n", Angaj.nume, Angaj.firma, Angaj.varsta);
                }
            fclose(fis);
        }
        else if(meniu == 5){
            int max; ident_firma(V, n, &max);
            printf("\nFirma / Firmele cu cea / cel mai mare numar de angajati: ");
            for(int i = 0; i < n; i++)
                if(V[i].f.nr_Ang == max)
                    printf("%s; ", V[i].firma);
            printf("\n");
        }
        else break;
	}

	return 0;
}
