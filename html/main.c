#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* f;
    char mensaje[20]="Hola a todos";

    f = fopen("mihtml.html","w");


    if(f!=NULL)
    {
        fprintf(f,"<html><head>");
        fprintf(f,mensaje);
        fprintf(f,"</head></html>");
        fclose(f);
    }
    return 0;
}
