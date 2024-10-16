#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int mat, cj, ivt;
}ZNAMKY;

typedef struct{
    char jmeno[8];
    int vek;
    ZNAMKY znamky;
}ZAK;
void vypisTridu(ZAK t[], int n)
{
    printf("Jmeno     vek  mat   cj  ivt\n");
    for (int i=0; i<n; i++)
    {
        printf("%-8s%5d%5d%5d%5d\n",t[i].jmeno, t[i].vek, t[i].znamky.mat, t[i].znamky.cj, t[i].znamky.ivt);
    }
}

float prumer(ZAK trida[], int n) {
float soucet=0.;

for(int i=0; i<n; i++) {
    soucet = soucet + trida[i].znamky.mat;
}
soucet = soucet / n;
return soucet;
}
int main()
{
    printf("Prace se zaky ve tride\n");
    printf("-----------------------\n\n");
    // definuj pole zaku trida (typ ZAK) o 50 polozkach
    ZAK trida[50] = {{"Adam", 16, {1,2,3}}, {"Eva",15,{2, 3, 1}}, {"Mirek", 17, {4, 3, 1}}, {"Alena", 16, {2, 5, 3}},
    {"Oto", 15,{4, 4, 3}}, {"Petra", 16, {2, 4, 1}}, {"Pavel", 15, {1, 1, 1}}, {"Jana",15,{1, 5, 4}} };
    /*vlozte do definice tato data: {"Adam", 16, {1,2,3}}, {"Eva",15,{2, 3, 1}}, {"Mirek", 17, {4, 3, 1}}, {"Alena", 16, {2, 5, 3}},
    "Oto", 15,{4, 4, 3}}, {"Petra", 16, {2, 4, 1}}, {"Pavel", 15, {1, 1, 1}}, {"Jana",15,{1, 5, 4}} };*/

    //definujte promenou, ve ktere bude aktualni pocet prvku v poli a inicializujte ji
    int n = 8;
    //tridu si vypiste, vypis je hotov, staci ho zavolat
    vypisTridu(trida,n);
    //Napiste a zavolejte funkci, ktera vrati prumernou znamku z matematiky, vysledek vypiste na 2 desetinna mista
    printf("%.2f", prumer(trida,n));
    //Napiste funkci a zavolejte ji, která vrati pocet jednicek z IVT, vysledek vypiste

    //Napiste funkci, ktera vypise jmena zaku, kteri maji z cestiny jednicku


    return 0;
}
