#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const MAX=7000;

int nacti(FILE *f, int pole[]) {
int i=0;

while(fscanf(f, "%d", &pole[i]) == 1) {
    i++;
}
return i;
}

bool NeniSerazene(int pole[], int delka) {
for(int i=1;i<delka;i++)
    if(pole[i -1]>pole[i]) return true;
return false;
}

int SekvencniNeserazenes(int pole [], int delka, int klic) {
pole[delka-1] = klic;
int i = 0;
while (pole[i] != klic)
{
i = i + 1;
}
if (i < delka) return i;
else return -1;
}

int SekvencniNeserazenebez(int pole [], int delka, int klic) {
int i = 0;
while (i < delka && pole[i] != klic)
{
i = i + 1;
}

if (i < delka) return i;
else return -1;
}

int SekvencniSerazenes(int pole [], int delka, int klic) {

}

int SekvencniSerazenebez(int pole [], int delka, int klic) {
int i = 0;
while (i < delka && pole[i] <klic)
{
i = i + 1;
}
if (i < delka && pole[i] == klic)
return i;
else return -1;
}

int BinarniVyhledavani(int pole [], int l, int p, int klic) {
int stred;
while (l <= p) {
stred = (l+p)/2;

if (pole[stred] = klic)
return stred;

if (pole[stred] < klic)
l = stred+1;
else
p = stred-1;
}
return -1;
}

void menu() {
printf("1. Sekvencni na neserazenem poli se zarazkou\n");
printf("2. Sekvencni na neserazenem poli bez zarazky\n");
printf("2. Sekvencni na serazenem poli se zarazkou\n");
printf("4. Sekvencni na serazenem poli bez zarazky\n");
printf("5. Binarni vyhledavani\n");
}



void Proved(int pole[], int delka, int volba, int l, int p) {
int klic, kde;
printf("Zadej vyhledavany klic: ");
scanf("%d", &klic);

switch(volba) {
    case 1: kde = SekvencniNeserazenes(pole, delka+1, klic);
            if(kde == -1)
                printf("nenalezeno\n");
            else
                printf("Prvek se nachazi na pozici %d\n\n", kde);
        break;

    case 2: kde = SekvencniNeserazenebez(pole, delka, klic);
            if(kde == -1)
                printf("nenalezeno\n");
            else
                printf("Prvek se nachazi na pozici %d\n\n", kde);
        break;


    case 3: kde = SekvencniSerazenes(pole, delka+1, klic);
            if(kde == -1)
                printf("nenalezeno\n");
            else
                printf("Prvek se nachazi na pozici %d\n\n", kde);
        break;

    case 4: kde = SekvencniSerazenebez(pole, delka, klic);
            if(kde == -1)
                printf("nenalezeno\n");
            else
                printf("Prvek se nachazi na pozici %d\n\n", kde);
        break;

    case 5: kde = BinarniVyhledavani(pole, l, p, klic);
            if(kde == -1)
                printf("nenalezeno\n");
            else
                printf("Prvek se nachazi na pozici %d\n\n", kde);
        break;
    }
    system("pause");
}






int main()
{
    FILE *a = fopen("s1.txt", "r");
    if(a == NULL) return -1;

    FILE *b = fopen("s2.txt", "r");
    if(b == NULL) return -1;

    int volba = 1;
    int delka;

    int pole[MAX];
    delka = nacti(b, pole);

    int l = 0;
    int p = delka - 1;

    while(volba != 0) {
        menu();
        printf("Vyber volbu: ");
        scanf("%d", &volba);
        Proved(pole, delka, volba, l, p);
        system("cls");
    }















    fclose(a);
    fclose(b);
    return 0;
}
