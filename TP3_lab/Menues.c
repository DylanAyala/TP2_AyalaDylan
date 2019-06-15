#include "Menues.h"


int menu()
{
    int option;
    system("cls");
    printf("***MENU DE MANEJO DE DATOS DE NOMINA DE EMPLEADOS***\n\n");
    printf("1. Cargar datos de empleados desde archivo de texto\n");
    printf("2. Cargar datos de archivo binario\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados (sub menu)\n");
    printf("8. Salvar los datos en un archivo de texto\n");
    printf("9. Guardar como archivo binario\n");
    printf("0. Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&option);

    return option;

}



int menuOfOreder (void)
{
    int option;
    system("cls");
    printf("---MENU DE ORDENAMIENTO---\n\n");
    printf("1. Listar por ID\n");
    printf("2. Listar por orden alfabetico\n");
    printf("3. Listar por horas trabajadas\n");
    printf("4. Listar por salario\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&option);
    option=validationMenu(option,1,4);

    return option;
}



int typeOfOrder()
{
    char selec;
    int opt;
    printf("\n");
    printf("A-Desendente\n");
    printf("B-Asendente\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c",&selec);
    selec=toupper(selec);
    selec=validationChar(selec,'A','B');
    if(selec=='A')
        opt=0;
    else if (selec=='B')
        opt=1;
    return opt;
}
