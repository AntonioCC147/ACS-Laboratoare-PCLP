#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct autoturisme{
    char proprietar[25], nr_Inmatriculare[11];
    int zi, luna, an;
}A;

void functie1(int an, char judet[2], A V[], int n, A Revizie[], int *k, int *nr_Auto, int *verificare){
    *nr_Auto = *verificare = *k = 0;

    for(int i = 0; i < n; i++)
        if(V[i].an == an && V[i].nr_Inmatriculare[0] == judet[0] && V[i].nr_Inmatriculare[1] == judet[1]){
            Revizie[*k] = V[i]; (*k)++; (*nr_Auto)++;
            for(int j = i + 1; j < n; j++)
                if(strcmp(V[i].proprietar, V[j].proprietar) == 0 && V[i].an == V[j].an && V[i].nr_Inmatriculare[0] == V[j].nr_Inmatriculare[0] && V[i].nr_Inmatriculare[1] == V[j].nr_Inmatriculare[1])
                    *verificare = 1;
        }
}

void functie2(A Revizie[], int k){
    A aux;

    for(int i = 0; i < k - 1; i++){
        for(int j = i + 1; j < k; j++)
            if(Revizie[i].luna > Revizie[j].luna){
                aux = Revizie[i]; Revizie[i] = Revizie[j]; Revizie[j] = aux;
            }
        for(int j = i + 1; j < k; j++)
            if(Revizie[i].luna == Revizie[j].luna && Revizie[i].zi > Revizie[j].zi ){
                aux = Revizie[i]; Revizie[i] = Revizie[j]; Revizie[j] = aux;
            }
    }

    FILE *fis2 = fopen("fisierAB2.txt", "wt");
    if(fis2 == NULL){ printf("Fisierul nu poate fi deschis!"); exit(1); }

    for(int i = 0; i < k; i++)
        fprintf(fis2, "%s %d %d %d\n", Revizie[i].nr_Inmatriculare, Revizie[i].zi, Revizie[i].luna, Revizie[i].an);

    fclose(fis2);
}

int main()
{
	A V[10]; FILE *fis = fopen("fisierAB", "rb");
	if(fis == NULL){ printf("Fisierul nu poate fi deschis!"); exit(1); }

	fseek(fis, 0L, SEEK_END);
	int nr = ftell(fis) / sizeof(A);
	fseek(fis, 0L, SEEK_SET);

	for(int i = 0; i < nr; i++)
        fread(&V[i], sizeof(A), 1, fis);

	A Revizie[10]; int an, nr_Auto, verificare, k; char acronim[2];
	printf("Citeste un an de la tastatura: "); scanf("%d", &an); getchar();
	printf("Citeste acronimul unui judet: "); gets(acronim);

	functie1(an, acronim, V, nr, Revizie, &k, &nr_Auto, &verificare);
	if(verificare == 1) printf("Exista cel putin un proprietar care sa detina cel putin 2 autoturisme cu revizia in acest an.\n");

    functie2(Revizie, k);

    int luna;
    printf("Citeste o luna de la tastatura (reprezentata in cifre): "); scanf("%d", &luna);

    FILE *fis2 = fopen("fisierAB2.txt", "rt");
    if(fis2 == NULL){ printf("Fisierul nu poate fi deschis!"); exit(1); }

    char nr_Inmat[11]; int z, l, a;
    for(int i = 0; i < nr_Auto; i++){
        fscanf(fis2, "%s%d%d%d", &nr_Inmat, &z, &l, &a);
        if(luna == l)
            printf("%s %d %d %d\n", nr_Inmat, z, l, a);

    }

    fclose(fis); fclose(fis2);

	return 0;
}
