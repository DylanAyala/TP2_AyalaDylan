#include "Employee.h"
#include "stdlib.h"
#include <string.h>



int employee_setId(Employee* this,int id)
{
    int itsOk=0;
    if(this!=NULL && id >0)
    {
        this->id=id;
        itsOk=1;
    }

    return itsOk;
}



int employee_getId(Employee* this,int* id)
{
    int itsOk=0;
    if(this!=NULL && id!=NULL)
    {
        *id = this->id;
        itsOk = 1;
    }
    return itsOk;
}


int employee_setNombre(Employee* this,char* name)
{
    int itsOk=0;
    if(this!=NULL && name!=NULL)
    {
        strcpy(this->nombre,name);
        itsOk=1;

    }

    return itsOk;
}


int employee_getNombre(Employee* this,char* name)
{
    int itsOk=0;
    if(this!=NULL && name!=NULL)
    {
        strcpy(name,this->nombre);
        itsOk=1;
    }

    return itsOk;
}



int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk=0;

    if(this!=NULL && horasTrabajadas>0)
    {
        this->horasTrabajadas=horasTrabajadas;
        todoOk = 1;
    }


    return todoOk;
}



int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk=0;

    if(this!=NULL && horasTrabajadas>0)
    {
        *horasTrabajadas=this->horasTrabajadas;
        todoOk = 1;
    }


    return todoOk;
}



int employee_setSueldo(Employee* this,int sueldo)
{
   int todoOk=0;

    if(this!=NULL && sueldo>0)
    {
        this->sueldo=sueldo;
        todoOk = 1;
    }


    return todoOk;
}



int employee_getSueldo(Employee* this,int* sueldo)
{
   int todoOk=0;

    if(this!=NULL && sueldo>0)
    {
        *sueldo=this->sueldo;
        todoOk = 1;
    }


    return todoOk;
}


Employee* employee_new()
{
    Employee* this= (Employee*) malloc(sizeof(Employee));
    if(this != NULL)
    {
        this->id=0;
        strcpy(this->nombre,"");
        this->horasTrabajadas=0;
        this->sueldo=0;
    }

    return this;
}



Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* this;
        if(idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
        {
            this= employee_new();
            if(this!=NULL)
            {
                if(!employee_setId(this,atoi(idStr)) || !employee_setNombre(this,nombreStr) || !employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr)) || !employee_setSueldo(this,atoi(sueldoStr)))
                {
                    free(this);
                    this=NULL;
                }
            }
        }

    return this;
}


void showEmployees(LinkedList* pArrayLinkedList)
{
    if(pArrayLinkedList!=NULL)
    {
        for(int i=0;i<ll_len(pArrayLinkedList);i++)
        {
            showEmployee((Employee*) ll_get(pArrayLinkedList,i));
        }
        printf("\n\n");
    }
}


void showEmployee(Employee* emp)
{
    if(emp!=NULL)
    printf("%4d  %10s  %5d      %5d\n",emp->id,emp->nombre,emp->horasTrabajadas,emp->sueldo);
}



int orderByID(void* emp1, void* emp2)
{
    int retorno=0;
    Employee* p1;
    Employee* p2;

    if(emp1 != NULL && emp2 != NULL)
    {
        p1=(Employee*) emp1;
        p2=(Employee*) emp2;

        if(p1->id > p2->id)
            retorno = 1;
        else if(p1->id < p2->id)
            retorno=-1;
        else
            retorno=0;
    }
    return retorno;
}


int orderByName(void* emp1, void* emp2)
{
    int retorno=0;
    Employee* p1;
    Employee* p2;

    if(emp1 != NULL && emp2 != NULL)
    {
        p1=(Employee*) emp1;
        p2=(Employee*) emp2;

        if(strcmp(p1->nombre,p2->nombre)==-1)
            retorno = 1;
        else if(strcmp(p1->nombre,p2->nombre)==1)
            retorno=-1;
        else
            retorno=0;
    }
    return retorno;
}


int orderBySalary(void* emp1, void* emp2)
{
    int retorno=0;
    Employee* p1;
    Employee* p2;

    if(emp1 != NULL && emp2 != NULL)
    {
        p1=(Employee*) emp1;
        p2=(Employee*) emp2;

        if(p1->sueldo > p2->sueldo)
            retorno = 1;
        else if(p1->sueldo < p2->sueldo)
            retorno=-1;
        else
            retorno=0;
    }
    return retorno;
}


int orderByHours(void* emp1 , void* emp2)
{
    int retorno=0;
    Employee* p1;
    Employee* p2;

    if(emp1 != NULL && emp2 != NULL)
    {
        p1=(Employee*) emp1;
        p2=(Employee*) emp2;

        if(p1->horasTrabajadas > p2->horasTrabajadas)
            retorno = 1;
        else if(p1->horasTrabajadas < p2->horasTrabajadas)
            retorno=-1;
        else
            retorno=0;
    }
    return retorno;
}
