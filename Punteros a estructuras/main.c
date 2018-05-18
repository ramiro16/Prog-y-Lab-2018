#include <stdio.h>
#include <stdlib.h>

/*  NOTAS DE CLASE

    -int y long int pesan lo mismo para C.
    -void pesa 1
    -sizeof redonda si el tipo de dato no es multiplo de 4.


*/

typedef struct
{
    int a;
    char b;

}dato;


int main()
{
    /*
    dato d;

    d.a=5;
    d.b='<';

    dato* pDato;

    pDato = &d; //pdato apunta a la direccion de memoriade d.

    printf("%d -- %c",pDato->a, pDato->b); //El operado -> me perimite acceder a los valores de la estructura a la que el puntero esta apuntando
*/
     //////EJEMPLO 2//////////
    int i;

    dato l[2]={{1,'a'},{1,'b'}};
    dato* pLista;

    pLista = l; //No pongo & porque lista ya es un array

    for(i=0;i<2;i++)
    {
        printf("%d---%c\n",(pLista+i)->a,(pLista+i)->b); // (pLista+i) me da la posicion de lo que voy a mostrar, y el operador ->accede a lo que hay para mostrarlo
    }

    return 0;
}
