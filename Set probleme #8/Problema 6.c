#include <stdio.h>
#include <string.h>

typedef struct student{
    char nume[25];
    float nota1, nota2, nota3;
};

float nota_max(struct student *S, int n, char nota){
    float max = 0.0;

    for(int i = 0; i < n; i++)
        switch(nota){
            case 1: if(S[i].nota1 > max)
                        max = S[i].nota1;
                break;
            case 2: if(S[i].nota1 > max)
                        max = S[i].nota2;
                break;
            case 3: if(S[i].nota1 > max)
                        max = S[i].nota3;
                break;
        }

    return max;
}

float media(struct student *S, int i){

    return (float)((S[i].nota1 + S[i].nota2 + S[i].nota3) / 3.0);
}

void ordonare(struct student *S1, struct student *S2){
    struct student aux;

    aux = *S1; *S1 = *S2; *S2 = aux;
}

int main()
{
    ///a)
    struct student studenti[6]; int n;

    printf("Cititi numarul de studenti pe care doriti sa-i memorati: ");
    scanf("%d", &n); getchar();

    for(int i = 0; i < n; i++){
        printf("Cititi date despre studentul %d:\n", i+1);
        printf("Numele: "); gets(studenti[i].nume);
        printf("Nota 1, Nota 2 si Nota 3: "); scanf("%f%f%f", &studenti[i].nota1, &studenti[i].nota2, &studenti[i].nota3);
        getchar();
    }

    ///b)
    char caut[25]; int i, j;

    printf("Tastati numele elevului pe care il cautati: "); gets(caut);

    for(i = 0; i < n; i++)
        if(stricmp(caut, studenti[i].nume) == 0){
            printf("Student gasit. Informatiile despre acestea sunt: \n");
            printf("Nume: "); puts(studenti[i].nume);
            printf("Nota 1: %.2f, Nota 2: %.2f, Nota 3: %.2f\n", studenti[i].nota1, studenti[i].nota2, studenti[i].nota3);
            i = -1; break;
        }
    if(i != -1)
        printf("Elevul pe care il cautati nu figureaza in baza de date.\n");

    ///c)
    char materie[25]; int nota;

    printf("Tastati o materie de la tastatura pentru a afla cel mai bun student la aceasta.\n");
    printf("Informatica (Nota 1) / Matematica (Nota 2) / Fizica (Nota 3): ");
    gets(materie);

    if(stricmp("Informatica", materie) == 0) nota = 1;
    else if(stricmp("Matematica", materie) == 0) nota = 2;
    else if(stricmp("Fizica", materie) == 0) nota = 3;

    printf("Studentul / Studentii cu cele mai mari note:\n");
    for(i = 0; i < n; i++)
        switch(nota){
            case 1: if(studenti[i].nota1 == nota_max(&studenti, n, nota))
                        puts(studenti[i].nume);
                break;
            case 2: if(studenti[i].nota2 == nota_max(&studenti, n, nota))
                        puts(studenti[i].nume);
                break;
            case 3: if(studenti[i].nota3 == nota_max(&studenti, n, nota))
                        puts(studenti[i].nume);
                break;
            default: printf("Eroare.\n");
                break;
        }

    ///d)
    float media_max = 0.0;

    for(i = 0; i < n; i++)
        if(media_max < media(&studenti, i))
            media_max = media(&studenti, i);

    printf("Premiantul / Preminatii:\n");
    for(i = 0; i < n; i++)
        if(fabs(media(&studenti, i) - media_max) < 0.00000001)
            puts(studenti[i].nume);

    ///e)
    for(i = 0; i < n; i++)
        for(j = i + 1; j < n; j++)
            if(studenti[i].nota2 < studenti[j].nota2)
                ordonare(&studenti[i], &studenti[j]);

    printf("Noua baza de date dupa ordonare:\n");
    for(i = 0; i < n; i++){
        printf("Studentul cu numarul %d:\n", i+1);
        printf("Nume: "); puts(studenti[i].nume);
        printf("Nota 1: %.2f, Nota 2: %.2f, Nota 3: %.2f\n", studenti[i].nota1, studenti[i].nota2, studenti[i].nota3);
    }

    ///f)
    for(i = 0; i < n; i++)
        if(studenti[i].nota1 < 5 || studenti[i].nota2 < 5 || studenti[i].nota3 < 5)
            printf("Studentul %s nu promoveaza la cel putin o materie.\n", studenti[i].nume);

	return 0;
}
