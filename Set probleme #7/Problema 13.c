#include <stdio.h>
#include <string.h>

void sterge(char s[], int p, int n)
{
    for(int i = 1; i <= n; i++)
        strcpy(s+p, s+p+1);
}

void inserare(char s[], char sdat[], int q)
{
    char aux[25];

    strcpy(aux, s+q); strcpy(s+q, sdat); strcat(s+1, aux);
}

int main()
{
    char s[50], a[10], b[10];

    gets(s); gets(a); gets(b);

    char *p; p = strstr(s, a);

    while(p)
    {
        sterge(s, strlen(s)-strlen(p), strlen(a));
        inserare(s, b, strlen(s)-strlen(p));
        p = strstr(s + strlen(s)-strlen(p), a);
    }

    puts(s);

    return 0;
}
