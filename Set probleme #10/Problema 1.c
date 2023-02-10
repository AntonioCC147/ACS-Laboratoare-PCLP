#include <stdio.h>
#include <string.h>

int main()
{
	char sir[50], aux[50], *p;

	///a
	FILE *fisier = fopen("fisier1.txt", "wt");

	gets(sir); strcpy(aux, sir);

	fputs(sir, fisier); fprintf(fisier, "\n");

	for(int i = 0; i < strlen(sir); i++)
        fprintf(fisier, "%c ", sir[i]);
    fprintf(fisier, "\n");

    p = strtok(sir, " ");
    while(p){
        fputs(p, fisier); fprintf(fisier, " ");
        p = strtok(NULL, " ");
    }
    fprintf(fisier, "\n");

    p = strtok(aux, " ");
    while(p){
        fputs(p, fisier); fprintf(fisier, "\n");
        p = strtok(NULL, " ");
    }
    fclose(fisier);

    ///b
    FILE *fisier2 = fopen("fisier1.txt", "rt"); char c;

    c = getc(fisier2);
    while(c != EOF){
        putchar(c);
        c = getc(fisier2);
    }
    fclose(fisier2);

    ///c
    char cuv1[25], cuv2[25];

    printf("Tasteaza primul cuvant: "); gets(cuv1);
    printf("Tasteaza al 2-lea cuvant: "); gets(cuv2);

    FILE *fisier3 = fopen("fisier1.txt", "rt"); char text[50];

    fgets(text, 50, fisier3);

    p = strtok(text, " ");
    while(p){
        puts(p);
        p = strtok(NULL, " ");
    }

	return 0;
}
