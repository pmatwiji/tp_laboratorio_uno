
#include <stdio.h>
#include "funciones.h"


int ingresarOpcion (void) //funcion para ingresar opcion
{
    int opcion;
    printf("Ingrese un numero: \n");
    scanf("%d", &opcion);
    return opcion;
}

void pedirNumero (float* numero)
{
    printf("Ingrese un numero: \n");
    fflush(stdin);
    scanf("%f", numero);
}

float sumar(float datoUno, float datoDos)
{
    float suma;
    suma=datoUno+datoDos;
    return suma;
}
float restar(float datoUno, float datoDos)
{
    float resta;
    resta=datoUno-datoDos;
    return resta;
}
float multiplicar(float datoUno, float datoDos)
{
    float multiplicacion;
    multiplicacion=datoUno*datoDos;
    return multiplicacion;
}
float dividir(float datoUno, float datoDos)
{
    float division;
    division=datoUno/datoDos;
    return division;
}

/*int factorial (int datoUno, int datoDos)
{
    long long int datoUno;
    int i;
    int resultado = 1;

    for (i=numero, i >= 1, i--)
    {
        resultado = resultado * i;
    }
    return resultadoFactorial;
}*/
