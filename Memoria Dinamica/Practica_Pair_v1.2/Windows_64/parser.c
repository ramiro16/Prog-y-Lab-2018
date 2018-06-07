#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{
    int aux;

    pFile = fopen("data.csv","r");

    aux = fscanf(pFile);


    return 0;
}
