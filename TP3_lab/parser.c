#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int itsOk=-1;
    int counter;
    char buffer[4][150];

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        Employee* employeeNew;
            while(!feof(pFile))
            {
                counter=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n] \n",buffer[0],buffer[1],buffer[2],buffer[3]);


                    if(counter==4)
                    {
                        employeeNew=employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
                        if(employeeNew!=NULL)
                        {
                            ll_add(pArrayListEmployee,employeeNew);
                            itsOk=1;
                        }
                    }

            }
    }
    return itsOk;
}


int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    int itsOk=-1;
    int counter;
    if(pArrayListEmployee!=NULL)
    {
        while(!feof(pFile))
        {
            Employee* employeeNew=employee_new();
            if(employeeNew!=NULL)
            {
                counter=fread(employeeNew,sizeof(Employee),1,pFile);
                if(counter==1)
                {
                    ll_add(pArrayListEmployee,employeeNew);
                    itsOk=1;
                }
                if(counter<1)
                {
                    if(feof(pFile))
                        break;
                    else
                    {
                        itsOk=0;
                        break;
                    }
                }
            }
        }
    }
    return itsOk;
}
