#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *vstup, *vystup;
    char znak;
    vstup=fopen("zadani1.txt", "r");
    vystup=fopen("bunajegej.txt", "w");
    if (vstup==NULL || vystup==NULL) return -1;

    while (fscanf(vstup, "%c", &znak) == 1) {
        if(znak>='0' && znak <= '5')
    {
        fprintf(vystup," ");
    }
    else if(znak>='6' && znak <='9')
    {
        fprintf(vystup, "$");
    }
        else
            fprintf(vystup, "%c", znak);
        }
    fclose(vstup);
    fclose(vystup);
    return 0;
}
