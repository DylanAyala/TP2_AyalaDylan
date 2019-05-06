#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "validation.h"

#define LENGTHY 10
#define LONGNAME 51


typedef struct
{
    int id;
    char name[LONGNAME];
    char lastName[LONGNAME];
    float salary;
    int sector;
    int isEmpy;

}Employee;

int addEmployee(Employee list[], int len, int id, int index, char name[],char lastName[],float salary,int sector);
int initEmployee(Employee employee[], int sizeEmp);
int findEmployeeById(Employee list[], int len, int id);
int menu (void);
int menuOfSort (void);
int modifyEmployee (Employee employee[], int len,int file);
int printEmployee (Employee employee);
int removeEmployee(Employee list[], int len, int id);
int searchFree(Employee list[], int len, int id);

int main()
{
    char name[100];
    char lastName[100];

    int end;
    int exit=0;
    int id;
    int idOk;
    int index;
    int order;
    int sector;

    float salary;


    Employee employee[LENGTHY]/*=
    {
        {1001, "david", "bruches",15000 ,1001, 1},
        {1002, "laura", "kerekes",20000 ,1002, 1},
        {1003, "Bella", "Adda"   ,40000 ,1002, 1},
    }*/;

    initEmployee(employee,LENGTHY);

    do
    {
        switch(menu())
        {
        case 1:

            system("cls");
            printf("        Alta de empleado\n\n");


            index=searchFree(employee,LENGTHY,id);
            if(index == -1)
            {
                printf("\nNo hay espacios disponibles\n");
                system("pause");
                break;
            }
            else
            {
                printf("Ingrese id del empleado: ");
                scanf("%d",&id);
                id=validationId(id);
                idOk=findEmployeeById(employee,LENGTHY,id);

                if (idOk==-1)
                {
                    printf("Ingrese nombre del empleado: ");
                    fflush(stdin);
                    scanf("%s",name);
                    validationString(name,LONGNAME);
                    strlwr(name);
                    name[0]=toupper(name[0]);
                    strcpy(employee[index].name,name);

                    printf("Ingrese apellido del empleado: ");
                    fflush(stdin);
                    scanf("%s",lastName);
                    validationString(lastName,LONGNAME);
                    strlwr(lastName);
                    lastName[0]=toupper(lastName[0]);
                    strcpy(employee[index].lastName,lastName);

                    printf("Ingrese el salario: ");
                    scanf("%f",&salary);
                    salary=validationPositive(salary);
                    employee[index].salary=salary;

                    printf("Ingrese el sector del trabajo: ");
                    scanf("%d",&sector);
                    sector=validationSector(sector);
                    employee[index].sector=sector;

                    idOk=addEmployee(employee,LENGTHY,id,index,name,lastName,salary,sector);
                }
                else
                    printf("El legajo %d ya existe\n",id);

                if(idOk==0)
                    printf("\nEl empleado fue cargado correctamente\n");
                else
                    printf("\nEl empleado no fue cargado\n");

                system("pause");
                break;
            }
        case 2:
            system("cls");
            printf("---Modificar empleado---\n\n");
            printf("Ingrese id: ");
            scanf("%d",&id);
            id=validationId(id);
            idOk=findEmployeeById(employee,LENGTHY,id);

            if(idOk==-1)
            {
                printf("No existe\n");
                system("pause");
                break;
            }
            else
            {
                end=modifyEmployee(employee,LENGTHY,idOk);
                if(end==-1)
                    {
                    printf("\nModificacion cancelada\n");
                    system("pause");
                    }
                else
                    {
                    printf("\nLa modificacion fue realizada correctamente\n");
                    system("pause");
                    }
            }
            break;

        case 3:
            system("cls");
            printf("\nIngrese legajo: ");
            scanf("%d",&id);
            id=validationId(id);
            removeEmployee(employee,LENGTHY,id);

            break;
        case 4:
            order=menuOfSort();
            break;
        case 0:
            exit=1;
            break;
        default:
            printf("Esa opcion no existe, reingrese ");
            break;
        }
    }while(exit==0);
}


int initEmployee(Employee employee[], int len)
{
    for(int i=0;i<len;i++)
    {
        employee[i].isEmpy=1;
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
    printf("4-Informar\n");
    printf("0-Salir");
    printf("\n\nIngrese opcion: ");
    fflush(stdin);
    scanf("%d",&option);
    return option;
}

int searchFree(Employee list[], int longEmp, int id)
{

    int index=-1;

    for(int i=0;i<longEmp;i++)
    {
        if(list[i].isEmpy==1)
        {
            index=i;
            break;
        }
    }
    return index;
}


int findEmployeeById(Employee list[], int len, int id)
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



int addEmployee(Employee list[], int len, int id, int index, char name[],char lastName[],float salary,int sector)
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

int modifyEmployee (Employee employee[], int len, int file)
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
                                validationString(name,51);
                                strcpy(employee[file].name,name);

                                break;
                            case 2:
                                printf("\nInrese nuevo apellido del empleado: ");
                                fflush(stdin);
                                scanf("%s",lastName);
                                strlwr(lastName);
                                lastName[0]=toupper(lastName[0]);
                                validationString(lastName,51);
                                strcpy(employee[file].lastName,lastName);
                                break;
                            case 3:
                                printf("\nModifique el salario: ");
                                scanf("%f",&salary);
                                salary=validationPositive(salary);
                                employee[file].salary=salary;
                                break;
                            case 4:
                                printf("\nModifique el sector del trabajo: ");
                                scanf("%d",&sector);
                                validationSector(sector);
                                employee[file].sector=sector;
                                break;
                            case 0:
                                printf("\nVolver al menu anterior?");
                                fflush(stdin);
                                confirm=getche();
                                confirm=tolower(confirm);
                                confirm=validationChar(confirm);
                                validationChar(confirm);
                                break;
                        }
            }while(confirm=='n');
            return 1;
    }

    else
    {
        return -1;
    }
}


int printEmployee (Employee employee)
{
    printf("%d  %10s        %10s    %.2f    %d",employee.id,employee.name,employee.lastName,employee.salary,employee.sector);
    return 0;
}

int removeEmployee(Employee list[], int len, int id)
{
    int index;
    char confirm;

    index=findEmployeeById(list,len,id);
    if(index==-1)
    {
        printf("El legajo no existe\n");
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
                system("pause");
            }
            else
            {
                printf("\n La baja se canselo\n");
                system("pause");
            }
    }
    return 0;
}

int menuOfSort (void)
{
    int option;
    system("cls");
    printf("**********Menu de opciones**********\n\n");
    printf("1-Mostrar empleados por apellidos A-Z\n");
    printf("2-Mostrar empleados por apellidos Z-A\n");
    printf("3-Mostrar por sector Z-A\n");
    printf("0-Volver al menu anterior");
    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%d",&option);
    return option;
}
