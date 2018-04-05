#include <stdio.h>
#include <stdlib.h>

int pedirEntero(char[50],int,int);

int validarEntero(int, int, int, char[]);

int main()
{
    int edad;
    int legajo;
    int nota;

    edad = pedirEntero(" edad:", 18, 60);
    legajo = pedirEntero(" legajo:",1,1000);
    nota = pedirEntero(" nota:",1,10);

    printf("La edad es %d. El legajo es %d. La nota es %d\n", edad, legajo,nota);


    return 0;
}

int pedirEntero(char mensaje[50],int min,int max)
{
    int numero;

    printf("Ingrese%s", mensaje);
    scanf("%d",&numero);

    numero = validarEntero(numero,min,max, mensaje);

    return numero;
}

int validarEntero(int dato, int min, int max,char mensaje[])
{
    while(dato<min || dato>max )
    {
        printf("Error. Reingrese%s ", mensaje);
        scanf("%d", &dato);
    }
}
