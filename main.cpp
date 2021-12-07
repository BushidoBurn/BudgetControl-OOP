#include <iostream>
#include "expense.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "Testing .gitignore" << endl;
    Expense exp = Expense(1, 11.3, "Nike bag");
    exp.showExpenseDetails();
    exp.showTotalNumberOfExpenses();

    FixedExpense f_exp = FixedExpense(1, 3, 1, 12.3, "Rent");

    return 0;
}