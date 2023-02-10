#include <stdio.h>

void schimb(char cuv[])
{
    char c;

    for(int i = 0; i < strlen(cuv); i=i+2)
    {
        c = cuv[i];
        cuv[i] = cuv[i+1];
        cuv[i+1] = c;
    }
}

int main()
{
	char cuv[20];

	gets(cuv);

	schimb(cuv);

	puts(cuv);

	return 0;
}
