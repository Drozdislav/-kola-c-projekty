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



double obdelnik(double a, double b, float eps, Tfce func)
{
    double k = 1;
    double h = 0;
    double S = eps + 200;
    double Spred = eps + 100;
    double suma = 0.0;
    int p = 0;

    while(fabs(Spred - S) > eps)
    {
        p++;
        h = (b-a)/k;
        Spred = S;

        for(int i = 0; i<=k-1; i++)
        {
            suma = suma + horner(func,a + (h/2) + i*h);
        }

        S = h * suma;
        printf("%d.S : %.4f\n", p,S);

        k = k*2;
    }
    printf("\n");
    return S;
}




int main() {
    int ok = 1;
    Tintervaly *intervaly;
    int m;
    Tfce fce, der;
    float eps, r;
    Tfce fce1 = { .koef = {-15, -2, 7, 1}, .n = 4};


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

    double vysledekObdelnik = obdelnik(-0.7,0.7,0.000001,fce1);
    printf("Obsah plochy pod grafem je %.2f jednotek\n", vysledekObdelnik);


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
