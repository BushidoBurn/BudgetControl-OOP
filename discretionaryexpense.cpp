#include "discretionary.h"
#include "colors.h"
#include "some_globals.h"
Discretionary::Discretionary(int start_month, int how_many_months, int month, float price, string definition)
    : Expense(month, price, definition)
{
    cout << "Start : " << start_month << " " << how_many_months << endl;
}
void Discretionary::print_detail(Expense *exp)
{
    cout << FMAG("Definition ") << exp->getDefinition() << " " << exp->getPrice() << " " << months[(exp->getMonth() - 1)] << endl;
}