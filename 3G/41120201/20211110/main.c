#include <stdio.h>
#include <stdlib.h>

int sekundyF(int hodiny, int minuty, int sekundy){
int vysledek;
vysledek = hodiny*3600 + minuty*60 + sekundy;





return vysledek;
}
int main()
{
int hodiny, minuty, sekundy;

printf("zadej pocet sekund\n");
scanf("%d", &sekundy);

printf("zadej pocet hodin\n");
scanf("%d", &hodiny);

printf("zadej pocet minut\n");
scanf("%d", &minuty);





printf("vysledek je %d\n", sekundyF(hodiny, minuty, sekundy));

    return 0;
}
