#include <stdio.h>

int perfect(int n)
{
    int div, S = 0;

    for(div = 1; div <= n / 2; div++)
        if(n % div == 0)
            S = S + div;

    if(n == S)
        return 1;
    else
        return 0;
}

int main()
{
	int numar;

	scanf("%d", &numar);

	if(perfect(numar) == 1)
        printf("Numarul este perfect.");
    else
        printf("Numarul nu este perfect.");

	return 0;
}
