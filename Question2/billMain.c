#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "bill.h"


int main (int argc, char *argv[]) {
    int number;
    time_t t;
    double perTax = strtod(argv[1], NULL) / 100;
    double perTip = strtod(argv[2], NULL) / 100;

    srand((unsigned) time(&t));
    number = rand() % 4;
    
    //external functions defined in taxTip.c
    double calcTip(const Item table[], double tip, int number);
    double calcTax(const Item table[], double tax, int number);
    double getItemCost(const Item table[], int number);

    //external table defined in itemTable.c
    extern Item ItemTable[]; 

    printf("The menu items are\n");
    printf("Salad: $9.95\n");
    printf("Soup: $4.55\n");
    printf("Sandwich: $13.25\n");
    printf("Pizza: 22.35\n");

    if (argc == 3 && perTip < .99 && perTax < .99){
        printf("The tax percentage entered is %.3f and the tip percentage is %.3f.\n", perTax, perTip);
    }
    else if (perTax > .99 || perTip > .99){
        printf("Tax and tip rate values cannot be over 100%.\n");
    }
    else
        printf("To calculate tax and tip, enter a value for tax percentage, then enter a value for tip percentage\n");

    double billTip = calcTip(ItemTable, perTip, number);
    double billTax = calcTax(ItemTable, perTax, number);
    double itemCost = getItemCost(ItemTable, number);
    double billTotal = billTax + billTip + itemCost;
        
    printf("The bill is:\nItem Cost: $%.2f\nTax Amount: $%.2f\nTip Amount: $%.2f/nTotal Bill: $%.2f\n", itemCost, billTax, billTip, billTotal);

    return EXIT_SUCCESS;

}