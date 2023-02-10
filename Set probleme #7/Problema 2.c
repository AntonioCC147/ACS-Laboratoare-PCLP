#include <stdio.h>

int main()
{
	char s[25]; int i;

	gets(s);

	for(i = 0; s[i]; i++)
        printf("%c ", s[i]);

    printf("\nNumarul de caractere este %d.", i);

	return 0;
}
