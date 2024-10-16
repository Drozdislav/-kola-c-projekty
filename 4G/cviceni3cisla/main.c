#include <stdio.h>
#include <stdlib.h>

void prekopiruj(FILE *vstup, FILE *vystup) {
    int pocet=0, cislo, min, max;
    fscanf(vstup,"%d", &cislo);
    max=min=cislo;
    pocet++;
    fprintf(vystup,"%d", cislo);

    while (fscanf(vstup, "%d", &cislo) == 1) {
    fprintf(vystup, "%d\n", cislo);
    if (min>cislo) min=cislo;
    if (max<cislo) max=cislo;
    pocet++;
}
    printf("pocet je %d\n", pocet);
    printf("max je %d\n", max);
    printf("min je %d\n", min);
    fclose(vstup);
    fclose(vystup);
}

int main()
{
    FILE *vstup, *vystup;
    vstup=fopen("cisla.txt", "r");
    vystup=fopen("cisla_vystup.txt", "w");
    if (vstup==NULL || vystup==NULL) return -1;


    prekopiruj(vstup,vystup);
    return 0;
}
