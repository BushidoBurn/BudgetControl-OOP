#include <iostream>
#include <string>
#include <vector>
#pragma once
using namespace std;

class Expense
{
private:
    /* data */
    int month;
    float price;
    string definition;

    inline static vector<Expense *> expense_vector;

public:
    Expense(int month, float price, string definition);

    ~Expense();

    void showExpenseDetails();

    void showTotalNumberOfExpenses();

    void addExpenseToVector(Expense &e);

    void popExpenseFromVector();

    void listAllExpenses();
};