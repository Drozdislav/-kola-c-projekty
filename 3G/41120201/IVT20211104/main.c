#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, K=0, Z=0;
    printf("zadej cislo ");
    scanf("%d", &x);

    while(x!=0)
    {
        if(x>0)
            K++;
        else
            Z++;

    printf("zadej cislo:" );
    scanf("%d", &x);
    }
    printf("kladnych: %d, zapornych %d",K, Z);

    return 0;
}
