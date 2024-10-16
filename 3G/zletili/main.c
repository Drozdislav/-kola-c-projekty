#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char jmeno[21];
    int vek;
}Tosoba;


/** Funkce poprehazuj poprehazuje bunky tak, aby v leve casti pole byli lide s vekem mensim jak 18 a v prave casti lide s vekem vetsim nebo rovnym 18, tj. neplnoleti a plnoleti**/
void Poprehazuj(Tosoba pole[], int od, int po, int pivot)
{
int levy = od;
int pravy = po;
Tosoba pom;
do{
    while(pole[levy].vek < pivot && levy < po) ++levy;
    while(pivot <= pole[pravy].vek && pravy > od) --pravy;

    if(levy<pravy){
        pom=pole[levy];
        pole[levy]=pole[pravy];
        pole[pravy]=pom;
    }

    if(levy<=pravy) {++levy; --pravy;}

} while(levy < pravy);
}

int Nacti(Tosoba pole[], FILE *vstup)
{
int i = 0;
while(fscanf(vstup, "%20s %d", &pole[i].jmeno, &pole[i].vek) == 2) {
    i++;
}
return i;
}

void Vypis(Tosoba pole[], int delka, FILE *out) {
int i;

for(i=0; i < delka; i++) {
    fprintf(out, "%s %d\n" , pole[i].jmeno, pole[i].vek);
}

}

int main(void)
{
    Tosoba pole[100];
    int delka;
    FILE *vstup = fopen("osoby.txt", "r");
    if(vstup==NULL) {
        printf("soubor se nepodarilo otevrit");
        return -1;
    }

    delka = Nacti(pole, vstup);
    Poprehazuj(pole,0,delka-1,18);
    Vypis(pole, delka, stdout);

fclose(vstup);


return 0;
}
