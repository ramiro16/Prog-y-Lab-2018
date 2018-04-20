#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define TAM 5

float calcularPromedio(int numero1, int numero2)
{
    float prom;

    prom = (float)(numero1 + numero2) / 2; //EL FLOAT INDICA CASTEO PARA PODER PASAR A DECIMAL LA SUMA Y QUE EL PROMEDIO NO DE ENTERO

    return prom;
}

void mostrarAlumnos(char nombre[][20],int legajo[],int nota1[],int nota2[],float promedio[],int cantidad)
{
    int i;

    printf("NOMBRE\t\tLEGAJO\t\tNOTA 1\t\tNOTA 2\t\tPROMEDIO\n");

    for(i=0;i<cantidad;i++)
    {
        printf("%s\t\t%d\t\t%d\t\t%d\t\t%.2f\n",nombre[i],legajo[i],nota1[i],nota2[i],promedio[i]);
    }

    ordenarAlumnos(nombre,legajo,nota1,nota2,promedio,TAM);

    system("pause");
    system("cls");
}

int buscarLegajo(int legajo[],int tam,int leg)
{
    int index = -1;
    int i;

    for(i=0;i<tam;i++)
    {
        if(legajo[i]==leg)
        {
            index = i;
            break;
        }
    }
    return index;
}

void ordenarAlumnos(char nombre[][20],int legajo[],int nota1[],int nota2[],float promedio[],int tam)
{
    int i,j;
    char auxNombre[20];
    int auxLeg, auxnota;
    float auxprom;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(strcmp(nombre[i],nombre[j])>0)
            {
                strcpy(auxNombre,nombre[i]);
                strcpy(nombre[i],nombre[j]);
                strcpy(nombre[j],auxNombre);

                auxLeg = legajo[i];
                legajo[i] = legajo[j];
                legajo[j] = auxLeg;

                auxnota = nota1[i];
                nota1[i] = nota1[j];
                nota1[j] = auxnota;

                auxnota = nota2[i];
                nota2[i] = nota2[j];
                nota2[j] = auxnota;

                auxprom = promedio[i];
                promedio[i] = promedio[j];
                promedio[j] = auxprom;
            }
        }
    }
}
