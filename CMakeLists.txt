cmake_minimum_required(VERSION 3.21)
project(BudgetControl_OOP)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(BudgetControl_OOP
        colors.h
        discretionary.h
        discretionaryexpense.cpp
        expense.cpp
        expense.h
        fixedexpence.h
        fixedexpense.cpp
        main.cpp
        manager.cpp
        manager.h
        some_globals.h)
