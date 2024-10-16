#include <stdio.h>
#include <stdlib.h>

void vypis(char mat1[][100], int n) {
int i, j;
for(i=0; i<n; i++) {
    for(j=0; j<n; j++) {
        printf("%c", mat1[i][j]);
        }
    }
}

void vlozznaky(char mat1[][100], int n) {
int i,j;
for(i=0; i<n; i++) {
    for(j=0; j<n; j++) {
        mat1[i][j] = '*';
        }
    }
}
int main()
{
    int n=10;

    char mat1[100][100];
    vlozznaky(mat1,n);
    vypis(mat1,n);
    return 0;
}
