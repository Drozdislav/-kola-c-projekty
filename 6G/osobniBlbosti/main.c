#include <stdio.h>
#include <stdlib.h>
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

    printf("a: %f, b: %f\n", a,b);
    swapNumbers(&a,&b);
    printf("a: %f, b: %f\n", a,b);

    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    vypis1DpoleCISLA(arr,n);
    bubblesort(arr,n);
    vypis1DpoleCISLA(arr,n);

    return 0;
}
