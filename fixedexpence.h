#include "expense.h"
#pragma once
class FixedExpense : public Expense
{
private:
    /* data */
    int start_month;
    int how_many_months;

public:
    FixedExpense(int start_month, int how_many_months, int month, float price, string definition);
};