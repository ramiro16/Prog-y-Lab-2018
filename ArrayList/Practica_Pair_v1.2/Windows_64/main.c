#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"

/*      NOTAS DE CLASE

ArrayLit es una estructura para manipular arrays

*/

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
    ArrayList* lista;
    Employee* e1; //Puntero a em pleado
    Employee* e2;
    Employee* auxEmp;
    int aux,i;

    lista = al_newArrayList();

    e1 = (Employee*)malloc(sizeof(Employee));
    e2 = (Employee*)malloc(sizeof(Employee));

    e1->id = 666;
    strcpy(e1->name,"Juan");
    strcpy(e1->lastName,"Gomez");
    e1->isEmpty = 1;

    e2->id = 999;
    strcpy(e2->name,"Mariana");
    strcpy(e2->lastName,"Castro");
    e2->isEmpty = 1;

    al_add(lista,e1);
    al_add(lista,e2);

    aux = al_len(lista);
    printf("Cantidad de empleados guardados(Size del AL): %d\n",aux);

    for(i=0;i<al_len(lista);i++)
    {
        auxEmp = (Employee*)al_get(lista,i);
        employee_print(auxEmp);
    }

    al_sort(lista,employee_compare,0);

    printf("\n\nPost ordenamiento:\n");

    for(i=0;i<al_len(lista);i++)
    {
        auxEmp = (Employee*)al_get(lista,i);
        employee_print(auxEmp);
    }

    al_remove(lista,1);

     printf("\n\nPost eliminacion:\n");

    for(i=0;i<al_len(lista);i++)
    {
        auxEmp = (Employee*)al_get(lista,i);
        employee_print(auxEmp);
    }

    return 0;
}
