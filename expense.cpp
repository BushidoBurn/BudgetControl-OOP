#include <iostream>
#include <string>
#include <vector>
#include "expense.h"
#include "some_globals.h"
#include <algorithm>
#include <fstream>
#include <typeinfo>
#include "fixedexpence.h"
#include "discretionary.h"
#include <sstream>


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
    this->mytype = 0;
}

void Expense::showExpenseDetails()
{
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
    Expense::expense_vector.push_back(&e);
}
void Expense::popExpenseFromVector()
{
    this->expense_vector.pop_back();
}

void Expense::listAllExpenses()
{ int counter=0;
    for (auto exp : Expense::expense_vector)
    {
         exp->print_detail(counter);
         counter++;
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
void print_detail()
{
}

Expense *Expense::findExpense(string searchWord, Expense *expense)
{


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
    std::sort(this->expense_vector.begin(), this->expense_vector.end(),
              [] (Expense* lhs, Expense* rhs) {
                  return lhs->getPrice() < rhs->getPrice();
              });
//    for (const auto& element : this->expense_vector)
//        std::cout << element->price<< std::endl;
}

void Expense::writeAllToFile(string fName)
{
    ofstream output;
    output.open(fName);

    for (auto e : this->expense_vector)
    {
        e->writeToFile(output);
    }

    output.close();
}

void Expense::readAllFromFile(string fName)
{
    string definition = "";
    float price = 0;
    int month;
    int mytype = 0;
    int start_month = 0;
    int howManyMonths = 0;
    string *p_definition = &definition;
    float *p_price = &price;
    int *p_month = &month;
    int *p_mytype = &mytype;
    int *p_start_month = &start_month;
    int *p_howmanymonths = &howManyMonths;

    ifstream input(fName);

    for (string line; getline(input, line);)
    {
        this->getSplittedValues(line, " ", p_start_month, p_howmanymonths, p_definition, p_price, p_month, p_mytype);
        if (*p_mytype == 0)
        {
            Expense::addExpenseToVector(*(new Expense(month, price, definition)));
        }
        if (*p_mytype == 1)
        {
            Expense::addExpenseToVector(*(new FixedExpense(start_month, howManyMonths, month, price, definition)));

        }
        if (*p_mytype == 2)
        {
            Expense::addExpenseToVector(*(new Discretionary(start_month, howManyMonths, month, price, definition)));
        }
    }

    input.close();
}

void Expense::getSplittedValues(string line, string delimiter, int *start_month, int *howmanymonths, string *definition, float *price, int *month, int *mytype)
{
    int token_count = 0;

    vector<string> v = split(line, ' ');
    for (auto token : v)
    {
        if (token_count == 0)
        {
            if (!token.compare("*"))
                *mytype = 0;
            if (!token.compare("**"))
                *mytype = 1;
            if (!token.compare("***"))
                *mytype = 2;
        }
        else if (token_count == 1)
        {
            *definition = token;
        }
        else if (token_count == 2)
        {
            *price = stof(token);
        }
        else if (token_count == 3)
        {
            *month = stoi(token);
        }
        else if (token_count == 4)
        {
            *start_month = stoi(token);
        }
        else if (token_count == 5)
        {
            *howmanymonths = stoi(token);
        }
        token_count++;
    }
}

void Expense::writeToFile(ofstream &output)
{
    output << "*"
           << " ";
    output << this->getDefinition() << " ";
    output << this->getPrice() << " ";
    output << month << " ";
}

vector<string> Expense::split(const string &s, char delim)
{
    vector<string> result;
    stringstream ss(s);
    string item;

    while (getline(ss, item, delim))
    {
        result.push_back(item);
    }

    return result;
}