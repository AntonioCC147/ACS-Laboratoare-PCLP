#include <stdio.h>

int main()
{
    char c;

    scanf("%c", &c);

    for(int i = 1; i <= 3; i++)
    {
        for(int j = 1; j <= i; j++)
            printf("%c", c);
        printf("\n");
    }

    ///Sau
    ///printf("%c\n%c%c\n%c%c%c", c, c, c, c, c, c);

    return 0;
}
