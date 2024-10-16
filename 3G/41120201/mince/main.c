#include <stdio.h>
#include <stdlib.h>
#include <time.h>


long long int hodminci(int kolik)
{
    srand(time(NULL));
    int hod;
    long long int p=0, ucet=0;

    while (ucet<kolik)
    {
        p++;
        hod = rand()%2;
         if(hod==1) {
            ucet++;
         }
         else {
            ucet--;


         }
     printf("ucet je %d", ucet);
    }






    return p;
}


int main()
{
 int kolik;
 printf("kolik chces vydelat: ");
 scanf("%d", &kolik);

 printf("Bylo potreba hazet celkem %lld krat", hodminci(kolik));




    return 0;
}
