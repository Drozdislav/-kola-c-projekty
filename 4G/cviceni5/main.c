#include <stdio.h>
#include <stdlib.h>

void rozdel(FILE *vstup, FILE *G, FILE *F) {
char trida[4];
char jmeno[30];
int znamkap;
int znamkat;
float prumer;

while(fscanf(vstup, "%30s %3s %d %d",&jmeno,&trida,&znamkat,&znamkap)==4) {
    prumer = (znamkat + znamkap) / 2.0;

    if(trida[2] == G) {
        fprintf(G,"%30s %3s %d %d %.2f \n", jmeno, trida, znamkat, znamkap, prumer);
        }
    else {
        fprintf(F,"%30s %3s %d %d %.2f \n", jmeno, trida, znamkat, znamkap, prumer);
        }
    }
}



int main()
{
    FILE* v = fopen("zaci.txt", "r");
if (v == NULL) {
printf("Soubor se nepovedlo otevrit.\n");
return EXIT_FAILURE;
}

    FILE* g = fopen("g.txt", "w");
if (g == NULL) {
printf("Soubor se nepovedlo otevrit.\n");
return EXIT_FAILURE;
}

    FILE* f = fopen("f.txt", "w");
if (g == NULL) {
printf("Soubor se nepovedlo otevrit.\n");
return EXIT_FAILURE;
}

rozdel(v,g,f);
fclose(v);
fclose(g);
fclose(f);
    return 0;
}
