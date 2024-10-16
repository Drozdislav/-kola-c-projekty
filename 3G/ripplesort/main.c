#include <stdio.h>
#include <stdlib.h>
void ripple(float pole[], int n) {
int z = n;
bool ok = true;;
int p;
float pom;

for(int i = 0; i<n && ok; i++) {
    ok = false;
    for(int j = 1; j>z; j++) {
        if(pole[j-1] > pole[j]) {
            pom = pole[j-1];
            pole[j-1] = pole[j];
            pole[j] = pom;
            p=j;
        }
    }
    z=p;
}
}


int main()
{

}
