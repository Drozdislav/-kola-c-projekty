#include "duleziteFunkce.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Tmatice * novaMatice(int r, int s) {
 Tmatice * matice = malloc(sizeof(Tmatice));

  // Pokud se nepovedlo alokovat strukturu, vratim NULL.
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


  // Vyrobim pole.
  Tmatice * m = novaMatice(r,s);
  if (m == NULL)
    return m;

  // etu nanejvys dimenze souradnic.
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
Vrati zbytek po vydeleni dvou ciswel
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

//--------------------OSM DAM--------------------

TReseni *reseniHead = NULL;

void polozDamu(TSach *plocha, int x, int y)
{
    plocha->ypozice[x] = y;
    plocha->jevradku[y] = true;
    plocha->jesikmozprava[x - y + 7] = true;
    plocha->jesikmozleva[x + y] = true;
}

void zapamatuj(TSach *plocha)
{
    TReseni *novyUzel = (TReseni *)malloc(sizeof(TReseni));
    if (novyUzel == NULL) {
        printf("Chyba alokace paměti!\n");
        return;
    }

    for (int i = 0; i < 8; i++) {
        novyUzel->ypozice[i] = plocha->ypozice[i];
    }

    novyUzel->next = reseniHead;
    reseniHead = novyUzel;
}

void odeberDamu(TSach *plocha, int x, int y)
{
    plocha->ypozice[x] = 0;
    plocha->jevradku[y] = false;
    plocha->jesikmozprava[x - y + 7] = false;
    plocha->jesikmozleva[x + y] = false;
}

bool jeOhrozena(TSach *plocha, int x, int y)
{
    if (plocha->jevradku[y] || plocha->jesikmozleva[x + y] || plocha->jesikmozprava[x - y + 7])
        return true;
    else
        return false;
}

void zkusSloupec(TSach *plocha, int x)
{
    for (int y = 0; y < 8; y++)
    {
        if (!jeOhrozena(plocha, x, y))
        {
            polozDamu(plocha, x, y);

            if (x == 7)
                zapamatuj(plocha);
            else
                zkusSloupec(plocha, x + 1);

            odeberDamu(plocha, x, y);
        }
    }
}

void tiskReseniOsmiDam()
{
    int volba;
    printf("-------------------- RESENI OSMI DAM --------------------\n");
    printf("Zvol si, ktery styl reseni chces, aby ti program vytiskl:\n");
    printf("Tisk reseni v ciselne forme.............................1\n");
    printf("Tisk reseni v obrazkove forme...........................2\n");
    scanf("%d", &volba);
    switch (volba)
    {
        case 1:
            printf("1. Tisk reseni v ciselne forme:\n");
            TReseni *aktualni1 = reseniHead;
            int cisloReseni1 = 1;
            while (aktualni1)
            {
                printf("Reseni %d: ", cisloReseni1++);
                for (int i = 0; i < 8; i++)
                {
                    printf("%d ", aktualni1->ypozice[i]);
                }
                printf("\n");
                aktualni1 = aktualni1->next;
            }
        break;

        case 2:
            printf("2. Tisk reseni v obrazkove forme:\n");
            TReseni *aktualni2 = reseniHead;
            int cisloReseni2 = 1;
            while (aktualni2)
            {
                printf("Reseni %d:\n", cisloReseni2++);

                for (int i = 0; i < 8; i++)
                {
                    for (int j = 0; j < 8; j++)
                    {
                        if (aktualni2->ypozice[j] == i)
                            printf("[o]");
                        else
                            printf("[ ]");
                    }
                    printf("\n");
                }

                printf("\n");
                aktualni2 = aktualni2->next;
            }
            break;
        default:
            printf("Neplatna volba. Zadejte 1 nebo 2.\n");
    }


}

void testOsmiDam()
{
    TSach plocha = {
        .ypozice = {0},
        .jevradku = {false},
        .jesikmozleva = {false},
        .jesikmozprava = {false},
    };

    zkusSloupec(&plocha, 0);
    tiskReseniOsmiDam();
}
