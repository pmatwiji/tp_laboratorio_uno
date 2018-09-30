#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "toolbox.h"
#include "gets.h"
#define LARGO 5


int main()
{
    sEmployee arrayEmployees[LARGO];
    initEmployees(arrayEmployees, LARGO);

    int opcion;
    int flagValidacion = 0;
    int auxiliarId;
    int modificacionId;
    char auxiliarName[51];
    char auxiliarLastName[51];
    float auxiliarSalary;
    int auxiliarSector;
    int foundIndex;

    do
    {
        opcion = getInt("MENU:\n"
                        "1. Alta empleado\n"
                        "2. Modificar empleado\n"
                        "3. Baja Empleado\n"
                        "4. Informar\n"
                        "5. Salir\n"
                        "Ingrese una opcion: ");
        fflush(stdin);

        switch(opcion)
        {
        case 1:
            flagValidacion++;
            auxiliarId = nuevoID(arrayEmployees, LARGO);
            getStringLetras("Ingrese el nombre: ", auxiliarName);
            getStringLetras("Ingrese el apellido: ", auxiliarLastName);
            auxiliarSalary = getFloat("Ingrese el sueldo: ");
            auxiliarSector = getInt("Ingrese el sector: ");
            addEmployee(arrayEmployees, LARGO, auxiliarId, auxiliarName, auxiliarLastName, auxiliarSalary, auxiliarSector);
            break;

        case 2:
            if(flagValidacion != 0)
            {
                printf("Ingrese el ID a buscar: ");
                scanf("%d", &modificacionId);
                foundIndex = findEmployeeById(arrayEmployees, LARGO, modificacionId);
                if (foundIndex == -1)
                {
                    printf("No se encuentra ese ID.\n");
                    system("pause");
                    system("cls");
                    break;
                }
                printf("ID encontrado, modifique los datos a continuacion: \n");
                getStringLetras("Ingrese el nombre: ", auxiliarName);
                getStringLetras("Ingrese el apellido: ", auxiliarLastName);
                auxiliarSalary = getFloat("Ingrese el sueldo: ");
                auxiliarSector = getInt("Ingrese el sector: ");
                printf("Confirma la modificacion? S/N\n");
                opcion=getChar("");
                switch(opcion)
                {
                case 's':
                    strcpy(arrayEmployees[foundIndex].name, auxiliarName);
                    strcpy(arrayEmployees[foundIndex].lastName, auxiliarLastName);
                    arrayEmployees[foundIndex].salary = auxiliarSalary;
                    arrayEmployees[foundIndex].sector = auxiliarSector;
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
                break;
            }
            else
            {
                printf("No se ingreso ningun dato\n");
                system("pause");
                system("cls");
                break;
            }

        case 3:
            if(flagValidacion != 0)
            {
                printf("Ingrese el ID a buscar: ");
                scanf("%d", &modificacionId);
                foundIndex = findEmployeeById(arrayEmployees, LARGO, modificacionId);
                if (foundIndex == -1)
                {
                    printf("No se encuentra ese ID.\n");
                    system("pause");
                    system("cls");
                    break;
                }
                printf("ID encontrado. \n");
                printf("Confirma la modificacion? S/N\n");
                opcion=getChar("");
                switch(opcion)
                {
                case 's':

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
                break;
            }
            else
            {
                printf("No se ingreso ningun dato\n");
                system("pause");
                system("cls");
                break;
            }

        case 4:
            if(flagValidacion != 0)
            {
//              mostrarEmpleados(arrayEmployee, 2);
                break;
            }
            else
            {
                printf("No se ingreso ningun dato\n");
                system("pause");
                system("cls");
                break;
            }
        case 5:
            printf("\nGracias por utilizar nuestro sistema\n\n");
            break;

        default:

            printf("Por favor, ingrese una opcion valida\n");
            system("pause");
            system("cls");
        }
    }
    while(opcion != 5);


    return 0;
}


