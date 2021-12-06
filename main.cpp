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
    exp.~Expense();
    return 0;
}