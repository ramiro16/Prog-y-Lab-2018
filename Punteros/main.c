#include <stdio.h>
#include <stdlib.h>

int cargararray(int*,int);
void mostrararray(int*,int);

int main()
{

    int vector[3];
    int i;
    int retorno = 0;

    if(cargararray(vector,3))
    {
        printf("Carga exitosa!\n");

    }
    else
    {
        printf("Error al cargar los datos\n");
    }

    return 0;

}

int cargararray(int* array,int tam)
{
    int i;
    int retorno = 0;

    if(array != NULL)
    {
        retorno = 1;
        for(i=0;i<tam;i++)
        {
            printf("Ingrese numero!");
            scanf("%d",array+1);
        }
    }

    return retorno;

}
void mostrararray(int* array,int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        printf("\n%d",*(array+1));
    }

}
