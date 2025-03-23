#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "duleziteFunkce.h"

typedef struct
{
    int ypozice[8];
    bool jevradku[8];
    bool jesikmozleva[15];
    bool jesikmozprava[15];
} TSach;

typedef struct TReseni {
    int ypozice[8];       // Pole pro ulozeni pozic dam v jednotlivxch sloupcich
    struct TReseni *next;  // Ukazatel na dalsi reseni v seznamu
} TReseni;



void testOsmiDam()
{
    TSach plocha =
    {
        .ypozice = {0},
        .jevradku = {false},
        .jesikmozleva = {false},
        .jesikmozprava = {false},
    };

    zkusSloupec(&plocha, 0);


}

void zkusSloupec(TSach *plocha, int x)
{
    for (int y=0; y<7; y++)
    {
        if (!jeOhrozena(plocha, x, y))
        {
            polozDamu(plocha, x, y);

            if(x == 7)
                zapamatuj(plocha);
            else
                zkusSloupec(plocha, x + 1);

            odeberDamu(plocha, x, y);
        }
    }
}

void polozDamu(TSach * plocha, int x, int y)
{
    plocha->ypozice[x] = y;
    plocha->jevradku[y] = true;
    plocha->jesikmozprava[x-y+7] = true;
    plocha->jesikmozleva[x+y] = true;
}

bool jeOhrozena(TSach *plocha, int x, int y)
{
    if(plocha->jevradku[y] || plocha->jesikmozleva[x+y] || plocha->jesikmozprava[x-y+7])
}

void zapamatuj(TSach * plocha)
{
    //tady se budou vkladat spravna reseni do lin. seznamu
}


void odeberDamu(TSach *plocha, int x, int y)
{

}

int main()
{
    /**
    int pocetCifer;
    int x[1000];
    z10doBin(458, x, &pocetCifer);
    vypis1DpoleCISLA(x, pocetCifer);


    float a = 10;
    float b = 20;

    printf("-------------------------\n");

    printf("a: %f, b: %f\n", a,b);

    printf("-------------------------\n");

    swapNumbers(&a,&b);
    printf("a: %f, b: %f\n", a,b);

    printf("-------------------------\n");

    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    vypis1DpoleCISLA(arr,n);
    bubblesort(arr,n);
    vypis1DpoleCISLA(arr,n);

    printf("-------------------------\n");
    float x1 = 0.0;
    float x2 = 0.0;

    quadraticEquationSolver(1,3,-6,&x1,&x2);

    printf("-------------------------\n");

    sumaFaktorialDelenoCislem(5);
    faktorialCisla(5);
    **/
    return 0;
}
