/*
 * Projekt:
 * Autor:
 * Datum:
 */
#include "mojematice.h"
#include "gvid.h"       // par drobnosti pro zjednoduseni prace
#include <stdio.h>
#include <stdlib.h>
// #include <string.h>  // pro praci s textovymi retezci
// #include <stdbool.h> // pro praci s typem bool a konstantami true a false
// #include <ctype.h>   // isalpha, isspace, islower, isupper, ...
// #include <math.h>    // funkce z matematicke knihovny
// #include <float.h>   // konstanty pro racionalni typy DBL_MAX, DBL_DIG, ...
// #include <limits.h>  // konstanty pro celociselne typy INT_MAX, INT_MIN, ...
// #include <time.h>    // funkce time a dalsi pro praci s casem

void test(void)
{
  printf("\n buna je neger!\n");
}


//int main(int argc, char *argv[])  // pro parametry prikazoveho radku
int main(void)
{
FILE* in = fopen("matice.txt", "r");
    if(in == NULL) return -1;

FILE* in2 = fopen("matice2.txt", "r");
    if(in == NULL) return -1;

Tmatice * matice = nactiMatici(in);

Tmatice * matice2 = nactiMatici(in2);

tiskniMatici(stdout, sectiMatice(matice, matice2));
uvolniMatici(matice);
uvolniMatici(matice2);
  test();

  return 0;
}
