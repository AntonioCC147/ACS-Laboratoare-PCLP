#include <stdio.h>

int main()
{
	int m;

	printf("Citeste numarul de elemente ale vectorului: ");
	scanf("%d", &m);

	int *V = (int*) calloc(m, sizeof(int));
	if(V == NULL){
        printf("Alocare esuata!");
        exit(1);
	}

	printf("Citeste elementele vectorului: ");
	for(int i = 0; i < m; i++)
        scanf("%d", &V[i]);

    printf("Elementele vectorului citit sunt: ");
	for(int i = 0; i < m; i++)
        printf("%d ", V[i]);

    free(V);

	return 0;
}
