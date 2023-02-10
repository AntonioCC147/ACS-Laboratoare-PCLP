#include <stdio.h>
#include <string.h>

void ordonare(char s[]){
    char aux;

    for(int i = 0; i < strlen(s) - 1; i++)
        for(int j = i + 1; j < strlen(s); j++)
            if(s[i] > s[j]){
                aux = s[i]; s[i] = s[j]; s[j] = aux;
            }
}

int main()
{
    char cuv[10][25]; int n, k = 0;

    printf("Citeste numarul de cuvinte: ");
    scanf("%d", &n); getchar();

    printf("Citeste cuvintele: ");
    for(int i = 0; i < n; i++)
        gets(cuv[i]);

    for(int i = 0; i < n; i++)
        ordonare(cuv[i]);

    for(int i = 1; i < n; i++)
        if(strcmp(cuv[0], cuv[i]) == 0)
            k++;

    printf("Din cele %d cuvinte citite, %d sunt anagrame cu primul.", n, k);

	return 0;
}
