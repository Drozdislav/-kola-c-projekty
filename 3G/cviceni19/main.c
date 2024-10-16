#include <stdio.h>
#include <stdlib.h>
#include  <time.h>

//Funkce vyplni ctvercovou matici n × m nahodnymi cisly
void vyplnNahodne(int mat[][100], int n, int m)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      mat[i][j] = rand() % 50 - 25;
  }
}

//Funkce pro vypis libovolne ctvercove matice n × m
void vypisMat(int mat[][100], int n, int m)
{
  printf("\n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
     printf("%4d", mat[i][j]);
    printf("\n");
  }
}

int aritmetickyprumer(int mat[][100], int n, int m) {
int soucet = 0;
int pocet = 0;
int prumer = 0;

int i,j;

for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++) {
    soucet = soucet + mat[i][j];
    pocet++;
    }
        }

    return prumer = soucet / pocet;
}

int nejvetsicislo(int mat[][100], int n, int m) {
int nejvetsi = mat[0][0];
int i,j;

for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++) {
    if(mat[i][j]>nejvetsi)
        nejvetsi = mat[i][j];
    }
        }

}

void soucetradku(int mat[][100], int n, int m) {
int soucet = 0;
int i,j;

for (i = 0; i < n; i++)
  {
    soucet = 0;
    for (j = 0; j < m; j++) {
    soucet = soucet + mat[i][j];
        }
    printf("\n%d", soucet);

    }
}

void nejvetsisloupcu(int mat[][100], int n, int m) {
int nejvetsi;
int i,j;
for (j = 0; j < m; j++)
  {
    nejvetsi = mat[0][j];

    for (i = 0; i < n; i++) {
        if(mat[i][j]>nejvetsi)
            nejvetsi=mat[i][j];
    }
    mat[n][j] = nejvetsi;
  }
}

int main()
{

  srand( (unsigned) time(NULL));
  int n, m;
  printf("Zadej pocet radku matice: ");
  scanf("%d", &n);
  while (n < 1 || n > 100)
  {
    printf("Cislo musi byt mezi 1 a 100: ");
    scanf("%d", &n);
  }
  printf("Zadej pocet sloupcu matice: ");
  scanf("%d", &m);
  while (m < 1 || m > 100)
  {
    printf("Cislo musi byt mezi 1 a 100: ");
    scanf("%d", &m);
  }

    int mat1[100][100];
    vyplnNahodne(mat1,n,m);
    vypisMat(mat1,n,m);
    int prumer = aritmetickyprumer(mat1,n,m);
    int max = nejvetsicislo(mat1,n,m);
    printf("\nnejvetsi je %d a prumer je %d", max, prumer);

    soucetradku(mat1,n,m);

    nejvetsisloupcu(mat1,n,m);
    n++;
    vypisMat(mat1,n,m);

  printf("\nKoncim s maticemi ...");
  return 0;
}
