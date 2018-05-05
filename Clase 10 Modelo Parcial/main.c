#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define OCUPADO 0
#define LIBRE 1

#define TamU 5
#define TamP 10

typedef struct
{
    char nombre[50];
    int idUsuario;
    int edad;
    float calificacion;

    int estado;

}eUsuario;

typedef struct
{
    int idProducto;
    int idUsuario;
    int stock;
    float precio;
    char nombre[50];

    int estado;

}eProducto;

void hardcodearUsuarios(eUsuario[],int);
void hardcodearProductos(eProducto[],int);

void mostrarUsuarios(eUsuario[],int);
void mostrarProductos(eProducto[],int);

void eUsuario_mostrarUno(eUsuario);

int eUsuario_init(eUsuario[],int);
int eProducto_init(eProducto[],int);

int eUsuario_alta(eUsuario[],int);
int eUsuario_modificacion(eUsuario[],int);
int eUsuario_baja(eUsuario[] ,int);

int eProducto_alta(eProducto[],int,eUsuario[],int);

int eUsuario_buscarLugarLibre(eUsuario[],int);
int eUsuario_siguienteId(eUsuario[] ,int);

int eProducto_buscarLugarLibre(eProducto[],int);
int eProducto_siguienteId(eProducto[],int);





int main()
{
    eUsuario usuario[TamU];
    eProducto producto[TamP];
    //int auxUser;

    char seguir='s';
    int opcion=0;

    eUsuario_init(usuario,TamU);
    eProducto_init(producto,TamP);

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
                hardcodearUsuarios(usuario,TamU);
                eUsuario_alta(usuario,TamU);
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                eUsuario_modificacion(usuario,TamU);
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                eUsuario_baja(usuario,TamU);
                system("pause");
                system("cls");
                break;
            case 4:
                system("cls");
                hardcodearProductos(producto,TamP);

                eProducto_alta(producto,TamP,usuario,TamU);
                system("pause");
                system("cls");
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
                system("cls");
                mostrarProductos(producto,TamP);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 10:
                system("cls");
                mostrarUsuarios(usuario,TamU);
                printf("\n");
                system("pause");
                system("cls");
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

    printf("ID USUARIO\tNOMBRE\t\tEDAD\n\n");

    for(i=0;i<tam;i++)
    {
        if(usuario[i].estado == 0)
        {
            printf("%d%19s%13d\n",usuario[i].idUsuario,usuario[i].nombre,usuario[i].edad);
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
