#include <stdio.h>

int main()
{
	int v[10], n, i, j, contor, max = 1;

	printf("Citeste numarul n: ");
	scanf("%d", &n);

	printf("Citeste tabloul: ");
	for(i = 0; i < n; i++)
        scanf("%d", &v[i]);

    for(i = 0; i < n; i++)
    {
        contor = 1;
        for(j = i + 1; j < n; j++)
            if(v[i] == v[j])
                contor++;
        if(contor > max)
            max = contor;
    }

    printf("Valorile cu cele mai multe aparitii sunt: ");
    for(i = 0; i < n; i++)
    {
        contor = 1;
        for(j = i + 1; j < n; j++)
            if(v[i] == v[j])
                contor++;
        if(contor == max)
           printf("%d ", v[i]);
    }

	return 0;
}
