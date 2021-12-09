#include "discretionaryexpense.h"

Discretionary::Discretionary(int start_month, int how_many_months, int month, float price, string definition)
    : Expense(month, price, definition)
{
    cout << "Start : " << start_month << " " << how_many_months << endl;
}
