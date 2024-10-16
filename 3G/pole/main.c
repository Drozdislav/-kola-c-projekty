#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pole[5], i;

    for(i=0;i<5; i++)
    {
        printf("zadej %d. cislo ", i+1);
        scanf("%d", &pole[i]);
    }

    for(i=4;i>=0;i--)
    {
        printf("%d\n" ,pole[i]);
    }
    return 0;
}
