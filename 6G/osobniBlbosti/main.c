#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "duleziteFunkce.h"


int main()
{
    /**
    int pocetCifer;
    int x[1000];
    z10doBin(458, x, &pocetCifer);
    vypis1DpoleCISLA(x, pocetCifer);
    **/

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
    return 0;
}
