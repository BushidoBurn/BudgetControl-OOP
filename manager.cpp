#include<iostream>
#include "manager.h"
#include <unistd.h>
#include<stdlib.h>
#include "expense.h"
#include "fixedexpence.h"
#include "discretionary.h"

using std::cout;
using std::cin;


void manage(){
    int isRunning = 1;
    std::string option,fileName,searchTerm,definition;
    int month;
    string price;
    int start_month,howManyMonths,index;

    Expense root=  Expense(0,0,"ROOT");


    while(isRunning){
        index=-9999;
        definition="";
        fileName="";
        searchTerm="";
        month=-1000;
        price="";
        start_month=-9999;
        howManyMonths=-9999;
        printOptions();
        cout<<"Please Enter Your Selection"<<endl;
        cin>>option;
        if(!option.compare("insert"))
        {
            cout<<"Is This A Fixed Expense type Y or n N Please";
            cin>>option;
            if(!option.compare("Y"))
            {
                cout<<"Enter Starting Month"<<endl;
                cin>>start_month;
                cout<<"Enter How Many Months Does It Last"<<endl;
                cin>>howManyMonths;
                cout<<"Enter Price"<<endl;
                cin>>month;
                cout<<"Enter Month"<<endl;
                cin>>price;
                cout<<"Enter Definition"<<endl;
                cin>>definition;


                Expense::addExpenseToVector(*(new FixedExpense(start_month,howManyMonths,month,atof(price.c_str()),definition)));
            }
            else if(!option.compare("N")){
                cout<<"Enter Starting Month"<<endl;
                cin>>start_month;
                cout<<"Enter How Many Months Does It Last"<<endl;
                cin>>howManyMonths;
                cout<<"Enter Price"<<endl;
                cin>>month;
                cout<<"Enter Month"<<endl;
                cin>>price;
                cout<<"Enter Definition"<<endl;
                cin>>definition;

                Expense::addExpenseToVector(*(new Discretionary(start_month,howManyMonths,month,atof(price.c_str()),definition)));
            }
            else
                cout<<"Please Enter Y Or N"<<endl;

        }
        else if(!option.compare("del_all"))
        {
            root.deleteAllExpenses();
        }
        else if(!option.compare("del"))
        {
            cout<<"Please Enter Item Index Number"<<endl;
            cin>>index;
            root.deleteOneExpense(index);
        }
        else if(!option.compare("find"))
        {   cout<<"Please Enter Search Word"<<endl;
            cin>>searchTerm;
            root.findAndList(searchTerm);
        }
        else if(!option.compare("list")){
            root.listAllExpenses();

        }
        else if (!option.compare("sort")){
            root.sortByPrice();
            //root.listAllExpenses();
        }
        else if (!option.compare("write")){
            cout<<"Please Enter File Name"<<endl;
            cin>>fileName;
            root.writeAllToFile(fileName);
        }
        else if(!option.compare("read"))
        {
            cout<<"Please Enter File Name"<<endl;
            cin>>fileName;
            root.readAllFromFile(fileName);
        }
        else if(!option.compare("clear"))
        {
            clearScreen();
        }
    }


}


void printOptions(){
    printf("\n#################################################################################################--Commands--################################################################################################");
    printf("\n#\tinsert=insert\n#\tdel_all=Delete all items from memory\n#\tdel=Delete given item\n#\tfind=find\n#\tlist=list\n#\tsort=sort\n#\twrite=write to file\n#\tread=read from file\n#\tclear=clearscreen\n");
    printf("\n############################################################################################################################################################################################################\n");
    //scanf("%c", action);
    fflush(stdin);

}

void clearScreen()
{
    unsigned int microseconds;

    //usleep(2000000);
    system("clear");
}



