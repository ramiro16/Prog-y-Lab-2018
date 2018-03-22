#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1;
    float numero2;
    float resultado;
    char letra;

    numero1 = 87;







    numero2 = 69.123;

    printf("Ingrese un numero entero: ");
    scanf("%d",&numero1);
    printf("Ingrese un numero decimal: ");
    scanf("%f",&numero2);

    printf("Ingrese una letra: ");
    letra = getche();

    printf("\nEl numero entero es: %d y el numero flotante es: %.2f\n",numero1,numero2);

    resultado = numero1 + numero2;

    printf("\nLa suma de ambos numeros es: %.2f\n",resultado);
    printf("La letra es ingresada es: %c\n\n",letra);

    return 0;
}
