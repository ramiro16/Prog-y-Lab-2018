#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OCUPADO 0
#define LIBRE 1

#define TamU 5

typedef struct
{
    char nombre[50];
    int idUsuario;
    float calificacion;

    int estado;

}eUsuario;

void hardcodearUsuarios(eUsuario[],int);
void mostrarUsuarios(eUsuario[],int);

int eUsuario_init(eUsuario[],int);
int eUsuario_alta(eUsuario[] ,int);
int eUsuario_buscarLugarLibre(eUsuario listado[],int);
int eUsuario_siguienteId(eUsuario[] ,int);

int main()
{
    eUsuario usuario[TamU];

    char seguir='s';
    int opcion=0;

    eUsuario_init(usuario,TamU);

    while(seguir=='s')
    {
        printf("1- Alta de usuario\n");
        printf("2- Modificar datos de usuario\n");
        printf("3- Baja de usuario\n");
        printf("4- Publicar producto\n");
        printf("5- Modificar publicacion\n");
        printf("6- Cancelar publicacion\n");
        printf("7- Comprar producto\n");
        printf("8- Listar publicaciones de usuario\n");
        printf("9- Listar publicaciones\n");
        printf("10- Listar usuarios\n\n");


        printf("11- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                //hardcodearUsuarios(usuario,TamU);
                eUsuario_alta(usuario,TamU);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                system("cls");
                mostrarUsuarios(usuario,TamU);
                break;
            case 11:
                seguir = 'n';
                break;
        }
    }

    return 0;
}

void hardcodearUsuarios(eUsuario usuario[],int tam)
{
    int i;

    char nombre[][50]={"Maria","Pedro","Marta","Gabriel","Oscar"};
    int id[]={100,101,102,103,104};
    float cal[]={7,8,3,4,9};
    int estado = OCUPADO;

    for(i=0;i<tam;i++)
    {
        strcpy(usuario[i].nombre,nombre[i]);
        usuario[i].idUsuario=id[i];
        usuario[i].calificacion=cal[i];
        usuario[i].estado = OCUPADO;
    }
}

void mostrarUsuarios(eUsuario usuario[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(usuario[i].estado == 0)
        {
            printf("%d -- %s -- %.2f\n",usuario[i].idUsuario,usuario[i].nombre,usuario[i].calificacion);
        }
    }
}

int eUsuario_alta(eUsuario listado[],int limite)
{
    int retorno = -1; //DEVUELVE -1 SI LIMITE < 0
    char nombre[50];
    int id;
    int indice;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2; //DEVUELVE -2 SI NO ENCUENTRA LUGAR LIBRE
        indice = eUsuario_buscarLugarLibre(listado,limite); //LLAMA A BUSCAR LUGAR
        if(indice >= 0)
        {
            retorno = -3;
            id = eUsuario_siguienteId(listado,limite); //GENERA UNA ID
            //if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))
            /*{
            retorno = 0;
            strcpy(listado[indice].nombre,"juan ");
            listado[indice].idUsuario = id;
            listado[indice].estado = OCUPADO;
            }*/
            printf("Ingrese nombre:");
            fflush(stdin);
            gets(listado[indice].nombre);

            printf("Ingrese edad:");
            scanf("%d",&listado[indice].)
        }
    }
    return retorno;
}

int eUsuario_buscarLugarLibre(eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eUsuario_siguienteId(eUsuario listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                    if(listado[i].idUsuario>retorno)
                    {
                         retorno=listado[i].idUsuario;
                    }
            }
        }
    }

    return retorno+1;
}

int eUsuario_init(eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= LIBRE;
            listado[i].idUsuario= 0;
        }
    }
    return retorno;
}
