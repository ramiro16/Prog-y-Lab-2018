#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo;
    char nombre[50];
    float promedio;

}eAlumno;

void mostrarTodo(eAlumno[], int);

int main()
{
    eAlumno clase[3];
    int i;

    for(i=0;i<3;i++)
    {
        printf("Ingrese legajo:");
        scanf("%d",&clase[i].legajo);

        printf("Ingrese nombre:");
        fflush(stdin);
        gets(clase[i].nombre);

        printf("Ingrese promedio: ");
        scanf("%f",&clase[i].promedio);
    }

    mostrarTodo(clase , 3);

    return 0;
}

void mostrarTodo(eAlumno alumnos[], int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        printf("%d -- %s -- %.2f\n",alumnos[i].legajo,alumnos[i].nombre,alumnos[i].promedio);
    }
}
