#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Needed for strcat
#include <math.h>
#include <stdbool.h>
#include "duleziteFunkce.h"

#define MAXN 100  // Define max string size

int cifernySoucet(int zadani, int delitel, int vysledek)
{

    int pom = zadani;
    pom = pom / delitel;
    if(pom == 0)
    {
        return vysledek;
    }
    else
    {
        vysledek = vysledek + pom;
        delitel = delitel * 10;
        vysledek = cifernySoucet(zadani, delitel, vysledek);
    }
    return vysledek;
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

    //testOsmiDam();
    char rimskeCislo[MAXN];
    int cislicko = 1974;

    toRoman(cislicko, rimskeCislo);
    printf("Cislo %d na rimske cislice je: %s\n", cislicko, rimskeCislo);
**/
    //vypisFibonacci(1000000,0,1);
    int zadani = 123456;
    int penis = cifernySoucet(zadani,1,0);
    printf("ciferny soucet %d je %d",zadani,penis);
    return 0;
}
