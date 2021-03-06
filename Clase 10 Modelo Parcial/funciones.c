#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "funciones.h"

void hardcodearUsuarios(eUsuario usuario[],int tam)
{
    int i;

    char nombre[][50]={"Maria","Pedro","Marta","Gabriel","Oscar"};
    int id[]={100,101,102,103,104};
    int edad[]={22,34,18,31,45};
    float cal[]={7,8,3,4,9};

    for(i=0;i<tam;i++)
    {
        strcpy(usuario[i].nombre,nombre[i]);
        usuario[i].idUsuario=id[i];
        usuario[i].calificacion=cal[i];
        usuario[i].estado = OCUPADO;
        usuario[i].edad = edad[i];
    }
}

void mostrarUsuarios(eUsuario usuario[],int tam)
{
    int i;

    printf("ID USUARIO\tNOMBRE\t\tEDAD\t\tCALIFICACION\n\n");

    for(i=0;i<tam;i++)
    {
        if(usuario[i].estado == 0)
        {
            printf("%d%19s%13d%19d\n",usuario[i].idUsuario,usuario[i].nombre,usuario[i].edad,usuario[i].calificacion);
        }
    }
}

int eUsuario_alta(eUsuario listado[],int limite)
{
    int retorno = -1; //DEVUELVE -1 SI LIMITE < 0
    //char nombre[50];
    int id;
    int indice;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2; //DEVUELVE -2 SI NO ENCUENTRA LUGAR LIBRE
        indice = eUsuario_buscarLugarLibre(listado,limite); //LLAMA A BUSCAR LUGAR
        if(indice >= 0)
        {
            retorno = -3;
            id = eUsuario_siguienteId(listado,limite);//GENERA UNA ID

            //if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))

            retorno = 0;
            /*{
            strcpy(listado[indice].nombre,"juan ");
            listado[indice].idUsuario = id;
            listado[indice].estado = OCUPADO;
            }*/
            printf("Ingrese nombre:");
            fflush(stdin);
            gets(listado[indice].nombre);

            printf("Ingrese edad:");
            scanf("%d",&listado[indice].edad);

            while(listado[indice].edad <= 0 || listado[indice].edad >99)
            {
                printf("Edad erronea. Reingrese edad:");
                scanf("%d",&listado[indice].edad);
            }

            listado[indice].idUsuario = id;
            listado[indice].estado = OCUPADO;
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

int eUsuario_modificacion(eUsuario listado[] ,int limite)
{
    int retorno = -1;
    int aux;
    int i;
    int opcion;

    char seguir = 's';

    if(limite > 0 && listado != NULL)
    {
        retorno = -2; //Devuelve -2 si lograr pedir un ID a modificar pero no puede modificar nada

        mostrarUsuarios(listado, limite);

        printf("\nIngrese ID de usuario a modificar:");
        scanf("%d",&aux);

        for(i=0;i<limite;i++)
        {
            if(listado[i].idUsuario == aux)
            {
                while(seguir == 's')
                {
                    printf("\nQue desea modificar?\n\n");
                    printf("1-Nombre\n");
                    printf("2-Edad\n");

                    scanf("%d",&opcion);

                    switch(opcion)
                    {
                        case 1:
                            printf("\nIngrese nuevo nombre:");
                            fflush(stdin);
                            gets(listado[i].nombre);
                            retorno = 0;
                            seguir = 'n';
                            break;
                        case 2:
                            printf("\nIngrese nueva edad:");
                            scanf("%d",&listado[i].edad);
                            retorno = 0;
                            seguir = 'n';
                            break;
                    }
                }

                break;
            }
        }
    }


    return retorno;
}

int eUsuario_baja(eUsuario listado[] ,int limite)
{
    int retorno = -1; //NO LOGRA PASAR EL PRIMER IF
    int aux;
    int i;
    char rta;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2; //SI EL ID INGRESADO ES INCORRECTO

        mostrarUsuarios(listado, limite);

        printf("\nIngrese ID de usuario que desea dar de baja:");
        scanf("%d",&aux);

        for(i=0;i<limite;i++)
        {
            if(listado[i].idUsuario == aux)
            {
                system("cls");
                printf("Desea dar de baja al siguiente usuario? S/N\n\n");
                eUsuario_mostrarUno(listado[i]);
                rta = getch();

                if(rta == 'S' || rta == 's')
                {
                    listado[i].estado = LIBRE;
                    retorno = 0;
                    printf("\nSE HA DADO DE BAJA CON EXITO!\n");
                    break;
                }
                else
                {
                    printf("\nSE HA CANCELADO LA BAJA\n");
                    break;
                }

            }
        }
    }

    return retorno;
}

void eUsuario_mostrarUno(eUsuario listado)
{
    printf("ID USUARIO\tNOMBRE\t\tEDAD\n\n");
    printf("%d%19s%13d\n",listado.idUsuario,listado.nombre,listado.edad);
}

int eProducto_init(eProducto listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado = LIBRE;
            listado[i].idProducto = 0;
        }
    }
    return retorno;
}

void hardcodearProductos(eProducto listado[],int limite)
{
    int i;

    int id[]={1000,1001,1002,1003,1004,1005,1006,1007,1008,1009};
    int usuarioVendedor[]={100,104,102,100,101,103,104,100,102,104};
    int stock[]={10,7,8,3,9,23,42,17,25,5};
    float precio[]={10.20,7,25,34,10,25.50,120.30,9.99,12,300.35};
    char nombre[][50]={"Joystick","Pelota Playa","Taza","Videojuego","Camiseta","Pintura","Carpeta","Paragua","Adorno","Trofeo"};

    for(i=0;i<limite;i++)
    {
        listado[i].idProducto = id[i];
        listado[i].stock = stock[i];
        listado[i].precio = precio[i];
        listado[i].idUsuario = usuarioVendedor[i];
        strcpy(listado[i].nombre,nombre[i]);
        listado[i].estado = OCUPADO;
    }
}

void mostrarProductos(eProducto listado[],int limite)
{
    int i;

    printf("ID PRODUCTO\tNOMBRE\t\tPRECIO\t\tSTOCK\n\n");

    for(i=0;i<limite;i++)
    {
        if(listado[i].estado == 0)
        {
            printf("%d%19s%15.2f%14d\n",listado[i].idProducto,listado[i].nombre,listado[i].precio,listado[i].stock);
        }
    }
}

int eProducto_alta(eProducto listadoP[], int limiteP, eUsuario listadoU[], int limiteU)
{
    int i;

    int retorno = -1; //DEVUELVE -1 SI LIMITE < 0
    int auxId;
    int indice;

    if(limiteU > 0 && limiteP > 0 && listadoU != NULL && listadoP != NULL)
    {
        retorno = -2; //DEVUELVE -2 SI NO ENCUENTRA LUGAR LIBRE
        mostrarUsuarios(listadoU,limiteU);
        printf("Ingrese ID de usuario que realizara publicacion:");
        scanf("%d",&auxId);

        for(i=0;i<limiteU;i++)
        {
            if(listadoU[i].idUsuario == auxId)
            {
                indice = eProducto_buscarLugarLibre(listadoP,limiteP); //BUSCA LUGAR EN ARRAY PRODCUTO IGNORAR IDENTIFICADOR

                if(indice >= 0)
                {
                    retorno = 0;

                    auxId = eProducto_siguienteId(listadoP,limiteP);//GENERA UNA ID IGNORAR IDENTIFICADOR

                    printf("Ingrese nombre de producto:");
                    fflush(stdin);
                    gets(listadoP[indice].nombre);

                    printf("Ingrese cantidad de producto:");
                    scanf("%d",&listadoP[indice].stock);

                    printf("Ingrese precio de producto:");
                    scanf("%f",&listadoP[indice].precio);

                    listadoP[indice].idProducto = auxId;
                    listadoP[indice].estado = OCUPADO;
                }
            }
        }
    }

    return retorno;
}

int eProducto_buscarLugarLibre(eProducto listado[],int limite)
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

int eProducto_siguienteId(eProducto listado[],int limite)
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

int eProducto_modificacion(eProducto listadoP[],int limiteP, eUsuario listadoU[],int limiteU)
{
    int retorno = -1;
    int aux;
    int i,j;
    char auxChar;

    if(limiteU > 0 && limiteP > 0 && listadoP != NULL && listadoU != NULL)
    {
        retorno = -2;

        mostrarUsuarios(listadoU, limiteU);

        printf("\nIngrese ID de usuario que modificara sus productos:");
        scanf("%d",&aux);

        for(i=0;i<limiteU;i++)
        {
            if(listadoU[i].idUsuario == aux)
            {
                mostrarProductosxUsuario(listadoU,limiteU,listadoP,limiteP);

                printf("Ingrese ID de producto que desea modificar:");
                scanf("%d",&aux);

                for(j=0;j<limiteP;j++)
                {
                    if(listadoP[j].idProducto == aux)
                    {
                         printf("Desea modificar precio y stock? S/N");
                         fflush(stdin);
                         auxChar = getch();

                         if(auxChar == 's' || auxChar == 'S')
                         {
                           printf("Ingrese nuevo precio:");
                           scanf("%f",&listadoP[j].precio);

                           printf("Ingrese nueva cantidad de stock:");
                           scanf("%d",&listadoP[j].stock);

                           retorno = 0;

                           break;
                         }
                    }
                }
            }
        }
    }


    return retorno;
}

void mostrarProductosxUsuario(eUsuario listadoU[],int limiteU,eProducto listadoP[],int limiteP)
{
    int i,j;
    int aux;

    mostrarUsuarios(listadoU,limiteU);

    printf("\nIngrese ID de usuario para ver sus publicaciones:");
    scanf("%d",&aux);

    system("cls");

    for(i=0;i<limiteU;i++)
    {
        if(listadoU[i].estado == OCUPADO && listadoU[i].idUsuario == aux)
        {
            printf("Publicaciones del usuario %s con el ID %d\n\n",listadoU[i].nombre,listadoU[i].idUsuario);
            printf("\nID PRODUCTO\tNOMBRE\t\tPRECIO\t\tSTOCK\n");

            for(j=0;j<limiteP;j++)
            {
                if(listadoU[i].idUsuario == listadoP[j].idUsuario)
                {
                    printf("%d\t%15s\t%14.2f\t%10d\n",listadoP[j].idProducto,listadoP[j].nombre,listadoP[j].precio,listadoP[j].stock);
                }
            }
        }
    }
}

int comprarProducto(eProducto listadoP[],int limiteP,eUsuario listadoU[],int limiteU)
{
    int aux;
    int i,j;
    int retorno = -1;

    mostrarProductos(listadoP,limiteP);
    printf("Ingrese ID de producto que desea comprar:");
    scanf("%d",&aux);

    for(i=0;i<limiteP;i++)
    {
            if(listadoP[i].idProducto == aux && listadoP[i].stock > 0)
            {
                retorno = 0;
                listadoP[i].stock--;
                printf("COMPRA REALIZADA CON EXITO!\n\n");

                for(j=0;j<limiteU;j++)
                {
                    if(listadoP[i].idUsuario == listadoU[j].idUsuario)
                    {
                        printf("Ingresar calificacion del 1 a 10:");
                        scanf("%d",&aux);

                        listadoU[j].calificacion = listadoU[j].calificacion + aux;
                        break;
                    }
                }

            }
    }

    return retorno;
}
