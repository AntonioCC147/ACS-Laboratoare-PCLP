#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char sir[25];
    int valoare;
}STRUCT;

void functie(int A[], int n, int B[], int m, int C[], int *p){
    *p = 0;

    for(int i = 0; i < n; i++)
        if(A[i] > 0) C[(*p)++] = i;

    for(int i = 0; i < m; i++)
        if(B[i] == 0) C[(*p)++] = i;
}

int main()
{
    STRUCT V[25]; int A[25], B[25], C[50], n, m, i, j; int k;

    printf("Citeste numarul intreg si pozitiv n: "); scanf("%d", &n);
    printf("Citeste numarul intreg si pozitiv m: "); scanf("%d", &m);

    FILE *fis = fopen("fis_binar.dat", "rb");
    if(fis == NULL){ printf("Fisierul nu poate fi deschis!"); exit(1); }

    fread(A, sizeof(int), n, fis);
    fread(B, sizeof(int), m, fis);

    fclose(fis);

    int p;
    functie(A, n, B, m, C, &p);
    if(p == 0){
        printf("Vectorul nu a putut fi construit."); exit(1);
    }

    int numar;
    printf("\nCu cate fisiere text doresti sa lucram? Citeste un numar intreg si strict pozitiv: "); scanf("%d", &numar);

    char nume_fisier[25], linie[81], sir[25]; k = 0;
    for(i = 0; i < numar; i++){
        printf("Citeste numele fisierului: "); gets(nume_fisier);
        FILE *fis = fopen(nume_fisier, "rt");
        if(fis == NULL){ printf("Fisierul citit nu a putut fi deschis!\n"); }
        else if(C[i] != 0){
            for(j = 0; j < p && !feof(nume_fisier); j++)
                fgets(linie, 80, fis);
            for(j = 0; j < p; j++)
                sir[j] = linie[C[j]];
            sir[j] = '\0';
            strcpy(V[k].sir, sir); V[k].valoare = p; k++;
            fclose(fis);
        }
    }
    if(k != 0){
        fis = fopen("binar-rezultat", "wb");
        if(fis == NULL){ printf("Fisierul nu poate fi deschis!"); exit(1); }
        fwrite(V, sizeof(STRUCT), k, fis);
        fclose(fis);
    }

	return 0;
}
