#include <stdio.h>

int suma(int *m, int n){
    int S = 0;

    for(int i = 0; i < n; i++)
        S = S + m[i];

    return S;
}

void schimbare(int *m1, int *m2, int n){
    int aux;

    for(int i = 0; i < n; i++){
        aux = m1[i]; m1[i] = m2[i]; m2[i] = aux;
    }
}

int main()
{
	int m, n;

    printf("Citeste numarul de linii si coloane pentru matrice: ");
    scanf("%d%d", &m, &n);

    int **a = (int*) malloc(m * n * sizeof(int));
    if(a == NULL){
        printf("Alocare esuata!");
        exit(1);
    }
    for(int i = 0; i < m; i++){
        a[i] = (int*) malloc(n * sizeof(int));
        if(a[i] == NULL){
            printf("Alocare esuata!");
            exit(1);
        }
    }

    printf("Citeste matricea: ");
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for(int i = 0; i < m - 1; i++){
        for(int j = i + 1; j < m; j++)
            if(suma(&a[i][0], n) > suma(&a[j][0], n))
                schimbare(&a[i][0], &a[j][0], n);
    }

    printf("Noua matrice:\n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    for(int i = 0; i < m; i++)
        free(a[i]);
    free(a);

	return 0;
}
