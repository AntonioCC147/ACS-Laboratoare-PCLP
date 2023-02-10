///Problema facuta DOAR cu fisiere binare
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct persoana{
    char nume[25], prenume[50];
    float varsta;
}P;

int main()
{
	P V[10]; int n = 2, i;

	///a) Citire
	for(i = 0; i < n; i++){
        printf("# Persoana %d:\n", i+1);
        printf("Nume: "); gets(V[i].nume);
        printf("Prenume: "); gets(V[i].prenume);
        printf("Varsta: "); scanf("%f", &V[i].varsta);
        printf("\n"); getchar();
	}

	FILE *fis = fopen("fisier6", "wb");
	if(fis == NULL){ printf("Fisierul nu s-a putut deschide!"); exit(1); }

	for(i = 0; i < n; i++){
        fwrite(&V[i], sizeof(P), 1, fis);
	}

	fclose(fis); fis = fopen("fisier6", "rb");
	if(fis == NULL){ printf("Fisierul nu s-a putut deschide!"); exit(1); }

	P V2[10]; int nr;
	fseek(fis, 0L, SEEK_END);
    nr = ftell(fis) / sizeof(P);
    fseek(fis, 0L, SEEK_SET);

	///b) Afisare
	for(i = 0; i < nr; i++){
        fread(&V2[i], sizeof(P), 1, fis);
        printf("%s %s %.1f\n", V2[i].nume, V2[i].prenume, V2[i].varsta);
	}
	printf("\n");

	///c) Citire persoane noi
	P V3[10]; int n2;
    printf("Cititi cate persoane doriti sa mai introduceti: "); scanf("%d", &n2); getchar();
    for(i = 0; i < n2; i++){
        printf("# Persoana %d:\n", i+1);
        printf("Nume: "); gets(V3[i].nume);
        printf("Prenume: "); gets(V3[i].prenume);
        printf("Varsta: "); scanf("%f", &V3[i].varsta);
        printf("\n"); getchar();
	}

	fclose(fis); fis = fopen("fisier6", "r+b"); int verif, j, curent;
	if(fis == NULL){ printf("Fisierul nu s-a putut deschide!"); exit(1); }

	///c) Verificare si adaugare a celor neexistenti deja
	for(i = 0; i < n2; i++){
        verif = 0;
        for(j = 0; j < nr; j++){
            fread(&V2[j], sizeof(P), 1, fis);
            if(strcmp(V3[i].nume, V2[j].nume) == 0 && strcmp(V3[i].prenume, V2[j].prenume) == 0 && V3[i].varsta == V2[j].varsta)
                verif = 1;
        }
        if(verif == 0){
            curent = fseek(fis, 0L, SEEK_CUR);
            fseek(fis, 0L, SEEK_END);
            fwrite(&V3[i], sizeof(P), 1, fis);
            fseek(fis, 0L, curent);
        }
	}

	fseek(fis, 0L, SEEK_END);
    nr = ftell(fis) / sizeof(P);
    fseek(fis, 0L, SEEK_SET);

	///c) Afisare actualizata
	for(i = 0; i < nr; i++){
        fread(&V2[i], sizeof(P), 1, fis);
        printf("%s %s %.1f\n", V2[i].nume, V2[i].prenume, V2[i].varsta);
	}

	fclose(fis);

	///d) Media de varsta
	float S = 0.0;
    for(i = 0; i < nr; i++)
        S = S + V2[i].varsta;
    printf("\nMedia de varsta este: %.2f.", S / nr);

    ///e) Sortare
    P aux;

    for(int i = 0; i < nr - 1; i++)
        for(j = i + 1; j < nr; j++){
            if(V2[i].varsta > V2[j].varsta)
                aux = V2[i];
                V2[i] = V2[j];
                V2[j] = aux;
        }

    fis = fopen("fisier6", "wb");
    if(fis == NULL){ printf("Fisierul nu s-a putut deschide!"); exit(1); }

    fwrite(V2, sizeof(P), nr, fis);

    fclose(fis);

    fis = fopen("fisier6", "rb");
    if(fis == NULL){ printf("Fisierul nu s-a putut deschide!"); exit(1); }

    ///f) Eliminare
    char numeElim[25], prenumeElim[50];
    printf("\nCiteste numele persoanei pe care doriti sa o eliminati: "); gets(numeElim);
    printf("Citeste prenumele persoanei pe care doriti sa o eliminati: "); gets(prenumeElim);

    fis = fopen("fisier6", "wb");
    if(fis == NULL){ printf("Fisierul nu s-a putut deschide!"); exit(1); }

    for(i = 0; i < nr; i++)
        if(strcmp(V2[i].nume, numeElim) != 0 || strcmp(V2[i].prenume, prenumeElim) != 0){
            fwrite(&V2[i], sizeof(P), 1, fis);
            printf("\nDA - %s", V2[i].nume);}
    fclose(fis);

    ///g)
    fis = fopen("fisier6", "rb");
    if(fis == NULL){ printf("Fisierul nu s-a putut deschide!"); exit(1); }

    fseek(fis, 0L, SEEK_END);
    nr = ftell(fis) / sizeof(P);
    fseek(fis, 0L, SEEK_SET);

    fread(V2, sizeof(P), nr, fis);
    for(int i = 0; i < nr; i++)
        printf("%s\n", V2[i].nume);

	return 0;
}
