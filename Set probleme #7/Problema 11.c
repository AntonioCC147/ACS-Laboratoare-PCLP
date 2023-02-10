#include <stdio.h>
#include <string.h>

void transf(char text[])
{
    char p = text[0], u = text[strlen(text)-1];

    for(int i = 0; i < strlen(text); i++)
        if(text[i] == p || text[i] == u)
            text[i] = text[i] - 32;
}

int main()
{
	char text[50];

	gets(text);

	transf(text);

	puts(text);

	return 0;
}
