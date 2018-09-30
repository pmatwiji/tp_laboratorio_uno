#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "toolbox.h"
#include "ArrayEmployees.h"


float pedirNumero()
{
    float auxiliar;
    printf("Ingrese un numero: ");
    scanf("%f", &auxiliar);
    return auxiliar;
}

float calcularAreaCirculo (float radio)
{
    float resultado;
    resultado = 3.14 * radio * radio;
    return resultado;
}

int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s", mensaje);
    scanf("%d", &auxiliar);
    return auxiliar;
}
float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s", mensaje);
    scanf("%f", &auxiliar);
    return auxiliar;
}
char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &auxiliar);
    return auxiliar;
}

int esNumerico(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}
int esTelefono(char str[]);
int esAlfaNumerico(char str[])
{
    int i;
    {
        while(str[i] != '\0')
        {
            if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            {
                return 0;
            }
            i++;
        }
        return 1;
    }
}
int esSoloLetras(char str[])

{
    int i;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

void getString(char mensaje[], char input[])
{
    printf("%s",mensaje);
    scanf("%s", input);
}
int getStringLetras(char mensaje[], char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
int getStringNumeros(char mensaje[], char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

//void inicializarArray(Persona arrayPersonas[],int cantidad, int valorIlogico)
//{
//    int i;
//    for(i=0; i<cantidad; i++)
//    {
//        arrayPersonas[i].legajo = valorIlogico;
//    }
//}
//
//int buscarPrimerLugarLibre (Persona arrayPersonas[],  int cantidad, int valorIlogico)
//{
//    int i;
//    for(i=0; i<cantidad; i++)
//    {
//        if(arrayPersonas[i].legajo == valorIlogico)
//        {
//            return i;
//        }
//    }
//    return -1;
//}
