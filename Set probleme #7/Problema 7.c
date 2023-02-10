#include <stdio.h>
#include <string.h>

void inlocuire(char s[]){
    for(int i = 0; i < strlen(s); i++)
        if(s[i] == 'z')
            s[i] = 'a';
        else if(s[i] != ' ')
            s[i]++;
}

int main()
{
    char s[25];

    printf("Citeste sirul: ");
    gets(s);

    inlocuire(s);

    printf("Noul sir este: ");
    puts(s);

	return 0;
}
