#include <iostream>
#include "expense.h"
#include "fixedexpence.h"
#include "discretionary.h"
#include "some_globals.h"
#include <string>
#include "manager.h"

using std::cin;
using std::cout;
using std::endl;

extern vector<int> found_expense_index_vector;

int main()
{
    printOptions();
    manage();

    return 0;
}