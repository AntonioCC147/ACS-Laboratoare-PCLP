#include <stdio.h>

int main()
{
	char s[25];

	//scanf("%s", &s);
	//printf("Sirul este: %s\n", s);

	gets(s);
	printf("Sirul este: %s", s);

	return 0;
}
