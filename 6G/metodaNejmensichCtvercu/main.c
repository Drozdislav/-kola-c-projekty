#include <stdio.h>
#include <stdlib.h>
#include "pole.h"

typedef struct
{
    double prvek[2][3];
    int radku,sloupcu;
} TMatice;

void konRegrese(double y[], int n, double *b)
{
    double sumy = 0.0;

    for(int i = 0; i<n; i++)
    {
        sumy = sumy + y[i];
    }

    *b = sumy / n;
}


void linRegrese(double x[], double y[], int n, double *a, double *b)
{
    double sumx = 0.0;
    double sumx2 = 0.0;
    double sumy = 0.0;
    double sumxy = 0.0;
    for(int i = 0; i < n; ++i)
    {
        sumx = sumx + x[i];
        sumx2 = sumx2 + x[i] * x[i];
        sumxy = sumxy + x[i] * y[i];
        sumy = sumy + y[i];
    }

    TMatice m = {
  .prvek =
  {
    {1.1, 2.2, 3.3},
    {4.4, 5.5, 6.6},
  },
  .radku = 2,
  .sloupcu = 3,
};

 // øešení soustavy lineárních rovnic napøíklad zavoláním funkce pro
 // Gaussovu eliminaèní metodu

 *a = (sumxy - (sumy*sumx)/n) / (sumx2 - (sumx*sumx)/n); //MISTO TOHOHLR TAM BUDE PRPRAVENA GAUSOVA FUNKCE UZ OD MARTINKA
 *b = (sumy - *a *sumx) /n; // MUSIS JI UMET ZAVOLAT
 }



int main() //cau bunisku
{
    double a;
    double b;

    linRegrese(TAB_X, TAB_Y, TAB_LEN, &a, &b);

    printf("y=%.2f x+%.2f\n", a,b);

    konRegrese(TAB_Y, TAB_LEN, &b);

    printf("y = %.2f\n", b);


    return 0;
}
