/*Hlavn� nab�dka
IVT-3.G-2021/22
Jazyk C - cvi�en� 11
Martina Kope�kov�
�
9:34
Dne�n� cvi�en� bude zam��en� na vol�n� funkc� a orientaci v ciz�m programu. V�echny body (mimo bod� 1, 12, 16 a 17) prove�te pouze pomoc� vol�n� ji� napsan�ch funkc�.
Zkop�rujte si z p�ilo�en�ho souboru zdrojov� k�d. Ov��te si jeho funk�nost. S pomoc� u�itele si projd�te k�d a vysv�tlete si jednotliv� ��dky programu.


1. Ve funkci main nadefinujte pole cel�ch ��sel a, b, c, d, e, f o velikosti n (n je ji� nadefinovan� prom�nn� a m� p�i�azenou hodnotu).
2. Pole a a b vypl� n�hodn�mi ��sly.
3. Vypi� pole a i b.
4. Vypl� pole c sou�tem pol� a a b (po jednotliv�ch ��slech).
5. Vypi� pole c.
6. Vypl� pole d dv�ma ��sly 3 a 8 na p�esk��ku.
7. Vypi� pole d.
8. Vypl� pole e dv�ma ��sly tak, �e do prvn� poloviny v poli bude ��slo 5 a od druh� poloviny tam bude ��slo 2.
9. Vypi� pole e.
10. Do pole f dej opa�nou kopii pole a.
11. Vypi� pole f.
12. Nadefinuj (napi�) funkci vyplnCislem, kter� cel� pole vypln� jedn�m ��slem (parametr).
13. Vypl� pole a ��sly 1, pole b ��sly 2, pole c ��sly 3, pole d ��sly 4, pole e ��sly 5.
14. Vytiskni pole a, b, c, d, e.
14. Pomoc� vol�n� n�kolika funkc� vypl� pole f tak, �e v n�m bude sou�et pol� a, b, c, d, e.
15. Vypi� pole f a zkontroluj si s ostatn�mi.
16. Definuj dal�� pole g, tentokr�t o 2*n prvc�ch.
17. Definuj funkci slucPole, kter� dv� pole o velikosti n slou�� do t�et�ho pole o velikosti 2*n.
18. Pole g napl� slou�en�m pol� a a c.
19. Vypi� pole g.

main.c
C
Koment��e ke kurzu
Va�e pr�ce
Zad�no
Soukrom� koment��e*/
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

