#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int opcion;
    float datoUno;
    float datoDos;
    float suma;
    float resta;
    float multiplicacion;
    float division;
    //int resultadoFactorial;
    int marcadorUno=0;
    int marcadorDos=0;


    do
    {
        printf("1. Ingrese el primer operando\n");
        printf("2. Ingrese el segundo operando\n");
        printf("3. Calcular todas las operaciones\n");
        printf("4. Informar resultados\n");
        printf("5. Salir\n");

        opcion = ingresarOpcion();

        switch (opcion)
        {
        case 1:
            marcadorUno=1;
            pedirNumero(&datoUno);
            break;
        case 2:
            marcadorDos=1;
            pedirNumero(&datoDos);
            break;
        case 3:
            if (marcadorUno == 0 || marcadorDos == 0)
            {
                printf("Error. Ingrese ambos numeros para continuar\n");
            }
            else
            {
                printf("Se estan realizando las operaciones\n");
                suma=sumar(datoUno, datoDos);
                resta=restar(datoUno, datoDos);
                multiplicacion=multiplicar(datoUno, datoDos);
                division=dividir(datoUno, datoDos);

            }
            break;
        case 4:
            if (marcadorUno == 0 || marcadorDos == 0)
            {
                printf("Error. Ingrese ambos numeros para continuar\n");
            }
            else
            {
                printf("El primer operando es: %.2f\n", datoUno);
                printf("El segundo operando es: %.2f\n", datoDos);
                printf("El resultado de la suma es: %.2f\n", suma);
                printf("El resultado de la resta es: %.2f\n", resta);
                printf("El resultado de la multiplicacion es: %.2f\n", multiplicacion);
                if (datoUno == 0 || datoDos == 0)
                {
                    printf("El numero 0 no es divisible\n");
                }
                else
                {
                    printf("El resultado de la division es: %.2f\n", division);
                }
            }
            //printf("El factorial de %f es %lld",datoUno, resultadoFactorial);
            break;
        case 5:
            opcion = 5;
            break;
        default:
            printf("Ingrese un numero valido: \n");
            break;
        }

        system("pause");
        system("cls");
    }
    while (opcion != 5);
    return 0;
}


