#include <iostream>
#include "expense.h"
#include "fixedexpence.h"
#include "discretionary.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{

    cout << "Testing .gitignore" << endl;

    // Expense exp = Expense(1, 11.3, "Nike bag");
    // exp.showExpenseDetails();
    // exp.showTotalNumberOfExpenses();

    FixedExpense f_exp = FixedExpense(1, 3, 1, 12.3, "Rent");
    FixedExpense d_exp = FixedExpense(1, 3, 1, 12.3, "Rent1");

    Discretionary a = Discretionary(1, 3, 1, 12.5, "Rent22");
    Discretionary b = Discretionary(1, 3, 1, 12.7, "Rent33");

    // Expense * exp_p;

    for (Expense *ex : f_exp.getAllExpenses())
    {
        ex->print_detail(ex);
    }

    return 0;
}