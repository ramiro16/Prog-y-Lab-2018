#include <stdio.h>
#include <stdlib.h>

#define TAM 5

/*  NOTAS DE CLASE

Realloc - reasigna espacio en memoria. Recibe sizeof del tipo de dato * la cantidad total de elementos que necesito
-Si encuentra espacio agrega esos elementos.
-Si encuentra pero no continuo mueve todos los elementos.
-si no hay memoria continua para reservar, devuelve NULL

*/

int main()
{
    int* pVector;
    int* aux;
    int i;

    pVector = (int*)malloc(sizeof(int)*TAM); //*5 especifica que necesito espacio para 5 enteros

    if(pVector != NULL)
    {
        for(i=0;i<TAM;i++)
        {
            *(pVector+i) = i+1;
        }
        for(i=0;i<TAM;i++)
        {
            printf("%d\n",*(pVector+i));
        }

        aux = (int*)realloc(pVector, sizeof(int)*(TAM*2));

        if(aux != NULL)
        {
            pVector = aux;

            for(i=0;i<TAM*2;i++)
            {
                *(pVector+i) = i+1;
            }

            printf("Luego del realloc\n");

            for(i=0;i<TAM*2;i++)
            {
                printf("%d\n",*(pVector+i));
            }

            aux = (int*)realloc(pVector, sizeof(int)*4);
            if(aux != NULL)
            {
                printf("Luego del realloc por menos:\n");

                for(i=0;i<4;i++)
                {
                    printf("%d\n",*(pVector+i));
                }
            }
        }

    }



    return 0;
}
