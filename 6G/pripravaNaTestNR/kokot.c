#include <stdio.h>
#include <stdlib.h>
#include "kokot.h"

//printf("penis");

Tintervaly* NactiIntervaly(FILE *f)
{
    int pocet;
    Tintervaly *poleI;

    if(f==NULL) return NULL;
    fscanf(f, "%d", &pocet);
    poleI = malloc(sizeof(Tintervaly));
    if(poleI==NULL) return NULL;

    poleI->pocet = pocet;
    for(int i = 0; i<pocet; i++)
    {
        fscanf(f, "%f%f", &(poleI->pole[i].a), &(poleI->pole[i].b));

    }
    return poleI;
}

Tfce NactiKoef(FILE * f)
{
    int pocet;
    Tfce fce;
     if(f==NULL)
     {
         fce.n = -1;
         return fce;
     }
    fscanf(f, "%d", &pocet);
    if (pocet <= 0)
    {
        fce.n = -1;
        return fce;
    }

    fce.n = pocet;
    for(int i = 0; i<pocet; i++)
    {
        fscanf(f, "%f", &fce.koef[i]);
    }

    return fce;
}
