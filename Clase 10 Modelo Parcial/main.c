#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "funciones.h"

int main()
{
    eUsuario usuario[TamU];
    eProducto producto[TamP];

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
                //eProducto_alta(producto,TamP,usuario,TamU);
                system("pause");
                system("cls");
                break;
            case 5:
                system("cls");
                eProducto_modificacion(producto,TamP,usuario,TamU);
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 6:
                break;
            case 7:
                system("cls");
                comprarProducto(producto,TamP,usuario,TamU);
                system("pause");
                system("cls");
                break;
            case 8:
                system("cls");
                mostrarProductosxUsuario(usuario,TamU,producto,TamP);
                printf("\n");
                system("pause");
                system("cls");
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
