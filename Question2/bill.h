#include <stdio.h>
#include <stddef.h>
typedef struct {
    char *Item;         //8 bytes
    double cost;      //8 bytes
} Item, *PtrToItem;
typedef const Item *PtrToConstItem;