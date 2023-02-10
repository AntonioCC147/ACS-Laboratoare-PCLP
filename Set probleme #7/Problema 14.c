#include <stdio.h>
#include <string.h>

int main()
{
	char text[20][20], cuv[20]; int n, i, nr_ap = 0;

	scanf("%d", &n);

	for(i = 0; i < n; i++)
	{
        scanf("%s", text[i]);
        getchar();
    }

    gets(cuv);

    for(i = 0; i < n; i++)
        if(strcmp(text[i], cuv) == 0)
            nr_ap++;

    printf("Numarul de aparitii al cuvantului %s in text este de %d ori.", cuv, nr_ap);

	return 0;
}
