#include "fixedexpence.h"
#include "some_globals.h"
#include "colors.h"
#include <iostream>
using namespace std;
/* data */
int start_month;
int how_many_months;

FixedExpense::FixedExpense(int start_month, int how_many_months, int month, float price, string definition)
    : Expense(month, price, definition)
{

    this->start_month = start_month;
    this->how_many_months = how_many_months;
    cout << "Start : " << start_month << " " << how_many_months << endl;
    this->mytype = 1;
}
void FixedExpense ::showExpenseDetails()
{
    cout << months << endl;
    cout << FBLU("Definition ") << this->getDefinition() << endl;
    cout << "Price " << this->getPrice() << endl;
    cout << "Month " << months[(month - 1)] << endl;
}

void FixedExpense::print_detail(Expense *exp)
{
    cout << FBLU("Definition ") << exp->getDefinition() << " " << exp->getPrice() << " " << months[(exp->getMonth() - 1)] << endl;
}

void FixedExpense::writeToFile(ofstream &output)
{
    output << "**"
           << " ";
    output << this->getDefinition() << " ";
    output << this->getPrice() << " ";
    output << month << " ";
    output << this->getStartMonth() << " ";
    output << this->getHownManyMonths() << endl;
}

int FixedExpense::getStartMonth()
{
    return this->start_month;
}

int FixedExpense::getHownManyMonths()
{
    return this->how_many_months;
}