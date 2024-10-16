#include <stdio.h>
#include <stdlib.h>

/** mocnina **/
int mocnina(int x, int n)
{
    int i, v=x;

    for(i=2;i<=n;i=i+1)
    {
        v=v*x;
    }

return v;
}



int main()
{
    int x, n;

    printf("Zadej cislo:");
    scanf("%d",&x);

    printf("Zadej cislo:");
    scanf("%d",&n);


    printf("vysledek je %d",mocnina(x, n));

    return 0;
}
