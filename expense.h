#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Expense
{
private:
    /* data */
    int month;
    float price;
    string definition;
    inline static int expense_counter = {0};
    inline static vector<Expense *> expense_vector;
    inline static vector<string> months = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

public:
    Expense(int month, float price, string definition)
    {

        this->month = month;
        this->price = price;
        this->definition = definition;
        this->expense_counter++;
        this->expense_vector.push_back(this);
        cout << "1  Expence Created" << endl;
    }

    ~Expense()
    {

        // this->month = NULL;
        // this->price = NULL;
        this->definition.clear();
        this->expense_counter--;
        cout << "1  Expence Destroyed" << endl;
    }

    void showExpenseDetails()
    {
        cout << "Definition " << definition << endl;
        cout << "Price " << price << endl;
        cout << "Month " << months.at(month - 1) << endl;
    }
    void showTotalNumberOfExpenses()
    {
        cout << "There are totally " << this->expense_counter << " in memory" << endl;
    }

    void addExpenseToVector(Expense &e)
    {
        this->expense_vector.push_back(&e);
    }
    void popExpenseFromVector()
    {
        this->expense_vector.pop_back();
    }

    void listAllExpenses()
    {
        for (auto exp : this->expense_vector)
        {
            cout << exp->definition << " " << exp->price << " " << Expense::months.at(exp->month - 1) << endl;
        }
    }
};

class FixedExpense : public Expense
{
private:
    /* data */
    int start_month;
    int how_many_months;

public:
    FixedExpense(int start_month, int how_many_months, int month, float price, string definition)
        : Expense(month, price, definition)
    {
        cout << "Start : " << start_month << " " << how_many_months << endl;
    }
};

class Discretionary : public Expense
{
private:
    /* data */

public:
    Discretionary(int start_month, int how_many_months, int month, float price, string definition)
        : Expense(month, price, definition)
    {
        cout << "Start : " << start_month << " " << how_many_months << endl;
    }
};