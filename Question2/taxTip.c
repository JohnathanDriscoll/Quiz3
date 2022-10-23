#include <string.h>
#include "bill.h"

double calcTip(PtrToConstItem ptr, double tip, int num){
    double itemCost = ptr[num].cost;
    double tipAmt;
    tipAmt = itemCost * tip;

    return tipAmt;

double calcTax(PtrToConstItem ptr, double tax, int num){
    double itemCost = ptr[num].cost;
    double itemTax;
    itemTax = itemCost * tax;

    return itemTax;

double getItemCost(PtrToConstItem ptr, int num){
    return ptr[num].cost;