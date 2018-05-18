#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

void inicializarPersona(EPersona* pPersona, int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        (pPersona+i)->estado = 0;
    }
}


void mostrarPersona(EPersona persona[], int tam)
{
    int i;

    printf("NOMBRE\t\t\t\tEDAD\t\t\t\tDNI\n\n");

    for(i=0;i<tam;i++)
    {
        if(persona[i].estado == 1)
        {
            printf("%s\t\t\t\t%d\t\t\t\t%d\n",persona[i].nombre,persona[i].edad,persona[i].dni);
        }
    }
}


int obtenerEspacioLibre(EPersona* pPersona, int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        if((pPersona+i)->estado == 0)
        {
            return i;
        }
    }
    return -1;
}

void altaPersona(EPersona* pPersona, int tam)
{
    int i, espacioLibre;

    espacioLibre = obtenerEspacioLibre(pPersona, tam);

    for(i=0;i<tam;i++)
    {
        if(espacioLibre != -1)
        {
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets((pPersona+espacioLibre)->nombre);

            printf("Ingrese edad: ");
            scanf("%d",(pPersona+espacioLibre)->edad);

            while((pPersona+espacioLibre)->edad) <= 0 || persona[espacioLibre].edad > 100)
            {
                printf("\nEdad Invalida. Reingrese edad <1-99>: ");
                scanf("%d",&persona[espacioLibre].edad);
                system("cls");
            }

            printf("Ingrese DNI: ");
            scanf("%d",&persona[espacioLibre].dni);

            while(persona[espacioLibre].dni <= 0)
            {
                printf("\nDNI Invalido. Reingrese DNI: ");
                scanf("%d",&persona[espacioLibre].dni);
                system("cls");
            }

            persona[espacioLibre].estado = 1;
            break;
        }
        else
        {
            printf("No hay espacio para agregar persona!\n\n");
            system("pause");
            break;
        }
    }
}

int buscarPorDni(EPersona persona[],int dni)
{
    int i;
    int pos;
    int flag = 0;

    for(i=0;i<20;i++)
    {
        if(persona[i].dni == dni)
        {
            flag = 1;
            pos = i;
        }
    }

    if(flag == 0)
    {
        pos = -1;
    }

    return pos;
}

void borrarPersona(EPersona persona[], int tam)
{
    int dni, pos;
    char respuesta;

    printf("Ingrese DNI de la persona que desea borrar: ");
    scanf("%d",&dni);

    pos = buscarPorDni(persona, dni);

    if(pos != -1)
        {
            printf("\nSeguro que desea eliminar?...\n\nNombre:%s\tEdad:%d\tDNI:%d\n\n",persona[pos].nombre,persona[pos].edad,persona[pos].dni);
            printf("\nIngrese S para confirmar, N para cancelar");
            fflush(stdin);
            respuesta=tolower(getch());
            while(respuesta != 's' && respuesta!= 'n')
                {
                    printf("\nRespuesta incorrecta. Reingrese respuesta: ");
                    fflush(stdin);
                    respuesta=getche();
                }
            if(respuesta =='s')
                {
                    printf("\nSe han borrado los datos.\n");
                    persona[pos].estado = 0;
                }
            else
                {
                    printf("\nNo se han eliminado los datos.\n");
                }
        }
        if(pos == -1)
        {
            printf("No se ha encontrado el DNI.\n");
        }
    }

void ordenarPersonas(EPersona persona[], int tam)
{
    int i,j;
    EPersona auxPersona;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(strcmp(persona[i].nombre,persona[j].nombre) == 1)
            {
                auxPersona = persona[i];
                persona[i] = persona[j];
                persona[j] = auxPersona;
            }
        }
    }

    mostrarPersona(persona, tam);
}

void graficoEdades(int contMenor18, int cont19a35, int contMayor35)
{
    int i;
    int j;
    int max=0;
    int valor[3]={contMenor18,cont19a35,contMayor35};

    for (i = 0; i < 3; i++)
    {
        if (valor[i] > max)
        {
            max = valor[i];
        }
    }
    printf("\n");
    for (i = max; i > 0; i--)
    {
        printf("F%d",i);
        for (j = 0; j < 3; j++)
        {

            if (valor[j] >= i)
            {
                printf("\t  *");
            }
            else
            {
                printf("\t ");
            }
        }
        printf("\n");
    }
    printf("\t<19\t19-35\t >35\n");
    system("pause");
    system("cls");
}
