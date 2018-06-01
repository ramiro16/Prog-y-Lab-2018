#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*  NOTAS DE CLASE

FUNCION MALLOC, RESERVA DINAMICA DE MEMORIA, DEVUELVE UN PUNTERO A VOID, RECIBE UN TAMAÑO.
LE PASO EL TIPO DE DATO A RESERVAR, Y RESERVA ESA CANTIDAD DE BYTES EN MEMORIA CONSECUTIVOS
-Se debe castear el tipo de dato void que devuelve malloc al tipo de dato que le asigno

-getters y setters son fuciones.
-setter, settea, dan un valor al campo
-getter, funciones que me permite obtener datos

*/
typedef struct
{
    int id;
    char nombre[50];

}ePersona;

int ePersona_setId(ePersona*,int); //Un puntero a persona y el id a setear en la estructura
int ePersona_setNombre(ePersona*,char*);
int ePersona_getId(ePersona*);
char* ePersona_getNombre(ePersona*);

int main()
{
    ePersona* pPersona;

    pPersona = (ePersona*)malloc(sizeof(ePersona)); //Le asigna al puntero la primer direccion de esos bytes consecutivos que hayo

    if(pPersona != NULL)
    {
        if(ePersona_setId(pPersona, 45) == -1)
        {
            printf("ID INCORRECTO!");
        }
        else
        {
            if(ePersona_setNombre(pPersona,"Juan") == -1)
            {
                printf("NOMBRE INCORRECTO!");
            }
            else
            {
                printf("%d--%s",ePersona_getId(pPersona),ePersona_getNombre(pPersona)); //Recordar que el operador -> sustituye el * (operador de inacceso)
            }
        }
    }


    return 0;
}

int ePersona_setId(ePersona* this, int id)
{
    int ret = -1;

    if(id > 0 && this != NULL)
    {
        ret = 1;
        this->id = id;
    }

    return ret;
}

int ePersona_setNombre(ePersona* this,char* nombre)
{
     int ret = -1;

    if(this != NULL && nombre != NULL && (strlen(nombre)>3))
    {
        ret = 1;
        strcpy(this->nombre,nombre);
    }

    return ret;
}

int ePersona_getId(ePersona* this)
{
    int ret = -1;

    if(this != NULL)
    {
        ret = this->id;
    }

    return ret;
}

char* ePersona_getNombre(ePersona* this)
{
    char* ret = NULL;

    if(this != NULL)
    {
        ret = this->nombre;
    }

    return ret;
}

