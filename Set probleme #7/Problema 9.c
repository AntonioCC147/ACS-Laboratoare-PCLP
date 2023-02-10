#include <stdio.h>
#include <string.h>

int main()
{
    char s[50];

    printf("Cititi sirul: ");
    gets(s);

    for(int i = 0; i < strlen(s); i++)
        if(strchr("aeiou", s[i]) != NULL){
            strcpy(s + i, s + i + 1);
            i--;
        }

    printf("Noul sir: %s.\n", s);

    char subsir[50] = ""; int p, q, k = 0;

    printf("Cititi pozitiile p si q: ");
    scanf("%d%d", &p, &q);

    for(int i = p; i < q; i++)
        subsir[k++] = s[i];

    subsir[k] = '\0';

    printf("Subsirul este: %s.", subsir);

	return 0;
}
