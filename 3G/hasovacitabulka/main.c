#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/******** struktura osoba *******/
typedef struct
{
char jmeno[21];
int vek;
bool obsazeno;

} Tosoba;



/******** Vypis cele tabulky *******/
void vypis (Tosoba pole[], int delka)
{

    for(int i = 0;i<n;i++){
        if(obsazeno == 0){
        printf("jmeno: %c, vek : %d", pole[i].jmeno,pole[i].vek);
    }
    }

    /** Pohlidejte si, ze obsazeno je 1, 0 totiz znamena, ze polozka neexistuje, podle toho vypisujte,
        tzn. vypisujete pouze pole, kde obsazeno je 1. **/
}


/******** Inicializace *******/
void init(Tosoba pole[], int delka)
{
    for(int i = 0;i<n;i++){
        pole[i].obsazeno=0;
    }

   /** v kazde bunce pole nastav obsazeno na 0:  pole[i].obsazeno=0;**/
}


/******** Hashovaci funkce *******/
int hashfunkce (int vek_vkladane_osoby, int delkapole)
{
return vek_vkladane_osoby%delkapole;
  /** vrati bud upraveny vek (podle delky pole) nebo totalni cif soucet, nebo jednotky, nebo udelejte vlastni hashfunkci podle delky pole*/
}


/******** Vloz do tabulky *******/
int vlozHtab(Tosoba pole[], int delka , Tosoba pom a)
{
    int index = hashfunkce(pom.vek, delka) //výpoèet polohy prvku
    pole[index] = prvek
    pole[index].obsazeno = true;
}

/******** Vymaz z tabulky *******/
int vymazHtab(Tosoba pole[], int delka, int vek)
{
  tab[hash(prvek.klic, N)].obsazeno = false
}

/******** Najdi v tabulce *******/
int najdiHtab(Tosoba pole[],int n, int vek)
{
    /**dopln (viz Classroom str. 37)**/
    /** Pohlidejte si, ze obsazeno je 1, 0 totiz znamena, ze polozka neexistuje, podle toho vypisujte **/
}



/******** MAIN ******************************************************/
int main(void)
{
/** 1. Vytvor osoba pole[10] + dalsi pomocne promenne, popr. pole jine delky pokud chcete**/

   char osoba [10];
   int delka;
   Tosoba pom;
/** 3. Zavolej inicializaci pole: funkci init (chceme vsechny pole nastavit na obsazeno = 0) **/

   init(pole,10);

/** 4. Do pole bude uzivatel zadavat osoby: jmeno a vek, a to tak dlouho, dokud uzivatel nezada nesmyslny vek, tj.
       napriklad zaporny. **/
    int vek;
    printf("Zadej jmeno: ");
    scanf("%20s",pom.jmeno);
    printf("Zadej vek: ");
    scanf("%d",&vek);
    //pom.obsazeno=true;

    while(0 < vek )
    {
      vlozHtab(pole,10,pom);

      printf("Zadej jmeno: ");
      scanf("%c",osoba);
      printf("Zadej vek: ");
      scanf("%d",vek);
    }


/** 3. Zavolejte funkci vypis **/

    vypis(pole,10)


/** 4. Zavolejte funkci pro vyhledani osoby ... vyhledavame podle veku **/

    printf("Zadej vek osoby, kterou hledame: ");
    scanf("%d",&vek);
    if (najdiHtab(pol,10,vek)==-1)
        printf("Takova osoba zde neni.\n");
    else
        printf("Jmeno:%s, vek: %d\n"pole[pozice].jmeno, pole[pozice].vek)
    //vypis jmeno osoby, pokud existuje (obsazeno == 1), jinak vypis, ze takova osoba neni

/** 5. Zavolejte funkci pro odebrani nejake osoby ... odebirame osobu podle jejiho veku **/

    printf("Zadej vek osoby, kterou odebereme: ");
    scanf("%d",&vek);
    if(vymazHtab(pole,10,vek)==-1)
        printf("Osoba tady neni\n");
    else
        printf("Osoba byla odebrana %s\n",pole[pozice].jmeno);

/** 6. Zavolejte funkci vypis **/

    //dopln

  return 0;
}
