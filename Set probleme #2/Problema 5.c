#include <stdio.h>

int main()
{
    int n, term1 = 0, term2 = 1, term3;

    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
        if(i == 1)
        printf("%d ", term1);
        else if(i == 2)
            printf("%d ", term2);
        else
        {
            term3 = term2 + term1;
            term1 = term2; term2 = term3;
            printf("%d ", term3);
        }

    /**
    int v;

    scanf("%d", &v);

    for(int i = 1; i <= n; i++)
        if(i == 1)
        printf("%d ", term1);
        else if(i == 2)
            printf("%d ", term2);
        else
        {
            term3 = term2 + term1;
            term1 = term2; term2 = term3;
            if(term3 >= v)
                i = n;
            else
                printf("%d ", term3);
        }
    **/

    return 0;
}
