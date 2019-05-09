#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "validation.h"

#define LENG 10
#define NAME 51


typedef struct
{
    int id;
    char name[NAME];
    char lastName[NAME];
    float salary;
    int sector;
    int isEmpy;

} eEmployee;

int addEmployee(eEmployee list[], int len, int id, int index, char name[],char lastName[],float salary,int sector);
int initEmployee(eEmployee employee[], int sizeEmp);
int findEmployeeById(eEmployee list[], int len, int id);
int menu (void);
int menuOfSort (void);
int modifyEmployee (eEmployee employee[], int len,int file);
int printEmployee (eEmployee employee);
int deleteEmployee(eEmployee list[], int len, int id);
int findPlace(eEmployee list[], int tam, int id);
int showEmployees(eEmployee emp[], int leng);
int showOrdered(int choice, eEmployee emp[], int lenEmp);

int main()
{
    char name[100];
    char lastName[100];

    int end;
    int exit=0;
    int id = 1;
    int idOk;
    int index;
    int order;
    int sector;
    int showOk;
    int entryEmployee = 0;

    float salary;


    eEmployee employee[LENG]/*=
    {
        {1001, "david", "bruches",15000 ,1001, 1},
        {1002, "laura", "kerekes",20000 ,1002, 1},
        {1003, "Bella", "Adda"   ,40000 ,1002, 1},
    }*/;

    initEmployee(employee,LENG);

    do
    {
        switch(menu())
        {
        case 1:

            system("cls");
            printf("        Alta de empleado\n\n");


            index=findPlace(employee,LENG,id);
            if(index == -1)
            {
                printf("\nNo hay espacios disponibles\n");
                system("pause");
                break;
            }
            else
            {
                printf("Ingrese nombre del empleado: ");
                fflush(stdin);
                scanf("%s",name);
                validationName(name,NAME);
                strlwr(name);
                name[0]=toupper(name[0]);
                strcpy(employee[index].name,name);

                printf("Ingrese apellido del empleado: ");
                fflush(stdin);
                scanf("%s",lastName);
                validationName(lastName,NAME);
                strlwr(lastName);
                lastName[0]=toupper(lastName[0]);
                strcpy(employee[index].lastName,lastName);

                printf("Ingrese el salario: ");
                scanf("%f",&salary);
                salary=validationSalary(salary);
                employee[index].salary=salary;

                printf("Ingrese el sector del trabajo: ");
                scanf("%d",&sector);
                sector=validationSector(sector);
                employee[index].sector=sector;

                idOk=addEmployee(employee,LENG,id,index,name,lastName,salary,sector);

                if(idOk==0)
                {
                    printf("\nEl empleado fue cargado correctamente\n");
                    id++;
                    entryEmployee = 1;
                }

                else
                {
                    printf("\nEl empleado no fue cargado\n");
                }


                break;
            }
        case 2:

            if (entryEmployee == 1)
            {
                system("cls");
                printf("---Modificar empleado---\n\n");
                printf("Ingrese id: ");
                scanf("%d",&id);
                idOk=findEmployeeById(employee,LENG,id);
                if(idOk==-1)
                {
                    printf("No existe\n");
                    system("pause");
                    break;
                }
                else
                {
                    end=modifyEmployee(employee,LENG,idOk);
                    if(end==-1)
                    {
                        printf("\nModificacion cancelada\n");
                        system("pause");
                    }
                    else
                    {
                        printf("\nLa modificacion fue realizada correctamente\n");
                    }
                }
            }
            else
            {
                printf("\nNo se ingresaron Empleados enteriormente\n");
            }

            break;

        case 3:
            if (entryEmployee)
            {
                system("cls");
                printf("\nIngrese id: ");
                scanf("%d",&id);
                id=validationId(id);
                deleteEmployee(employee,LENG,id);
            }
            else
            {
                printf("\nNo se ingreso ningun empleado\n");
            }


            break;
        case 4:
            showOk = showEmployees(employee, LENG);
            if(showOk == -1)
            {
                printf("\nNo hay empleados para mostrar\n\n");
            }
            break;
        case 5:
            if(entryEmployee){
                order=menuOfSort();
            }else{
                printf("\nNo se ingreso ningun empleado anteriormente\n\n");
            }

            break;

        case 0:
            exit=1;
            break;
        default:
            printf("Esa opcion no existe, reingrese ");
            break;
        }
        system("pause");
    }
    while(exit==0);
}


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

int findPlace(eEmployee list[], int tam, int id)
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

int modifyEmployee (eEmployee employee[], int len, int file)
{
    char confirm='n';
    char entry='n';
    char name[100];
    char lastName[100];

    int option;
    int sector;

    float salary;

    printEmployee(employee[file]);
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

int deleteEmployee(eEmployee list[], int len, int id)
{
    int index;
    char confirm;

    index=findEmployeeById(list,len,id);
    if(index==-1)
    {
        printf("El id no existe\n");
        system("pause");
    }
    else
    {
        printEmployee(list[index]);
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
    printf("2-Total y promedio de los salarios, y cuántos empleados superan el salario promedio.");
    printf("0-Volver al menu anterior");
    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%d",&option);
    return option;
}


int showEmployees(eEmployee emp[], int leng)
{
    int index = -1;
    for(int i=0; i<leng; i++)
    {
        if (emp[i].isEmpy == 1)
        {
            printEmployee(emp[i]);
            index = 1;
        }

    }

    return index;
}

int printEmployee (eEmployee employee)
{
    printf("%d  %10s        %10s    %.2f    %d \n",employee.id,employee.name,employee.lastName,employee.salary,employee.sector);
    return 0;
}

int showOrdered(int choice, eEmployee emp[], int lenEmp)
{
    switch(choice){
    case 1:
        for(int i=0;i<lenEmp;i++){

        }

        break;

    }
}
