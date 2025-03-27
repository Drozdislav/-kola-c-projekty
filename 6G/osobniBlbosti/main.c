#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Needed for strcat
#include <math.h>
#include <stdbool.h>
#include "duleziteFunkce.h"

#define MAXN 100  // Define max string size

void toRoman(int cislo, char *romanCislo)
{
    char *str_romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    romanCislo[0] = '\0';  // Initialize as an empty string
    int i = 0;

    while (cislo > 0)
    {
        while (cislo >= values[i])
        {
            strcat(romanCislo, str_romans[i]);  // Correct way to append strings
            cislo -= values[i];
        }
        i++;
    }
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
    //testOsmiDam();
    char rimskeCislo[MAXN];
    int cislicko = 1974;

    toRoman(cislicko, rimskeCislo);
    printf("Cislo %d na rimske cislice je: %s\n", cislicko, rimskeCislo);

    return 0;
}
