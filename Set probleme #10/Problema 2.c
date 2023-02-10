#include <stdio.h>

int main()
{
	FILE *fisier = fopen("fisier2.txt", "wt");

	char prop[100];

	printf("Cititi diverse propozitii. Acestea trebuie sa se termine cu \'.\'.\n");
	printf("Cand nu mai doriti sa tastati propozitii, tastati numarul 0.\n");

	gets(prop);
	while(strcmp(prop, "0") != 0){
        fputs(prop, fisier);
        if(prop[strlen(prop)-1] == '.') fprintf(fisier, "\n");
        else fprintf(fisier, " ");
        gets(prop);
	}

    fclose(fisier);

    ///a)
    char *p; fisier = fopen("fisier2.txt", "rt");

    printf("Continutul fisierului este:\n");
    while(fgets(prop, 100, fisier) != NULL)
        printf("%s", prop);

    ///b)
    char cuv[25]; int k = 1; fseek(fisier, 0, SEEK_SET);

    printf("\nTastati un cuvant: "); gets(cuv);

    while(fgets(prop, 100, fisier) != NULL){
        p = strtok(prop, " .");
        while(p){
            if(strcmp(p, cuv) == 0)
                printf("Cuvantul se gaseste pe linia %d.\n", k);
            p = strtok(NULL, " .");
        }
        k++;
    }

    ///c)
    fseek(fisier, 0, SEEK_SET); int nrCuv = 0, nrCaract = 0;

    while(fgets(prop, 100, fisier) != NULL){
        p = strtok(prop, " ");
        while(p){
            nrCuv++; nrCaract = nrCaract + strlen(p);
            p = strtok(NULL, " ");
        }
    }

    printf("\nFisierul contine %d cuvinte si %d caractere.\n", nrCuv, nrCaract-1);

    ///d)
    fseek(fisier, 0, SEEK_SET); int maxim = 0;

    while(fgets(prop, 100, fisier) != NULL)
        if(strlen(prop) > maxim)
            maxim = strlen(prop);

    fseek(fisier, 0, SEEK_SET);
    printf("\nLinia / Liniile de lungime maxima:\n");
    while(fgets(prop, 100, fisier) != NULL)
        if(strlen(prop) == maxim)
            printf("%s", prop);

    fclose(fisier);

	return 0;
}
