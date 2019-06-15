#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "Employee.h"
#include "Menues.h"



int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int itsOk=-1;
    FILE* pFile;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {

        pFile= fopen(path,"r");
        if(pFile==NULL)
        {
            itsOk=0;
        }
        else
        {
            itsOk=parser_EmployeeFromText(pFile,pArrayListEmployee);
        }

    }

    fclose(pFile);
    return itsOk;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int itsOk=-1;
    FILE* pFile;
    pFile=fopen(path,"rb");
    if(pFile==NULL)
    {
        return itsOk;
    }

    else
    {
        itsOk=parser_EmployeeFromBinary(pFile,pArrayListEmployee);
    }

    return itsOk;
}



int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int itsOk=-1;
    int auxId;
    char idAux[50];
    char auxHoras[50];
    char auxSalario[50];
    char auxNombre[130];
    char confirm;
    int index=-1;
    Employee* auxEmployee=employee_new();


    system("cls");
    printf("---Carga de empleado nuevo---\n\n");

    printf("Ingrese ID: ");
    fflush(stdin);
    scanf("%d", &auxId);

    for(int i=0; i<ll_len(pArrayListEmployee); i++)
    {
        auxEmployee= ((Employee*) ll_get(pArrayListEmployee,i));
        if(auxEmployee->id==auxId)
        {
            index=i;
            break;
        }
    }
    while(index!=-1){
        printf("El ID ya existe, ingrese otro: ");
        fflush(stdin);
        scanf("%d", &auxId);
        index=-1;
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            auxEmployee= ((Employee*) ll_get(pArrayListEmployee,i));
            if(auxEmployee->id==auxId)
            {
                index=i;
                break;
        }
        }
    }
    sprintf(idAux, "%d", auxId);

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(auxNombre);

    printf("Ingrese horas trabajadas: ");
    fflush(stdin);
    gets(auxHoras);

    printf("Ingrese salario: ");
    fflush(stdin);
    gets(auxSalario);

    printf("\nConfirma la carga? s/n: ");
    fflush(stdin);
    confirm=getchar();
    confirm=tolower(confirm);
    if(confirm=='s')
    {
        Employee* empNew=employee_newParametros(idAux,auxNombre,auxHoras,auxSalario);
        ll_add(pArrayListEmployee,empNew);
        itsOk=1;
    }
    else
    {
        itsOk=0;
    }



    return itsOk;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int itsOk=-1;
    int id;
    char name[128];
    int hours;
    int salary;

    int index=-1;
    char confirm;
    Employee* auxEmployee=employee_new();

    system("cls");
    printf("---Editar empleado---\n\n");
    if(auxEmployee==NULL)
    {
        itsOk=0;
    }
    else
    {
        if(ll_len(pArrayListEmployee)==0)
            itsOk=4;
        else
        {

            showEmployees(pArrayListEmployee);
            printf("\n---Editar empleado---\n");

            printf("Ingrese id: ");
            scanf("%d", &id);
            id=validationNum(id);

            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                auxEmployee= ((Employee*) ll_get(pArrayListEmployee,i));
                if(auxEmployee->id==id)
                {
                    index=i;
                    showEmployee(auxEmployee);
                    break;
                }
            }

            if(index!=-1)
            {
                printf("\nIngrese nombre nuevo: ");
                fflush(stdin);
                gets(name);
                validationString(name);

                printf("Ingrese horas trabajadas actuales: ");
                scanf("%d",&hours);
                hours=validationNum(hours);

                printf("Ingrese salario: ");
                scanf("%d",&salary);
                salary=validationNum(salary);

                printf("\n");
                printf("Desea modificar los datos del siguiente empleado?\n");
                printf("ID: %d\nNombre: %s\nHoras trabajadas: %d\nSalario: %d",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
                printf("\nConfirma editar el usuario? s/n: ");
                fflush(stdin);
                confirm= getchar();
                confirm=tolower(confirm);

                if(confirm=='s')
                {
                    strcpy(auxEmployee->nombre,name);
                    auxEmployee->horasTrabajadas=hours;
                    auxEmployee->sueldo=salary;

                    ll_push(pArrayListEmployee,index,auxEmployee);
                    ll_remove(pArrayListEmployee,index);
                    itsOk=1;
                }
                else
                    itsOk=2;
            }
            else
                itsOk=3;
        }
    }
    return itsOk;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int itsOk=-1;
    int id;
    int index=-1;

    char confirm;

    Employee* auxEmployee=employee_new();

    system("cls");
    printf("---Eliminar empleado---\n\n");
    if(auxEmployee==NULL)
        itsOk=0;
    else
    {
        if(ll_len(pArrayListEmployee)==0)
            itsOk=4;
        else
        {
            showEmployees(pArrayListEmployee);
            printf("\n---Eliminar empleado---\n");

            printf("Ingrese id: ");
            scanf("%d",&id);
            id=validationNum(id);

            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                auxEmployee= ((Employee*) ll_get(pArrayListEmployee,i));
                if(auxEmployee->id==id)
                {
                    index=i;
                    break;
                }
            }

            if(index!=-1)
            {
                showEmployee(auxEmployee);
                printf("\nConfirma eliminar el usuario? s/n: ");
                fflush(stdin);
                confirm= getchar();
                confirm=tolower(confirm);
                confirm=validationChar(confirm,'s','n');

                if(confirm=='s')
                {
                    ll_remove(pArrayListEmployee,index);
                    itsOk=1;
                }
                else
                    itsOk=2;
            }
            else
            {
                itsOk=3;
            }
        }
    }

    return itsOk;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int listOk=0;
    if(pArrayListEmployee!=NULL)
    {
        system("cls");
        printf(" ID  |  Nombre  |  Horas  |  Salario\n\n");
        showEmployees(pArrayListEmployee);
        printf("\n");
        listOk=1;
    }

    return listOk;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int order;
    int sortOk=0;

    if(pArrayListEmployee!=NULL)
    {

        switch(menuOfOreder())
        {
        case 1:

            order=typeOfOrder();
            if(order==0)
            {
                ll_sort(pArrayListEmployee,orderByID,order);
                controller_ListEmployee(pArrayListEmployee);
                sortOk=1;
            }
            else
            {
                ll_sort(pArrayListEmployee,orderByID,order);
                controller_ListEmployee(pArrayListEmployee);
                sortOk=1;
            }
            break;


        case 2:

            order=typeOfOrder();
            if(order)
            {
                ll_sort(pArrayListEmployee,orderByName,order);
                controller_ListEmployee(pArrayListEmployee);
                sortOk=1;
            }
            else
            {
                ll_sort(pArrayListEmployee,orderByName,order);
                controller_ListEmployee(pArrayListEmployee);
                sortOk=1;
            }
            break;

        case 3:

            order=typeOfOrder();
            if(order)
            {
                ll_sort(pArrayListEmployee,orderByHours,order);
                controller_ListEmployee(pArrayListEmployee);
                sortOk=1;
            }
            else
            {
                ll_sort(pArrayListEmployee,orderByHours,order);
                controller_ListEmployee(pArrayListEmployee);
                sortOk=1;
            }
            break;

        case 4:

            order=typeOfOrder();
            if(order)
            {
                ll_sort(pArrayListEmployee,orderBySalary,order);
                controller_ListEmployee(pArrayListEmployee);
                sortOk=1;

            }
            else
            {
                ll_sort(pArrayListEmployee,orderBySalary,order);
                controller_ListEmployee(pArrayListEmployee);
                sortOk=1;
            }
            break;
        }

    }
    return sortOk;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* auxEmp;
    int size=ll_len(pArrayListEmployee);
    int itsOk=-1;

    int id;
    int hours;
    int salary;

    char name[130];

    if(pArrayListEmployee!=NULL && path!=NULL)
    {
        if(size>0)
        {
            pFile=fopen(path,"w");
            if(pFile!=NULL)
            {
                for(int i=0; i<size; i++)
                {
                    auxEmp=(Employee*)ll_get(pArrayListEmployee,i);
                    employee_getId(auxEmp,&id);
                    employee_getNombre(auxEmp,name);
                    employee_getHorasTrabajadas(auxEmp,&hours);
                    employee_getSueldo(auxEmp,&salary);
                    fprintf(pFile,"%d,%s,%d,%d\n",id,name,hours,salary);
                }
                fclose(pFile);
                itsOk=1;
            }

            else
                itsOk=0;
        }


    }

    return itsOk;
}



int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* auxEmp;
    int itsOk=-1;

    if(pArrayListEmployee!=NULL && path!=NULL)
    {
        if(ll_len(pArrayListEmployee)>0)
        {
            pFile=fopen(path,"wb");
            if(pFile!=NULL)
            {
                for(int i=0; i<ll_len(pArrayListEmployee); i++)
                {
                    auxEmp=ll_get(pArrayListEmployee,i);
                    if(auxEmp!=NULL)
                    {
                        fwrite(auxEmp,sizeof(Employee),1,pFile);
                    }
                    itsOk=1;
                }
                fclose(pFile);
            }
        }
    }
    else
        itsOk=0;

    return itsOk;
}
