/**
    Cerinta:
        Trebuia sa facem un fel de sistem care determina un numar egal de barbati si femei pentru a putera participa la o extragere pentru o excursie.
        Aveai de citit un numar X care sa fie par. Aveam un fisier care continea angajati (nume si cod) si noi trebuia sa vedem cati sunt pentru a-i
    putea extrage mai apoi.
        Dupa asta citim niste numere ce reprezinta liniile pe care se gasesc angajatii si trebuie sa verificam sa fie jumatate barbati si jumatate femei.
    Barbatii au in cod prima cifra 1, iar femeile 2. Daca nu sunt egali la numar barbatii si femeile, trebuie sa iei de la sfarsit spre inceput numerele
    care nu convin si sa cautam altele incat sa ajungem la un numar egal de femei si barbati. Facem asta pana avem numar egal de barbati si femei.
        La final, optional, se afiseaza informatiile pe ecran despre cei extrasi pentru excursie.

    PUNCTAJ: 50/50
**/
#include <stdio.h>
#include <stdlib.h>

typedef struct angajat{
    char nume[25], cod[10]; ///Consideram numele ca fiind de maxim 25 de caractere, iar codul de 10 caractere, primul caracter fiind 1 sau 2
}ANG;

void verificare(ANG tablou_excursie[], int X, int tablou_reparatii[], int *Y){
    *Y = 0; int nr_b = 0, nr_f = 0;

    for(int i = 0; i < X; i++)
        if(tablou_excursie[i].cod[0] == '1') nr_b++;
        else if(tablou_excursie[i].cod[0] == '2') nr_f++;

    int val;
    if(nr_b != nr_f){
        val = (nr_b + nr_f) / 2;
        ///Dupa ce aflam cati barbati si cate femei ar trebui adaugate in lista, vedem cati dintre "barbati" / cate dintre "femei" sunt mai multi / multe decat ar trebui
        ///Vom parcurge de la final spre inceput tabloul si vom luam fix cate pozitii ne trebuie (numarul de pozitii fiind memorate in variabila "val")
        if(nr_b > nr_f){
            val = nr_b - val;
            for(int i = X - 1; i >= 0; i--)
                if(tablou_excursie[i].cod[0] == '1' && val != 0){
                    tablou_reparatii[(*Y)++] = i; val--;
                }
        }
        else{
            val = nr_f - val;
            for(int i = X - 1; i >= 0; i--)
                if(tablou_excursie[i].cod[0] == '2' && val != 0){
                    tablou_reparatii[(*Y)++] = i; val--;
                }
        }
    }
}

int main()
{
    ///Citirea lui X, dupa conditiile specificate
    int X;
    do{
        printf("Citeste-l pe X, valoare intreaga strict pozitiva si para: "); scanf("%d", &X);
    }while(X <= 0 || X % 2 == 1);

    FILE *fis = fopen("angajati.dat", "rb");
    if(fis == NULL){ printf("\nFisierul nu poate fi deschis!"); exit(1); }

    ///Verificarea numarului total de angajati din fisier
    fseek(fis, 0L, SEEK_END);
    int nr_ang = ftell(fis) / sizeof(ANG);
    fseek(fis, 0L, SEEK_SET);

    if(X > nr_ang){
        printf("\nIn fisier nu exista suficienti angajati!"); exit(1);
    }

    ///Citirea (daca este posibil) a valorilor intregi si pozitive si verificarea introducerii datelor
    int V[25], ver; ///Consideram ca in fisier nu pot exista mai multi de 25 de angajati
    for(int i = 0; i < X; i++){
        do{
            printf("Citeste o valoare pe care nu ai mai citit-o si este mai mica decat %d: ", nr_ang); scanf("%d", &V[i]);
            ver = 1;
            for(int j = 0; j < i; j++)
                if(V[i] == V[j]) ver = 0;
        }while(V[i] > nr_ang || ver == 0);
    }

    ///Citirea din fisier a datelor angajatiilor de pe pozitiile specificate anterior
    ANG tablou_excursie[25];
    for(int i = 0; i < X; i++){
        fseek(fis, sizeof(ANG) * V[i], SEEK_SET);
        fread(&tablou_excursie[i], sizeof(ANG), 1, fis);
    }

    int tablou_reparatii[25], Y = 0;
    do{
        verificare(tablou_excursie, X, tablou_reparatii, &Y);

        if(Y == 0) printf("\nNumarul de barbati si de femei este egal.");

        int Valori_Noi[25], verif;
        ///Daca tablou_reparatii s-a format, citim alte Y valori, respectand toate conditiile date
        if(Y != 0){
            for(int i = 0; i < Y; i++)
                do{
                    printf("\nCiteste o noua valoare, diferita de ce ai mai citit pana acum si care respecta conditiile: "); scanf("%d", &Valori_Noi[i]);
                    verif = 1;
                    for(int j = 0; j < X; j++)
                        if(Valori_Noi[i] == V[j]) verif = 0;
                }while(verif == 0 || Valori_Noi[i] > nr_ang);

            ///Suprascriem noile valori
            for(int i = 0; i < Y; i++){
                fseek(fis, sizeof(ANG) * Valori_Noi[i], SEEK_SET);
                fread(&tablou_excursie[tablou_reparatii[i]], sizeof(ANG), 1, fis);
            }
        }
    }while(Y != 0);

    fclose(fis);

    ///Afisarea finala a continutului tabloului
    printf("\n");
    for(int i = 0; i < X; i++)
        printf("\n# Angajat %d: Nume: %s; Cod: %s;", i+1, tablou_excursie[i].nume, tablou_excursie[i].cod);

    return 0;
}
