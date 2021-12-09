#include "expense.h"
#pragma once
class Discretionary : public Expense
{
private:
    /* data */

public:
    Discretionary(int start_month, int how_many_months, int month, float price, string definition);
    virtual void print_detail(Expense *exp);
};