#ifndef KOKOT_H_INCLUDED
#define KOKOT_H_INCLUDED
#include <stdio.h>
#define maxi 100

typedef struct
{
    float a,b;
} Tinterval;

typedef struct
{
    Tinterval pole[maxi];
    int pocet;
} Tintervaly;

typedef struct
{
    float koef[maxi];
    int n;
} Tfce;

Tintervaly* NactiIntervaly(FILE *f);
Tfce NactiKoef(FILE * f);

#endif // KOKOT_H_INCLUDED
