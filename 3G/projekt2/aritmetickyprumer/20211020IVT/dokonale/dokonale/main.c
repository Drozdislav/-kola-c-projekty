#include <stdio.h>
#include <stdlib.h>

int dokonale(int n)
{

 int S=0, i=0;

 for(i=1; i<= n/2; i++)
 {
    if(n%i==0)
        S=S+i;
 }

 if(S==n)
    return 1;
 else
    return 0;
}

int main()
{
    int n;

    printf("zadej cislo: ");
    scanf("%d", &n);


    if (dokonale(n)==1)
        printf("cislo doko");
        else
            printf("cislo nedoko");

return 0;
}
