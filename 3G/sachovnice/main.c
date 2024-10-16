#include <stdio.h>
#include <stdlib.h>


//Funkce vyplni ctvercovou matici n × n znakem znak
void vypln1(char mat[][100], int n, char znak)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      mat[i][j] = znak;
  }
}

//Funkce pro vypis libovolne ctvercove matice n × n
void vypisMat(char mat[][100], int n)
{
  printf("\n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
     printf("%c ", mat[i][j]);
    printf("\n");
  }

}

void sachovnice(char mat[][100], int n) {
for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
     if((i+j)%2 == 0)
        mat[i][j] = '\333';
  }

}

void diagonaly(char mat[][100], int n) {
  for (int i = 0; i < n; i++) {
  {
    for (int j = 0; j < n; j++)
     if(i==j || (i+j)== n-1)
        mat[i][j] = '*';
  }

}
}

void nadpoddiagonalou(char mat[][100], int n) {
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        if(j<i)
            mat[i][j] = '+';
        else if(i==j)
            mat[i][j] = ' ';
        else
            mat[i][j] = '*';

        }
    }
}

int main()
{
    int n;
      printf("Zadej velikost matice: ");
  scanf("%d", &n);

  char mat1[100][100];
  vypln1(mat1,n,' ');
  sachovnice(mat1,n);
  vypisMat(mat1,n);

  char mat2[100][100];
  vypln1(mat2,n,' ');
  diagonaly(mat2,n);
  vypisMat(mat2,n);

  char mat3[100][100];
  vypln1(mat3,n,' ');
  nadpoddiagonalou(mat3,n);
  vypisMat(mat3,n);

  printf("\nKoncim s maticemi ...");
  return 0;
}
