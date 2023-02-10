/**
    Cerinta:

    Scrieti o functie care sa aiba ca parametrii (cel putin): o matrice A, un vector v1 si un vector v2. Lista de parametrii va fi completata
    in functie de necesitate!
    Functia trebuie sa verifice daca vectorul v1 reprezinta o linie din matricea A si, daca da, sa inlocuiasca linia respectiva cu vectorul v2.
    Atentie, trebuie tratata si situatia in care vectorul v1 se regaseste in mai multe linii ale matricei A.
    Functia trebuie sa transmita catre main() daca a efectuat cel putin o astfel de inlocuire si, in plus, indicii liniilor care au fost inlocuite.

    PUNCTAJ: 13/15
**/
#include <stdio.h>

void f(int A[][10], int l, int v1[], int v2[], int n, int *verif)
{
    int i, k = 1, OK = 0; *verif = 0;

    for(i = 0; i < n; i++)
        if(A[l][i] != v1[i])
            k = 0;

    if(k == 1)
    {
        for(i = 0; i < n; i++)
            A[l][i] = v2[i];
        if(OK == 0)
            *verif = 1;
    }
}

int main()
{
    int M[10][10], n, m, i, j, verif;

    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &M[i][j]);

    int v1[10], n1, v2[10], n2;

    scanf("%d", &n1);
    for(i = 0; i < n1; i++)
        scanf("%d", &v1[i]);

    scanf("%d", &n2);
    for(i = 0; i < n2; i++)
        scanf("%d", &v2[i]);

    if(n1 != n2 || n1 != m || n2 != m)
    {
        printf("Vectorii nu au lungimi identice. Nu se poate face modificarea.");
        return 0;
    }

    for(i = 0; i < n; i++)
    {
        f(M, i, v1, v2, n1, &verif);
        if(verif == 1)
            printf("S-a modificat linia: %d\n", i);
    }

    printf("\nNoua matrice:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            printf("%d ", M[i][j]);
        printf("\n");
    }

	return 0;
}
