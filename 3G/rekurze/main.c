#include <stdio.h>
#include <stdlib.h>

int fce(int x)
{
    if(x==0)
        return 1;
    return 2*fce(x-1)+1;
}



int main()
{
    printf("hodnota je %d\n", fce(4));
    return 0;
}
