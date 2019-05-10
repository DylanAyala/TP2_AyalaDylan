#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "validation.h"
#include "funcionEmployee.h"
#define LENG 10
#define LENGSEC 5
#define NAME 51

int initEmployee(eEmployee employee[], int len)
{
    for(int i=0; i<len; i++)
    {
        employee[i].isEmpy=0;
    }
    return 0;
}


int menu (void)
{
    int option;
    system("cls");
    printf("**********Menu de opciones**********\n\n");
    printf("1-Alta empleado\n");
    printf("2-Modificar empleado\n");
    printf("3-Baja empleado\n");
    printf("4-Mostar empleados\n");
    printf("5-Informar\n");
    printf("0-Salir");
    printf("\n\nIngrese opcion: ");
    fflush(stdin);
    scanf("%d",&option);
    return option;
}

int findPlace(eEmployee list[], int tam)
{

    int index=-1;

    for(int i=0; i<tam; i++)
    {
        if(list[i].isEmpy==0)
        {
            index=i;
            break;
        }
    }
    return index;
}


int findEmployeeById(eEmployee list[], int len, int id)
{
    int index = -1;

    for(int i=0; i < len; i++)
    {
        if(list[i].isEmpy == 1 && list[i].id == id)
        {
            index = i;
            break;
        }
    }

    return index;
}



int addEmployee(eEmployee list[], int len, int id, int index, char name[],char lastName[],float salary,int sector)
{
    char confirm;

    printf("\n\nConfirma el ingreso del empleado? s/n: ");
    fflush(stdin);
    confirm=getche();
    confirm=validationChar(confirm);

    if(confirm=='s')
    {
        list[index].isEmpy=1;
        list[index].id=id;
        strcpy(list[index].name,name);
        strcpy(list[index].lastName,lastName);
        list[index].salary=salary;
        list[index].sector=sector;
        return 0;
    }
    else
    {
        printf("Canselado\n");
        return -1;
    }
}

int modifyEmployee (eEmployee employee[], int len, int file, eSector sec[], int lengSec)
{
    char confirm='n';
    char entry='n';
    char name[100];
    char lastName[100];

    int option;
    int sector;
    int indexSe;
    float salary;
    indexSe = indexSec(sec,LENGSEC,employee[file]);
    printEmployee(employee[file], sec[indexSe]);
    printf("\nConfirma la modificacion del empleado? s/n: ");
    fflush(stdin);
    entry=getche();
    entry=tolower(entry);
    entry=validationChar(entry);

    if(entry=='s')
    {
        do
        {
            printf("\n1-Modificar nombre");
            printf("\n2-Modificar apellido");
            printf("\n3-Modificar salario");
            printf("\n4-Modificar sector");
            printf("\n0-Finalizar");
            printf("\n\nIngrese opcion: ");
            fflush(stdin);
            scanf("%d",&option);
            switch(option)
            {
            case 1:
                printf("\nIngrese nuevo nombre: ");
                fflush(stdin);
                scanf("%s",name);
                strlwr(name);
                name[0]=toupper(name[0]);
                validationName(name,51);
                strcpy(employee[file].name,name);

                break;
            case 2:
                printf("\nInrese nuevo apellido del empleado: ");
                fflush(stdin);
                scanf("%s",lastName);
                strlwr(lastName);
                lastName[0]=toupper(lastName[0]);
                validationName(lastName,51);
                strcpy(employee[file].lastName,lastName);
                break;
            case 3:
                printf("\nModifique el salario: ");
                scanf("%f",&salary);
                salary=validationSalary(salary);
                employee[file].salary=salary;
                break;
            case 4:
                printf("\nModifique el sector del trabajo: ");
                mostrarSectores(sec, lengSec);
                scanf("%d",&sector);
                validationSector(sector);
                employee[file].sector=sector;
                break;
            case 0:
                printf("\nVolver al menu anterior?(s/n)");
                fflush(stdin);
                confirm=getche();
                confirm=tolower(confirm);
                confirm=validationChar(confirm);
                validationChar(confirm);
                break;
            }
        }
        while(confirm=='n');
        return 1;
    }

    else
    {
        return -1;
    }
}

int deleteEmployee(eEmployee list[], int len, int id, eSector sec[], int lengSec)
{
    int index;
    int indexSe;
    char confirm;

    index=findEmployeeById(list,len,id);
    if(index==-1)
    {
        printf("El id no existe\n");
        system("pause");
    }
    else
    {
        indexSe = indexSec(sec, LENGSEC, list[index]);
        printEmployee(list[index], sec[indexSe]);
        printf("\nConfirma la baja del empleado? s/n");
        fflush(stdin);
        confirm=getche();
        confirm=tolower(confirm);
        validationChar(confirm);

        if (confirm=='s')
        {
            list[index].isEmpy=0;
            printf("\nEl empleado se dio de baja de manera correcta\n");
        }
        else
        {
            printf("\n La baja se canselo\n");
        }
    }
    return 0;
}

int menuOfSort (void)
{
    int option;
    system("cls");
    printf("**********Menu de opciones**********\n\n");
    printf("1-Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n");
    printf("2-Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n");
    printf("0-Volver al menu anterior");
    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%d",&option);
    return option;
}


int showEmployees(eEmployee emp[], int leng, eSector sec[], int lengSec)
{
    int index = -1;
    for(int i=0; i<leng; i++)
    {
        if (emp[i].isEmpy == 1)
        {
            for(int j=0; j<lengSec; j++)
            {
                if(sec[j].id==emp[i].sector)
                {
                    printEmployee(emp[i], sec[j]);

                }
            }
            index = 1;
        }

    }

    return index;
}

int printEmployee (eEmployee employee, eSector sec)
{
    printf("%d  %10s        %10s    %.2f    %s \n",employee.id,employee.name,employee.lastName,employee.salary,sec.name);
    return 0;
}

int showOrdered(int choice, eEmployee emp[], int lenEmp, eSector sec[], int lengSec)
{
    eEmployee aux;
    int indexSe;
    int cantidadMasPromedio = 0;
    int count=0;
    float salarioTotal = 0;
    float promedioSalario;

    switch(choice)
    {
    case 1:

        for(int i=0; i<lenEmp; i++)
        {
            for(int j=i+1; j<lenEmp; j++)
            {
                if (emp[i].sector>emp[j].sector)
                {
                    aux=emp[i];
                    emp[i]=emp[j];
                    emp[j]=aux;
                }

            }
        }

        for(int i=0; i<lenEmp; i++)
        {
            for(int j=i+1; j<lenEmp; j++)
            {
                if (strcmp(emp[i].lastName,emp[j].lastName)>0 && emp[i].sector == emp[j].sector)
                {
                    aux=emp[i];
                    emp[i]=emp[j];
                    emp[j]=aux;
                }

            }
        }
        system("cls");

        printf("Legajo    Nombre   Apellido     Salario   Sector \n");
        printf("------    ------   --------    ---------  ------ \n");
        for(int i=0; i<lenEmp; i++)
        {
            if(emp[i].isEmpy==1)
            {
                indexSe = indexSec(sec, LENGSEC, emp[i]);
                printEmployee(emp[i], sec[indexSe]);
                printf("\n");
            }
        }


        break;
    case 2:
        for(int i=0; i<lenEmp; i++)
        {
            if(emp[i].isEmpy==1)
            {
                salarioTotal+= emp[i].salary;
                count++;
            }
        }
        promedioSalario = salarioTotal / count;

        for(int i=0; i<lenEmp; i++)
        {
            if(emp[i].isEmpy==1 && emp[i].salary> promedioSalario)
            {
                cantidadMasPromedio++;
            }

        }
        printf("El salario total de todo los empleados es: %.2f\n", salarioTotal);
        printf("Promedio de los salarios: %.2f\n", promedioSalario);
        printf("Cantidad de empleados que superan el promedio: %d\n", cantidadMasPromedio);

        break;

    default:
        printf("Opcion no valida");

    }
    return 0;
}


void mostrarSectores(eSector sec[], int leng)
{

    for (int i=0; i<leng; i++)
    {
        printSector(sec[i]);
    }
}

void printSector(eSector sec)
{
    printf("%d  %s\n", sec.id, sec.name);
}

int indexSec(eSector sec[], int lengSec, eEmployee emp)
{
    int index=-1;

    for(int i=0; i<lengSec; i++)
    {
        if(emp.sector==sec[i].id)
        {
            index= i;
        }
    }

    return index;
}
