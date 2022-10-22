//Compile using the following command: gcc employeeMain.c employeeTable.c employeeOne.c

//gcc employeeMain.c employeeTable.c employeeTwo.c

#include <string.h>
#include <stdlib.h>
#include "employee.h"
int main(void){
    //defined in employeeOne.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);
    PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char * phoneToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);

    //defined in employeeTable.c
    extern Employee EmployeeTable[];    //extern means it was defined somewhere else.  Tells the cpu not to waste space defining it here.
    extern const int EmployeeTableEntries;     

    PtrToEmployee matchPtr;  //Declaration

     //Search by EID number
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1001);   
    if (matchPtr != NULL)
        printf("Employee ID 1001 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID 1001 is NOT found in the record\n");

    //Search by Name
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if (matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");

    //Search by phone number
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "310-555-1215");
    if (matchPtr != NULL)
        printf("310-555-1215 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("310-555-1215 is NOT found in the record\n");

    //search by salary
            matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 8.78);
    if (matchPtr != NULL)
        printf("An employee that makes 8.78 salary is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("An employee that makes 8.78 salary is NOT found in the record\n");

    return EXIT_SUCCESS;
}