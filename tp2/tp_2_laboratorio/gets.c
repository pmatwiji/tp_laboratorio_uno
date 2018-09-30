#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "gets.h"
#include <conio.h>
#include <string.h>


int getInt (char mensaje[])
{
    int auxiliar;
    printf("%s", mensaje);
    scanf("%d", &auxiliar);
    return auxiliar;
}
