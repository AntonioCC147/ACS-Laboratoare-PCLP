#include <stdio.h>

int main()
{
    char c;

    scanf("%c", &c);

    //a)
    printf("Codul ASCII al caracterului %c = %d.\n", c, c);

    //b)
    printf("%c\n", c+1);

    //c)
    printf("%c%c%c%c%c\n",'a', 'a'+1, 'a'+2, 'a'+3, 'a'+4);

    //d)
    printf("%c", 'A'+15);

    return 0;
}
