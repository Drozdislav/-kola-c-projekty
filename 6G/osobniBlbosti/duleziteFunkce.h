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
void z10doBin(int cislo, int x[], int *pocetCifer);

void swapNumbers(float *cislo1, float *cislo2);
void bubblesort(float pole[], int n);


/** \brief Vyresi kvadratickou rovnici kde koeficienty a,b,c jsou float cisla
 *
 * \param float a Koeficient u x na 2.
 * \param float b Koeficient u x.
 * \param float c Realny clen rovnice
 * \param float * x1 Ukazatel na promennou ktera v sobe ma vysledek kdyz je ve vzorci +
 * \param float * x1 Ukazatel na promennou ktera v sobe ma vysledek kdyz je ve vzorci -
 * \return void
 *
 * <p>Funkce vytiskne vysledky na obrazovku i do promenych zadanych uzivatelem.
 * pokud je D = 0, napise se vysledek pouze do x1, pokud je D<0, nezapise se
 * nic a funkce vypise, ze D je mensi nez nula</p>
 */
void quadraticEquationSolver(float a, float b, float c, float * x1, float * x2);

/** \brief Program, ktery vraci faktorial zadaneho cisla int */
int faktorialCisla(int cislo);

/** \brief Write a program in C to find the sum of the series 1!/1+2!/2+3!/3+4!/4+5!/5 using the function. Expected Output : The sum of the series is : 34 */
void sumaFaktorialDelenoCislem(int cislo);
#endif // MOJEMATICE_H_INCLUDED
