#include <stdio.h>
#include <stdlib.h>

struct bozo
{
  char jmeno[20];
  int plat;
};

int main()
{

  struct bozo min;
  struct bozo max;
  struct bozo osoba;


  FILE* f = fopen("osoby.txt","r");
  if (f == NULL) { // povinný test
    printf("Soubor se nepovedlo otevrit.\n");
    return EXIT_FAILURE;

  FILE* fnew = fopen("gej.txt","w");
  if (f == NULL) {
    printf("Soubor se nepovedlo otevrit.\n");
    return EXIT_FAILURE;


  if(fscanf(f, "%s %d", osoba.jmeno, &osoba.plat) == 2){
    max = osoba;
    min = osoba;

    fprintf(fnew, "%s %d\n", osoba.jmeno, osoba.plat * 115 / 100);
  }

  while(fscanf(f, "%s %d", osoba.jmeno, &osoba.plat) == 2){
    if(osoba.plat <= min.plat) min = osoba
    if(osoba.plat >= max.plat) max = osoba

    fprintf(fnew, "%s %d\n", osoba.jmeno, osoba.plat * 115 / 100);
  }

  printf("max: %20s" max.jmeno);
  printf("min: %20s" min.jmeno);

    return 0;
}

