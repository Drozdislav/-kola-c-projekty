#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // pro vyhledavani filmu, kdyz ho chci zmenit
#define MAX 200

typedef struct {
  char nazev[20];
  char stat[20];
  int rokVydani;
  int delka;
  bool barevny;
} FILM;

void menu() {
  printf("Pridej film .................................1\n");
  printf("Uprav film ..................................2\n");
  printf("Vypis filmu .................................3\n");
  printf("Vypis barevne filmy .........................4\n");
  printf("Prumerna delka film .........................5\n");
  printf("Vypis cernobilych filmu po zadanem roce......6\n");
  printf("Zalohuj seznam do souboru....................7\n");
//printf("Aktualizuj seznam do puvodniho souboru.......8\n");
  printf("Seradit filmy podle abecedy a vypis..........8\n");
  printf("Seradit filmy podle roku vydani a vypis......9\n");
//printf("Zalohuj barevne filmy do souboru............11\n");
  printf("Smaz film...................................10\n");
  printf("Vyhledat film podle nazvu...................11\n");
  printf("Konec programu...............................0\n");

}

int nacteniZeSouboru(FILE* vstup, FILM p[]) {
  int i = 0;
  int barevny;
  while(i < MAX && fscanf(vstup, "%22s%d%17s%11d%d", p[i].nazev, &p[i].rokVydani, p[i].stat, &p[i].delka, &barevny) ==5)
  {
	p[i].barevny = barevny == 1;
  i = i+1;
  }

	if (i == MAX) {
		printf("doslo misto\n");
	}
  return i;
}

void zalohaDoSouboru(FILE * vystup, FILM p[], int n) {
  for(int i = 0; i < n; i++) {
	  fprintf(vystup, "%22s %d %17s %11d %d\n", p[i].nazev, p[i].rokVydani, p[i].stat, p[i].delka, p[i].barevny);
  }
}

/**
void zalohaDoSouboruBarevne(FILE *vystup, film p[]) {
  int i =0;
  while(fprintf(vystup, "%22s%15d%17s%11d%d", p[i].nazev, p[i].rokVydani, p[i].stat, p[i].delka, p[i].barevny)==5 && p[i].barevny == 1) {
    i = i+1;
  }

}
**/


void vypisfilmu(FILM p[], int n) {
  printf("%-22s%-17s%-15s%-11s%9s","Nazev filmu","Rok vydání","Stat","Delka (min)","Barevny?");
  printf("\n------------------------------------------------------------------------\n");
  for (int i = 0; i < n; i++) {
    printf("%-22s%-15d%-17s%-11d", p[i].nazev, p[i].rokVydani, p[i].stat, p[i].delka);
    if (p[i].barevny)
      printf("   Ano\n");
    else
      printf("    Ne\n");
  }
}


void vypisBarevnehofilmu(FILM p[], int n) {
  printf("%-22s%-17s%-15s%-11s%-9s\n","Nazev filmu","Stat","Rok Vydání", "Delka","Barevny?");
  printf("\n------------------------------------------------------------------------\n");
  for (int i = 0; i < n; i++) {
    if (p[i].barevny) {
      printf("%-22s%-15d%-17s%-11d", p[i].nazev, p[i].rokVydani, p[i].stat, p[i].delka);
      if (p[i].barevny)
        printf("   Ano\n");
      else
        printf("    Ne\n");
    }
  }
}

void razeniPodleAbecedy(FILM p[], int n)
{
  FILM pom;
  for(int d = 0; d<n-1; d++)
  {
    for(int i = n-1; i>d; i--)
    {
      if(strcmp(p[i].nazev, p[i-1].nazev)<0)
      {
        pom = p[i];
        p[i] = p[i-1];
        p[i-1] = pom;
      }
    }
  }
}

void razeniPodleRokuVydani(FILM p[], int n)
{
  FILM pom;
  for(int d = 0; d<n-1; d++)
  {
    for(int i = n-1; i>d; i--)
    {
      if(p[i].rokVydani < p[i-1].rokVydani)
      {
        pom = p[i];
        p[i] = p[i-1];
        p[i-1] = pom;
      }
    }
  }
}


bool pridejfilm(FILM p[], int n) {
  if (n >= MAX)
    return false;
  else {
    FILM novy;
    int barevny;
    printf("Zadej nazev filmu: ");
    scanf(" %22[^\n]", novy.nazev); // nacte cely radek do konce i s mezerami
    printf("Zadej stat, ze ktereho film pochazi: ");
    scanf(" %22[^\n]", novy.stat); // nacte cely radek do konce i s mezerami
    printf("Zadej rok vydani: ");
    scanf("%d", &novy.rokVydani);
    printf("Zadej delku filmu: ");
    scanf("%d", &novy.delka);
    printf("Je film barevny?\n   0...Ne, 1...Ano: ");
    scanf("%d", &barevny);
    if (barevny)
      novy.barevny = true;
    else
      novy.barevny = false;
    p[n] = novy;
    return true;
  }
}

bool smazfilm(FILM p[], int *n, char nazev[]) {
  int i = 0;
  while (i < *n && strcmp(p[i].nazev, nazev) != 0)
    i++;
  if (i == *n)
    return false;
  for (int j = i; j < *n - 1; j++)
    p[j] = p[j+1];
  (*n)--;
  return true;
}
/**
bool smazfilmUPGRADE(FILM p[], int *n, char nazev[]) {
  int i = 0;
  for (i=0;i < *n;i++) {
     if (i == *n)
    return false;

    if()

  }

  for (int j = i; j < *n - 1; j++)
    p[j] = p[j+1];
  (*n)--;
  return true;
}
**/

void vyhledatFilm(FILM p[], int n) {
  char hledanyNazev[20];
  printf("Zadejte nazev filmu, ktery chcete vyhledat: ");
  scanf("%s", hledanyNazev);

  bool nalezeno = false;
  for (int i = 0; i < n; i++) {
    if (strcmp(hledanyNazev, p[i].nazev) == 0) {
      nalezeno = true;
      printf("Nazev: %s\nStat: %s\nRok vydani: %d\nDelka: %d min\nBarevny: %s\n\n", p[i].nazev, p[i].stat, p[i].rokVydani, p[i].delka, p[i].barevny ? "Ano" : "Ne");
    }
  }

  if (!nalezeno) {
    printf("Film s nazvem %s nebyl nalezen.\n", hledanyNazev);
  }
}

// Funkce, ktera vyhleda film a pak ji opravi. Kdyz ho nenajde, vrati false.
bool opravfilm(FILM p[], int n, char nazev[]) {
  int i = 0;
  while (i < n && strcmp(p[i].nazev, nazev) !=0) // pocitame s tim, ze zadny film se nejmenuje stejne
    i++;
  if (i == n)
    return false; // proslo se cele pole, ale film v nem nebyl
  printf("Zaznam filmu: nazev: %s, stat: %s, rok vydani: %d, delka: %d, ", p[i].nazev,
         p[i].stat,p[i].rokVydani,p[i].delka);
  if (p[i].barevny)
    printf("barevny: Ano\n");
  else
    printf("barevny: Ne\n");
  printf("Zadej nazev filmu: ");
  scanf(" %15[^\n]", p[i].nazev); // nacte cely radek do konce i s mezerami
  printf("Zadej stat, ze ktereho film pochazi: ");
  scanf(" %15[^\n]", p[i].stat); // nacte cely radek do konce i s mezerami
  printf("Zadej rok vydani: ");
  scanf("%d", &p[i].rokVydani);
  printf("Zadej delku filmu: ");
  scanf("%d", &p[i].delka);
  printf("Je film barevny?   0...Ne, 1...Ano: ");
  int barevny;
  scanf("%d", &barevny);
  if (barevny)
    p[i].barevny = true;
  else
    p[i].barevny = false;
  return true;
}

float prumer(FILM p[], int n) {
  float soucet = 0;
  for (int i = 0; i < n; i++)
    soucet += p[i].delka;
  if (n > 0)
    return soucet / n;
  else
    return 0; // pro jistotu
}

bool vypisCBfilmuporoce(FILM p[], int n, int rok) {
  bool navratBool = false;
  printf("%-22s%-17s%-15s%-11s","Nazev filmu","Stat","Rok Vydání", "Delka");
  printf("\n----------------------------------------------------------\n");
  for(int i=0; i<n; i++) {
    if(rok<p[i].rokVydani && !p[i].barevny) {
      printf("%-22s%-17s%-15d%-11d\n", p[i].nazev, p[i].stat, p[i].rokVydani, p[i].delka);
      navratBool = true;
      }
  }
  return navratBool;
}

int main() {
  FILE * seznam = fopen("seznam.txt", "r");
  FILE * zaloha = fopen("zaloha.txt", "w");

  if(seznam == NULL || zaloha == NULL) {
    printf("Soubory se nepodarilo otevrit. \n");
    return -1;
  }
  FILM pole[MAX];
  int n = nacteniZeSouboru(seznam,pole);
  /** film pole[MAX] = {
    {"La Haine", "Francie", 1995, 97, false},
    {"Sexmise", "Polsko", 1983, 120, true},
    {"Nabarvene ptace", "Cesko", 2019, 169, false},
    {"Schindleruv seznam", "USA", 1993, 195, false},
    {"Pulp Fiction", "USA", 1994, 154, true},
    {"Majak", "USA", 2019, 110, false},
    {"Obchod na korze", "Ceskoslovensko", 1965, 128, false},
    {"Amadeus", "USA", 1984, 160, true},
    {"Mrazik", "USSR", 1964, 79, true},
    {"Klub Rvacu", "USA", 1999, 139, true},
    {"Prazdniny v Rime", "USA", 1953, 118, false}
  }; **/

  int volba = 1;
  while (volba != 0) {
    system("cls"); // smaze obrazovku
    menu();
    scanf("%d", &volba);
    switch (volba) {
    case 1: // pridej film
      if (pridejfilm(pole, n)) {
        printf("film byl pridan.\n");
        n++; // pridala se film, musi se zvednout pocet sopek
        system("pause");
      } else
        printf("V pameti uz neni dost mista na pridani dalsiho filmu.\n");
        system("pause");
      break;
    case 2: // uprav film
      printf("Zadej nazev filmu, ktery chces upravit: ");
      char nazev[16];
      scanf(" %15[^\n]s", nazev);
      if (opravfilm(pole, n, nazev)) {
        printf("film byl opraven.\n");
        system("pause");
        }
      else
        printf("Takovy film se v seznamu nenachazi.\n");
        system("pause");

      break;
    case 3: // vypis filmy
      vypisfilmu(pole, n);
      system("pause");
      break;
    case 4: // vypis barevne filmy
      vypisBarevnehofilmu(pole, n);
      system("pause");
      break;
    case 5: // prumerna delka filmu
      printf("Prumerna delka filmu je %.2f minut.\n", prumer(pole, n));
      system("pause");
      break;
    case 6: // vypis cernobilich filmu po zadanem roce
      printf("Zadej rok vydani: ");
      int rok;
      scanf(" %d", &rok);
      if (vypisCBfilmuporoce(pole,n,rok)) {
        printf("filmy byly vypsany.\n");
        system("pause"); }
      else
        printf("Po roce %d neni v seznamu zadny cernobily film\n", rok);
        system("pause");
      break;

    case 7: // zaloha do souboru
      zalohaDoSouboru(zaloha,pole,n);
      printf("Zaloha byla vytvorena.\n");
      system("pause");

      break;
 /**   case 8:
      zalohaDoSouboru(seznam,pole);
      printf("Aktualizace byla uspesna.");
      break; **/

    case 8: // razeni podle abecedy
      razeniPodleAbecedy(pole,n);
      vypisfilmu(pole,n);
      system("pause");
      break;

    case 9: // razeni podle roku vydani
      razeniPodleRokuVydani(pole,n);
      vypisfilmu(pole,n);
      system("pause");
      break;

 /**   case 11:
      zalohaDoSouboruBarevne(zaloha,pole);
      printf("Zaloha barevnych filmu byla vytvorena.");
      break;
      **/
  case 10: // smazat film
    printf("Zadej nazev filmu, ktery chces smazat: ");
    char jmeno[16];
    scanf(" %15[^\n]s", jmeno);
   if (smazfilm(pole, &n, jmeno))
    printf("Film byl odstranen.\n");
   else
    printf("Film se v seznamu nenachazi.\n");
  break;

  case 11: // vyhledat film
    vyhledatFilm(pole,n);
    system("pause");
  break;

    case 0: // konec
      printf("Koncim s filmy.\n");
      break;
    default:
      printf("Netrefil ses, zkus to znovu.\n");
      break;
    }
    if (volba != 0)
    system("read a"); // pocka na stisk klavesy
  }


  fclose(zaloha);
  fclose(seznam);
  return 0;
}
/**
La_Haine 1995 Francie 97 false
Sexmise 1983 Polsko 120 true
Nabarvene_ptace 2019 Cesko 169 false
Schindleruv_seznam 1993 USA 195 false
Pulp_Fiction 1994 USA 154 true
Majak 2019 USA 110 false
Obchod_na_korze 1965 Ceskoslovensko 128 false
Amadeus 1984 USA 160 true
Mrazik 1964 USSR 79 true
Klub_Rvacu 1999 USA 139 true
Prazdniny_v_Rime 1953 USA 118 false
**/
