#include "duleziteFunkce.h"
#include <stdio.h>
#include <stdlib.h>

Tmatice * novaMatice(int r, int s) {
 Tmatice * matice = malloc(sizeof(Tmatice));

  // Pokud se nepovedlo alokovat strukturu, vr�t�m NULL.
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


  // Vyrob�m pole.
  Tmatice * m = novaMatice(r,s);
  if (m == NULL)
    return m;

  // �tu nanejv�� dimenze sou�adnic.
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
Vr�t� zbytek po vydelen� dvou ciswel
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

void z10doBin(int cislo, int x[], int *pocetCifer) {
    int n = 1;
    *pocetCifer = 0;
    while (cislo > n) {
        n = n * 2;
        (*pocetCifer)++;
    }

    for (int i = *pocetCifer - 1; i >= 0; i--) {
        x[i] = cislo % 2;
        cislo /= 2;
    }
}

void vypis1DpoleCISLA(int pole[], int pC)
{
    printf("Vypis pole: \n");
    for(int i = 0; i<pC; i++)
    {
        printf(" %d", pole[i]);
    }
    printf("\n");
}

void bubblesort(float pole[], int n)
{
    float pom;

    for(int i = 0; i<n-1 ; i++)
    {
        for(int j = 0; j<n-i-1; j++)
        {
            if(pole[j] > pole[j+1])
            {
                swapNumbers(&pole[j], &pole[j+1]);
            }
        }
    }
}


void swapNumbers(float *cislo1, float *cislo2)
{
    float pomocna;
    pomocna = *cislo1;
    *cislo1 = *cislo2;
    *cislo2 = pomocna;
}


void quadraticEquationSolver(float a, float b, float c, float * x1, float * x2)
{
    float discr = (b*b) - (4 * a * c);

    if(discr < 0)
    {
        printf("Discriminant is less than zero, equation has no result\n");
        return;
    }
    else if(discr == 0)
    {
        *x1 = (-b)/(2*a);
        printf("discriminant is zero, equation has one result: x1 = %2.f\n", &x1);
        printf("result was put inside the x1 variable\n");
    }
    else
    {
        *x1 = ((-b) + sqrt(discr))/2*a;
        *x2 = ((-b) - sqrt(discr))/2*a;
        printf("discriminant is more zero, equation has two result: x1 = %.4f, x2 = %.4f\n", *x1, *x2);
        printf("result was put inside the x1 and x2 variable\n");
    }
}


int faktorialCisla(int cislo)
{
    int faktorial = 1;

    for(int i = 1; i<cislo+1; i++)
    {
        faktorial = faktorial * i;
    }
    //printf("faktorial %d je %d\n", cislo, faktorial);
    return faktorial;
}


void sumaFaktorialDelenoCislem(int cislo)
{
    int suma = 0;
    int pom = 0;

    for(int i = 1; i<cislo+1; i++)
    {
        pom = faktorialCisla(i);
        suma = suma + (pom/i);
    }
    printf("Vysledek prikladu se scitanim a delenim faktorialu je: %d\n", suma);
}

