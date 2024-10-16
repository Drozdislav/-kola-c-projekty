#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
  int id;
  char jmeno[21];
  char prijmeni[21];
  int vek;
  char povolani[21];
  char zeme[21];
  int plat;
  bool smazano; // true smazano, false neni smazano
} Tosoba;

int nacti(Tosoba p[], FILE *k)
{
int i = 0;
while(fscanf(k,"%d %20s %20s %d %20s %20s %d", &p[i].id, &p[i].jmeno, &p[i].prijmeni, &p[i].vek, &p[i].povolani, &p[i].zeme, &p[i].plat) == 7)
  {
    p[i].smazano=false;

  }
    return i;
}

int zmeny(Tosoba p[], int n, FILE *z)
{
  Tosoba pom;
  int ind;

  while(fscanf(z,"%d %20s %20s %d %20s %20s %d", &pom.id, &pom.jmeno, &pom.prijmeni, &pom.vek, &pom.povolani, &pom.zeme, &pom.plat) == 7)
  {
    fscanf(z, "%d", &ind);
    switch(ind)
    {
      case 0:
          p[pom.id - 1]=pom;
          //p[ind] = pom;
          break;
      case -1:
         p[pom.id - 1].smazano=true;
          break;
      case 1:
         p[n] = pom;
         n++;
          break;
    }
  }
  return n;

}

void zapis(FILE *k, Tosoba p[], int n)
{
  int i,j=1;
  for(i=0; i<n; i++)
  {
    if(p[i].smazano==false)
    {
      fprintf(k,"%d %s %s %d %s %s %d\n", j, p[i].jmeno, p[i].prijmeni, p[i].vek, p[i].povolani, p[i].zeme, p[i].plat);
      j++;
    }
  }

}

int main()
{
    FILE *k, *z;
    Tosoba pole[100];
    int n;

    k = fopen("kmenovy.txt","r");
    z = fopen("zmeny.txt","r");
    if(k==NULL || z==NULL)
      return -1;

    n=nacti(pole,k);
    n=zmeny(pole, n, z);
    fclose(k);
    k = fopen("kmenovy.txt","w");

    zapis(k, pole, n);

    fclose(k);
    fclose(z);

    return 0;
}
