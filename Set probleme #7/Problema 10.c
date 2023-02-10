#include <stdio.h>
#include <string.h>

void vocale(char cuv[])
{
    for(int i = 0; i < strlen(cuv); i++)
        if(strchr("aeiou", cuv[i]) != NULL && cuv[i] >= 'a' && cuv[i] <= 'z')
            cuv[i] = cuv[i] - 32;
}

int main()
{
	char cuv[20];

	gets(cuv);

	vocale(cuv);

	puts(cuv);

	return 0;
}
