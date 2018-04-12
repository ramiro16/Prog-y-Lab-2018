#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "funciones.h"

#define TAM 5

//---------------------------------------VECTORES /ARRAY------------------------------------------//
int main()
{
    int vector[TAM];
    int i;
    int mayor, menor, indice;

    for(i=0;i<TAM;i++)
    {
        vector[i] = 0;
    }

    cargarVector(vector,TAM);
    mostrarVector(vector, TAM);

    mayor = buscarMaximo(vector, TAM);
    printf("El maximo es: %d", mayor);
    //mostrarMaxMin(vector,TAM);
    menor = buscarMinimo(vector, TAM);
    printf("\nEl minimo es: %d", menor);

    indice = buscarValor(vector, TAM, 14);

    printf("El indice es: %d", indice)


    return 0;
}
