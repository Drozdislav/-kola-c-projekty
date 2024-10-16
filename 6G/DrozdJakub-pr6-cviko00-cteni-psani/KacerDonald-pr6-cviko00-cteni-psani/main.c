/*
 * Projekt: pr6-cviko00-cteni-psani-reseni
 * Verze: 1.0
 * Autor: Drozd Jakub
 * Datum: 1. 10. 2024
 *
 * Šablona školního projektu © 2021 David Martinek.
 *
 * Zadání:
 * 1. Zorientuj se v připraveném (nehotovém) programu.
 * 2. Doplň kód programu tak, aby vypsal vektor načtený ze zadaného souboru,
 *    pak provedl obrácení pořadí jeho souřadnic a vypsal i tento upravený
 *    vektor.
 *
 * Formát vstupního souboru:
 * - Na prvním řádku je počet souřadnic vektoru, které následují.
 * - Na dalších řádcích jsou prvky - desetinná čísla (typ float).
 * - Pro načtení ze souboru použij vhodnou funkci z modulu vektor.
 *
 * Formát výstupního souboru:
 * - Stejný jako vstupní (včetně 1. řádku)
 * - Tiskni na konzoli (stdout - standardní výstup).
 * - Použij vhodnou funkci z modulu vektor.
 *
 * Použij připravený datový typ Tvektor* a hotové funkce z modulu vektor.
 * Tyto funkce si prohlédni, ale znovu je nepiš - máš je pouze použít podle
 * návodu.
 *
 * Doplň kód funkcí main, obratSouradniceVektoru.
 *
 */

// Systémové hlavičkové soubory
#include <stdio.h>
#include <stdlib.h>
// #include <string.h>  // pro práci s textovými řetězci
#include <stdbool.h> // pro práci s typem bool a konstantami true a false
#include <ctype.h>   // isalpha, isspace, islower, isupper, ...
// #include <math.h>    // funkce z matematické knihovny
// #include <float.h>   // konstanty pro racionální typy DBL_MAX, DBL_DIG, ...
// #include <limits.h>  // konstanty pro celočíselné typy INT_MAX, INT_MIN, ...
// #include <time.h>    // funkce time a další pro práci s časem


// Uživatelské hlavičkové soubory
// Prozkoumej je. Fungují jako miniaturní knihovny funkcí.

#include "gvid.h"
// Můžeš použít:
// dprintf() - jako printf, ale pro ladící účely
// vycistiKonzoli() - vyčistí konzoli
// uint - zkratka pro typ unigned int


#include "vektor.h"
//Realizuje typ Tvektor*. (Pracuje se zde s typem "ukazatel na Tvektor"!)
//Pomocí připravených funkcí lze s typem Tvektor* pracovat takto:
//Tvektor* vektor = novyVektor(5); // Alokuje novou strukturu s polem délky 5
//                                 // a vrátí na ni ukazatel.
//vektor->souradnice[index]  // Práce s prvkem pole (souřadnicí) - všimni si,
//                           // že se indexuje pole (složka souradnice) uvnitř
//                           // struktury. Proměnná vektor je ukazatel, proto
//                           // místo . použiješ ->.
//vektor->dimenze        // Přístup k údaji o délce pole
//uvolniVektor(vektor);  // Uvolní alokovanou paměť. (Očekává ukazatel a vektor
//                       // je ukazatel, proto bez &).
//S čistým typem Tvektor se tady nikde pracovat nebude.



///////////////////////////// DOPLŇ ŘEŠENÍ ///////////////////////////////

/** \brief Obrátí souřadnice zadaného vektoru.
 *
 * \param vektor Tvektor* Vektor, jehož souřadnice změní pořadí.
 * \return void
 */
void obratSouradniceVektoru(Tvektor *vektor)
{
    if (vektor == NULL || vektor->dimenze <= 1)
        return;

    for (int i = 0; i < vektor->dimenze / 2; i++)
    {
        // Prohazujeme prvky od začátku a konce
        float temp = vektor->souradnice[i];
        vektor->souradnice[i] = vektor->souradnice[vektor->dimenze - 1 - i];
        vektor->souradnice[vektor->dimenze - 1 - i] = temp;
    }
}

////////////////////////////////// MAIN ////////////////////////////////////////

int main(void)
{
    // Zeptej se uživatele na cestu k souboru s daty.
    char cesta[100];
    printf("Zadej cestu k souboru: ");
    scanf("%99s", cesta);

    // Otevři soubor, jehož název máš v proměnné cesta.
    FILE *f = fopen(cesta, "r");
    if (f == NULL)
    {
        fprintf(stderr, "Chyba! Soubor %s nejde otevřít pro čtení.\n", cesta);
        return 1;
    }

    // Načti soubor pomocí funkce z modulu vektor. Ošetři chybu, kdy funkce vrátí NULL.
    Tvektor *v = nactiVektorZeSouboru(f);
    if (v == NULL)
    {
        fprintf(stderr, "Chyba! Asi není dost paměti pro vytvoření vektoru nebo špatný formát souboru.\n");
        fclose(f);
        return 1;
    }

    // Vytiskni na výstup (stdout) načtený vektor
    printf("Nacteny vektor:\n");
    tiskniVektor(stdout, v);

    // Proveď obrácení souřadnic vektoru.
    obratSouradniceVektoru(v);

    // Vytiskni na výstup obrácený vektor
    printf("Obraceny vektor:\n");
    tiskniVektor(stdout, v);

    // Uvolni paměť, zavři soubor.
    uvolniVektor(v);
    fclose(f);

    return 0;
}
