#include <stdio.h>

typedef struct fig_geom{
    char nume;
    union fig{
        int raza;
        struct laturi{
            int lungime, latime;
        }l;
    }f;
};

int main()
{
    struct fig_geom fig;

    do{
        printf("Citeste un caracter de la tastatura (c - cerc, p - patrat, d - dreptunghi):\n");
        scanf("%c", &fig.nume); getchar();
    }while(fig.nume != 'c' && fig.nume != 'p' && fig.nume != 'd');

    switch(fig.nume)
    {
        case 'c': printf("Tastati raza cercului: "); scanf("%d", &fig.f.raza);
                  printf("Perimetrul cercului este %.3f si aria este %.3f.", 2*3.14*fig.f.raza, 3.14*fig.f.raza*fig.f.raza);
            break;
        case 'p': printf("Tastati lungimea patratului: "); scanf("%d", &fig.f.l.lungime); fig.f.l.latime = fig.f.l.lungime;
                  printf("Perimetrul patratului este %d si aria este %d.", 4 * fig.f.l.lungime, fig.f.l.lungime * fig.f.l.latime);
            break;
        case 'd': printf("Tastati lungimea si latimea dreptunghiului: "); scanf("%d%d", &fig.f.l.lungime, &fig.f.l.latime);
                  printf("Perimetrul drepuntghiului este %d si aria este %d.", 2 * fig.f.l.lungime + 2 * fig.f.l.latime, fig.f.l.lungime * fig.f.l.latime);
            break;
    }

	return 0;
}
