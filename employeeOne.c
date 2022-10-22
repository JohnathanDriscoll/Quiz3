#include <string.h>
#include "employee.h"
PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int tableSize, long targetNumber){
    const PtrToConstEmployee endPtr = ptr + tableSize;
    for(; ptr < endPtr; ptr++)  //search until end of table  ptr++ will increment by what??
    {   //for pointers, you dereference with the arrow ->
        if(ptr->number == targetNumber) //dereference the pointer number and check if it equals the Employee number
            return (PtrToEmployee) ptr; //return location of the number to callee.
    }
     return NULL;   //this will only happen if no Employee number matches in loop above
}

//Essentially the same functionality as above but comparing strings to check if equal
PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int tableSize, char * targetName){
    const PtrToConstEmployee endPtr = ptr + tableSize;
    for(; ptr < endPtr; ptr++)
    {
        if(strcmp(ptr->name,targetName) == 0) //strcmp is string compare
            return (PtrToEmployee) ptr;
    }
    return NULL;
}

//search by phone number
PtrToEmployee searchEmployeeByPhone(PtrToConstEmployee ptr, int tableSize, char * targetPhone){
    const PtrToConstEmployee endPtr = ptr + tableSize;
    for(; ptr < endPtr; ptr++)
    {
        if(strcmp(ptr->phone,targetPhone) == 0) 
            return (PtrToEmployee) ptr;
    }
    return NULL;
}
//Search by salary
PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int tableSize, double targetSalary){
    const PtrToConstEmployee endPtr = ptr + tableSize;
    for(; ptr < endPtr; ptr++)  
    {   
        if(ptr->salary == targetSalary) 
            return (PtrToEmployee) ptr;
    }
     return NULL;
}