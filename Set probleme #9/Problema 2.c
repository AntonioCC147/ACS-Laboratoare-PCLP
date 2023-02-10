#include <stdio.h>

typedef struct lista{
    char nume[25];
    int varsta;
    struct lista *urm;
}L;

int main()
{
	L *cap_lista, *p, *q; int n, i, k = 0;

	printf("Cititi numarul de elemente: ");
	scanf("%d", &n); getchar();

	p = (L*) malloc(sizeof(L));
	if(p == NULL){
        printf("Alocare esuata!"); exit(1);
	}

	printf("Nume #1: "); gets(p -> nume);
	printf("Varsta #1: "); scanf("%d", &p -> varsta); getchar();

	p -> urm = NULL;
	cap_lista = p;

	for(i = 2; i <= n; i++){
        q = (L*) malloc(sizeof(L));
        if(q == NULL){
            printf("Alocare esuata."); exit(1);
        }
        printf("Nume #%d: ", i); gets(q -> nume);
        printf("Varsta #%d: ", i); scanf("%d", &q -> varsta); getchar();
        q -> urm = NULL;
        p -> urm = q;
        p = q;
	}

	for(p = cap_lista; p != NULL; p = p -> urm)
        if(strcmp(p -> nume, "George") == 0 && (p -> varsta) == 19){
            if(p -> urm == NULL){
                printf("George este ultima persoana din lista"); exit(1);
            }
            if(p -> urm -> varsta < 19)
                printf("Persoana de dupa George este mai tanara.");
            else
                printf("Persoana de dupa George NU este mai tanara.");
            k = 1;
        }

    if(k == 0)
        printf("George nu se gaseste in lista.");

	return 0;
}
