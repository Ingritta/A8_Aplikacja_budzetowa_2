#ifndef APPLICATIONMANAGER_H
#define APPLICATIONMANAGER_H

#include <iostream>
#include "UserManager.h"
#include "User.h"
#include "XmlFile.h"
#include "TransactionManager.h"

using namespace std;

class ApplicationManager {
    UserManager userManager;
    TransactionManager *transactionManager;
    const string NAME_OF_FILE_WITH_TRANSACTIONS;
    const string NAME_OF_FILE_WITH_EXPENSES;

public:
    ApplicationManager(string nameOfFileWithUsers, string nameOfFileWithTransactions, string nameOfFileWithExpenses) : userManager(nameOfFileWithUsers), NAME_OF_FILE_WITH_TRANSACTIONS (nameOfFileWithTransactions), NAME_OF_FILE_WITH_EXPENSES (nameOfFileWithExpenses) {
        transactionManager = NULL;
    };
    ~ApplicationManager() {
        delete transactionManager;
        transactionManager = NULL;
    };
    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();
    int getLoggedUserId();
    bool checkIfUserIsLogged();
    void userRegistration();
    void changePasswordOfLoggedUser();
    void userLogout();
    void userLogin();
    void addDetailsOfIncomeTransaction();
    void addDetailsOfExpenseTransaction();
    void printCurrentMonthBalance();
    void printLastMonthBalance();
    void printBalanceForChoosenPeriod();
};

//void showAllUsers();

#endif

