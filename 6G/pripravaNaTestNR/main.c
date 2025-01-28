#include "kokot.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float horner(Tfce f, float x) {
    float suma = 0.0;
    for (int i = 0; i < f.n; i++) {
        suma = (suma * x) + f.koef[i];
    }
    return suma;
}

float newton(Tfce f, Tfce der, float eps, float x, int *ok) {
    int poc = 1000;
    while(fabs(horner(f, x)) > eps && poc > 0) {
        if (horner(der, x) == 0) {
            *ok = 0;
            return -1;
        }
        x = x - horner(f, x) / horner(der, x);
        poc--;
    }
    if (poc == 0) *ok = 0;
    return x;
}

int main() {
    int ok = 1;
    Tintervaly *intervaly;
    int m;
    Tfce fce, der;
    float eps, r;

    FILE *f = fopen("data1.txt", "r");
    if (f == NULL) {
        perror("Chyba pøi otvírání souboru");
        return -1;
    }

    /** metody **/
    if (fscanf(f, "%c", &m) != 1) {
        printf("Chyba pøi ètení metody\n");
        return -1;
    }

    /** koeficienty funkce **/
    fce = NactiKoef(f);

    /** koeficienty derivace **/
    der = NactiKoef(f);

    /** chyba **/
    if (fscanf(f, "%f", &eps) != 1) {
        printf("Chyba pøi ètení hodnoty chyby\n");
        return -1;
    }

    /** intervaly **/
    intervaly = NactiIntervaly(f);
    if (intervaly == NULL) {
        printf("Problém pøi ètení intervalù\n");
        return -1;
    }

    switch (m) {
        case 'N':
            for (int i = 0; i < intervaly->pocet; i++) {
                ok = 1;
                r = newton(fce, der, eps, intervaly->pole[i].a, &ok);
                if (ok == 1) {
                    printf("Reseni %d. je %f \n", i+1, r);
                } else {
                    printf("Vadne reseni %d\n", i);
                }
            }
            break;
        case 'B':
            printf("Metoda bisekce chybí\n");
            break;
    }

    fclose(f);
    return 0;
}
