#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <string>
#include <iomanip>
#include <cctype>

#include <cstdlib>
#include <string>
#include <algorithm>
#include <conio.h>

#include "IncomeFile.h"
#include "ExpenseFile.h"
#include "Income.h"
#include "Expense.h"
#include "SupportiveMethods.h"
#include "DateManager.h"

using namespace std;

class TransactionManager {

    const string NAME_OF_FILE;
    IncomeFile incomeFile;
    ExpenseFile expenseFile;
    const int LOGGED_USER_ID;
    vector <Income> incomes;
    vector <Expense> expenses;
    int amountOfIncomesTransactions;
    int amountOfExpensesTransactions;
    int choosenBeginDate;
    int endDate;
    float expenseBalance;
    float incomeBalance;

    Income giveDataOfNewIncomeTransaction();
    Expense giveDataOfNewExpenseTransaction();
    int getNewExpenseId();
    int getNewIncomeId();
    void readTransactionsOfLoggedUserFromFile();
    void printDetailsOfIncomeTransaction(Income income);
    void printDetailsOfExpenseTransaction(Expense expense);
    int askAboutDate();
    bool checkWrittenQuota(string writtenQuota);
    float correctQuota();
    void countIncomesBalance(vector <Income> incomes);
    void countExpensesBalance(vector <Expense> expenses);
    void countFirstDayOfCurrentMonth();
    void printBalance();

public:
    TransactionManager(string nameOfFileWithIncomes, string nameOfFileWithExpenses, int loggedUserId) : incomeFile(nameOfFileWithIncomes), expenseFile(nameOfFileWithExpenses), LOGGED_USER_ID(loggedUserId) {
        loggedUserId = 0;
        incomes = incomeFile.readIncomeTransactionsOfLoggedUserFromFile(LOGGED_USER_ID);
        expenses = expenseFile.readExpenseTransactionsOfLoggedUserFromFile(LOGGED_USER_ID);
        amountOfIncomesTransactions = 0;
        amountOfExpensesTransactions = 0;
    };

    DateManager dateManager;
    char selectOptionFromUserMenu();
    void addDetailsOfIncomeTransaction();
    void addDetailsOfExpenseTransaction();
    void printCurrentMonthBalance();
    void printLastMonthBalance();
    void printBalanceForChoosenPeriod();
};

#endif
