#include <stdio.h>

void comune(int a[], int n1, int b[], int n2, int c[], int *k)
{
    int i, j; *k = 0;

    for(i = 0; i < n1; i++)
        for(j = 0; j < n2; j++)
            if(a[i] == b[j])
                c[(*k)++] = a[i];
}

int main()
{
	int a[10], n1, i, b[10], n2, j, c[20], n3;

	scanf("%d", &n1);
	for(i = 0; i < n1; i++)
        scanf("%d", &a[i]);

	scanf("%d", &n2);
	for(j = 0; j < n2; j++)
        scanf("%d", &b[j]);

    comune(a, n1, b, n2, c, &n3);

    if(n3 == 0)
        printf("Nu s-au gasit elemente comune.");
    else
        for(i = 0; i < n3; i++)
            printf("%d ", c[i]);

	return 0;
}
