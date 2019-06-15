#include "Validations.h"

char validationChar(char character, char charA, char charB)
{
    while(character!=charA && character!=charB)
    {
        printf("Opcion incorrecta, reingrese %c/%c: ",charA,charB);
        fflush(stdin);
        scanf("%c",&character);
        character=toupper(character);
    }
    return character;
}


int validationNum (int num)
{
    int option=num;
    while(option<=0)
    {
        printf("Valor no valido, por favor reingrese: ");
        scanf("%d",&option);
    }
    return option;
}


int validationMenu(int option, int a, int b)
{
    while(option<a || option>b)
    {
        printf("Opcion inexistente, reingrese: ");
        scanf("%d",&option);
    }
    return option;
}



void validationString (char string[])
{
    while(strlen(string)<1 )
    {
        printf("No ingreso ningun nombre, por favor reingrese: ");
        fflush(stdin);
        gets(string);
    }
}
