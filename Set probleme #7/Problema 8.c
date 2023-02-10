#include <stdio.h>
#include <string.h>

int main()
{
    char a[20], b[20];

    printf("Citeste sirul a: ");
    gets(a);
    printf("Citeste sirul b: ");
    gets(b);

    if(strcmp(b + strlen(b)-strlen(a), a) == 0)
        printf("%s este sufix al lui %s.", a, b);
    else
        printf("%s nu este sufix al lui %s.", a, b);

	return 0;
}
