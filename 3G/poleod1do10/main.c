#include <stdio.h>
#include <stdlib.h>
#define POCET 10

int main(int argc, char** argv) {

    int pole[POCET];

    int i;
    for (i = 0; i < POCET; i++)
    {
        pole[i] = i + 1;
    }

    for (i = 0; i < POCET; i++)
    {
        printf("%d ", pole[i]);
    }
    return 0;
}
