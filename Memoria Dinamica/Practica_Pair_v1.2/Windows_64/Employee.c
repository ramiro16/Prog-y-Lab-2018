#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    Employee* e1;
    Employee* e2;
    int retorno;

    e1 = (Employee*)pEmployeeA;
    e2 = (Employee*)pEmployeeB;

    retorno = strcmp(e1->name,e2->name);

    return retorno;
}


void employee_print(Employee* this)
{
    printf("\nNombre:%s\tApellido:%s\tID:%d",this->name,this->lastName,this->id);
}


Employee* employee_new(void)
{
    Employee* returnAux = NULL;



    return returnAux;

}

void employee_delete(Employee* this)
{


}

int employee_setId(Employee* this, int id)
{

    return 0;

}

int employee_getId(Employee* this)
{

    return 0;

}


