#include <stdio.h>

void cit_m(int M[][10], int *n, int *m){

    printf("Citeste numarul de linii si coloane pentru matrice: ");
    scanf("%d%d", n, m);

    printf("Citeste matricea: ");
    for(int i = 0; i < *n; i++)
        for(int j = 0; j < *m; j++)
            scanf("%d", &M[i][j]);
}

void cit_v(int V[], int *p){

    printf("Citeste numarul de elemente pentru vector: ");
    scanf("%d", p);

    printf("Citeste vectorul: ");
    for(int i = 0; i < *p; i++)
        scanf("%d", &V[i]);
}

void identice(int a[][10], int l, int n, int b[], int *k)
{
    int i, j; *k = 1;

    for(i = 0; i < n; i++)
        if(a[l][i] != b[i]){
            *k = 0; i = n;
        }
}

int main()
{
	int M[10][10], n, m, V[10], p, k, verif = 0;

	cit_m(M, &n, &m);
	cit_v(V, &p);

	if(m != p){
        printf("Nu se poate.");
        return 0;
	}

    for(int i = 0; i < n; i++){
        identice(M, i, m, V, &k);
        if(k != 0)
            verif = 1;
    }

    if(verif == 1)
        printf("Cel putin o linie din matrice coincide cu vectorul dat.");
    else
        printf("Nicio linie din matrice nu coincide cu vectorul dat.")

	return 0;
}
