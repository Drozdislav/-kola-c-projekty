#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=100, i;
    float S=0, x=0.01;

    for(i=1; i<=n; i++)
    {
    S = S + x;
    }

    printf("vysledek je %f",S);

    return 0;
}
