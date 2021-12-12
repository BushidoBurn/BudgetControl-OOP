#include "discretionary.h"
#include "colors.h"
#include "some_globals.h"
#include <iostream>
using namespace std;
Discretionary::Discretionary(int start_month, int how_many_months, int month, float price, string definition)
    : Expense(month, price, definition)
{
    // cout << "Start : " << start_month << " " << how_many_months << endl;
    this->mytype = 2;
    this->start_month = start_month;
    this->how_many_months = how_many_months;
}
void Discretionary::print_detail()
{
    cout << FMAG("Definition ") << this->getDefinition() << " " << this->getPrice() << " " << months[(this->getMonth() - 1)] << endl;
}

int Discretionary::getStartMonth()
{
    return this->start_month;
}

int Discretionary::getHownManyMonths()
{
    return this->how_many_months;
}

void Discretionary::writeToFile(ofstream &output)
{
    output << "***"
           << " ";
    output << this->getDefinition() << " ";
    output << this->getPrice() << " ";
    output << month << " ";
    output << this->getStartMonth() << " ";
    output << this->getHownManyMonths() << endl;
}