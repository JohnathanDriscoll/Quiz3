#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stddef.h>
#include <string.h>

typedef struct {
    char *item;         //8 bytes
    double cost;      //8 bytes
} 
Item, *PtrToItem;
typedef const Item *PtrToConstItem;

Item ItemTable[] = 
{
    {"Salad", 9.95},
    {"Soup", 4.55},
    {"Sandwich", 13.25},
    {"Pizza", 22.35}
};

/*char getItemName(PtrToConstItem ptr, int num){
    return ptr[num].item;
}*/
double getItemCost(PtrToConstItem ptr, int num){
    return ptr[num].cost;
}
int main () {
    int number;
    char name;
    time_t t;

    srand((unsigned) time(&t));
    number = rand() % 3;

    printf(" Cost: %.2f\n", getItemCost(ItemTable, number));
}