#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"
#include "validaciones.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option;
    int test;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        option = menu();

        switch(option)
        {
        case 1:
            test = controller_loadFromText("data.csv",listaEmpleados);
            if(test==TRUE)
            {
                printf("Empleados cargados con exito.\n");
            }
            else
            {
                printf("Error, no se pudo cargar los datos.\n");
                system("pause");
                exit(EXIT_FAILURE);
            }
            system("pause");
            system("cls");
            break;
        case 2:
            controller_loadFromBinary("dataBinary.bin",listaEmpleados);
            system("pause");
            system("cls");
            break;
        case 3:
            controller_addEmployee(listaEmpleados);
            system("pause");
            system("cls");
            break;
        case 4:
            controller_editEmployee(listaEmpleados);
            system("pause");
            system("cls");
            break;
        case 5:
            controller_removeEmployee(listaEmpleados);
            system("pause");
            system("cls");
            break;
        case 6:
            controller_ListEmployee(listaEmpleados);
            system("pause");
            system("cls");
            break;
        case 7:
            if(ll_len(listaEmpleados)>1)
            {
               controller_sortEmployee(listaEmpleados);
            }
            else
            {
                printf("No hay datos suficientes para ordenar.\n");
            }

            system("pause");
            system("cls");
            break;
        case 8:
            test = controller_saveAsText("dataText.csv",listaEmpleados);
            if(test==TRUE)
            {
                printf("Datos guardados con exito.\n");
            }
            else
            {
                printf("Error, no se pudo guardar los datos.\n");
            }
            system("pause");
            system("cls");
            break;
        case 9:
            controller_saveAsBinary("dataBinary.bin",listaEmpleados);
            if(test==TRUE)
            {
                printf("Datos guardados con exito.\n");
            }
            else
            {
                printf("Error, no se pudo guardar los datos.\n");
            }
            system("pause");
            system("cls");
            break;
        case 10:
            printf("Gracias por utilizar el sistema.\n");
            ll_deleteLinkedList(listaEmpleados);
            break;
        }
    }
    while(option != 10);
    return 0;
}
