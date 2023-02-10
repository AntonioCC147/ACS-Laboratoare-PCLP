#include <stdio.h>
#include <string.h>

int main()
{
	char text[50], cuv[50]; int nr_cuv = 0;

	gets(text);

	for(int i = 0; i < strlen(text); i++)
	{
        if(text[i] == ' ')
        {
            nr_cuv++;
            printf("\n");
        }
        else
            printf("%c", text[i]);
    }

    printf("\nTextul contine %d cuvinte.", nr_cuv + 1);

	return 0;
}
