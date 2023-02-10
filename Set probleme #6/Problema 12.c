#include <stdio.h>

void schimb(int a[], int b[], int n){
    int aux;

    for(int i = 0; i < n; i++){
        aux = a[i]; a[i] = b[i]; b[i] = aux;
    }
}

int main()
{
    int M[10][10], n, m;

    printf("Citeste numarul de linii si coloane pentru matrice: ");
    scanf("%d%d", &n, &m);

    printf("Citeste matricea: ");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &M[i][j]);

    int l1, l2;
    printf("Tastati liniile pe care doriti sa le interschimbati: ");
    scanf("%d%d", &l1, &l2);
    schimb(&M[l1][0], &M[l2][0], m);

    printf("Noua matrice:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            printf("%d ", M[i][j]);
        printf("\n");
    }

    /*
    int c1, c2;
    printf("Tastati coloanele pe care doriti sa le interschimbati: ");
    scanf("%d%d", &c1, &c2);
    schimb(&M[0][c1], &M[0][c2], n);

    printf("Noua matrice:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            printf("%d ", M[i][j]);
        printf("\n");
    }
    */

	return 0;
}
