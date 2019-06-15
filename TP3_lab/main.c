#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Menues.h"
#include "Status.h"
#include "Validations.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/



int main()
{

    char confirm='n';
    int exit = 0;

    int result;
    int addOk;

    int flagLoadLinkedList=0;
    int flagAdd=0;

    LinkedList* employeeLinkedList = ll_newLinkedList();


    do{
        switch(menu())
        {
        case 1:

            if(!flagLoadLinkedList)
            {
                result=controller_loadFromText("./data.csv",employeeLinkedList);
                statusLoadFromText(result);
                flagLoadLinkedList=1;

            }
            else
                printf("\nYa hay un archivo cargado\n");
            break;

        case 2:

            if(!flagLoadLinkedList)
            {
                result=controller_loadFromBinary("./data.bin",employeeLinkedList);
                statusLoadFromBinary(result);
                flagLoadLinkedList=1;
            }
            else
                printf("\nYa hay un archivo cargado\n");
            break;

        case 3:

            result=controller_addEmployee(employeeLinkedList);
            addOk=statusAddEmployee(result);
            if(addOk==1)
                flagAdd=1;
            break;

        case 4:

            result=controller_editEmployee(employeeLinkedList);
            statusEditEmployee(result);
            break;

        case 5:

            result=controller_removeEmployee(employeeLinkedList);
            statusDeleteEmployee(result);
            break;

        case 6:

            if(!flagAdd && !flagLoadLinkedList)
                printf("\nNo hay ningun dato cargado\n\n");
            else
                result=controller_ListEmployee(employeeLinkedList);
            break;

        case 7:

            if(!flagAdd && !flagLoadLinkedList)
                printf("No hay ningun dato cargado\n");
            else
            {
                result=controller_sortEmployee(employeeLinkedList);
                if(!result)
                    printf("\nError al realizar el ordenamiento\n");
            }
            break;

        case 8:

            result=controller_saveAsText("./dataSave.csv",employeeLinkedList);
            if(result==1)
            {
                printf("Se guardo correctamente\n");
                flagLoadLinkedList=0;
                flagAdd=0;
                ll_deleteLinkedList(employeeLinkedList);
                employeeLinkedList=ll_newLinkedList();
            }
            else if(result==-1)
                printf("Error al ejecutar la opcion\n");
            break;

        case 9:

            result=controller_saveAsBinary("./dataSave.bin",employeeLinkedList);
            if(result==1)
            {
                printf("El archivo se creo correctamente\n");
                flagLoadLinkedList=0;
                flagAdd=0;
                ll_deleteLinkedList(employeeLinkedList);
                employeeLinkedList=ll_newLinkedList();
            }
            if(result==-1)
                printf("Error al ejecutar la opcion\n");
            else if(result==0)
                printf("No se encontro ningun archivo\n");
            break;

        case 0:

            printf("Salir?\n");
            printf("Confirma? S/N: ");
            fflush(stdin);
            confirm=getchar();
            confirm=toupper(confirm);
            confirm=validationChar(confirm, 'S','N');
                if(confirm=='S')
                {
                     exit=1;
                     printf("\nGracias por usar el programa");
                }

            break;
        default:
            printf("Error de dato ingreasdo, reingrese\n");
            break;
        }
          system("pause");
    }while(exit==0);


    return 0;

}


