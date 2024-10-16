#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
char ypozice[8];
bool jevradku[8];
bool jesikmozleva[15];
bool jesikmozprava[15];
} TSach;

typedef struct {

} TReseni;


void zkusSloupec(TSach *plocha, int x, int y) {
for (y=0; y<=7;y++) {
if (!jeOhrozena(plocha, x, y)) {
polozDamu(plocha, x, y);
if (x == 7)
zapamatuj(*plocha);
else
zkusSloupec(plocha, x + 1);
odeberDamu(plocha, x, y);
        }
    }
}

void polozDamu(TSach *plocha, int y, int x) {
plocha->jesikmozprava[x-y+7] = true;
plocha->jesikmozleva[x+y] = true;
plocha->jevradku[y] = true;
plocha->ypozice[x] = true;
}

int main()
{

TSach plocha = {
.ypozice = {0},
.jevradku = {false},
.jesikmozleva = {false},
.jesikmozprava = {false},
};


    return 0;
}
