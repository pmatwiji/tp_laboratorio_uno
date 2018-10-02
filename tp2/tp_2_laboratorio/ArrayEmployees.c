#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "arrayEmployees.h"
#include "toolbox.h"
#define MAX 1000


int initEmployees(sEmployee* arrayEmployees, int capacidad)
{
    int retorno = -1;
    if(arrayEmployees != NULL && capacidad!=0)
    {
        retorno = 0;
        for(int i=0; i<capacidad; i++)
        {
            arrayEmployees[i].isEmpty = 1;
        }
    }
    return retorno;
}

int menu()
{
    int opcion;
    fflush(stdin);
    printf("MENU:\n"
           "1. Alta empleado\n"
           "2. Modificar empleado\n"
           "3. Baja Empleado\n"
           "4. Informar\n"
           "5. Salir\n"
           "Ingrese una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    while(opcion < 0 || opcion > 5)
    {
        printf("Por favor, ingrese una opcion valida\n");
        system("pause");
        system("cls");
        fflush(stdin);
        printf("MENU:\n"
               "1. Alta empleado\n"
               "2. Modificar empleado\n"
               "3. Baja Empleado\n"
               "4. Informar\n"
               "5. Salir\n"
               "Ingrese una opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }

    return opcion;
}


int buscarLibre(sEmployee* arrayEmployees, int capacidad) //obtainfreeslot
{
    int retorno = -1;
    int i;
    if(capacidad > 0 && arrayEmployees != NULL)
    {
        for(i=0; i<capacidad; i++)
        {
            if(arrayEmployees[i].isEmpty == 1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

static int nuevoID()
{
    static int id=-1;

    id ++;

    return id;
}

int addEmployee(sEmployee* arrayEmployees, int capacidad, int auxiliarId, char auxiliarName[], char auxiliarLastName[], float auxiliarSalary, int auxiliarSector)
{

    int retorno = -1;
    int id;
    int index = buscarLibre(arrayEmployees,capacidad);
    int posicionEmployee = findEmployeeById(arrayEmployees, MAX, index);
    if(capacidad > 0 && arrayEmployees != NULL)
    {
        if(index != -1)
        {
            if(arrayEmployees[posicionEmployee].isEmpty==0)
            {
                id = nuevoID();
            }
            arrayEmployees[index].id=id;
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
            strcpy(arrayEmployees[index].name, auxiliarName);
            strcpy(arrayEmployees[index].lastName, auxiliarLastName);
            arrayEmployees[index].salary = auxiliarSalary;
            arrayEmployees[index].sector = auxiliarSector;
            arrayEmployees[index].isEmpty = OCUPADO;
            retorno = 0;

            printf("El usuario se registro correctamente.\n");
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
        if(arrayEmployees[i].id == id && arrayEmployees[i].isEmpty == 0)
        {
            return i;
            break;
        }
    }
    return -1;
}

int removeEmployee(sEmployee* arrayEmployees, int capacidad, int id)
{
    int retorno = -1;
    int auxiliarId;
    char opcion;

    printf("Ingrese el ID a buscar: \n");
    scanf("%d", &auxiliarId);
    int idEmployee=findEmployeeById(arrayEmployees, MAX, auxiliarId);
    if (idEmployee>=0)
    {
        printf("Confirma la baja? S/N\n");
        opcion=getChar("");
        switch(opcion)
        {
        case 's':
            arrayEmployees[idEmployee].isEmpty = 1;
            printf("Baja realizada con exito.\n");
            system("pause");
            system("cls");
            break;
        case 'n':
            printf("Se cancelo la baja.\n");
            system("pause");
            system("cls");
            break;
        default:
            printf("Ingrese una opcion valida.\n");
            break;
        }
    }
    else
    {
        printf ("ID vacio, intente nuevamente.\n");
        system ("pause");
        system("cls");
    }

    return retorno;
}

void modificarEmpleado(sEmployee* arrayEmployees, int capacidad)
{
    char auxiliarName[51];
    char auxiliarLastName[51];
    float auxiliarSalary;
    int auxiliarSector;
    char opcion;
    int auxiliarId;

    printf("Ingrese el ID a buscar: \n");
    scanf("%d", &auxiliarId);
    int idEmployee=findEmployeeById(arrayEmployees, MAX, auxiliarId);
    if (idEmployee>=0)
    {
        printf("ID encontrado, modifique los datos a continuacion: \n");

        printf("Ingrese el nombre: ");
        scanf("%s", auxiliarName);
        auxiliarName[0]=toupper(auxiliarName[0]);
        printf("Ingrese el apellido: ");
        scanf("%s", auxiliarLastName);
        auxiliarLastName[0]=toupper(auxiliarLastName[0]);
        printf("Ingrese el sueldo: ");
        scanf("%f", &auxiliarSalary);
        printf("Ingrese el sector: ");
        scanf("%d", &auxiliarSector);
        printf("Confirma la modificacion? S/N\n");
        opcion=getChar("");
        switch(opcion)
        {
        case 's':
            strcpy(arrayEmployees[idEmployee].name, auxiliarName);
            strcpy(arrayEmployees[idEmployee].lastName, auxiliarLastName);
            arrayEmployees[idEmployee].salary = auxiliarSalary;
            arrayEmployees[idEmployee].sector = auxiliarSector;
            printf("Modificacion realizada con exito.\n");
            system("pause");
            system("cls");
            break;
        case 'n':
            printf("Se cancelo la modificacion.\n");
            system("pause");
            system("cls");
            break;
        default:
            printf("Ingrese una opcion valida.\n");
            break;
        }
    }
    else
    {
        printf ("ID vacio, intente nuevamente.\n");
        system ("pause");
        system("cls");
    }
}

int sortEmployees(sEmployee* arrayEmployees, int cantidad)
{
    int retorno = -1;
    sEmployee aux;
    if(cantidad > 0 && arrayEmployees != NULL)
    {
        for(int i=0; i<cantidad - 1; i++)
        {
            for(int j=i+1; j<cantidad; j++)
            {
                if(strcmp(arrayEmployees[j].lastName, arrayEmployees[i].lastName) < 0)
                {
                    aux = arrayEmployees[i];
                    arrayEmployees[i] = arrayEmployees[j];
                    arrayEmployees[j] = aux;
                }
                else if(strcmp(arrayEmployees[j].lastName, arrayEmployees[i].lastName) == 0 && arrayEmployees[j].sector < arrayEmployees[i].sector)
                {
                    aux = arrayEmployees[i];
                    arrayEmployees[i] = arrayEmployees[j];
                    arrayEmployees[j] = aux;
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}

int printEmployees(sEmployee* arrayEmployees, int cantidad)
{
    int retorno = -1;
    printf("\n%5s %30s %30s %8s %3s \n", "ID","NOMBRE","APELLIDO","SUELDO","SECTOR");
    for(int i = 0; i < cantidad; i++)
    {
        if(arrayEmployees[i].isEmpty == 0)
        {
            printf("%5d %30s %30s %8.2f %3d\n", arrayEmployees[i].id, arrayEmployees[i].name, arrayEmployees[i].lastName, arrayEmployees[i].salary, arrayEmployees[i].sector);
        }
    }
    retorno = 0;
    return retorno;
}

void promediosSalario(sEmployee arrayEmployees[], int capacidad)
{
    float promedio = 0;
    float total = 0;
    int contadorEmployees = 0;
    int salarioMayor = 0;

    for(int i=0; i<capacidad; i++)
    {
        if(arrayEmployees[i].isEmpty == 0)
        {
            contadorEmployees++;
            total= total + arrayEmployees[i].salary;
        }
    }
    promedio = total/contadorEmployees;

    for(int i=0; i<capacidad; i++)
    {
        if(arrayEmployees[i].isEmpty == 0)
        {
            if(arrayEmployees[i].salary > promedio)
            {
                salarioMayor++;
            }
        }
    }

    printf("Total Salarios: %.2f\n", total);
    printf("Promedio Salarios: %.2f\n", promedio);
    printf("Cantidad de Empleados que superan el promedio: %d\n", salarioMayor);
}
