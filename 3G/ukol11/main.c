/*Hlavní nabídka
IVT-3.G-2021/22
Jazyk C - cvièení 11
Martina Kopeèková
•
9:34
Dnešní cvièení bude zamìøené na volání funkcí a orientaci v cizím programu. Všechny body (mimo bodù 1, 12, 16 a 17) proveïte pouze pomocí volání již napsaných funkcí.
Zkopírujte si z pøiloženého souboru zdrojový kód. Ovìøte si jeho funkènost. S pomocí uèitele si projdìte kód a vysvìtlete si jednotlivé øádky programu.


1. Ve funkci main nadefinujte pole celých èísel a, b, c, d, e, f o velikosti n (n je již nadefinovaná promìnná a má pøiøazenou hodnotu).
2. Pole a a b vyplò náhodnými èísly.
3. Vypiš pole a i b.
4. Vyplò pole c souètem polí a a b (po jednotlivých èíslech).
5. Vypiš pole c.
6. Vyplò pole d dvìma èísly 3 a 8 na pøeskáèku.
7. Vypiš pole d.
8. Vyplò pole e dvìma èísly tak, že do první poloviny v poli bude èíslo 5 a od druhé poloviny tam bude èíslo 2.
9. Vypiš pole e.
10. Do pole f dej opaènou kopii pole a.
11. Vypiš pole f.
12. Nadefinuj (napiš) funkci vyplnCislem, která celé pole vyplní jedním èíslem (parametr).
13. Vyplò pole a èísly 1, pole b èísly 2, pole c èísly 3, pole d èísly 4, pole e èísly 5.
14. Vytiskni pole a, b, c, d, e.
14. Pomocí volání nìkolika funkcí vyplò pole f tak, že v nìm bude souèet polí a, b, c, d, e.
15. Vypiš pole f a zkontroluj si s ostatními.
16. Definuj další pole g, tentokrát o 2*n prvcích.
17. Definuj funkci slucPole, která dvì pole o velikosti n slouèí do tøetího pole o velikosti 2*n.
18. Pole g naplò slouèením polí a a c.
19. Vypiš pole g.

main.c
C
Komentáøe ke kurzu
Vaše práce
Zadáno
Soukromé komentáøe*/
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

void kopie(int zdroj[], int cil[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cil[i] = zdroj[i];
  }
}

void opacnaKopie(int zdroj[], int cil[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cil[i] = zdroj[n - 1 - i];
  }
}

void soucetPoli(int cil[], int zdroj1[], int zdroj2[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cil[i] = zdroj1[i] + zdroj2[i];
  }
}

void vyplnPoleDvemaCisly(int p[], int n, int cislo1, int cislo2)
{
  for (int i = 0; i < n; i = i + 2)
  {
    p[i] = cislo1;
  }
  for (int i = 1; i < n; i = i + 2)
  {
    p[i] = cislo2;
  }
}
void vyplnPoleDvemaCislyDoPoloviny(int p[], int n, int cislo1, int cislo2)
{
  for (int i = 0; i < n/2; i++)
  {
    p[i] = cislo1;
  }
  for (int i = n/2; i < n; i++)
  {
    p[i] = cislo2;
  }
}

//tady bude kod funkce z bodu 12
vyplnCislem(int p[], int n, int gejisek)
{
    for(int i = 0; i < n; i++)
    {
        p[i] = gejisek;
    }
}

slucPole(int p[], int prvni[], int druhy[], int n )
{
    for(int i = 0; i < n; i++)
    {
        p[i] = prvni[i];
    }

    for(int i = n; i < 2*n; i++)
    {
        p[i] = druhy[i-n];
    }
}

int main()
{
    srand( (unsigned) time(NULL)); //nutne pro generovani nahodnych cisel
    printf("Zadej pocet prvku v poli: ");
    int n;
    scanf("%d", &n);
    // tady dopln kod
    int a[n], b[n], c[n], d[n], e[n], f[n], g[n*2];
    nahodnePole(a, n);
    nahodnePole(b, n);
    vypisPole(a, n);
    vypisPole(b, n);
    soucetPoli(c, a, b, n);
    vypisPole(c, n);
    vyplnPoleDvemaCisly(d, n, 3, 8);
    vypisPole(d, n);
    vyplnPoleDvemaCislyDoPoloviny(e, n, 5, 2);
    vypisPole(e, n);
    opacnaKopie(a, f, n);
    vypisPole(f, n);
    vyplnCislem(a, n, 1);
    vyplnCislem(b, n, 2);
    vyplnCislem(c, n, 3);
    vyplnCislem(d, n, 4);
    vyplnCislem(e, n, 5);
    vypisPole(a, n);
    vypisPole(b, n);
    vypisPole(c, n);
    vypisPole(d, n);
    vypisPole(e, n);
    soucetPoli(f, a, b, n);
    soucetPoli(f, f, c, n);
    soucetPoli(f, f, d, n);
    soucetPoli(f, f, e, n);
    vypisPole(f, n);
    slucPole(g, a, c, n);
    vypisPole(g, n);


    printf("\nKoncim, Goog Bye...");
    return 0;
}

