#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"

#define TAM 5

int main()
{
    //int i;

    int legajo[TAM]={100,101,102,103,104};
    char nombre[TAM][20]={"Maria","Pedro","Rocio","Ailin","Gustavo"};
    int nota1[TAM]={5,7,9,6,10};
    int nota2[TAM]={7,8,10,5,4};
    float promedio[TAM]={6,7.5,9.5,5.5,7};

    int index;
    int legBuscado;

   /* for(i=0;i<TAM;i++)
        {
        printf("Ingrese nombre:");
        fflush(stdin);
        gets(nombre[i]);

        printf("Ingrese legajo:");
        scanf("%d",&legajo[i]);

        printf("Ingrese primer nota:");
        scanf("%d",&nota1[i]);

        printf("Ingrese segunda nota:");
        scanf("%d",&nota2[i]);

        promedio[i] = calcularPromedio(nota1[i],nota2[i]);

        system("cls");
        }*/

        mostrarAlumnos(nombre,legajo,nota1,nota2,promedio,TAM);

        printf("Ingrese legajo a buscar:");
        scanf("%d",&legBuscado);

        index = buscarLegajo(legajo,TAM,legBuscado);

        if(index != -1)
        {
            printf("El indice del legajo encontrado es: %d\n\n", index);
            system("pause");
        }
        else
        {
            printf("No se ha encontrado el legajo\n\n");
            system("pause");
        }

        system("cls");

        ordenarAlumnos(nombre,legajo,nota1,nota2,promedio,TAM);
        mostrarAlumnos(nombre,legajo,nota1,nota2,promedio,TAM);
        system("pause");
        system("cls");


    return 0;
}


