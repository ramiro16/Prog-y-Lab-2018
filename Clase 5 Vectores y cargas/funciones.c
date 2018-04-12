#include "funciones.h"
#include "funciones.c"

void mostrarVector(int vec[TAM],int tamanio)
{
    int i;

    for(i=0;i<tamanio;i++)
    {
        printf("Posicion %d -- %d\n",i, vec[i]);
    }

}

void modificarVector(int vec[TAM],int tamanio)
{
    vec[3] = 789;
}

void mostrarMaxMin(int vec[TAM], int tamanio)
{
    int i;
    int max; //int max = INT_MIN;
    int min; //int min = INT_MAX;

    for(i=0;i<tamanio;i++)
    {
        if(vec[i]>max)
        {
            max = vec[i];
        }
        if(vec[i]<min)
        {
            min = vec[i];
        }
    }

    printf("Numero mayor: %d\nNumero menor: %d", max,min);

}

int buscarMaximo(int vec[TAM],int tam)
{
    int maximo;
    int i;
    int flag = 0;

    for(i=0;i<tam;i++)
    {
        if(flag == 0 || vec[i]>maximo)
        {
            maximo = vec[i];
            flag = 1;
        }
    }

    return maximo;
}

int buscarMinimo(int vec[TAM],int tam)
{
    int i;
    int minimo;
    int flag = 0;

    for(i=0;i<tam;i++)
    {
        if(flag == 0 || vec[i] < minimo)
        {
            minimo = vec[i];
            flag = 1;
        }
    }

    return minimo;
}

void cargarVector(int vec[], int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",&vec[i]);
    }
}

int buscarValor(int vec[], int tam, int valor)
{
    int index = -1;
    int i;

    for(i=0;i<tam;i++)
    {
        if(valor == vec[i])
        {
            index = i;
            break;
        }
    }

    return index;
}
