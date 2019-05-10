#ifndef funtions
#define funtions
#define LENG 10
#define LENGSEC 5
#define NAME 51

typedef struct
{
    int id;
    char name[NAME];
} eSector;

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
int modifyEmployee (eEmployee employee[], int len, int file, eSector sec[], int lengSec);
int printEmployee (eEmployee employee, eSector sec);
int deleteEmployee(eEmployee list[], int len, int id, eSector sec[], int lengSec);
int findPlace(eEmployee list[], int tam, int id);
int showEmployees(eEmployee emp[], int leng, eSector sec[], int lengSec);
int showOrdered(int choice, eEmployee emp[], int lenEmp, eSector sec[], int lengSec);
void mostrarSectores(eSector sec[], int leng);
void printSector(eSector sec);
int indexSec(eSector sec[], int lengSec, eEmployee emp);

#endif // funtions
