
#include <stdio.h>
#include "funciones.h"


int ingresarOpcion (void) //funcion para ingresar opcion
{
    int opcion;
    printf("Ingrese una opcion: \n");
    scanf("%d", &opcion);
    return opcion;
}

void pedirNumero (float* numero) //funcion para pedir los numeros
{
    printf("Ingrese un numero: \n");
    fflush(stdin);
    scanf("%f", numero);
}

float sumar(float datoUno, float datoDos) //funcion para sumar
{
    float suma;
    suma=datoUno+datoDos;
    return suma;
}
float restar(float datoUno, float datoDos) //funcion para restar
{
    float resta;
    resta=datoUno-datoDos;
    return resta;
}
float multiplicar(float datoUno, float datoDos) //funcion para multiplicar
{
    float multiplicacion;
    multiplicacion=datoUno*datoDos;
    return multiplicacion;
}
float dividir(float datoUno, float datoDos) //funcion para dividir
{
    float division;
    division=datoUno/datoDos;
    return division;
}

long int factorial (long int numero) //funcion para sacar el factorial de un numero
{
    int i;
    int resultado = 1;

    for (i=numero; i >= 1; i--)
    {
        resultado = resultado * i;
    }
    return resultado;
}
