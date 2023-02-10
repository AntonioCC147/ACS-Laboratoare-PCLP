#include <stdio.h>
#include <string.h>

typedef struct persoana{
    char nume[25], prenume[50], CNP[15];
};

void schimbare(struct persoana *P1, struct persoana *P2){
    struct persoana aux;

    aux = *P1; *P1 = *P2; *P2 = aux;
}

int main()
{
    int n, i, j; char alocare[50];

    ///a)
    printf("Citeste numarul de persoane pe care doriti sa le introduceti: ");
    scanf("%d", &n); getchar();

    struct persoana *P = (struct persoana*) malloc(n * sizeof(struct persoana));
    if(P == NULL){
        printf("Alocare esuata!");
        exit(1);
    }

    for(i = 0; i < n; i++){
        printf("Persoana %d:\n", i+1);

        printf("Nume: "); gets(alocare);
        *P[i].nume = (char*) malloc((strlen(alocare) + 1) * sizeof(char));
        strcpy(P[i].nume, alocare);

        printf("Prenume: "); gets(alocare);
        *P[i].prenume = (char*) malloc((strlen(alocare) + 1) * sizeof(char));
        strcpy(P[i].prenume, alocare);

        printf("CNP: "); gets(alocare);
        *P[i].CNP = (char*) malloc((strlen(alocare) + 1) * sizeof(char));
        strcpy(P[i].CNP, alocare);
    }

    ///b)
    /**
    for(i = 0; i < n-1; i++)
        for(j = i + 1; j < n; j++)
            if(strcmp(P[i].CNP+1, P[j].CNP+1) > 0)
                schimbare(&P[i], &P[j]);
    **/

    ///c)
    for(i = 0; i < n-1; i++)
        for(j = i + 1; j < n; j++)
            if(strcmp(P[i].nume, P[j].nume) < 0)
                schimbare(&P[i], &P[j]);

    for(i = 0; i < n-1; i++)
        for(j = i + 1; j < n; j++)
            if(strcmp(P[i].prenume, P[j].prenume) > 0)
                schimbare(&P[i], &P[j]);

	return 0;
}
