#include <stdio.h>

void ordonare(int v[], int n){
    int aux;

    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if(v[i] > v[j]){
                aux = v[i]; v[i] = v[j]; v[j] = aux;
            }
}

int main()
{
    int m, n;

    printf("Citeste numarul de linii si coloane pentru matrice: ");
    scanf("%d%d", &m, &n);

    int **M = (int*) malloc(m * n * sizeof(int));
    if(M == NULL){
        printf("Alocare esuata!");
        exit(1);
    }
    for(int i = 0; i < m; i++){
        M[i] = (int*) malloc(n * sizeof(int));
        if(M[i] == NULL){
            printf("Alocare esuata!");
            exit(1);
        }
    }

    printf("Citeste matricea: ");
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &M[i][j]);

    for(int i = 0; i < m; i++)
        ordonare(&M[i][0], n);

    printf("Noua matrice:\n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)
            printf("%d ", M[i][j]);
        printf("\n");
    }

    for(int i = 0; i < m; i++)
        free(M[i]);
    free(M);

	return 0;
}
