#include <iostream>
#include "expense.h"
#include "fixedexpence.h"
#include "discretionary.h"
#include "some_globals.h"

using std::cin;
using std::cout;
using std::endl;

extern vector<int> found_expense_index_vector;

int main()
{

    FixedExpense f_exp = FixedExpense(1, 3, 1, 12.3, "Rent");
    FixedExpense d_exp = FixedExpense(1, 3, 1, 12.3, "Rent1");

    Discretionary a = Discretionary(1, 3, 1, 12.5, "Rent22");
    Discretionary b = Discretionary(1, 3, 1, 12.7, "Rent33");

    f_exp.findAndList("Rent33");
    f_exp.deleteOneExpense(3);
    f_exp.findAndList("Rent");

    return 0;
}