#include <stdio.h>

int main()
{
	char a[20], b[20];

	gets(a); gets(b);

	char *p = strstr(a, b);

	if(p == NULL)
    {
        printf("Sirul %s nu se gaseste in sirul %s.", b, a);
        return 1;
    }

	if(strstr(a + (strlen(a) - strlen(p) + strlen(b)), b) != NULL)
        printf("Sirul %s se gaseste de mai multe ori in sirul %s.", b, a);
    else
        printf("Sirul %s se gaseste o singura data in sirul %s.", b, a);
	return 0;
}
