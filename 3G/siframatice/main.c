#include <stdio.h>
#include <stdlib.h>
#define MAX 6


//funkce pro vypis matice slouzi pouze pro ladeni, ve vyslednem kodu neni potrebna
void vypisMatice(char mat[][MAX])
{
for (int i=0; i<MAX; i++)
{

  for(int j=0; j<MAX; j++)
    {
      printf("%c",mat[i][j]);

    }
    printf("\n");
}

}

void vymenaRadekSloupec(char mat1[][MAX], char mat2[][MAX]) {
int x = 0;
int y = 0;

for(int i=0; i<6; i++) {
    for(int j=0; j<6; j++) {
        mat2[x][y] = mat1[i][j];
        x++;
        }
        x = 0;
        y++;
    }
}

void maticeDoRetezce(char mat[][MAX], char retez[37]) {
int x = 0;
for(int i=0; i<MAX; i++) {
    for(int j=0; j<MAX; j++) {
            retez[x] = mat[i][j];
            x++;
        }
    }
}

void switchRetezec(char retez[37]) {
for(int i = 0; retez[i] != '\0'; i++) {
    switch (retez[i]) {
    case '*': retez[i] = 'A';
    break;
    case '+': retez[i] = 'E';
    break;
    case 'Q': retez[i] = 'I';
    break;
    case '-': retez[i] = 'O';
    break;
    case '?': retez[i] = 'U';
    break;
    default: break;
    }
}
}
int main(void) {
  printf("Zasifrovana zprava\n");
//char matice[MAX][MAX] = {{'K',' ','T','L','G',' '}, {'D','M','*','-','L',' '}, {'-','-',',',' ','Q',' '}, {' ','C',' ','G','.',' '}, {'S',' ','M','-','.',' '}, {'+','P','*','-','.',' '}};
char matice[MAX][MAX] = {{'C','N','J','Q','F','-'}, {'-','+','+','S','*','K'}, {' ','Z',' ',' ','C',' '}, {'T','*','N','N','+',' '}, {'+','B','*','*','B',' '}, {' ','Q','P',' ','-',' '}};
//char matice[MAX][MAX] = {{'B','N',' ',' ','    ','!'}, {'+','+','*','S','N','!'}, {'Z','Z','P','T','+','!'}, {' ',' ','P','-','L','!'}, {'P','D','L','R','+','!'}, {'+','-','+','?','Z','!'}};
char vypisovaciMat[MAX][MAX];
//tady dopln kod

//napis funkci, ktera v matici vymeni radky a sloupce, aplikuj na nasi matici

//definuj textovy retezec o vhodne velikosti (ma se tam vlezt cela matice MAX в MAX).
char retezec[37];


//napis funkci, ktera vezme matici a retezec a zkopiruje po radcich matici do retezce.

//napis funkci, ktera vezme retezec a vymeni v nem znaky: * -> A, + -> E, Q -> I, - -> O, ? -> U
//pouzij pritom prikaz switch!!!!!

//vypis retezec, pokud jsi vse udelal spravne, ceka te vtipna hlaska

//aktualni matici si zapoznamkuj a odpoznamkuj jinou, ceka te dalsi vtipna hlaska

vypisMatice(matice);
printf("\n");
vymenaRadekSloupec(matice,vypisovaciMat);
vypisMatice(vypisovaciMat);
maticeDoRetezce(vypisovaciMat,retezec);

printf("\n %s", retezec);

switchRetezec(retezec);

printf("\n %s", retezec);


  return 0;
}
