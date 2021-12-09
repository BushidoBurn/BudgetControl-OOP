#include <iostream>
#include "expense.h"
#include "fixedexpence.h"
#include "discretionary.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{

     FixedExpense f_exp = FixedExpense(1, 3, 1, 12.3, "Rent");
    FixedExpense d_exp = FixedExpense(1, 3, 1, 12.3, "Rent1");

    Discretionary a = Discretionary(1, 3, 1, 12.5, "Rent22");
    Discretionary b = Discretionary(1, 3, 1, 12.7, "Rent33");

    for (Expense *e : f_exp.findExpenseInVector("Rent33"))
    {
        cout << e->getDefinition() << endl;
    }

    return 0;
}