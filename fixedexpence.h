#include "expense.h"
#include <iostream>
#pragma once
using namespace std;
class FixedExpense : public Expense
{
private:
    /* data */
    int start_month;
    int how_many_months;

public:
    FixedExpense(int start_month, int how_many_months, int month, float price, string definition);
    void showExpenseDetails();
    virtual void print_detail(Expense *exp);
    virtual void writeToFile(ofstream &output);
    int getStartMonth();
    int getHownManyMonths();
};