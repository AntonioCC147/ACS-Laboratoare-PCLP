#include <stdio.h>

int main()
{
	FILE *fis1 = fopen("fisier3.1.txt", "wt"), *fis2 = fopen("fisier3.2", "wb");

	if(fis1 == NULL || fis2 == NULL){
        printf("Fisierul nu poate fi deschis!"); exit(1);
	}

	int n, i;

	printf("Cititi numarul de elemente de la tastatura: "); scanf("%d", &n);
	int *V = malloc(n * sizeof(int*));
	if(V == NULL){
        printf("Alocare esuata!");
	}

	for(i = 0; i < n; i++){
        scanf("%d", &V[i]);
        fprintf(fis1, "%d ", V[i]);
	}
	fwrite(V, sizeof(V[0]), n, fis2);

	fclose(fis1); fclose(fis2);

	fis1 = fopen("fisier3.1.txt", "rt"); fis2 = fopen("fisier3.2", "rb");
	if(fis1 == NULL || fis2 == NULL){
        printf("Fisierul nu poate fi deschise!"); exit(1);
	}

	printf("Afisarea elementelor din fisierul text: ");
	for(i = 0; i < n; i++){
        fscanf(fis1, &V[i]);
        printf("%d ", V[i]);
	}

    printf("\nAfisarea elementelor din fisierul binar: ");
	fread(V, sizeof(int), n, fis2);
	for(i = 0; i < n; i++)
        printf("%d ", V[i]);

	return 0;
}
