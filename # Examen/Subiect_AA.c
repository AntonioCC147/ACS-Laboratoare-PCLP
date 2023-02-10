#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct client{
    char nume[50];
    float debit, credit;
    int cod_client;
}C;

void functie1(C B[], int n2, int *cmax){
    *cmax = 0;

    for(int i = 0; i < n2; i++)
        if(B[i].cod_client > *cmax)
            *cmax = B[i].cod_client;
}

void functie2(C A[], int n1, C B[], int n2, C C1[], int *nc1, C CC[], int *ncc, C C2[], int *nc2){
    *nc1 = *ncc = *nc2 = 0;

    for(int i = 0; i < n1; i++)
        for(int j = 0; j < n2; j++)
            if(strcmp(A[i].nume, B[j].nume) == 0){
                strcpy(CC[*ncc].nume, A[i].nume); CC[*ncc].debit = A[i].debit + B[j].debit; CC[*ncc].credit = A[i].credit + B[j].credit; CC[*ncc].cod_client = B[j].cod_client;
                strcpy(A[i].nume, "NULL"); strcpy(B[j].nume, "NULL"); (*ncc)++; break;
            }

    for(int i = 0; i < n1; i++)
        if(strcmp(A[i].nume, "NULL") != 0)
            C1[(*nc1)++] = A[i];

    for(int i = 0; i < n2; i++)
        if(strcmp(B[i].nume, "NULL") != 0)
            C2[(*nc2)++] = B[i];
}

int main()
{
	C A[10], B[10];

	FILE *fis1 = fopen("fisierAA1.txt", "rt"), *fis2 = fopen("fisierAA2.txt", "rt");
    if(fis1 == NULL || fis2 == NULL){ printf("Fisierul nu poate fi deschis!"); exit(1); }

    int n1 = 0;
    while(!feof(fis1)){
        fscanf(fis1, "%s%f%f%d", &A[n1].nume, &A[n1].debit, &A[n1].credit, &A[n1].cod_client); n1++;
    }

    int n2 = 0;
    while(!feof(fis2)){
        fscanf(fis2, "%s%f%f%d", &B[n2].nume, &B[n2].debit, &B[n2].credit, &B[n2].cod_client); n2++;
    }

    fclose(fis1); fclose(fis2);

    int cmax;
    functie1(B, n2, &cmax);

    C C1[10], CC[10], C2[10]; int nc1, ncc, nc2;
    functie2(A, n1, B, n2, C1, &nc1, CC, &ncc, C2, &nc2);

    FILE *fis3 = fopen("fisierAA3", "wb");
    if(fis3 == NULL){ printf("Fisierul nu poate fi deschis!"); exit(1); }

    for(int i = 0; i < nc2; i++)
        fwrite(&C2[i], sizeof(C), 1, fis3);

    for(int i = 0; i < ncc; i++)
        fwrite(&CC[i], sizeof(C), 1, fis3);

    for(int i = 0; i < nc1; i++){
        C1[i].cod_client = cmax + i + 1;
        fwrite(&C1[i], sizeof(C), 1, fis3);
    }

    fseek(fis3, 0L, SEEK_END);
    int nr = ftell(fis3) / sizeof(C);
    printf("Numarul final de clienti este: %d.\n", nr);

    fclose(fis3);

	return 0;
}
