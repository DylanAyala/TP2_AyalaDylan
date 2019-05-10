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

int main()
{
    char name[100];
    char lastName[100];

    int end;
    int exit=0;
    int id = 1;
    int idOk;
    int index;
    int order=-1;
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

    eSector sectores[LENGSEC] = {  {1, "Comercial"},
        {2,"Soporte"},
        {3,"Factuacion"},
        {4, "Desarrollo"},
        {5, "Infrastructura"}
    };
    initEmployee(employee,LENG);

    do
    {
        switch(menu())
        {
        case 1:

            system("cls");
            printf("        Alta de empleado\n\n");


            index=findPlace(employee,LENG);
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

                mostrarSectores(sectores, LENGSEC);

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
                showEmployees(employee,LENG, sectores, LENGSEC);

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
                    end=modifyEmployee(employee,LENG,idOk, sectores, LENGSEC);
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
                deleteEmployee(employee,LENG,id, sectores, LENGSEC);
            }
            else
            {
                printf("\nNo se ingreso ningun empleado\n");
            }


            break;
        case 4:
            showOk = showEmployees(employee, LENG,sectores,LENGSEC);
            if(showOk == -1)
            {
                printf("\nNo hay empleados para mostrar\n\n");
            }
            break;
        case 5:
            if(entryEmployee)
            {
                order=menuOfSort();
                showOrdered(order,employee, LENG, sectores, LENGSEC);
            }
            else
            {
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

