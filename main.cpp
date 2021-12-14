
/*******************************************************************************************************************

  ____            _            _               ____   ____  _____
 |  _ \          | |          | |             / __ \ / __ \|  __ \
 | |_) |_   _  __| | __ _  ___| |_   ______  | |  | | |  | | |__) |
 |  _ <| | | |/ _` |/ _` |/ _ | __| |______| | |  | | |  | |  ___/
 | |_) | |_| | (_| | (_| |  __| |_           | |__| | |__| | |
 |____/ \__,_|\__,_|\__, |\___|\__|           \____/ \____/|_|
                     __/ |
                    |___/
*********************************************************************************************************************/
/*******************************************************************************************************************
*   MIT License
*
*   Copyright (c) 2021
*   This program is written for managing monthly expences and budget
*   Written In C++ Language Using OOP Principles
*   Classes: Expense,FixedExpense,Discretionary
*   #################################################################################################--Commands--################################################################################################
#	insert=insert
#	del_all=Delete all items from memory
#	del=Delete given item
#	find=find
#	list=list
#	sort=sort
#	write=write to file
#	read=read from file
#	clear=clearscreen

############################################################################################################################################################################################################
*   Author: Burak Nebioglu,Marcel Shabani,Nitesh Bhosale
***********************************************************************************************************************/


#include <iostream>
#include "expense.h"
#include "fixedexpence.h"
#include "discretionary.h"
#include "some_globals.h"
#include <string>
#include "manager.h"

extern vector<int> found_expense_index_vector;

int main()
{

    manage();

    return 0;
}