/* Téma matice a moduly - varianta s polem pevných rozměrů
 *
 * Autor: Drozd Jakub
 * Datum: 8.10.2024
 *
 * Verze: 2.1
 * Errata:
 * - maticeVymenRadky: viz záhlaví souboru matice.h
 * - maticeCtiZeSouboru: viz záhlaví souboru matice.h
 * - maticeCtiZeVstupu: viz záhlaví souboru matice.h
 * - testFileRW: Opraveno nesmyslné alokování prázdné matice před čtením
 *   ze souboru.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <float.h>
#include <time.h>

#include "gvid.h"
#include "matice.h"


/** \brief Otestuje operace maticeAlokuj, maticeRandom a maticeTiskni. */
void testInit(void)
{
  printf("==========================================\n");
  printf("Test vytvoreni a inicializace matice\n");
  Tmatice * matice = maticeAlokuj(50000000, 30000000);
//  Tmatice * matice = maticeAlokuj(5, 3);
//  maticeNastavPrvky(matice, 1.2);
  if (matice == NULL)
  { // Matici se nepovedlo vytvořit, tak vytisknu proč a skončím.
    maticeAktualniChyboveHlaseni(stderr);
    return;
  }
  maticeRandom(matice);
  maticeTiskni(matice);

  maticeUvolni(matice);

  printf("==========================================\n");
}






/** \brief Otestuje funkce pro čtení ze a zápis do souboru.
 *
 * \param input char*   Jméno vstupního souboru nebo NULL
 * \param output char*  Jméno výstupního souboru nebo NULL
 * \return int Vrací EXIT_FAILURE v případě chyby při práci se soubory.
 *
 * <p>Pokud je místo jména vstupního nebo výstupního souboru prázdný ukazatel
 * NULL, použije se soubor stdin nebo stdout.</p>
 *
 */
void testFileRW(char *input, char *output)
{
  printf("==========================================\n");
  printf("Test cteni a zapisu ze a do souboru\n");
  FILE *fin = stdin;
  FILE *fout = stdout;

  if (input != NULL)
    fin = fopen(input, "r");

  if (output != NULL)
    fout = fopen(output, "w");

  if (fin == NULL)
  {
    fprintf(stderr, "Chybny nazev vstupniho souboru.");
    fin = stdin;
    input = NULL;
  }

  if (fout == NULL)
  {
    fprintf(stderr, "Chybny nazev vystupniho souboru.");
    fout = stdout;
    output = NULL;
  }

  // Tady teď není potřeba volat funkci maticeAlokuj, protože to se už dělá
  // uvnitř funkce maticeCtiZeSouboru.
  Tmatice * m = maticeCtiZeSouboru(fin);
  if (m != NULL)
  { // Není chyba => zpracuji načtenou matici.
    maticeTiskniSoubor(fout, m);
    maticeUvolni(m);
  }
  else
  { // Při chybě tisknu chybové hlášení, zavřu soubory a končím.
    maticeAktualniChyboveHlaseni(stderr);
  }

  if (input != NULL) fclose(fin);
  if (output != NULL) fclose(fout);
  printf("==========================================\n");
  return;
}


/** \brief Vynásobí dvě matice a výsledek uloží do třetí nové matice.
 *
 * \param a const Tmatice* První vstupní matice.
 * \param b const Tmatice* Druhá vstupní matice.
 * \param c Tmatice* Výsledná, zatím nevytvořená matice.
 * \return bool Vrací true, pokud se operace povedla, jinak false.
 *
 * <p>Parametr c musí ukazovat na prozatím nevytvořenou matici, jinak dojde ke
 * ztrátě dat.</p>
 *
 * <p>Pokud jsou vstupní matice kompatibilní, tj. a->sloupcu == b->radku, dojde
 * k vytvoření výsledné matice o rozměrech c->radku = a-radku a c->sloupcu = b->sloupcu.
 * Do této matice pak bude uložen výsledek násobení a*b v tomto pořadí.</p>
 *
 * <p>Pozor! Operace maticového násobení není komutativní, tudíž záleží na
 * pořadí operandů.</p>
 */
Tmatice * maticeMult(const Tmatice *a, const Tmatice *b)
{
  if (a->sloupcu != b->radku)
    return NULL;

  Tmatice * c = maticeAlokuj(a->radku, b->sloupcu);
  if (c == NULL)
    return NULL;

  for (int row = 0; row < c->radku ; ++row)
  {
    for (int col = 0; col < c->sloupcu ; ++col)
    {
      double ssum;
      ssum = 0.0;
      for (int k = 0; k < a->sloupcu ; ++k)
      {
        ssum += a->prvek[row][k] * b->prvek[k][col];
      }
      c->prvek[row][col] = ssum;
    }
  }
  return c;

//  Poznámka: Všimni si, že operace se sama stará o alokaci výsledku a ošetření
//  chyb, které to může generovat. Jako autor takové operace nemůžu chtít po
//  uživateli (této funkce), aby před samotným spuštěním funkce prováděl nějaké
//  kroky nutné pro správné chování této funkce. Programy, které toto vyžadují,
//  jsou takzvaně "křehké", což je protiklad k programům "robustním".
}

/** \brief Test operací maticeRandom a maticeMult. */
void testMult(void)
{
  printf("==========================================\n");
  printf("Test nasobeni nahodnych matic\n");
  Tmatice * a = maticeAlokuj(4, 2);
  Tmatice * b = maticeAlokuj(2, 3);

  maticeRandom(a);
  maticeRandom(b);

  maticeTiskni(a);
  printf("*\n");
  maticeTiskni(b);
  printf("=\n");
  Tmatice * c = maticeMult(a, b);
  if (c != NULL)
  {
    maticeTiskni(c);
    maticeUvolni(c);
  }
  else
    printf("Tohle nejde!\n");

  maticeUvolni(a);
  maticeUvolni(b);
  printf("==========================================\n");
}




/** \brief Vrátí index řádku s pivotem.
 *
 * Poznámka: Použij funkci fabs pro práci s absolutní hodnotou.
 *
 * \param m Tmatice* Ukazatel na rozšířenou matici soustavy.
 * \param r int Index referenčního řádku (a sloupce)
 * \return int Index řádku s pivotem.
 *
 */
int maxAbsPivot(Tmatice *m, int r)
{
    int maxRow = r;
    double maxVal = fabs(m->prvek[r][r]);

    for (int i = r + 1; i < m->radku; ++i)
    {
        double val = fabs(m->prvek[i][r]);
        if (val > maxVal)
        {
            maxVal = val;
            maxRow = i;
        }
    }
    return maxRow;
}

/** \brief Testuje, zda je zadaná soustava ve tvaru horní trojúhelníkové matice.
 *
 * \param m Tmatice* Ukazatel na rozšířenou matici soustavy.
 * \return bool Vrací logickou hodnotu.
 *
 */
bool jeHorni(Tmatice *m)
{
    for (int i = 0; i < m->radku; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (fabs(m->prvek[i][j]) > DBL_EPSILON)
                return false;
        }
    }
    return true;
}


/** \brief Provede přímý chod GEM.
 *
 * Změní vstupní matici na ekvivalentní horní trojúhelníkovou matici. Využije
 * přitom pivotování a ekvivalentních úprav.
 *
 * Poznámka: Vytvoř si samostatnou funkci pro pivotování a samostatnou funkci
 * pro aplikaci ekvivalentních úprav (nulování prvků pod diagonálním prvkem),
 * které zde zavoláš.
 *
 * \param m Tmatice* Ukazatel na rozšířenou matici soustavy.
 * \return int Vrací kód chyby.
 */
int gemPrimy(Tmatice *m)
{
    for (int i = 0; i < m->radku; ++i)
    {
        int pivotRow = maxAbsPivot(m, i);
        if (pivotRow != i)
            maticeVymenRadky(m, i, pivotRow);

        for (int j = i + 1; j < m->radku; ++j)
        {
            double factor = m->prvek[j][i] / m->prvek[i][i];
            for (int k = i; k < m->sloupcu; ++k)
                m->prvek[j][k] -= factor * m->prvek[i][k];
        }
    }
    return EMOK;
}


/** \brief Provede přímý chod GJEM.
 *
 * Změní vstupní matici na ekvivalentní diagonální matici.
 *
 * Poznámka: Výsledná matice může, ale nemusí být jednotková.
 *
 * Poznámka: Funkci vytvoříš úpravou funkce gemPrimy.
 *
 * \param m Tmatice* Ukazatel na rozšířenou matici soustavy.
 */
void gjemPrimy(Tmatice *m)
{
    for (int i = 0; i < m->radku; ++i)
    {
        int pivotRow = maxAbsPivot(m, i);
        if (pivotRow != i)
            maticeVymenRadky(m, i, pivotRow);

        double pivot = m->prvek[i][i];
        for (int j = i; j < m->sloupcu; ++j)
            m->prvek[i][j] /= pivot;
            m->prvek[i][i] = 1;

        for (int j = 0; j < m->radku; ++j)
        {
            if (i != j)
            {
                double factor = m->prvek[j][i];
                m->prvek[j][i] = 0;
                for (int k = i+1; k < m->sloupcu; ++k)
                    m->prvek[j][k] -= factor * m->prvek[i][k];
            }
        }
    }
}


/** \brief Test přímého chodu, tj. operací gemPrimy a gjemPrimy.
 *
 * Zadání:
 * Pro řešení využij funkce z modulu matice.h a funkce gemPrimy a gjemPrimy.
 * 1. Načti soubor s maticí (nebo si ji inicializuj přímo tady ve funkci).
 *    Pomocí funkce maticeDuplikat si vyrob její duplikát.
 * 2. Proveď na ní přímý chod GEM a vytiskni výsledek.
 * 2. Na duplikátu vstupní matice proveď přímý chod GJEM a vytiskni výsledek.
 * 3. Ukliď po sobě.
 */
int testPrimehoChodu(Tmatice *m)
{
    for (int i = 0; i < m->radku; ++i)
    {
        if (fabs(m->prvek[i][i]) < DBL_EPSILON)
        {
            return 0;
        }
    }

    return 1;
}






/** \brief Vrací počet řešení upravené soustavy po provedení přímého chodu GEM.
 *
 * Součástí testu jsou i správné rozměry.
 *
 * \param m Tmatice* Ukazatel na rozšířenou matici soustavy.
 * \return bool Vrací hodnotu 1, když matice je rozšířenou maticí soustavy
 *              ve tvaru po provedení přímého chodu Gaussovy eliminační metody
 *              a soustava je dále řešitelná. Hodnotu 0 vrací, když soustava
 *              není ve tvaru horní trojúhelníkové matice nebo nemá žádné
 *              řešení. Hodnotu -1 vrací, když má soustava nekonečně mnoho
 *              řešení.
 */
int gemPoPrimem(Tmatice *m)
{
    if (!jeHorni(m))
        return 0;

    for (int i = 0; i < m->radku; ++i)
    {
        if (fabs(m->prvek[i][i]) < DBL_EPSILON)
            return -1;
    }

    return 1;
}


/** \brief Vrací počet řešení upravené soustavy po provedení přímého chodu GJEM.
 *
 * Součástí testu jsou i správné rozměry.
 *
 * \param m Tmatice* Ukazatel na rozšířenou matici soustavy.
 * \return bool Vrací hodnotu 1, když matice je rozšířenou maticí soustavy
 *              ve tvaru po provedení přímého chodu Gauss-Jordanovy eliminační
 *              metody a soustava je dále řešitelná. Hodnotu 0 vrací, když
 *              soustava není ve tvaru diagonální matice nebo nemá žádné
 *              řešení. Hodnotu -1 vrací, když má soustava nekonečně mnoho
 *              řešení.
 */
int gjemPoPrimem(Tmatice *m)
{
    for (int i = 0; i < m->radku; ++i)
    {
        if (fabs(m->prvek[i][i]) < DBL_EPSILON)
            return -1;
    }

    return 1;
}

/** \brief Test matic po přímém chodu
 *
 * Zadání:
 * Pro řešení využij předchozí hotové funkce.
 * 1. Načti soubor s maticí (nebo si ji inicializuj přímo tady ve funkci).
 * 2. Otestuj ji a vytiskni, zda jde o matici po provedení přímého chodu GEM nebo GJEM.
 * 3. Pokud nejde o upravenou matici, proveď přímý chod GEM, GJEM (funkce pro
 *    to už máš hotové).
 * 4. Výsledek znovu otestuj.
 * 5. Vypiš, kolik řešení zadaná soustava má (0, 1, nekonečno).
 */
int testMaticePoPrimemChodu(Tmatice *m)
{
    for (int i = 0; i < m->radku; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (fabs(m->prvek[i][j]) > DBL_EPSILON)
            {
                return 0;
            }
        }
    }

    return 1;
}




/** \brief Provede zpětný chod GEM.
 *
 * Hodnoty neznámých nastaví do posledního sloupce rozšířené matice soustavy.
 *
 * \param m Tmatice* Ukazatel na rozšířenou matici soustavy.
 */
void gemZpetny(Tmatice *m)
{
    for (int i = m->radku - 1; i >= 0; --i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            double factor = m->prvek[j][i] / m->prvek[i][i];
            for (int k = 0; k < m->sloupcu; ++k)
                m->prvek[j][k] -= factor * m->prvek[i][k];
        }
    }
}


/** \brief Provede zpětný chod GJEM.
 *
 * Hodnoty neznámých nastaví do posledního sloupce rozšířené matice soustavy.
 *
 * \param m Tmatice* Ukazatel na rozšířenou matici soustavy.
 */
void gjemZpetny(Tmatice *m)
{
    for (int i = 0; i < m->radku; ++i)
    {
        int pivotRow = maxAbsPivot(m, i);
        if (pivotRow != i)
            maticeVymenRadky(m, i, pivotRow);

        double pivot = m->prvek[i][i];
        for (int j = 0; j < m->sloupcu; ++j)
            m->prvek[i][j] /= pivot;

        for (int j = 0; j < m->radku; ++j)
        {
            if (i != j)
            {
                double factor = m->prvek[j][i];
                for (int k = 0; k < m->sloupcu; ++k)
                    m->prvek[j][k] -= factor * m->prvek[i][k];
            }
        }
    }
}



/** \brief Tiskne řešení soustavy rovnic, které je uloženo v posledním sloupci rozšířené matice soustavy.
 *
 * \param m Tmatice* Ukazatel na rozšířenou matici soustavy.
 */
void tiskReseni(Tmatice *m)
{
  printf("Reseni soustavy rovnic:");
  for (int r = 0; r < m->radku; ++r)
  {
    printf("x%d = %f\n", r, m->prvek[r][m->sloupcu-1]);
  }
}

/** \brief Vyřeší upravenou soustavu rovnic.
 *
 * Zadání:
 * Pro řešení využij funkce z modulu matice.h a funkce gemPoPrimem, gjemPoPrimem, gemZpetny a gjemZpetny.
 * 1. Načti soubor s maticí.
 * 1a. Uprav ji do požadovaného tvaru pro zpětný chod.
 * 2. Otestuj zda jde o matici s jedním řešením po provedení přímého chodu GEM nebo GJEM.
 * 3. Vyřeš ji.
 * 4. Vypiš řešení soustavy pomocí funkce tiskReseni.
 */
int testZpetnyChod(Tmatice *m)
{

    for (int i = 0; i < m->radku; ++i)
    {
        if (fabs(m->prvek[i][i]) < DBL_EPSILON)
        {
            return -1;
        }

        for (int j = 0; j < i; ++j)
        {
            if (fabs(m->prvek[i][j]) > DBL_EPSILON)
            {
                return 0;
            }
        }
    }

    return 1;
}

bool jeDDM(Tmatice *m)
{
int soucetRadku = 0;

for(int i = 0; i<m->sloupcu-1;i++)
    {

    soucetRadku = 0;
    for(int j = 0; j<m->radku-1; j++)
        {

        soucetRadku = soucetRadku + fabs(m->prvek[i][j]);

        }
        if(soucetRadku - fabs(m->prvek[i][i]) > fabs(m->prvek[i][i]))
           {
               return false;
           }
    }
return true;
}




/** Startovní bod programu. */
int main(void)
{
  // Co nepotřebuješ, si můžeš zakomentovat.

  srand(time(NULL));

  testInit();
  testFileRW("A.txt", NULL); // NULL -> bude zapisovat na stdout
  testMult();

  testPrimehoChodu("B.txt");          // otestuj i jiné soubory
  testMaticePoPrimemChodu("D.txt");   // otestuj i jiné soubory
  testZpetnyChod("E.txt");            // otestuj i jiné soubory
  return EXIT_SUCCESS;
}
