#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void funcionBienvenido(char* nombre);
void funcionDespedida(char* nombre);
void fdelagada(void(*punteroFuncion)(char* eldato),char* nombre);

void funcionDespedidaSin();
void funcionDespedidaMas(char*,char*);

int main()
{
    fdelagada(funcionBienvenido,"natalia natalia");
    getche();
    fdelagada(funcionDespedida,"natalia natalia");
    getche();

    return 0;
}

void funcionBienvenido(char* nombre)
{
    printf("Bienvenida %s, a la empresa.",nombre);
}

void funcionDespedida(char* nombre)
{
    printf("Vos %s, estas despedida --------->.",nombre);
}

void fdelagada(void(*punteroFuncion)(char* eldato),char* nombre)
{
    punteroFuncion(nombre);
}
