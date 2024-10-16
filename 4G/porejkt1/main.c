#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *vstup;
    char slovo[21];
    vstup = fopen("bunajegej.txt", "r");
    if(vstup==NULL)
        return -1;


    fscanf(vstup, "%20s", slovo);
    printf("%s", slovo);
    fscanf(vstup, "%20s", slovo);
    printf("%s", slovo);


    fclose(vstup);
    return 0;
}
