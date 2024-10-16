#include <stdio.h>
#include <stdlib.h>

void slucovani(FILE *s1, FILE *s2, FILE *s3) {
int i, j, pom1, pom2;
i = fscanf(s1, "%d", &pom1);
j = fscanf(s2, "%d", &pom2);

while(i==1){
        while(j==1 && pom2<=pom1) {
           fprintf(s3, "%d ", pom2);
           printf("%d ", pom2);
            j = fscanf(s2, "%d", &pom2);
        }
        while(i==1 && pom1<=pom2) {
            fprintf(s3, "%d ", pom1);
            printf("%d ", pom1);
            i = fscanf(s1, "%d", &pom1);
        }
        while(j!=1 && i ==1) {
            fprintf(s3, "%d ", pom1);
            printf("%d ", pom1);
            i = fscanf(s1, "%d", &pom1);
        }

    }

    while(j==1) {
        fprintf(s3, "%d ", pom2);
        printf("%d ", pom2);
        j = fscanf(s2, "%d", &pom2);
    }
}






int main()
{
    FILE *a = fopen("s1.txt", "r");
    FILE *b = fopen("s2.txt", "r");
    FILE *c = fopen("s3.txt", "w");

    if(a == NULL || b == NULL || c == NULL) {
        printf("soubor se nepodarilo otevrit");
        return -1;
    }

    slucovani(a,b,c);

    fclose(a);
    fclose(b);
    fclose(c);
    return 0;
}






































      /**  if(i==1) {
            i = fscanf(s1, "%d", &pom1);

        }
        **/
