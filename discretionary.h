#include "expense.h"
#include <iostream>
#pragma once
class Discretionary : public Expense
{
private:
    /* data */
    int start_month, how_many_months;

public:
    Discretionary(int start_month, int how_many_months, int month, float price, string definition);
    virtual void print_detail(Expense *exp);
    int getStartMonth();
    int getHownManyMonths();
    virtual void writeToFile(ofstream &output);
};