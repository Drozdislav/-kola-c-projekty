
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //nutne pro generovani nahodnych cisel

//zkusebni program na volani funkci (bude jich opravdu hodne)

void vypisPole(int p[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", p[i]);
  }
  printf("\n");
}

void nahodnePole(int p[], int n)
{
  for (int i = 0; i < n; i++)
  {
    p[i] = rand() % 50; //generovani nahodnych cisel
  }
}
int soucetPole(int p[], int n)
{
  int soucet = 0;
  for (int i = 0; i < n; i++)
  {
    soucet = soucet + p[i];
  }
  return soucet;
}


int nejvetsiCislo(int p[], int n)
{
  int max = p[0];
  for (int i = 0; i < n; i++)
  {
    if (max < p[i])
      max = p[i];
  }
  return max;
}

int poziceNejvetsihoCisla(int p[], int n)
{
  int max = 0;
  for (int i = 0; i < n; i++)
  {
    if (p[max] < p[i])
      max = i;
  }
  return max;
}

float prumerCisel(int p[], int n)
{
  int soucet = soucetPole(p, n);
  float prumer = (soucet * 1.)/n;
  return prumer;
}

int pocetNadprumernychCisel(int pole[], int n)
{
  int pocet = 0;
  float prumer = prumerCisel(pole, n);

     for (int i = 0; i < n; i++)
     {
         if(pole[i] > prumer)
            pocet++;
     }
  return pocet;
}

int main()
{
    srand( (unsigned) time(NULL)); //nutne pro generovani nahodnych cisel
    printf("Zadej pocet prvku v poli: ");
    int n;
    scanf("%d", &n);
    int a[n];
    nahodnePole(a, n);
    vypisPole(a, n);
    // tady dopln kod
    printf("Prumer je %.2f", prumerCisel(a, n));
    printf("\nNejvetsi cislo je: %d", nejvetsiCislo(a, n));
    printf("\npozice nejvetsiho cisla je: %d", poziceNejvetsihoCisla(a, n));
    printf("\npocet nadprumernych cisel je: %d", pocetNadprumernychCisel(a, n));


    printf("\nKoncim, Goog Bye...");
    return 0;
}

