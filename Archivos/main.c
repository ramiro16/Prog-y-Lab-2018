#include <stdio.h>
#include <stdlib.h>

/*

NOTAS DE CLASE

-Los archivos de texto guardan texto
-los binario guardan en binario pero respetando los tipos de dato
-

*/

int main()
{
    FILE* pArchivo; // Reprsenta el archivo en memoria

    char cadena[50] = "hola ";

    pArchivo = fopen("archivo.txt","w");//Por defecto y, si no se especifica, los archivos se leen en el directorio de proyecto.
                                        // Si el archivo de vuelve algo distinto de null podemos trabajar ocn el
    if(pArchivo !=NULL)
    {
        fprintf(pArchivo,"%s---%d",cadena,156);
        fclose(pArchivo);
        printf("Guardado!");
    }
    else
    {
        printf("Imposible guardar");
    }

    return 0;



    pArchivo = fopen("archivot.txt","r");

    if(pArchivo != NULL)
    {
        while(!feof(pArchivo)) //Lee linea por linea hasta que llegue al final, esa es la funcion de feof
              {
                  fgets(cadena,50,pArchivo);
                  puts(cadena);
              }

              fclose(pArchivo);
    }
}
