/* Projekt: pr6-cviko00-cteni-psani
 * Autor: David Martinek
 * Datum: 2024-09-09
 *
 * Modul: Typ vektor
 *
 * Popis: Implementace funkcí deklarovaných v hlavičkovém souboru vektor.h.
 *
 */

#include "vektor.h"
#include <stdlib.h>

Tvektor * novyVektor(uint dimenze)
{
  Tvektor * vektor = malloc(sizeof(Tvektor));

  // Pokud se nepovedlo alokovat strukturu, vrátím NULL.
  if (vektor == NULL)
    return NULL;

  vektor->souradnice = malloc(dimenze*sizeof(float));

  // Pokud se nepovedlo alokovat pole, vrátím NULL.
  if (vektor->souradnice == NULL)
  {
    free(vektor); // nezapomeň uvolnit už vyrobenou strukturu
    return NULL;
  }

  vektor->dimenze = dimenze;
  return vektor;
}

void uvolniVektor(Tvektor *v)
{
  // Uvolní dynamicky alokované pole z paměti.
  free(v->souradnice);

  free(v);
}


Tvektor * nactiVektorZeSouboru(FILE *f)
{
// Postup:
// 1. Přečte délku souboru z prvního řádku.
// 2. Pomocí funkce novyVektor vyrobí proměnou vektor (typu Tvektor *).
//    Pokud se to nepovede, vrátí funkční hodnotu NULL. Indikuje tím chybu.
// 3. Načte prvky ze souboru do pole (maximálně počet uvedený na 1. řádku).
//    Pokud je v souboru prvků méně, upraví údaj vektor->dimenze a vrátí zkrácené pole.
// 4. Vrátí ukazatel na strukturu s polem.

  // Načtu počet prvků z prvního řádku souboru.
  int dim;
  if (fscanf(f, "%d", &dim) != 1 || dim <= 0)
    return NULL;

  uint dimenze = (uint)dim;

  // Vyrobím pole.
  Tvektor * v = novyVektor(dimenze);
  if (v == NULL)
    return v;

  // Čtu nanejvýš dimenze souřadnic.
  for (uint i = 0; i < dimenze; ++i)
  {
    // Pokud nastane při čtení chyba, aktuální počet prvků je konečná délka a skončím.
    if (fscanf(f, "%f", &v->souradnice[i]) != 1)
    {
      v->dimenze = i;
      return v;
    }
  }

  return v;
}

void tiskniVektor(FILE *out, Tvektor * vektor)
{
  fprintf(out, "%d\n", vektor->dimenze);
  for (uint i = 0; i < vektor->dimenze; ++i)
  {
    fprintf(out, "  %g\n", vektor->souradnice[i]);
  }
}

