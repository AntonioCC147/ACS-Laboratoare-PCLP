#include <stdio.h>

struct nr_complex
{
    int real, imaginar;
};

void f(struct nr_complex a, struct nr_complex b, struct nr_complex *S, struct nr_complex *D)
{

    (*S).real = a.real + b.real;
    (*S).imaginar = a.imaginar + b.imaginar;

    (*D).real = a.real - b.real;
    (*D).imaginar = a.imaginar - b.imaginar;
}

int main()
{
    struct nr_complex nr1, nr2, S, D;

    printf("Cititi primul numar (parte reala / parte imaginara): ");
    scanf("%d%d", &nr1.real, &nr1.imaginar);

    printf("Cititi al doilea numar(parte reala / parte imaginara): ");
    scanf("%d%d", &nr2.real, &nr2.imaginar);

    f(nr1, nr2, &S, &D);
    printf("Suma numerelor este %d si %di.\n", S.real, S.imaginar);
    printf("Diferenta numerelor este %d si %di.", D.real, D.imaginar);

	return 0;
}
