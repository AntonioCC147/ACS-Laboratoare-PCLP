///Cerinta: https://imgur.com/wq43uFA
/// PUNCTAJ: 19/25 (Mi s-a spus ca am incurcat cerintele si am gresit din neatentie, nu din nestiinta)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    struct{
        char denumire_sistem[25], tip_procesor[25];
        float frecventa_procesor;
        int RAM, HDD;
    }sistem;
    int disponibil_stoc;
    float pret;
}Firma;

int verific_calc(Firma V[], int n){
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(strcmp(V[i].sistem.denumire_sistem, V[j].sistem.denumire_sistem) == 0 && strcmp(V[i].sistem.tip_procesor, V[j].sistem.tip_procesor) == 0
                && V[i].sistem.frecventa_procesor == V[j].sistem.frecventa_procesor && V[i].sistem.RAM == V[j].sistem.RAM
                && V[i].sistem.HDD == V[j].sistem.HDD)
                    return 0;
    return 1;
}

void citire_stoc(Firma V[], int *n){
    printf("Citeste numarul de calculatoare pe care doriti sa le introduceti: ");
    scanf("%d", n); getchar();

    for(int i = 0; i < *n; i++){
        do{
            printf("\n#Calculator %d:\n", i+1);
            printf("Denumire sistem: "); gets(V[i].sistem.denumire_sistem);
            printf("Tip procesor: "); gets(V[i].sistem.tip_procesor);
            printf("Frecventa procesor: "); scanf("%f", &V[i].sistem.frecventa_procesor);
            printf("RAM: "); scanf("%d", &V[i].sistem.RAM);
            printf("HDD: "); scanf("%d", &V[i].sistem.HDD);
            printf("Disponibilitate stoc: "); scanf("%d", &V[i].disponibil_stoc);
            printf("Pret: "); scanf("%f", &V[i].pret); getchar();
            if(verific_calc(V, *n) == 0)
                printf("Acest calculator a mai fost introdus. Introduceti altul: ");
        }while(verific_calc(V, *n) == 0);
    }
}

int caut_calculator(float pret_dat, float pret){
    if(pret_dat - 0.1 * pret_dat >= pret && pret <= pret_dat + 0.1 * pret_dat)
        return 1;
    return 0;
}

void disponibil_procesor(Firma V[], int n, char procesor[]){
    int k = 0;

    for(int i = 0; i < n; i++)
        if(strcmp(V[i].sistem.tip_procesor, procesor) == 0 && V[i].disponibil_stoc != 0)
            k++;

    if(k == 0)
        printf("In stoc nu este disponibil niciun sistem care are procesorul %s.", procesor);
    else
        printf("In stoc sunt disponibile %d sisteme care au procesorul %s.", k, procesor);
}

int main()
{
	Firma C[25]; int n;

	citire_stoc(C, &n);

    float pret; int verif = 0;

    printf("Tastati un pret pentru a putea identifica un sistem: "); scanf("%f", &pret);

    for(int i = 0; i < n; i++)
        if(caut_calculator(C[i].pret, pret) == 1){
            printf("Denumire sistem: %s, Tip Procesor: %s, Frecventa Procesor: %.2f, RAM: %d, HDD: %d.\n",
                C[i].sistem.denumire_sistem, C[i].sistem.tip_procesor, C[i].sistem.frecventa_procesor, C[i].sistem.RAM, C[i].sistem.HDD);
            verif = 1;
        }
    if(verif == 0)
        printf("Nu exista pe stoc un astfel de sistem.\n");

    char procesor[25];

    printf("\nTastati un tip de procesor: "); getchar(); gets(procesor);

    disponibil_procesor(C, n, procesor);

	return 0;
}
