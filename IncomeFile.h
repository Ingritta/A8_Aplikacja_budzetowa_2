#ifndef INCOMEFILE_H
#define INCOMEFILE_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <string>

#include "SupportiveMethods.h"
#include "Income.h"
#include "XmlFile.h"

using namespace std;

class IncomeFile {

    CMarkup xml;

protected:

    const string NAME_OF_FILE;
    int lastIncomeId;

    string getFileName();
    int getLastIncomeId();
    Income getDataOfTransaction(int loggedUserId);

public:
    IncomeFile(string nameOfFile) : NAME_OF_FILE(nameOfFile) {
        lastIncomeId = 0;
    }

    void addTransactionToFile(Income incomes);
    vector <Income> readIncomeTransactionsOfLoggedUserFromFile(int loggedUserId);
};

#endif
