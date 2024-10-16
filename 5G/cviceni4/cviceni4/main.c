#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _prvek Tprvek;
struct _prvek {
float data;
Tprvek * dalsi;
};

typedef struct {
Tprvek* prvni;
Tprvek* posledni;
int delka;
int maxDelka;
} Tfronta;

Tfronta frInit(int maxDelka) {
// Alokuj a inicializuj frontu s ukazateli
Tfronta f;
f.delka = maxDelka;
f.prvni = NULL;
f.posledni = NULL;
// prvni a poslední ukazujícími na NULL.
// Vra ukazatel na tuto prázdnou frontu nebo NULL.
return f;
}

bool frEnqueue(Tfronta *f, float d) {
Tprvek *novy = malloc(sizeof(Tprvek));
if (novy==NULL) return false;
    novy->data=d;
    novy->dalsi=f->posledni;
    f->posledni=novy;
return true;
}

bool frDequeue(Tfronta* f, float *d) {
if(f->prvni==NULL)
    return false;
*d=f->prvni->data;
Tprvek *novy =f->prvni;
f->prvni=f->prvni->dalsi;
free(novy);
if (prvni == NULL)
    posledni == NULL;
return true;
}

void frVypis(Tfronta* f) {
Tprvek *x=f->posledni;
while (x!=NULL){
    printf("%c,",x->data);
    x=x->dalsi;
}

int main()
{
    FILE* s = fopen("data10k.txt", "r");
    if(f == NULL) {
        printf("Soubor se nepodarilo otevrit")
        return -1;

frEnqueue(&f,);

frVypis(&f);
    }
    return 0;
}
