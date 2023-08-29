#ifndef EXPENSEFILE_H
#define EXPENSEFILE_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <string>

#include "SupportiveMethods.h"
#include "Expense.h"
#include "XmlFile.h"

using namespace std;

class ExpenseFile {

    CMarkup xml;

protected:

    const string NAME_OF_FILE;
    int lastExpenseId;

    string getFileName();
    bool checkIfFileIsEmpty();
    int getLastExpenseId();
    Expense getDataOfTransaction(int loggedUserId);

public:
    ExpenseFile(string nameOfFile) : NAME_OF_FILE(nameOfFile) {
        lastExpenseId = 0;
    }

    void addExpenseToFile(Expense expense);
    vector <Expense> readExpenseTransactionsOfLoggedUserFromFile(int loggedUserId);
};

#endif
