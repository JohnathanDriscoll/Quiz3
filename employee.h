#include <stdio.h>
#include <stddef.h>
typedef struct {
    long number;        //4 bytes
    char *name;         //8 bytes
    char *phone;        //8 bytes
    double salary;      //8 bytes
} Employee, *PtrToEmployee;
typedef const Employee *PtrToConstEmployee;
