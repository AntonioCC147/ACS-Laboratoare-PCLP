#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct evidenta_preturi_asigurare{
    int TA;
    float pret; ///presupunem ca exista 3 tipuri de asigurari, notate cu: 0/1/2
}EPA;

typedef struct evidenta_RAR{
    char NI[11];
    int valabilitate; ///presupunem 1 - valabil, 0 - nevalabil
}RAR;

typedef struct persoana{
    char nume[25], CNP[14], NI[11];
    int tipA;
    float cost;
    char data[11];
}pers;

void functie(int zi, int Poz[], int *k){
    *k = 0; pers V[25];

    FILE *fis = fopen("asigurari.dat", "rb");
    if(fis == NULL){ printf("Fisierul nu poate fi deschis!"); exit(1); }

    fseek(fis, 0L, SEEK_END);
    int n = ftell(fis) / sizeof(pers);
    fseek(fis, 0L, SEEK_SET);

    fread(V, sizeof(pers), n, fis);

    for(int i = 0; i < n; i++)
        if(((V[i].data[0] - '0') * 10 + V[i].data[1] - '0') == zi)
            Poz[(*k)++] = i;

    fclose(fis);
}

int main()
{
    ///Evidenta Preturi:
    EPA P[3];
    FILE *fis = fopen("ev_pret_asig.txt", "rt");
    if(fis == NULL){ printf("Fisierul nu poate fi deschis!"); exit(1); }
    for(int i = 0; i < 3; i++) fscanf(fis, "%d%f", &P[i].TA, &P[i].pret);
    fclose(fis);

    ///RAR:
    RAR V[25];
    fis = fopen("evidenta_RAR.dat", "rb");
    if(fis == NULL){ printf("Fisierul nu poate fi deschis!"); exit(1); }
    fseek(fis, 0L, SEEK_END);
    int n = ftell(fis) / sizeof(RAR);
    fseek(fis, 0L, SEEK_SET);
    fread(V, sizeof(RAR), n, fis);

    int valoare; pers p;

    do{
        printf("Doresti sa introduci un client care doreste sa cumpere o asigurare (1/0)? "); scanf("%d", &valoare); getchar();
        if(valoare == 1){
            printf("\nNumele: "); gets(p.nume);
            printf("CNP-ul: "); gets(p.CNP);
            printf("Numarul de Inmatriculare: "); gets(p.NI);
            printf("Tipul de Asigurare (0/1/2): "); scanf("%d", &p.tipA);

            int verif = 0;
            for(int i = 0; i < n; i++)
                if(strcmp(p.NI, V[i].NI) == 0 && V[i].valabilitate == 1){
                    verif = 1; break;
                }

            if(verif == 0) printf("Numarul de inmatriculare nu se gaseste in evidenta RAR.\n");
            else{
                int varsta;
                if(p.CNP[1] == '0') varsta = 23 - (p.CNP[2] - '0');
                else varsta = 23 + (100 - ((p.CNP[1] - '0') * 10 + p.CNP[2] - '0'));
                if(varsta < 30)
                    p.cost = P[p.tipA].pret + 1.0 * P[p.tipA].pret;
                getchar(); printf("Citeste data emiterii (sir de caractere): "); gets(p.data);

                FILE *fis2 = fopen("asigurari.dat", "ab");
                if(fis2 == NULL){ printf("Fisierul nu poate fi deschis!"); exit(1); }

                fwrite(&p, sizeof(pers), 1, fis2);

                fclose(fis2);
            }
        }
        else if(valoare == 0) break;
    }while(valoare != 0);

    int zi, Poz[25], k = 0;
    printf("Introduceti o zi din luna (numeric): "); scanf("%d", &zi);

    functie(zi, Poz, &k);

    if(k == 0)
        printf("Fisierul nu contine nicio asigurare incheiata in ziua citita.");
    else{
        pers componenta; float Suma_Cost = 0.0;
        FILE *fis = fopen("asigurari.dat", "rb");
        if(fis == NULL){ printf("Fisierul nu poate fi deschis!"); exit(1); }

        fseek(fis, 0L, SEEK_END);
        int n = ftell(fis) / sizeof(pers);
        fseek(fis, 0L, SEEK_SET);

        for(int i = 0; i < k; i++){
            fseek(fis, sizeof(pers) * Poz[i], SEEK_SET);
            fread(&componenta, sizeof(pers), 1, fis);
            Suma_Cost = Suma_Cost + componenta.cost;
        }

        printf("\nCostul total al asigurarilor este %.1f: ", Suma_Cost);
    }

	return 0;
}
