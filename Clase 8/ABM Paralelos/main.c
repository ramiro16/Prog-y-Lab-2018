#include <stdio.h>
#include <stdlib.h>
#define TAM 4

int buscarLibre(int[], int);
void mostrarAlumnos(int[], char[][20], int[], int[], float[], int);
float calcularPromedio(int, int);
int cargarAlumno(int[], char[][20], int[], int[], float[], int);

int main()
{
    int legajo[TAM]={100,101};
    char nombre[TAM][20]={"Pedro","Ailin"};
    int nota1[TAM]={8,10};
    int nota2[TAM]={5,9};
    float promedio[TAM]={6.5,9.5};
    int opcion;
    int index;
    int i;

    do
    {
        system("cls");
        printf("1. ALTAS\n2. MOSTRAR\n3. MODIFICAR\n4.BAJA\n5.ORDENAR (por nombre)\n9. SALIR\nElija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:

            index=cargarAlumno(legajo,nombre,nota1,nota2,promedio,TAM);
            if(index == -1)
            {
                printf("No hay lugar");
            }
            else
            {
                printf("Alumno ingresado");
                system("pause");
            }
            break;

        case 2:

        system("cls");
        mostrarAlumnos(legajo,nombre,nota1,nota2,promedio,TAM);
        system("pause");
        system("cls");

        break;
        }

    }
    while(opcion!=9);




    return 0;
}

int buscarLibre(int legajos[], int tam)
{
    int index=-1;
    int i;

    for(i=0;i<tam;i++)
    {
        if(legajos[i] == 0)
        {
            index = i;
            break;
        }
    }

    return index;
}

int cargarAlumno(int legajos[], char nombres[][20], int nota1[], int nota2[], float promedio[], int tam)
{
    int index ;
    index = buscarLibre(legajos, tam);
            if(index!=-1)
            {
                printf("Ingrese legajo:");
                scanf("%d",legajos);

                printf("Ingrese nombre:");
                fflush(stdin);
                gets(nombres);

                printf("Ingrese nota 1:");
                scanf("%d",&nota1);

                printf("Ingrese nota 2:");
                scanf("%d",&nota2);
                //Pedir datos
            }
            return index;
}


float calcularPromedio(int nota1, int nota2)
{
    float promedio;
    promedio = (float)(nota1+nota2)/2;
    return promedio;
}

void mostrarAlumnos(int legajos[], char nombres[][20], int nota1[], int nota2[], float promedio[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
            {
                if(legajos[i]!=0)
                {
                    printf("%d %s %d %d %f\n", legajos[i], nombres[i], nota1[i], nota2[i], promedio[i] );
                }

            }

}
