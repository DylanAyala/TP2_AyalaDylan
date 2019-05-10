#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int validationName(char name[], int len)
{
    while(strlen(name)>len)
    {
        printf("El nombre es demasiado largo");
        fflush(stdin);
        scanf("%s",name);
    }
    return 0;
}

float validationSalary (float number)
{
    while(number<0)
    {
        printf("El valor es negativo, no se puede ingresar. Reingresar: ");
        scanf("%f",&number);
    }
    return number;
}

int validationSector(int sector)
{
    while(sector<1 || sector>5)
    {
        printf("El codigo del sector no existe. Reingresar: ");
        scanf("%d",&sector);
    }

    return sector;
}

char validationChar(char character)
{
    while(character!='s' && character!='n')
    {
        printf("Opcion incorrecta, reingrese s/n: ");
        fflush(stdin);
        scanf("%c",&character);
        character=tolower(character);
    }
    return character;
}

int validationId (int id)
{
    while(id<1 || id>1100)
    {
        printf("Id incorrecta, reingrese valor entre 1 y 1100: ");
        scanf("%d",&id);
    }
    return id;
}
