#include <stdio.h>
#include <stdlib.h>

/*
    CUANDO UTILIZO ARCHIVOS 3 PASOS PRINCIPALES:
    1ro abrir archivo
    2ro obtenre los datos del archivo
    3ro cerrarlo

    SE PUEDE CREAR:
    archivos de texo
    archivos binarios (capacidad de guardar bloques de informacion)

    feof() funcion que me permite saber si encontrar el final en el archivo

*/

int main()
{
    FILE *fp; //DECLARACION DE LA ESTRUCTURA FILE(ARCHIVO). ESTE PUNTERO VA A REPRESENTAR A MI ARCHIVO, VA A APUNTAR A ARCHIVO

    char buffer[100] = "Esto es un texto dentro del fichero";
    char bufferIn[100];

    fp = fopen("fichero.txt", "w"); // fOpen abre el archivo. solo lo abre. Primer parametro, nombre del archivo. Segundo parametro modo de escritura(para leer, escribir, etc...) D:\\ramiro\\fichero.txt se pone solo si el fichero existe y esta en otro lado.

    fprintf(fp, buffer); //Imprime en el archio, escribe texto en el archivo
    fprintf(fp,"%s", "\nEsto es otro texto dentro de fichero");
    fprintf(fp, "\nEsto es otro texto dentro de fichero: y el buffer contiene: %s",buffer);

    fclose(fp); //cierra el archivo, le paso el puntero;
    system("pause");
    system("cls");

    fp = fopen("fichero.txt","r"); //abro para leer

    if(fp == NULL)
    {
        printf("Archivo no encontrado\n");
    }
    else
    {
        while(!feof(fp))
        {
            fgets(bufferIn,100,fp); //Toma una cadena y guarda lo que hay en el archivo en la variable, en este caso en "bufferIn", segundo parametro el tamaño de lo que peude leer, el puntoer al archivo es el ultimo parametro
            puts(bufferIn);
        }
    }

    return 0;
}
