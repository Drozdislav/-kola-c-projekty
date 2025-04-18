/* Iteracni metody
 *
 * Autor: Drozd Jakub
 * Datum: today
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
    int maxRow = r; // Začneme od referenčního řádku
    double maxVal = fabs(m->prvek[r][r]); // Absolutní hodnota na diagonále

    for (int i = r + 1; i < m->radku; i++) {
        double val = fabs(m->prvek[i][r]);
        if (val > maxVal) {
            maxVal = val;
            maxRow = i;
        }
    }

    return maxRow; // Vrátíme index řádku s maximálním pivotem
}

void vymenaRadku(Tmatice *m, int k, int r)
{
    float pomocna = 0;

    for(int i=0; i < m->sloupcu; i++)
    {
        pomocna = m->prvek[k][i];
        m->prvek[k][i] = m->prvek[r][i];
        m->prvek[r][i] = pomocna;
    }
}

void radkoveUpravy(Tmatice *m, int r)
{
    float c = 0;

    for(int k=r+1; k<m->sloupcu-1; k++)
    {
        c = m->prvek[k][r] / m->prvek[r][r];
        m->prvek[k][r] = 0.0;

        for(int s = r+1; s<m->sloupcu; s++)
        {
            m->prvek[k][s] = c * m->prvek[r][s] - m->prvek[k][s];
        }
    }
}

void radkoveUpravyGJEM(Tmatice *m, int r)
{
    float c = 0;

    for(int k=0; k<m->sloupcu-1; k++)
    {
        if(k!=r)
        {
            c = m->prvek[k][r] / m->prvek[r][r];
            m->prvek[k][r] = 0.0;

            for(int s = r+1; s<m->sloupcu; s++)
            {
                m->prvek[k][s] = -c * m->prvek[r][s] + m->prvek[k][s];
            }
        }
    }
}

/** \brief Testuje, zda je zadaná soustava ve tvaru horní trojúhelníkové matice.
 *
 * \param m Tmatice* Ukazatel na rozšířenou matici soustavy.
 * \return bool Vrací logickou hodnotu.
 *
 */
bool jeHorni(Tmatice *m)
{
    for(int r=0; r<m->sloupcu-1; r++)
    {
        for(int s=r+1; s<m->sloupcu-1; s++)
        {
            if(r<s && (m->prvek[s][r] != 0.0))
            {
                printf("\nCHYBA! Matice neni ve tvaru trojuhelnikove matice!! [%d,%d] prvek=%.2f\n",r,s,m->prvek[r][s]);
                return false;
            }
        }
    }
    return true;
}

bool jeHorniGJEM(Tmatice *m)
{
    for(int r=0; r<m->sloupcu-1; r++)
    {
        if(m->prvek[r][r] == 0)
        {
            printf("\nCHYBA! Matice neni ve tvaru po GJEM! %d] prvek=%.2f\n",r,m->prvek[r][r]);
            return false;
        }

        for(int s=0; s<m->sloupcu-1; s++)
        {
            if(r!=s && (m->prvek[s][r] != 0))
            {
                printf("\nCHYBA! Matice neni ve tvaru po GJEM! %d,%d] prvek=%.2f\n",r,s,m->prvek[r][s]);
                return false;
            }
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
    int k = 0;
    for(int r=0; r < m->radku-1; r++)
    {
        int k = maxAbsPivot(m,r);
        if(m->prvek[k][r] == 0)
        {
            printf("CHYBA! Pivot se rovná nule");
            return -1;
        }
        if(k != r)
        {
            vymenaRadku(m,k,r);
        }
        radkoveUpravy(m,r);
    }
    return 0;
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
  int k = 0;
    for(int r=0; r < m->radku; r++)
    {
        int k = maxAbsPivot(m,r);
        if(m->prvek[k][r] == 0)
        {
            printf("CHYBA! Pivot se rovná nule");
            return -1;
        }
        if(k != r)
        {
            vymenaRadku(m,k,r);
        }
        radkoveUpravyGJEM(m,r);
    }
    return 0;
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
void testPrimehoChodu(char *jmenoSouboru)
{
  printf("==========================================\n");
  // Načítání matice ze souboru
  FILE *f = fopen(jmenoSouboru, "r");
  if (f == NULL) {
      printf("CHYBA! Soubor se nepodařilo otevřít\n");
      return;
  }

  // Načtení matice
  Tmatice *m = maticeCtiZeSouboru(f);
  if (m == NULL) {
      printf("CHYBA! Nepodařilo se načíst matici\n");
      return;
  }

  // Vytvoření duplikátu
  Tmatice *duplikat = maticeDuplikat(m);
  if (duplikat == NULL) {
      printf("CHYBA! Nepodařilo se vytvořit duplikát matice\n");
      maticeUvolni(m);
      return;
  }

  // Provedení přímého chodu GEM na původní matici
  printf("GEM Primy chod:\n");
  gemPrimy(m);
  maticeTiskni(m);
  gemPoPrimem(m);


  // Provedení přímého chodu GJEM na původní matici
  printf("GJEM Primy chod:\n");
  gjemPrimy(duplikat);
  maticeTiskni(duplikat);


  // Uvolnění paměti
  maticeUvolni(m);
  maticeUvolni(duplikat);

  printf("==========================================\n");
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
    if(jeHorni(m) == false)
    {
        return -1;
    }
    printf("POCET RESENI MATICE:\n");
  if(m->prvek[m->radku][m->sloupcu-1] == 0 && m->prvek[m->radku][m->sloupcu] == 0)
  {
      //nekonecne mnoho resení
      printf("Matice ma nekonecne mnoho reseni!\n");
      return 0;
  }
  if(m->prvek[m->radku][m->sloupcu-1] != 0 && m->prvek[m->radku][m->sloupcu] != 0)
  {
      //jedno reseni
      printf("Matice ma jedno reseni!\n");
      return 1;
  }
  if(m->prvek[m->radku][m->sloupcu-1] == 0 && m->prvek[m->radku][m->sloupcu] != 0)
  {
      //zadne reseni
      printf("Matice nema zadne reseni!\n");
      return 0;
  }
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
    if(jeHorniGJEM(m) == true)
    {
        return 1;
    }
    else
    {
        return 0;
    }

    if(m->prvek[m->radku][m->sloupcu-1] == 0 && m->prvek[m->radku][m->sloupcu] == 0)
    {
        //nekonecne mnoho resení
        printf("Matice ma nekonecne mnoho reseni!\n");
        return -1;
    }
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
void testMaticePoPrimemChodu(char *jmenoSouboru)
{
  printf("==========================================\n");
  printf("Funkce testMaticePoPrimemChodu neni hotova.\n");

  FILE *f = fopen(jmenoSouboru, "r");
  if (f == NULL) {
      printf("CHYBA! Soubor se nepodařilo otevřít\n");
      return -1;
  }

  // Načtení matice
  Tmatice *m = maticeCtiZeSouboru(f);
  if (m == NULL) {
      printf("CHYBA! Nepodařilo se načíst matici\n");
      return -1;
  }

  Tmatice *d = maticeDuplikat(m);
  if (d == NULL) {
      printf("CHYBA! Nepodařilo se načíst matici\n");
      return -1;
  }


  if(jeHorni(m) == true)
  {
      printf("Jde o matici po pruchodu GEM\n");
      printf("==========================================\n");
      return;
  }

  if(jeHorniGJEM(m) == true)
  {
      printf("Jde o matici po pruchodu GJEM\n");
      printf("==========================================\n");
      return;
  }

  testPrimehoChodu(jmenoSouboru);


  gemZpetny(m);
  printf("GEM ZPETNY: \n");
  tiskReseni(m);

  printf("GJEM ZPETNY \n");
  gjemZpetny(d);
  tiskReseni(d);

  printf("GEM PO PRIMEM \n");
  gemPoPrimem(m);

  printf("GJEM PO PRIMEM\n");
  gjemPoPrimem(d);

  printf("==========================================\n");
}



/** \brief Provede zpětný chod GEM.
 *
 * Hodnoty neznámých nastaví do posledního sloupce rozšířené matice soustavy.
 *
 * \param m Tmatice* Ukazatel na rozšířenou matici soustavy.
 */


void gemZpetny(Tmatice *m)
{
    float suma = 0.0;

    for(int r = m->sloupcu-1; r>0; r--)
    {
        suma = 0.0;

        for(int s = r+1; s<m->sloupcu-1; s++)
        {
            suma = suma + m->prvek[r][s] * m->prvek[s][m->sloupcu];
        }
        m->prvek[r][m->sloupcu] = (m->prvek[r][m->sloupcu] - suma) / m->prvek[r][r];
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
    for(int r = 0; r<m->sloupcu; r++)
    {
        m->prvek[r][m->sloupcu] = m->prvek[r][m->sloupcu] / m->prvek[r][r];
        m->prvek[r][r] = 1;
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
void testZpetnyChod(char *jmenoSouboru)
{
  printf("==========================================\n");
  printf("Funkce testZpetnyChod\n");

  FILE *f = fopen(jmenoSouboru, "r");
  if (f == NULL) {
      printf("CHYBA! Soubor se nepodařilo otevřít\n");
      return -1;
  }

  // Načtení matice
  Tmatice *m = maticeCtiZeSouboru(f);
  if (m == NULL) {
      printf("CHYBA! Nepodařilo se načíst matici\n");
      return;
  }

  // Provedení přímého chodu GJEM na původní matici
  printf("GJEM zpetny chod:\n");
  if(jeHorniGJEM == true)
        {
        gjemZpetny(m);
        tiskReseni(m);
        }
        else
        {
            printf("CHYBA! Matice zadana do zpetneho gjem neni ve spravnem tvaru\n");
        }

  // Uvolnění paměti
  maticeUvolni(m);

  printf("==========================================\n");
}

void testZpetnyChodGJEM(char *jmenoSouboru)
{
  printf("==========================================\n");
  printf("Funkce testZpetnyChod\n");

  FILE *f = fopen(jmenoSouboru, "r");
  if (f == NULL) {
      printf("CHYBA! Soubor se nepodařilo otevřít\n");
      return -1;
  }

  // Načtení matice
  Tmatice *m = maticeCtiZeSouboru(f);
  if (m == NULL) {
      printf("CHYBA! Nepodařilo se načíst matici\n");
      return;
  }

  // Provedení přímého chodu GJEM na původní matici
  printf("GJEM zpetny chod:\n");
  if(jeHorniGJEM == true)
        {
        gjemZpetny(m);
        tiskReseni(m);
        }
        else
        {
            printf("CHYBA! Matice zadana do zpetneho gjem neni ve spravnem tvaru\n");
        }

  // Uvolnění paměti
  maticeUvolni(m);

  printf("==========================================\n");
}

bool jeDDM(Tmatice *m)
{
int soucetRadku = 0;

for(int i = 0; i<m->radku-1;i++)
    {

    soucetRadku = 0;
    for(int j = 0; j<m->radku-1; j++)
        {

        soucetRadku = soucetRadku + fabs(m->prvek[i][j]);

        }
        if(soucetRadku - fabs(m->prvek[i][i]) > fabs(m->prvek[i][i]))
           {
               printf("Matice neni DDM\n");
               return false;
           }
    }
    printf("Matice je DDM\n");
    return true;
}

void upravaMatice(Tmatice *m)
{
    float pmc=0;
    for(int i = 0; i<m->radku; i++)
    {
        pmc = m->prvek[i][i];

        for(int j = 0; j<m->sloupcu; j++)
        {
            m->prvek[i][j] = m->prvek[i][j] / pmc;
        }
        m->prvek[i][i] = 0;
    }
    printf("Uprava matice prosla\n");
}

void reseniGS(Tmatice *m, float eps, float x[]) //nedava to smysl, nemelo by se to pole vytvorit az podle toho, kolik ta matice ma radku == vysledku????
{
    float xpred = 0;
    float suma = 0;
    for(int i = 0; i<m->radku; i++)
    {
        x[i] = 0.0;
    }

    // na začátku pesimisticky
    bool jePresny = false;
    while (!jePresny)
    {
        jePresny = true;
        for (int r = 0; r< m->radku; r++)
        {
            xpred = x[r];
            suma = 0;
            for(int s = 0; s<m->sloupcu-1; s++)
            {
                suma = suma + m->prvek[r][s] * x[s];
            }

            x[r] = (m->prvek[r][m->sloupcu-1] - suma);


            jePresny = jePresny && fabs(xpred - x[r]) < eps;
        }
    }
}

void reseniJ(Tmatice *m, float eps, float x[]) {
    float xpred[m->radku-1];
    float suma = 0;
    for(int i = 0; i<m->radku; i++)
    {
        x[i] = 0.0;
    }

    // na začátku pesimisticky
    bool jePresny = false;
    while (!jePresny)
    {
        for(int j = 0; j<m->radku; j++)
            {
                xpred[j] = x[j];
            }
        jePresny = true;
        for (int r = 0; r< m->radku; r++)
        {
            suma = 0;
            for(int s = 0; s<m->sloupcu-1; s++)
            {
                suma = suma + m->prvek[r][s] * x[s];
            }

            x[r] = (m->prvek[r][m->sloupcu-1] - suma);


            jePresny = jePresny && fabs(xpred[r] - x[r]) < eps;
        }
    }
}


void testujGS(char jmenoSouboru[])
{
    printf("--- GAUSS-SEIDLOVA ITERACNI METODA ---");
    //DOKONCIT
    FILE *f = fopen(jmenoSouboru, "r");
    if (f == NULL)
        {
        printf("CHYBA! Soubor se nepodařilo otevřít\n");
        return -1;
        }

  // Načtení matice
    Tmatice *m = maticeCtiZeSouboru(f);
    if (m == NULL)
        {
        printf("CHYBA! Nepodařilo se načíst matici\n");
        return;
        }
        float x[m->sloupcu-2];

        if(jeDDM(m) == false)
        {
            printf("Matice neni ve tvaru DDM");
        }
        upravaMatice(m);
        reseniGS(m,0.01, x);

        printf("Vysledky:\n");

        for(int i = 0; i<m->radku;i++)
        {
            printf("x%d: %.2f\n", i+1, x[i]);
        }

        fclose(f);
        maticeUvolni(m);
}
void testujJ(char jmenoSouboru[])
{
    printf("--- JACOBIHO ITERACNI METODA ---");
    //DOKONCIT
    FILE *f = fopen(jmenoSouboru, "r");
    if (f == NULL)
        {
        printf("CHYBA! Soubor se nepodařilo otevřít\n");
        return -1;
        }

  // Načtení matice
    Tmatice *m = maticeCtiZeSouboru(f);
    if (m == NULL)
        {
        printf("CHYBA! Nepodařilo se načíst matici\n");
        return;
        }
        float x[m->sloupcu-2];

        if(jeDDM(m) == false)
        {
            printf("Matice neni ve tvaru DDM");
        }
        upravaMatice(m);
        reseniJ(m,0.01, x);

        printf("Vysledky:\n");

        for(int i = 0; i<m->radku;i++)
        {
            printf("x%d: %.2f\n", i+1, x[i]);
        }
    fclose(f);
    maticeUvolni(m);
}

/*
--------------------------------------
**ZACATEK RESENI NELINEARNICH ROVNIC**
--------------------------------------
*/
typedef double (*Tfun)(double);

float horner(float koef[], int n, float x) {
    float suma = 0.0;
    for (int i = 0; i < n + 1; i++) {
        suma = (suma * x) + koef[i];
    }
    return suma;
}

//P(x) = 7.5x^2 + 3.2x - 5.0
double f1(double x) {
    float koef[] = {7.5, 3.2, -5.0};
    return horner(koef, 2, x);
}

//P(x) = 9x^4 + 5.3x^3 - 6.3x^2 + 10x - 1.1
double f2(double x) {
    float koef[] = {9, 5.3, -6.3, 10, -1.1};
    return horner(koef, 4, x);
}

double rekurzivniBisekce(double a, double b, double eps, Tfun func) {
    double middle = (a + b) / 2;
    double fmiddle = func(middle);

    if (fabs(fmiddle) < eps || fabs(b - a) < eps) {
        return middle;
    }

    if (func(a) * fmiddle < 0) {
        return rekurzivniBisekce(a, middle, eps, func);
    } else {
        return rekurzivniBisekce(middle, b, eps, func);
    }
}

double nerekurzivniBisekce(double a, double b, double eps, Tfun func) {
    double middle, fa = func(a), fmiddle;

    while (fabs(b - a) >= eps) {
        middle = (a + b) / 2;
        fmiddle = func(middle);

        if (fabs(fmiddle) < eps) {
            return middle;
        }

        if (fa * fmiddle < 0) {
            b = middle;
        } else {
            a = middle;
            fa = fmiddle;
        }
    }

    return (a + b) / 2;
}

double regulaFalsi(double a, double b, float eps, Tfun func)
{
    double fa = func(a);
    double fb = func(b);
    double c = a + fa*(b-a)/(fa - fb);
    double fc;
    while (fabs(fc = func(c)) >= eps)
    {
        if (fa * fc < 0)
        {
            b = c;
            fb = fc;
        }
        else
        {
            a = c;
            fa = fc;
        }

        c = a + fa*(b-a)/(fa - fb);
    }
    return c;
}

double secny(double a, double b, float eps, Tfun func)
{
    double fa = func(a);
    double fb = func(b);
    double c = b - (fb*(b-a)) / (fb-fa);

    while(fabs(c) > eps)
    {
        a=b;
        b=c;
        double c = b - (fb*(b-a)) / (fb-fa);
    }

    return c;
}

/*float newton(float koef_fce[], float koef_drce[], int n, float eps)
{
    while(fabs(horner(koef_fce, n, x))>eps)
    {
        x=x-horner(koef_fce, n, x) / horner(koef_drce, n-1, x);
    }
    return x;
}*/


//(a + (h/2) + k*h)

/** Start point of the program */
int main(void)
{
    Tfun func = f2;

    double x = 2.0;
    printf("f1(%.1f) = %.2f\n", x, f1(x));

    double vysledekBisekce = nerekurzivniBisekce(1, 8, 0.001, func);
    printf("Vysledek nerekurzivni bisekce je %.5f\n", vysledekBisekce);

    vysledekBisekce = rekurzivniBisekce(1, 8, 0.001, func);
    printf("Vysledek rekurzivni bisekce je %.5f\n", vysledekBisekce);


    return EXIT_SUCCESS;
}
