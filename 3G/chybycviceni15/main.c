#include <stdio.h>
#include <string.h>
#define MAX 550

typedef struct
{
    int den;
    int mesic;
    char jmeno[31];
}Tjmeno;

/* Vsimni si, jakym zpusobem se nacitaji data ve funkci nactiDoPole. V podmince while cyklu je chyba, oprav ji!*/
int nactiDoPole(FILE * vstup, Tjmeno p[])
{
  int i = 0;
  while (i<MAX && fscanf(vstup,"%d. %d. %30s", &p[i].den, &p[i].mesic, p[i].jmeno) == 3 )
    {
      i++;
    }
  return i;
}

int menu()
{
  int volba;
  printf("Vypis vsechna jmena ............... 1\n");
  printf("Serad jmena podle abecedy ......... 2\n");
  printf("Kdo ma svatek ......................3\n");
  printf("Kdy ma svatek ......................4\n");
  printf("Konec programu......................0\n");
  printf("Zadej svou volbu 0–5: ");
  scanf("%d", &volba);
  while (volba <0 || volba > 4)
  {
    printf("Zadej svou volbu 0–5: ");
    scanf("%d", &volba);
  }
  return volba;
}


// Ve funkci vypisJmena je chyba ve for cyklu, oprav ji!*/
void vypisJmena(FILE *vystup, Tjmeno p[], int n)
{
  for (int i = 0; i < n; i++)
  {
    fprintf(vystup, "%s %d. %d.\n",p[i].jmeno, p[i]. den, p[i].mesic);
  }
  printf("\n");
}

void seradJmena(Tjmeno p[], int n)
{
    int i, j;
    Tjmeno pom;

    for(i=0;i<n;i++) {
        for(j = 1; j<n; j++)
        if(strcmp(p[j-1].jmeno, p[j].jmeno)>0) {
            pom = p[j];
            p[j] = p[j-1];
            p[j-1] = pom;
        }
    }
}


int  vyhledejDatum(Tjmeno p[], int n, char jmeno[])
{
    for(int i=0;i<n;i++) {
        if(strcmp(p[i].jmeno,jmeno)==0)
            return i;

        return -1;
    }
}

int vyhledejJmeno(Tjmeno p[], int n, int den, int mesic)
{
    for(int i=0;i<n;i++) {
        if(p[i].den == den && p[i].mesic == mesic)
            return i;

        return -1;
    }
}

int main(void) {
  printf("Razeni a vyhledavani\n");
  printf("--------------------\n");

  FILE* f = fopen("jmena.txt","r");
  if(f == NULL) {
    printf("soubor v pici");
    return -1;
  }

  int volba, cislo, pozice, pocet, den, mesic;
  char jmeno[31];
  Tjmeno jmena[MAX];
  pocet = nactiDoPole(f,jmena);
  printf("Pocet nactenych jmen: %d.\n", pocet);
  fclose(f);
  while ((volba = menu())!=0)
    {
      switch (volba)
        {
          case 1: vypisJmena(stdout,jmena,pocet);
                  break;
          case 2: seradJmena(jmena,pocet);
                  vypisJmena(stdout,jmena,pocet);
                  printf("Jmena jsou serazena.\n");
                  break;
          case 3: printf("Zadej den: ");
                  scanf("%d", &den);
                  printf("Zadej mesic: ");
                  scanf("%d",&mesic);
                  int pozice =  vyhledejJmeno(jmena,pocet,den,mesic);
                  if (pozice == -1)
                    printf("Tento den nema nikdo svatek.\n");
                  else
                    printf("%d. %d. ma svatek %s.\n",den, mesic, jmena[pozice].jmeno);
                  break;
          case 4: printf("Zadej jmeno: ");
                  scanf("%30s",jmeno);
                  pozice = vyhledejDatum(jmena,pocet,jmeno);
                  if (pozice == -1)
                    printf("Takove jmeno tady nemame.\n");
                  else
                    printf("%s ma svatek %d. %d.\n",jmena[pozice].jmeno, jmena[pozice].den,jmena[pozice].mesic);
                  break;


        }
    }

  printf("Konec programu\n");
  return 0;
}
