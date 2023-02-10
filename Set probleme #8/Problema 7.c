#include <stdio.h>
#include <string.h>

typedef struct carte{
    char titlu[50];
    int an;
    struct date_autor{
        char nume[25], prenume[50], gen;
    }autor;
};

///Citire gen pentru verificaere:
void citire_gen(char *gen){
    do{
        printf("Cititi un gen de la tastatura (D, C, T): ");
        scanf("%c", gen); getchar();
    }while(*gen != 'D' && *gen != 'C' && *gen != 'T');
}

///a)
int caut_carte(struct carte A[], char nume[], char prenume[], int n){
    int verif = 0;

    for(int i = 0; i < n; i++)
        if(stricmp(A[i].autor.nume, nume) == 0 && stricmp(A[i].autor.prenume, prenume) == 0)
            verif = 1;

    return verif;
}

///b)
int aparitii_autor(struct carte A[], int n, int j, char nume[], char prenume[]){
    int k = 0;

    for(int i = j; i < n; i++)
        if(stricmp(A[i].autor.nume, nume) == 0 && stricmp(A[i].autor.prenume, prenume) == 0)
            k++;

    return k;
}

///c)
void an_gen(struct carte A[], int n, int an, char gen, int *verificare){
    *verificare = 0;

    for(int i = 0; i < n; i++)
        if(A[i].an == an && A[i].autor.gen == gen){
            printf("Carte care apare in anul %d si este genul %c este: %s.\n", an, gen, A[i].titlu);
            *verificare = 1;
        }
}
///d)
///Interschimbare int:
void schimb_i(int *a, int *b){
    int aux;

    aux = *a; *a = *b; *b = aux;
}

///Interschimbare char:
void schimb_c(char a[], char b[]){
    char aux[50];

    strcpy(aux, a); strcpy(a, b); strcpy(b, aux);
}

void ordonare(struct carte A[], int n){
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if(strcmp(A[i].titlu, A[j].titlu) > 0){
                schimb_c(A[i].titlu, A[j].titlu);
                schimb_c(A[i].autor.nume, A[j].autor.nume);
                schimb_c(A[i].autor.prenume, A[j].autor.prenume);
                schimb_i(&A[i].an, &A[j].an);
                char aux = A[i].autor.gen; A[i].autor.gen = A[j].autor.gen; A[j].autor.gen = aux;
            }
}

int main()
{
    struct carte A[10];

    ///Citire date:
    int n, i;

    printf("Tastati cate carti doriti sa puneti in evidenta: ");
    scanf("%d", &n); getchar();

    for(i = 0; i < n; i++){
        printf("Tastati informatiile despre cartea cu numarul %d.\n", i + 1);
        printf("Titlul: "); gets(A[i].titlu);
        printf("Anul aparitiei: "); scanf("%d", &A[i].an); getchar();
        printf("Numele autorului: "); gets(A[i].autor.nume);
        printf("Prenumele autorului: "); gets(A[i].autor.prenume);
        citire_gen(&A[i].autor.gen);
    }
    if(n == 0) return 0;

    ///a)Cautare carte dupa nume:
    char nume_autor[25], prenume_autor[25]; int verificare1;

    printf("\nTASK A:\n");
    printf("Cauta o carte:\n");
    printf("Cititi numele autorului: "); gets(nume_autor);
    printf("Cititi prenumele autorului: "); gets(prenume_autor);

    for(i = 0; i < n; i++){
        verificare1 = caut_carte(A, nume_autor, prenume_autor, n);
        if(verificare1 == 1)
            printf("Cartea a fost gasita: %s.\n", A[i].titlu);
    }

    if(verificare1 == 0)
        printf("Autorul cautat nu apare in baza de date cu nicio carte.\n");

    ///b)Autorul cu cele mai mult carti:
    int numar, maxim = 1;

    for(i = 0; i < n; i++){
        numar = aparitii_autor(A, n, i, A[i].autor.nume, A[i].autor.prenume);
        if(numar > maxim)
            maxim = numar;
    }

    printf("\nTASK B:\n");
    printf("Lista cu autorii / autorul care apar/e de cele mai multe ori:\n");
    for(i = 0; i < n; i++){
        numar = aparitii_autor(A, n, i, A[i].autor.nume, A[i].autor.prenume);
        if(numar == maxim)
            printf("%s %s\n", A[i].autor.nume, A[i].autor.prenume);
    }

    ///c)
    char gen; int an, verificare2;

    printf("\nTASK C:\n");
    printf("Cititi un an de la tastatura: "); scanf("%d", &an); getchar();
    citire_gen(&gen);

    an_gen(A, n, an, gen, &verificare2);
    if(verificare2 == 0)
        printf("Baza de date nu contine carti din anul %d si genul %c.\n", an, gen);

    ///d)
    ordonare(A, n);

    printf("\nTASK D:\n");
    printf("Ordonarea crescatoare dupa titlu:\n");
    for(i = 0; i < n; i++){
        printf("Cartea %d:\n", i+1);
        printf("Titlu: %s, An: %d, Nume Autor: %s, Prenume Autor: %s, Gen: %c\n", A[i].titlu, A[i].an, A[i].autor.nume, A[i].autor.prenume, A[i].autor.gen);
    }

	return 0;
}
