#include <stdio.h>

int main()
{
    char c;

    scanf("%c", &c);

    if(c >= 'A' && c <= 'Z')
        printf("Litera mare.");
    else if(c >= 'a' && c <= 'z')
        printf("Litera mica.");
    else if(c >= '0' && c <= '9')
        printf("Cifra.");
    else
        printf("Alt caracter.");

    return 0;
}
