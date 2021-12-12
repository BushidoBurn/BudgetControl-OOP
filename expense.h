#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#pragma once
using namespace std;

class Expense
{
    ;

protected:
    /* data */
    int mytype;
    int month;
    float price;
    string definition;

    inline static vector<Expense *> expense_vector;
    inline static vector<Expense *> found_expense_vector;

public:
    Expense(int month, float price, string definition);

    virtual ~Expense(){};

    void showExpenseDetails();

    void showTotalNumberOfExpenses();

    void static addExpenseToVector(Expense &e);

    void popExpenseFromVector();

    void listAllExpenses();
    void setMonth(int month);
    void setPrice(float price);
    void setDefinition(string definition);
    int getMonth();
    float getPrice();
    string getDefinition();
    vector<Expense *> getAllExpenses();
    virtual void print_detail(){};
    Expense *findExpense(string searchWord, Expense *expense);
    vector<Expense *> findExpenseInVector(string searchWord);
    void findAndList(string searchWord);
    void deleteOneExpense(int ind);
    void updateOneExpense(int ind, string definition = "", float price = -9999.0, int month = -9999);
    void deleteAllExpenses();
    void sortByPrice();
    void writeAllToFile(string fName);
    virtual void writeToFile(ofstream &output);
    void readAllFromFile(string fName);
    void getSplittedValues(string line, string delimiter, int *start_month, int *howmanymonths, string *definition, float *price, int *month, int *mytype);
    vector<string> split(const string &s, char delim);
};
