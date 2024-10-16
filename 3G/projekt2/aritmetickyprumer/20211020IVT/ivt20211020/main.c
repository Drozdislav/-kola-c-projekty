#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    float S=0, x, P;

    printf("Zadej pocet cisel: ");
    scanf("%d", &n);

    for(i=1; i<=n; i++)
    {
        printf("zadej cislo: ");
        scanf("%f", &x);

        S = S + x;
    }

    P = S/n;
    printf("prumer je %.2f",P);

    return 0;
}
