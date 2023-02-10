#include <stdio.h>
#include <string.h>

typedef struct timp{
    int ora, minut, secunda;
};

typedef struct data{
    int zi, luna, an;
    struct timp moment;
};

int main()
{
    struct data calendar;

    printf("Citeste ziua: "); scanf("%d", &calendar.zi);
    printf("Citeste luna: "); scanf("%d", &calendar.luna);
    printf("Citeste anul: "); scanf("%d", &calendar.an);
    printf("Citeste ora: "); scanf("%d", &calendar.moment.ora);
    printf("Citeste minutul: "); scanf("%d", &calendar.moment.minut);
    printf("Citeste secunda: "); scanf("%d", &calendar.moment.secunda);

    printf("Datele sunt:\n");
    printf("Ziua %d, Luna %d, Anul %d, Ora %d, Minutul %d, Secunda %d.",
                            calendar.zi, calendar.luna, calendar.an, calendar.moment.ora, calendar.moment.minut, calendar.moment.secunda);

	return 0;
}
