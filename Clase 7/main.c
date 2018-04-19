#include <stdio.h>
#include <stdlib.h>

#define TAM 1

float calcularPromedio(int,int);
void mostrarAlumnos(char[][20],int[],int[],int[],float[],int);

int main()
{
    int i;

    int legajo[TAM];
    char nombre[TAM][20];
    int nota1[TAM];
    int nota2[TAM];
    float promedio[TAM];

    for(i=0;i<TAM;i++)
    {
        printf("Ingrese nombre:");
        fflush(stdin);
        gets(nombre[i]);

        printf("Ingrese legajo:");
        scanf("%d",&legajo[i]);

        printf("Ingrese primer nota:");
        scanf("%d",&nota1[i]);

        printf("Ingrese segunda nota:");
        scanf("%d",&nota2[i]);

        promedio[i] = calcularPromedio(nota1[i],nota2[i]);

        system("cls");
    }

        mostrarAlumnos(nombre,legajo,nota1,nota2,promedio,TAM);

       /* printf("NOMBRE\t\tLEGAJO\t\tNOTA 1\t\tNOTA 2\t\tPROMEDIO\n\n");

        for(i=0;i<TAM;i++)
        {
            printf("%s\t\t%d\t\t%d\t\t%d\t\t%.2f\n",nombre[i],legajo[i],nota1[i],nota2[i],promedio[i]);
        }
        */


    return 0;
}

float calcularPromedio(int numero1, int numero2)
{
    float prom;

    prom = (float)(numero1 + numero2) / 2; //EL FLOAT INDICA CASTEO PARA PODER PASAR A DECIMAL LA SUMA Y QUE EL PROMEDIO NO DE ENTERO

    return prom;
}

void mostrarAlumnos(char nombre[][20],int legajo[],int nota1[],int nota2[],float promedio[],int cantidad)
{
    int i;

    for(i=0;i<cantidad;i++)
    {
        printf("%s\t\t%d\t\t%d\t\t%d\t\t%.2f\n",nombre[i],legajo[i],nota1[i],nota2[i],promedio[i]);
    }

}
