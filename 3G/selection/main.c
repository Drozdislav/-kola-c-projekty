#include <stdio.h>
#include <stdlib.h>

void cislaDoPole(float pole[], FILE* f) {
int i = 0;
while(fscanf(f,"%f", &pole[i]) == 1)
    i++;
}

void vypis(float pole[], int n, FILE* out) {
for(int i = 0; i<n; i++) {
    fprintf(out, "%.1f \n", pole[i]);
    }
}

void SelectionSort(float pole[], int n) {
    int min;
    float x;
    for(int d = 0; d<n-2; d++) {
        min = d;

    for(int i = d+1; i<n-1; i++) {
        if(pole[min]>pole[i])
        min = i;
        }
x = pole[d];
pole[d] = pole[min];
pole[min] = x;
    }
}

int main()
{
    int n;

    FILE* f = fopen("cisla.txt", "r");
    if(f == 0) {
        printf("gej");
        return -1; }

    fscanf(f,"%f", &n);
    float pole[n];

    cislaDoPole(pole,f);
    SelectionSort(pole,n);
    vypis(pole,n,stdout);

    fclose(f);
    return 0;
}
