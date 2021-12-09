#include <iostream>
#include <string>
#include <vector>
#include "expense.h"
#include "some_globals.h"

using namespace std;

/* data */
int month;
float price;
string definition;
string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
inline static vector<Expense *> expense_vector;
int expense_counter;

Expense::Expense(int month, float price, string definition)
{
    expense_counter = 0;

    this->month = month;
    this->price = price;
    this->definition = definition;
    expense_counter++;
    this->expense_vector.push_back(this);
    cout << "1  Expence Created" << endl;
}

Expense::~Expense()
{

    // this->month = NULL;
    // this->price = NULL;
    this->definition.clear();
    expense_counter--;
    cout << "1  Expence Destroyed" << endl;
}

void Expense::showExpenseDetails()
{
    cout << months << endl;
    cout << "Definition " << definition << endl;
    cout << "Price " << price << endl;
    cout << "Month " << months[(month - 1)] << endl;
}
void Expense::showTotalNumberOfExpenses()
{
    cout << "There are totally " << expense_counter << " in memory" << endl;
}

void Expense::addExpenseToVector(Expense &e)
{
    this->expense_vector.push_back(&e);
}
void Expense::popExpenseFromVector()
{
    this->expense_vector.pop_back();
}

void Expense::listAllExpenses()
{
    for (auto exp : this->expense_vector)
    {
        cout << exp->definition << " " << exp->price << " " << months[(exp->month - 1)] << endl;
    }
}
