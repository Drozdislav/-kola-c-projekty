#include <stdio.h>
#include <stdlib.h>

typedef struct {
char jmeno[21];
char trida[4];
int pohlavi;
int znamka1;
int znamka2;

}Tzak;

int Nacti(TypZak pole[], int delka, FILE *vstup)
{
    int i=0;
    while(fscanf(vstup, "%30s %3s %d %d %d", pole[i].jmeno, pole[i].trida, &pole[i].p, &pole[i].z2) == 5) i++;
    return i;
}

void Vypis(TypZak pole[], int delka, FILE *out)
{
    for(int i=0; i<delka; i++)
        fprintf(out, "%s %s %d %d %d\n", pole[i].jmeno, pole[i].trida,pole[i].p, pole[i].z1, pole[i].z2);
}

int main()
{
    TypZak pole[100];
    int delka;
    FILE *vstup = fopen("zaci2.txt","r");
    if(vstup == NULL) return -1;

    delka = Nacti(pole, vstup);
    Vypis(pole, delka, stdout);
    fclose(vstup);
    return 0;
}
