#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "duleziteFunkce.h"

typedef struct
{
    int ypozice[8];
    bool jevradku[8];
    bool jesikmozleva[15];
    bool jesikmozprava[15];
} TSach;

typedef struct TReseni {
    int ypozice[8];       // Pole pro ulozeni pozic dam v jednotlivych sloupcich
    struct TReseni *next;  // Ukazatel na dalsi reseni v seznamu
} TReseni;

TReseni *reseniHead = NULL;

void polozDamu(TSach *plocha, int x, int y)
{
    plocha->ypozice[x] = y;
    plocha->jevradku[y] = true;
    plocha->jesikmozprava[x - y + 7] = true;
    plocha->jesikmozleva[x + y] = true;
}

void zapamatuj(TSach *plocha)
{
    TReseni *novyUzel = (TReseni *)malloc(sizeof(TReseni));
    if (novyUzel == NULL) {
        printf("Chyba alokace paměti!\n");
        return;
    }

    for (int i = 0; i < 8; i++) {
        novyUzel->ypozice[i] = plocha->ypozice[i];
    }

    novyUzel->next = reseniHead;
    reseniHead = novyUzel;
}

void odeberDamu(TSach *plocha, int x, int y)
{
    plocha->ypozice[x] = 0;
    plocha->jevradku[y] = false;
    plocha->jesikmozprava[x - y + 7] = false;
    plocha->jesikmozleva[x + y] = false;
}

bool jeOhrozena(TSach *plocha, int x, int y)
{
    if (plocha->jevradku[y] || plocha->jesikmozleva[x + y] || plocha->jesikmozprava[x - y + 7])
        return true;
    else
        return false;
}

void zkusSloupec(TSach *plocha, int x)
{
    for (int y = 0; y < 8; y++)
    {
        if (!jeOhrozena(plocha, x, y))
        {
            polozDamu(plocha, x, y);

            if (x == 7)
                zapamatuj(plocha);
            else
                zkusSloupec(plocha, x + 1);

            odeberDamu(plocha, x, y);
        }
    }
}

void tiskReseniOsmiDam()
{
    int volba;
    printf("-------------------- RESENI OSMI DAM --------------------\n");
    printf("Zvol si, ktery styl reseni chces, aby ti program vytiskl:\n");
    scanf("%d", &volba);
    switch (volba)
    {
        case 1:
            printf("1. Tisk reseni v ciselne forme:\n");
            TReseni *aktualni1 = reseniHead;
            int cisloReseni1 = 1;
            while (aktualni1)
            {
                printf("Reseni %d: ", cisloReseni1++);
                for (int i = 0; i < 8; i++)
                {
                    printf("%d ", aktualni1->ypozice[i]);
                }
                printf("\n");
                aktualni1 = aktualni1->next;
            }
        break;

        case 2:
            printf("2. Tisk reseni v obrazkove forme:\n");
            TReseni *aktualni2 = reseniHead;
            int cisloReseni2 = 1;
            while (aktualni2)
            {
                printf("Reseni %d:\n", cisloReseni2++);

                for (int i = 0; i < 8; i++)
                {
                    for (int j = 0; j < 8; j++)
                    {
                        if (aktualni2->ypozice[j] == i)
                            printf("[o]");
                        else
                            printf("[ ]");
                    }
                    printf("\n");
                }

                printf("\n");
                aktualni2 = aktualni2->next;
            }
            break;
        default:
            printf("Neplatna volba. Zadejte 1 nebo 2.\n");
    }


}

void testOsmiDam()
{
    TSach plocha = {
        .ypozice = {0},
        .jevradku = {false},
        .jesikmozleva = {false},
        .jesikmozprava = {false},
    };

    zkusSloupec(&plocha, 0);
    tiskReseniOsmiDam();
}

int main()
{
    /**
    int pocetCifer;
    int x[1000];
    z10doBin(458, x, &pocetCifer);
    vypis1DpoleCISLA(x, pocetCifer);


    float a = 10;
    float b = 20;

    printf("-------------------------\n");

    printf("a: %f, b: %f\n", a,b);

    printf("-------------------------\n");

    swapNumbers(&a,&b);
    printf("a: %f, b: %f\n", a,b);

    printf("-------------------------\n");

    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    vypis1DpoleCISLA(arr,n);
    bubblesort(arr,n);
    vypis1DpoleCISLA(arr,n);

    printf("-------------------------\n");
    float x1 = 0.0;
    float x2 = 0.0;

    quadraticEquationSolver(1,3,-6,&x1,&x2);

    printf("-------------------------\n");

    sumaFaktorialDelenoCislem(5);
    faktorialCisla(5);
    **/
    testOsmiDam();
    return 0;
}
