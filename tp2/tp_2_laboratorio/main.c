#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "toolbox.h"
#define MAX 1000



int main()
{
    sEmployee arrayEmployees[MAX];
    initEmployees(arrayEmployees, MAX);

    int opcion;
    int flagValidacion = 0;
    int auxiliarId;
    char auxiliarName[51];
    char auxiliarLastName[51];
    float auxiliarSalary;
    int auxiliarSector;
    int lugarLibre;


    do
    {
        opcion = menu();

        switch(opcion)
        {
        case 1:
            flagValidacion++;
            lugarLibre=buscarLibre(arrayEmployees, MAX);
            if (lugarLibre!=-1)
            {
                getStringLetras("Ingrese el nombre: ", auxiliarName);
                getStringLetras("Ingrese el apellido: ", auxiliarLastName);
                auxiliarSalary = getFloat("Ingrese el sueldo: ");
                auxiliarSector = getInt("Ingrese el sector: ");
            }
            else
            {
                printf("No hay mas espacio\n");
                system("pause");
                system("cls");
            }


            addEmployee(arrayEmployees, MAX, auxiliarId, auxiliarName, auxiliarLastName, auxiliarSalary, auxiliarSector);
            break;


        case 2:
            if(flagValidacion != 0)
            {
                modificarEmpleado(arrayEmployees, MAX);
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
                removeEmployee(arrayEmployees, MAX, auxiliarId);
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
                sortEmployees(arrayEmployees, MAX);
                printEmployees(arrayEmployees, MAX);
                promediosSalario(arrayEmployees, MAX);
                system("pause");
                system("cls");
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
        }
    }
    while(opcion != 5);


    return 0;
}


