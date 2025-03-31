#ifndef MOJEMATICE_H_INCLUDED
#define MOJEMATICE_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>
#define MAXN 100

typedef unsigned int uint;

typedef struct _matice {
    float prvek[MAXN][MAXN];
    uint radku, sloupcu;
} Tmatice;

typedef struct
{
    int ypozice[8];
    bool jevradku[8];
    bool jesikmozleva[15];
    bool jesikmozprava[15];
} TSach;

typedef struct TReseni {
    int ypozice[8];       // Pole pro ulozeni pozic dam v jednotlivych sloupcich
    struct TReseni *next;  // Ukazatel na dalsi reseni v seznamu
} TReseni;

/** \brief Uvolni alokovanou pamet pro strukturu matice */
void uvolniMatici(Tmatice *m);

/** \brief Secte dve matice stejneho rozmeru */
Tmatice * sectiMatice(Tmatice *m1, Tmatice *m2);

/** \brief Nacte matici ze souboru */
Tmatice * nactiMatici(FILE *in);

/** \brief Vytiskne matici do souboru */
void tiskniMatici(FILE *out, Tmatice *m);

/** \brief Vrati zbytek po deleni dvou cisel */
int zbytekPoDeleni(int dividend, int divisor);

/** \brief Vrati pocet bitu potrebnych k vyjadreni cisla v binarni soustave */
int getPocetCifer10do2(int cislo);

/** \brief Vypise jednorozmerne pole cisel */
void vypis1DpoleCISLA(int pole[], int pC);

/** \brief Prevede cislo z desitkove do binarni soustavy */
void z10doBin(int cislo, int x[], int *pocetCifer);

/** \brief Prohodi hodnoty dvou cisel */
void swapNumbers(float *cislo1, float *cislo2);

/** \brief Seradi pole cisel pomoci algoritmu Bubble Sort */
void bubblesort(float pole[], int n);

/** \brief Vyresi kvadratickou rovnici se zadanymi koeficienty */
void quadraticEquationSolver(float a, float b, float c, float * x1, float * x2);

/** \brief Vrati faktorial zadaneho cisla */
int faktorialCisla(int cislo);

/** \brief Vypocita soucet posloupnosti 1!/1 + 2!/2 + ... + N!/N */
void sumaFaktorialDelenoCislem(int cislo);

/** \brief Polozí damu na sachovnici na zadane souradnice */
void polozDamu(TSach *plocha, int x, int y);

/** \brief Ulozi aktualni reseni do seznamu vysledku */
void zapamatuj(TSach *plocha);

/** \brief Odebere damu ze sachovnice ze zadanych souradnic */
void odeberDamu(TSach *plocha, int x, int y);

/** \brief Zkontroluje, zda je dane pole ohrozeno jinou damou */
bool jeOhrozena(TSach *plocha, int x, int y);

/** \brief Rekurzivne prozkoumava moznosti umisteni dam ve sloupci */
void zkusSloupec(TSach *plocha, int x);

/** \brief Vytiskne nalezena reseni problemu osmi dam */
void tiskReseniOsmiDam();

/** \brief Spusti reseni problemu osmi dam a zobrazi vysledky */
void testOsmiDam();

void vypisFibonacci(int max, int predchozi, int kurentni);

void toRoman(int cislo, char *romanCislo);

#endif // MOJEMATICE_H_INCLUDED
