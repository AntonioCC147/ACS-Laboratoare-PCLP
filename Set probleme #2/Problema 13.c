#include <stdio.h>

int main()
{
    int n;

    scanf("%d", &n);

    switch(n){
        case 1: printf("Luni"); break;
        case 2: printf("Marti"); break;
        case 3: printf("Miercuri"); break;
        case 4: printf("Jii"); break;
        case 5: printf("Vineri"); break;
        case 6: printf("Sambata"); break;
        case 7: printf("Duminica"); break;
        default: printf("Eroare");
    }

    return 0;
}
