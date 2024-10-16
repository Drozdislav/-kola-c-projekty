#ifndef VEKTOR_H_INCLUDED
#define VEKTOR_H_INCLUDED

/* Projekt: pr6-cviko00-cteni-psani
 * Autor: David Martinek
 * Datum: 2024-09-09
 *
 * Modul: Typ vektor
 *
 * Popis: Obsahuje typy a funkce potřebné pro práci s typem Tvektor, což je
 *        v podstatě pole s proměnnou délkou realizované pomocí struktury.
 */

#include <stdio.h>
#include "gvid.h"

///////////////////////// DEKLARACE DATOVÉ STRUKTURY ///////////////////////////

/** Struktura zastřešující pole a údaj o jeho délce. */
typedef struct vektor
{
  float *souradnice; //< samotné dynamické pole souřadnic - tato složka se indexuje
  uint dimenze;      //< zde se ukládá aktuální délka pole - tedy kolik souřadnic vektor obsahuje
} Tvektor;

///////////////////////// HLAVIČKY POMOCNÝCH FUNKCÍ ////////////////////////////

/** \brief Alokuje v paměti strukturu s polem o zadané délce.
 *
 * Bázovým typem pole souřadnic je float.
 *
 * Pokud není dostatek paměti, vrací NULL.
 *
 * Poznámka: Funkce novyVektor - uvolniVektor se používají analogicky párům
 * funkcí fopen - fclose a malloc - free.
 *
 * \param dimenze uint Požadovaný počet prvků pole.
 * \return Tvektor* Vrací ukazatel na novou strukturu s polem a skutečnou délkou.
 */
Tvektor * novyVektor(uint dimenze);



/** \brief Uvolní alokované pole z paměti.
 *
 * Pozor! Pokus o uvolnění již uvolněného pole může vést k havárii.
 *
 * \param vektor Tvektor* Ukazatel na strukturu s polem alokovanou funkcí
 *                        novyVektor(). Parametr předávaný odkazem.
 */
void uvolniVektor(Tvektor *vektor);



/** \brief Načte souřadnice vektoru ze souboru a vrátí ukazatel na nově vyrobenou strukturu, tedy Tvektor*.
 *
 * V souboru musí být na prvním řádku celé číslo udávající počet souřadnic.
 *
 * Pokud je soubor vadný (například počet je <= 0) nebo není dost paměti pro
 * strukturu Tvektor, funkce vrací NULL. Po použití funkce je třeba výsledek
 * otestovat (podobně jako po použití fopen).
 *
 * \param f FILE* Ukazatel na soubor otevřený pro čtení.
 * \return Tvektor* Vrací ukazatel na strukturu s načteným polem nebo NULL.
 *
 */
Tvektor * nactiVektorZeSouboru(FILE *f);

/** \brief Vytiskne do souboru zadaný vektor.
 *
 * Nejprve tiskne dimenzi vektoru, až pak souřadnice - tak, aby formát
 * odpovídal vstupnímu souboru.
 *
 * Finta: Pro tisk na konzoli stačí při volání místo souboru zadat stdout.
 *
 * \param out FILE* Ukazatel na soubor otevřený pro zápis.
 * \param vektor Tvektor*  Ukazatel na strukturu s polem souřadnic.
 */
void tiskniVektor(FILE *out, Tvektor * vektor);


#endif // VEKTOR_H_INCLUDED
