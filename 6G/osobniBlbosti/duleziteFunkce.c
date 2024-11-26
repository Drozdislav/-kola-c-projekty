#include "duleziteFunkce.h"
#include <stdio.h>
#include <stdlib.h>

Tmatice * novaMatice(int r, int s) {
 Tmatice * matice = malloc(sizeof(Tmatice));

  // Pokud se nepovedlo alokovat strukturu, vrátím NULL.
  if (matice == NULL)
    return NULL;

    matice->radku=r;
    matice->sloupcu=s;

  return matice;
}


void uvolniMatici(Tmatice *m) {
free(m);
}

Tmatice * nactiMatici(FILE *in) {

int r,s;
  if (fscanf(in, "%d%d", &r, &s) != 2 || r <= 0 || s <= 0)
    return NULL;


  // Vyrobím pole.
  Tmatice * m = novaMatice(r,s);
  if (m == NULL)
    return m;

  // Ètu nanejvýš dimenze souøadnic.
  for (uint i = 0; i < m->radku; i++)
  {
      for(uint j=0; j< m->sloupcu; j++) {
        if (fscanf(in, "%f", &m->prvek[i][j]) != 1) {
            m->radku=i;
            m->sloupcu=j;
            return m;
            }
            }
    }

  return m;
}



void tiskniMatici(FILE *out, Tmatice *m){
 for (uint i = 0; i < m->radku; i++)
  {
      fprintf(out, "\n");
      for(uint j=0; j< m->sloupcu; j++) {
            fprintf(out, "%5.1f", m->prvek[i][j]);

            }

}

}

int jsouStejne(Tmatice *m1, Tmatice *m2){
if(m1->radku != m2->radku || m1->sloupcu != m2->sloupcu) {
    printf("matice nemaji stejnou velikost");
    return -1;
    }
return 0;
}

Tmatice * sectiMatice(Tmatice *m1, Tmatice *m2) {
    Tmatice * m3 = novaMatice(m1->radku,m1->sloupcu);
if(jsouStejne == 0) {

    for (uint i = 0; i < m1->radku; i++)
  {
      for(uint j=0; j< m1->sloupcu; j++) {
            m3->prvek[i][j] = m1->prvek[i][j] + m2->prvek[i][j];

            }

}
}



return m3;

}
/*
Vrátí zbytek po vydelení dvou ciswel
*/
int zbytekPoDeleni(int dividend, int divisor) {
    return dividend % divisor;  // Modulo operator returns the remainder
}

int getPocetCifer10do2(int cislo)
{
    int n = 1;
    int pocetCifer = 1;
    while(cislo>n)
    {
        n = n*2;
        pocetCifer = pocetCifer + 1;
    }
    return pocetCifer;
}

int z10doBin(int cislo)
{
    if(cislo<0)
    {
        cislo = cislo*(-1);
    }
    int n = 1;
    int pocetCifer = 1;
    while(cislo>n)
    {
        n = n*2;
        pocetCifer = pocetCifer + 1;
    }

    int x[pocetCifer+1];

    for(int i = 0; i<pocetCifer; i++)
    {
        if(zbytekPoDeleni(cislo,n) == 0)
        {
            x[i] = 1;
        }
        else
        {
            x[i] = 0;
        }
    }
    return x;
}

void vypis1DpoleCISLA(int pole[], int pC)
{
    printf("Vypis pole: \n");
    for(int i = 0; i<pC; i++)
    {
        printf("%d", pole[i]);
    }
}


