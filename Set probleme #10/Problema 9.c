#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studenti{
    char prenume[40], sex;
    float nota;
}STUD;

void citeste(STUD V[], int *n){
    FILE *fis = fopen("fisier9", "rb");
    if(fis == NULL){ printf("Fisierul nu poate fi deschis!"); exit(1); }

    fseek(fis, 0L, SEEK_END);
    *n = ftell(fis) / sizeof(STUD);
    fseek(fis, 0L, SEEK_SET);

    fread(V, sizeof(STUD), *n, fis);

    fclose(fis);
}

void adauga(STUD V[], int *n){
    FILE *fis = fopen("fisier9", "ab");
    if(fis == NULL){ printf("Fisierul nu poate fi deschis!"); exit(1); }

    printf("[2] Cand nu mai doresti introducerea unor studenti, tasteaza 0 in dreptul prenumelui.\n");
    while(1){
        printf("\n# Student %d:\n", *n);
        printf("Prenume: "); gets(V[*n].prenume); if(strcmp(V[*n].prenume, "0") == 0) break;
        printf("Sex (M / F): "); scanf("%c", &V[*n].sex); getchar();
        printf("Nota: "); scanf("%f", &V[*n].nota); getchar();
        fwrite(&V[*n], sizeof(STUD), 1, fis); (*n)++;
    }
    printf("\n");

    fclose(fis);
}

void calc_media(STUD V[], int n, float *media){
    float S = 0.0;

    for(int i = 0; i < n; i++)
        S = S + V[i].nota;
    *media = S / n;
}

void verifica(STUD V[], int n, int *verif){
    *verif = 0; int tasta; char prenume[40] = "NULL"; float nota = -1.0;

    do{
        printf("[4] Daca doriti sa cautati o persoana dupa prenume, tastati 1.");
        printf("\n[4] Daca doriti sa cautati o persoana dupa nota, tastati 2.");
        printf("\n[4] Optiune: "); scanf("%d", &tasta); getchar();
    }while(tasta != 1 && tasta != 2);

    if(tasta == 1){ printf("[4] Tasteaza un prenume pe care doriti sa-l cautati: "); gets(prenume); }
    else{ printf("[4] Tastati o nota pe care doriti sa o cautati: "); scanf("%f", &nota); getchar(); }

    for(int i = 0; i < n; i++)
        if(strcmp(V[i].prenume, prenume) == 0 || V[i].nota == nota)
            *verif = 1;
}

void identifica(STUD V[], int n, char Nota[10][40], int *k){
    *k = 0; float maxim  = 0.0;

    for(int i = 0; i < n; i++)
        if(V[i].nota > maxim)
            maxim = V[i].nota;

    for(int i = 0; i < n; i++)
        if(V[i].nota == maxim)
            strcpy(Nota[(*k)++], V[i].prenume);
}

void construieste(STUD V[], int n){
    FILE *fis1 = fopen("fete.dat", "wb"), *fis2 = fopen("baieti.dat", "wb");
    if(fis1 == NULL || fis2 == NULL){ printf("Fisierul nu poate fi deschis!"); exit(1); }

    for(int i = 0; i < n; i++)
        if(V[i].sex == 'F')
            fwrite(&V[i], sizeof(STUD), 1, fis1);
        else
            fwrite(&V[i], sizeof(STUD), 1, fis2);

    fclose(fis1); fclose(fis2);

    printf("[6] Fisierele au fost construite cu succes!\n");
}

void ordoneaza(){
    FILE *fis1 = fopen("fete.dat", "rb"), *fis2 = fopen("baieti.dat", "rb");
    if(fis1 == NULL || fis2 == NULL){ printf("Fisierul nu poate fi deschis!"); exit(1); }

    STUD F[20], M[20], aux; int f, m;

    ///Fete
    fseek(fis1, 0L, SEEK_END);
    f = ftell(fis1) / sizeof(STUD);
    fseek(fis1, 0L, SEEK_SET);

    fread(F, sizeof(STUD), f, fis1); fclose(fis1);

    for(int i = 0; i < f - 1; i++)
        for(int j = i + 1; j < f; j++)
            if(F[i].nota > F[j].nota){
                aux = F[i]; F[i] = F[j]; F[j] = aux;
            }

    ///Baieti
    fseek(fis2, 0L, SEEK_END);
    m = ftell(fis2) / sizeof(STUD);
    fseek(fis2, 0L, SEEK_SET);

    fread(M, sizeof(STUD), m, fis2); fclose(fis2);

    for(int i = 0; i < m - 1; i++)
        for(int j = i + 1; j < m; j++)
            if(strcmp(M[i].prenume, M[j].prenume) > 0){
                aux = M[i]; M[i] = M[j]; M[j] = aux;
            }

    fis1 = fopen("fete.dat", "wb"); fis2 = fopen("baieti.dat", "wb");
    if(fis1 == NULL || fis2 == NULL){ printf("Fisierul nu poate fi deschis!"); exit(1); }

    fwrite(F, sizeof(STUD), f, fis1);
    fwrite(M, sizeof(STUD), m, fis2);

    fclose(fis1); fclose(fis2);

    printf("[7] Fisierele au fost ordonate cu succes!\n");
}

void continut(){
    FILE *fis1 = fopen("fete.dat", "rb"), *fis2 = fopen("baieti.dat", "rb");
    if(fis1 == NULL || fis2 == NULL){ printf("Fisierul nu poate fi deschis!"); exit(1); }

    STUD F[20], M[20]; int f, m;

    ///Fete
    fseek(fis1, 0L, SEEK_END);
    f = ftell(fis1) / sizeof(STUD);
    fseek(fis1, 0L, SEEK_SET);

    fread(F, sizeof(STUD), f, fis1); fclose(fis1);

    printf("[8] Fete:\n");
    for(int i = 0; i < f; i++)
        printf("[8] Prenume: %s; Nota: %.2f\n", F[i].prenume, F[i].nota);

    ///Baieti
    fseek(fis2, 0L, SEEK_END);
    m = ftell(fis2) / sizeof(STUD);
    fseek(fis2, 0L, SEEK_SET);

    fread(M, sizeof(STUD), m, fis2); fclose(fis2);

    printf("\n[8] Baieti:\n");
    for(int i = 0; i < m; i++)
        printf("[8] Prenume: %s; Nota: %.2f\n", M[i].prenume, M[i].nota);
}

void reseteaza(){
    FILE *fis = fopen("fisier9", "wb"), *fis1 = fopen("fete.dat", "wb"), *fis2 = fopen("baieti.dat", "wb");
    fclose(fis);

    printf("[9] Fisierele au fost resetate cu succes!\n");
}

int main()
{
    STUD V[25]; int meniu, n = 0;

	while(1){
        printf("Daca doresti sa citesti informatii din fiser, apasa tasta 1.\n");
        printf("Daca doresti sa adaugi in fisier, apasa tasta 2.\n");
        printf("Daca doresti sa calculezi si afisezi media studentilor, apasa tasta 3.\n");
        printf("Daca doresti sa verifici existenta unor anumite persoane, apasa tasta 4.\n");
        printf("Daca doresti sa identifici persoana cu cea mai mare nota, apasa tasta 5.\n");
        printf("Daca doresti sa construiesti un fisier pentru fete / baieti, apasa tasta 6.\n");
        printf("Daca doresti sa ordonezi crescator / descrescator fetele / baietii, apasa tasta 7.\n");
        printf("[IN PLUS] Daca doresti sa afisezi continuturile fisierelor fete / baieti, apasa tasta 8.\n");
        printf("[IN PLUS] Daca doresti sa resetezi toate fisierele, apasa tasta 9.\n");
        printf("Optiune: "); scanf("%d", &meniu); getchar(); printf("\n");
        if(meniu == 1){ citeste(V, &n);
                        for(int i = 0; i < n; i++)
                            printf("[1] Prenume: %s, Sex: %c, Nota: %.2f;\n", V[i].prenume, V[i].sex, V[i].nota);
                        printf("\n");
        }
        else if(meniu == 2) adauga(V, &n);
        else if(meniu == 3){ float media; calc_media(V, n, &media); printf("[3] Media grupului de studenti este %.2f.\n\n", media); }
        else if(meniu == 4){ int verif; verifica(V, n, &verif);
            if(verif == 1) printf("\n[4] Fisierul contine studenti dupa criteriul cautat.\n");
                else printf("\n[4] Fisierul nu contine studenti dupa criteriul cautat.\n");
        }
        else if(meniu == 5){ char Nota[10][40], k; identifica(V, n, Nota, &k);
                             if(k == 1) printf("[5] Studentul cu cea mai mare nota este: %s.", Nota[0]);
                             else{ printf("[5] Studentii cu cea mai mare nota sunt: ");
                                   for(int i = 0; i < k; i++) printf("%s; ", Nota[i]);
                             }
                             printf("\n");
        }
        else if(meniu == 6){ construieste(V, n); printf("\n"); }
        else if(meniu == 7){ ordoneaza(); printf("\n"); }
        else if(meniu == 8){ continut(); printf("\n"); }
        else if(meniu == 9){ reseteaza(); printf("\n"); }
        else break;
	}

	return 0;
}
