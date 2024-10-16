#include <stdio.h>
#include <stdlib.h>

int main()
{
    int K=1000, P=0, x;

    while(K>0)
    {
        printf(" zadej balik: ");
        scanf("%d", &x);
        if(K>=x){
            K=K-x;
            P++;
        }

        else {
            printf("nevleze");
        }
    printf("%d", K);
    }



    return P;

    return 0;
}
