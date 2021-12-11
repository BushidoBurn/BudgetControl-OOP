#include <iostream>
#include <string>
#include <vector>
#include "expense.h"
#include "some_globals.h"
#include <algorithm>

using namespace std;

/* data */
int month;
float price;
string definition;
string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int expense_counter;
vector<int> found_expense_index_vector;
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
    for (Expense *exp : Expense::expense_vector)
    {
        cout << exp->getDefinition() << " " << exp->getPrice() << " " << exp->getMonth() << endl;
    }
}

void Expense::setMonth(int m)
{
    this->month = m;
}
void Expense::setPrice(float pr)
{
    this->price = pr;
}
void Expense::setDefinition(string df)
{
    this->definition = df;
}
int Expense::getMonth()
{
    return this->month;
}
float Expense::getPrice()
{
    return this->price;
}
string Expense::getDefinition()
{
    return this->definition;
}

vector<Expense *> Expense::getAllExpenses()
{
    return this->expense_vector;
}
void print_detail(Expense *exp)
{
}

Expense *Expense::findExpense(string searchWord, Expense *expense)
{

    // str.find("haystack");
    if (expense->getDefinition().find(searchWord) != string::npos)
        return expense;
    return NULL;
}

vector<Expense *> Expense::findExpenseInVector(string searchWord)
{
    this->found_expense_vector.clear(); // At the beginning of each search we do clean the vector
    found_expense_index_vector.clear();
    int counter = 0;
    for (Expense *ex : this->getAllExpenses())
    {

        if (ex->findExpense(searchWord, ex))
        {
            ex->found_expense_vector.push_back(ex);
            found_expense_index_vector.push_back(counter);
        }
        counter++;
    }
    return this->found_expense_vector;
}

void Expense::findAndList(string searchWord)
{
    vector<Expense *> dummy = this->findExpenseInVector(searchWord);

    for (int x = 0; x < dummy.size(); x++)
    {
        cout << "(" << found_expense_index_vector[x] << ") " << dummy[x]->getDefinition() << endl;
    }
}

void Expense::deleteOneExpense(int ind)
{
    this->expense_vector.erase(this->expense_vector.begin() + ind);
}

void Expense::updateOneExpense(int ind, string definition, float price, int month)
{

    if (!definition.empty())
        this->expense_vector.at(ind)->definition = definition;
    if (price != -9999.0)
        this->expense_vector.at(ind)->price = price;
    if (month != -9999)
        this->expense_vector.at(ind)->month = month;
}

void Expense::deleteAllExpenses()
{
    this->found_expense_vector.clear();
    found_expense_index_vector.clear();
    expense_vector.clear();
}

bool operator<(Expense a, Expense b)
{
    if (a.getPrice() < b.getPrice())
        return true;
    else
        return false;
}

void Expense::sortByPrice()
{
    sort(this->expense_vector.begin(), this->expense_vector.end());
}