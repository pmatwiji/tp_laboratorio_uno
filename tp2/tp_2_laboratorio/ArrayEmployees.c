#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployees.h"
#include "toolbox.h"
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define ILOGICO -1
#define LIBRE 1
#define OCUPADO 0


int initEmployees(sEmployee* arrayEmployees, int capacidad)
{
    int retorno = -1;
    if(arrayEmployees != NULL && capacidad!=0)
    {
        retorno = 0;
        for(int i=0; i<capacidad; i++)
        {
            arrayEmployees[i].isEmpty = LIBRE;
        }
    }
    return retorno;
}

int buscarLibre(sEmployee* arrayEmployees, int capacidad)
{
    int retorno = -1;
    int i;
    if(capacidad > 0 && arrayEmployees != NULL)
    {
        for(i=0; i<capacidad; i++)
        {
            if(arrayEmployees[i].isEmpty == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int nuevoID(sEmployee* arrayEmployees,int capacidad)
{
    int retorno = 0;
    int i;
    if(capacidad > 0 && arrayEmployees != NULL)
    {
        for(i=0; i<capacidad; i++)
        {
            if(arrayEmployees[i].isEmpty == OCUPADO)
            {
                retorno++;
            }
        }
    }
    return retorno+1;
}

int addEmployee(sEmployee* arrayEmployees, int capacidad, int auxiliarId, char auxiliarName[], char auxiliarLastName[], float auxiliarSalary, int auxiliarSector)
{

    int retorno = -1;
    int index;

    if(capacidad > 0 && arrayEmployees != NULL)
    {
        retorno = 0;
        index = buscarLibre(arrayEmployees,capacidad);
        if(index >= 0)
        {
            while(strlen(auxiliarName)>50)
            {
                printf("El nombre es demasiado largo, ingreselo nuevamente: ");
                fflush(stdin);
                gets(auxiliarName);
            }
            auxiliarName[0]=toupper(auxiliarName[0]);

            while(strlen(auxiliarLastName)>50)
            {
                printf("El apellido es demasiado largo, ingreselo nuevamente: ");
                fflush(stdin);
                gets(auxiliarLastName);
            }
            auxiliarLastName[0]=toupper(auxiliarLastName[0]);

            arrayEmployees[index].id = auxiliarId;
            strcpy(arrayEmployees[index].name, auxiliarName);
            strcpy(arrayEmployees[index].lastName, auxiliarLastName);
            arrayEmployees[index].salary = auxiliarSalary;
            arrayEmployees[index].sector = auxiliarSector;
            arrayEmployees[index].isEmpty = OCUPADO;

            printf("El usuario se registro correctamente. ID: %d\n", index);
            system("pause");
            system("cls");

        }
        else
        {
            printf("No hay mas espacio\n");
            system("pause");
            system("cls");

        }
    }
    return retorno;
}


int findEmployeeById(sEmployee* arrayEmployees, int capacidad, int id)
{
    int i;
    for(i=0; i<capacidad; i++)
    {
        if(arrayEmployees[i].id == id)
        {
            return i;
            break;
        }
    }
    return -1;
}

int removeEmployee(sEmployee* arrayEmployees, int capacidad, int id)
{


 return -1;
}
