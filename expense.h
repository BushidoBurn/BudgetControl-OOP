#include <iostream>
#include <string>

using namespace std;

class Expense
{
private:
    /* data */
    int month;
    float price;
    string definition;
    int expense_counter = {0};

public:
    Expense(int month, float price, string definition);
    ~Expense();

    void showExpenseDetails()
    {
        cout << "Definition " << definition << endl;
        cout << "Price " << price << endl;
        cout << "Month " << month << endl;
    }
    void showTotalNumberOfExpenses()
    {
        cout << "There are totally " << this->expense_counter << " in memory" << endl;
    }
};

Expense::Expense(int month, float price, string definition)
{

    this->month = month;
    this->price = price;
    this->definition = definition;
    this->expense_counter++;
    cout << "1  Expence Created" << endl;
}

Expense::~Expense()
{

    this->month = NULL;
    this->price = NULL;
    this->definition.clear();
    this->expense_counter--;
    cout << "1  Expence Destroyed" << endl;
}
