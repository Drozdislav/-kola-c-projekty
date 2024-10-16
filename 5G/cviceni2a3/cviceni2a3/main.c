#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _prvek Tprvek;
struct _prvek {
    char data;
    Tprvek * dalsi;
};

typedef struct {
    Tprvek* vrchol;
    int vyska;
} Tzasobnik;

Tzasobnik* zasInitD(void){
    Tzasobnik* z = malloc(sizeof(Tzasobnik));
    z-> vrchol=NULL;
return z;
}

bool zasPush(Tzasobnik *z, char d) {
Tprvek *novy = malloc(sizeof(Tprvek));
if (novy==NULL) return false;
    novy->data=d;
    novy ->dalsi=z->vrchol;
    z->vrchol=novy;
return true;
}

bool zasPop(Tzasobnik* z, char* d)
{
if(z->vrchol==NULL) return false;
*d=z->vrchol->data;
Tprvek *x =z->vrchol;
z->vrchol=z->vrchol->dalsi;
free(x);
return true;
}
void tisk(Tzasobnik *z){
Tprvek *x=z->vrchol;
while (x!=NULL){
    printf("%c,",x->data);
    x=x->dalsi;
}


}
void zasFree(Tzasobnik *z)
{
    char data;
    while (zasPop(z, &data));

}
int Over(FILE *f, Tzasobnik *z) {
char zn, pom;
while(fscanf(f, "%c", &zn)==1) {
    if(zn=='(' || zn=='[' || zn=='{' || zn=='<')
        zasPush(z,zn);
    else {
        switch(zn) {
        case ')': if(z->vrchol==NULL) return -1;
                if(z->vrchol->data == '(') zasPop(z,&pom);
                else return -2;
                break;
        case '}': if(z->vrchol==NULL) return -1;
                if(z->vrchol->data == '{') zasPop(z,&pom);
                else return -2;
                break;
        case ']': if(z->vrchol==NULL) return -1;
                if(z->vrchol->data == '[') zasPop(z,&pom);
                else return -2;
                break;
        case '>': if(z->vrchol==NULL) return -1;
                if(z->vrchol->data == '<') zasPop(z,&pom);
                else return -2;
                break;
        }
    }

}
if(z->vrchol != NULL) return -3;
else return 0;
}

int main(void) {
Tzasobnik *z = zasInitD();

FILE *vstup = fopen("data2.html", "r");
if(vstup == NULL) {
printf("soubor se nepodarilo otevrit");
return -1;
}
int chyba = Over(vstup,z);
switch(chyba) {
case -3:printf("Na konci chybi uzaviraci zavorka \n");
        break;
case -2:printf("Nespravne vnorene zavorky \n");
        break;
case -1:printf("Uzaviraci nema oteviraci \n");
        break;
case 0:printf("Alles gutte \n");
        break;
}
/*zasPush(z, 'a');
zasPush(z, 'b');
zasPush (z, 'c');
tisk(z);
char data;
zasPop (z, &data);
printf ("\n");
tisk(z);
zasFree(z);*/
return 0;
}
