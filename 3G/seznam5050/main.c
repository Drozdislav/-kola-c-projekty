#include <stdio.h>


void bozo(int p[], int pocet) {
  for(int i=0; i<50; i++) {
    p[i] = i+1;
  }
  for(int n=50; n<100; n++) {
    p[n] = pocet;
    pocet = pocet - 1;
  }
}

void vypis(int p[]) {
    for(int i=0; i<100; i++) {
      printf("%d \n", p[i]);
    }
}

int main() {
  int pole[200];
  int pocet = 49;
  bozo(pole,pocet);
  vypis(pole);
  }
