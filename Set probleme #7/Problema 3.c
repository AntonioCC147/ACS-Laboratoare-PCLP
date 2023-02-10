#include <stdio.h>
#include <string.h>

int main()
{
	char n1[25], n2[25]; int v1, v2;

	gets(n1); scanf("%d", &v1);
	gets(n2); gets(n2); scanf("%d", &v2);

	if(strcmp(n1, n2) == 0)
        printf("Numele sunt identice");
    else if(v1 < v2)
            puts(n1);
        else if(v2 < v1)
            puts(n2);
        else if(v1 == v2)
        {
            puts(n1); puts(n2);
        }

	return 0;
}
