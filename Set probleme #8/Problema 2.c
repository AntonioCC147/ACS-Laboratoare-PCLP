#include <stdio.h>

typedef struct timp{
    int ora, minut, secunda;
};

struct timp f(struct timp mom1, struct timp mom2, struct timp S)
{
    S.secunda = mom1.secunda + mom2.secunda;
    S.minut = mom1.minut + mom2.minut;
    S.ora = mom1.ora + mom2.ora;

    while(S.secunda >= 60)
    {
        S.minut = S.minut + 1;
        S.secunda = S.secunda - 60;
    }

    while(S.minut >= 60)
    {
        S.ora = S.ora + 1;
        S.minut = S.minut - 60;
    }

    return S;
}

int main()
{
    struct timp mom1, mom2, S;

    printf("Cititi datele primului moment (ora / minut / secunda): ");
    scanf("%d%d%d", &mom1.ora, &mom1.minut, &mom1.secunda);

    printf("Cititi datele celui de-al 2-lea moment (ora / minut / secunda): ");
    scanf("%d%d%d", &mom2.ora, &mom2.minut, &mom2.secunda);

    S = f(mom1, mom2, S);

    printf("Suma momentelor este: %d ore, %d minute, %d secunde.", S.ora, S.minut, S.secunda);

	return 0;
}
