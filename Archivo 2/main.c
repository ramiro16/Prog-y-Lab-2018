#include <stdio.h>
#include <stdlib.h>

/*
NOTAS DE CLASE

Funcion fwrite:

Escribe cualquier tipo de dato(binario,texto,estructura)en archivo.
-Recibe la direccion de memoria del dato que voy a escribir en el archivo
-sizeof del tipo de dato que voy a escribir
-cantidad de datos que vamos a escribir
-el puntero al archivo

Funcion fread:
-Recibe lo mismo que fwrite solo que cambian los roles, destino es origen y origen destino


Split : recortar el string con datos con un caracter especifico denominado delimitador. fscanf;

*/

typedef struct
{
    int a;
    char b;

}edato;

void funcion2a();

int main()
{

    FILE*  miArchivo;

/*    int numero=64;

    miArchivo = fopen("prueba1.txt","w");

    fwrite(&numero,sizeof(int),1,miArchivo);

    fclose(miArchivo);

    miArchivo = fopen("prueba1.txt","r");

    fread(&numero,sizeof(int),1,miArchivo);
    fclose(miArchivo);
    printf("NUMERO: %d",numero);
*/
////////////////// EJEMPLO 2 //////////////////////////////

    miArchivo = fopen("prueba.txt","w");
    int i;
    int numero;
    int lista[5] ={9,4,8,6,4};
/*

        for(i=0;i<5;i++)
        {
            printf("ingrese un numero:");
            scanf("%d",&numero);

            fwrite(&numero,sizeof(int),1,miArchivo);
        }

        fclose(miArchivo);

        miArchivo = fopen("prueba.txt","r");

        i=0;
        while(!feof(miArchivo))
        {
            fread(&numero,sizeof(int),1,miArchivo);
            i++;
        }

        fclose(miArchivo);
        for(i=0;i<5;i++)
        {
            printf("%d\n",lista[i]);
        }
*/


/////////////////////// EJEMPLO 3 ///////////////////////////////////

/*
    miArchivo = fopen("prueba3.txt","w");
    fwrite(lista,sizeof(int),5,miArchivo);
    fclose(miArchivo);

    miArchivo = fopen("prueba3.txt","w");
    fread(lista,sizeof(int),5,miArchivo);
    fclose(miArchivo);

    for(i=0;i<5;i++)
    {
        printf("%d\n",lista[i]);
    }
*/

////////////////////////EJERCICIO 4//////////////////////////////////////////////////7

    edato d={1,'B'};

    miArchivo = fopen("miBinario.dat","wb");

    if(miArchivo != NULL)
    {
        fread/*fwrite*/(&d,sizeof(edato),1,miArchivo);
        fclose(miArchivo);

        printf("%d---%c",d.a,d.b);
    }

    return 0;


}

