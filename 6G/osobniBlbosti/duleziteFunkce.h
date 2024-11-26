#ifndef MOJEMATICE_H_INCLUDED
#define MOJEMATICE_H_INCLUDED


#include <stdio.h>
#define MAXN 100

typedef unsigned int uint;

typedef struct _matice {
    float prvek[MAXN][MAXN];
    uint radku, sloupcu;
} Tmatice;

// Tmatice * novaMatice(int r, int s); B
void uvolniMatici(Tmatice *m);
Tmatice * sectiMatice(Tmatice *m1, Tmatice *m2);
Tmatice * nactiMatici(FILE *in);
void tiskniMatici(FILE *out, Tmatice *m);


int zbytekPoDeleni(int dividend, int divisor);
int getPocetCifer10do2(int cislo);
void vypis1DpoleCISLA(int pole[], int pC);
int z10doBin(int cislo);
#endif // MOJEMATICE_H_INCLUDED
