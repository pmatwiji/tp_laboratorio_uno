#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

int menu()
{
    int opcion;
    fflush(stdin);
    printf("MENU:\n"
            "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
            "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
            "3. Alta de empleado\n"
            "4. Modificar datos de empleado\n"
            "5. Baja de empleado\n"
            "6. Listar empleados\n"
            "7. Ordenar empleados\n"
            "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
            "9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
            "10. Salir\n"
           "Ingrese una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    while(opcion < 0 || opcion > 10)
    {
        printf("Por favor, ingrese una opcion valida\n");
        system("pause");
        system("cls");
        fflush(stdin);
        printf("MENU:\n"
            "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
            "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
            "3. Alta de empleado\n"
            "4. Modificar datos de empleado\n"
            "5. Baja de empleado\n"
            "6. Listar empleados\n"
            "7. Ordenar empleados\n"
            "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
            "9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
            "10. Salir\n"
           "Ingrese una opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }

    return opcion;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
    Employee* empleado;
    empleado = malloc(sizeof(Employee));

    if(empleado!=NULL)
    {
        empleado->id=idStr;
        strcpy(empleado->nombre, nombreStr);
        strcpy(empleado->horasTrabajadas, horasTrabajadasStr);
    }

    return empleado;
}
