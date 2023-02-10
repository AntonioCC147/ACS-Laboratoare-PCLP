#include <stdio.h>
#include <string.h>

int main()
{
	char s[25], *p; int k = 0;

	printf("Citeste sirul: ");
	gets(s);

	p = strtok(s, " ");

	while(p){
        if(strchr("aeiou", p[0]) != NULL && strchr("aeiou", p[strlen(p)-1]) != NULL)
            k++;
        p = strtok(NULL, " ");
	}

	printf("Sirul are %d cuvinte care incep si se termina cu o vocala.", k);

	return 0;
}
