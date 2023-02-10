#include <stdio.h>
#include <string.h>

typedef struct lista{
    char cuv[15];
    struct lista *urm;
}L;

int main()
{
	L *cap_lista, *p, *q; int n, i;

	printf("Cititi cate cuvinte doriti sa introduceti: "); scanf("%d", &n); getchar();

	for(i = 1; i <= n; i++){
        printf("# Cuvantul %d: ", i);
        if(i == 1){
            p = (L*) malloc(sizeof(L));
            if(p == NULL){
                printf("Alocare esuata!"); exit(1);
            }
            gets(p -> cuv);
            p -> urm = NULL;
            cap_lista = p;
        }
        else{
            q = (L*) malloc(sizeof(L));
            if(q == NULL){
                printf("Alocare esuata!"); exit(1);
            }
            gets(q -> cuv);
            q -> urm = NULL;
            p -> urm = q;
            p = q;
        }
	}

	printf("\nCuvintele citite, impreuna cu adresle lor urmatoare sunt: ");
	for(p = cap_lista; p != NULL; p = p -> urm)
        printf("%s-%p, ", p -> cuv, p);

    char fraza[100] = "";
    for(p = cap_lista; p != NULL; p = p -> urm){
        strcat(fraza, p -> cuv); strcat(fraza, " ");
    }
    printf("\n\nFraza formata din cuvintele citite este: "); puts(fraza);

	return 0;
}
