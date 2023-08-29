#include "ApplicationManager.h"

void ApplicationManager::userRegistration() {
    userManager.userRegistration();
}

void ApplicationManager::userLogin() {
    userManager.userLogin();
    if (userManager.checkIfUserIsLogged () == false) {
        transactionManager = new TransactionManager(NAME_OF_FILE_WITH_TRANSACTIONS, NAME_OF_FILE_WITH_EXPENSES, userManager.getLoggedUserId());
    }
}

void ApplicationManager::changePasswordOfLoggedUser() {
    userManager.changePasswordOfLoggedUser();
}

void ApplicationManager::userLogout() {
    userManager.userLogout();
    delete transactionManager;
    transactionManager = NULL;
}

char ApplicationManager::selectOptionFromMainMenu() {
    return userManager.selectOptionFromMainMenu();
}

char ApplicationManager::selectOptionFromUserMenu() {
    return transactionManager->selectOptionFromUserMenu();
}

bool ApplicationManager::checkIfUserIsLogged () {
    return userManager.checkIfUserIsLogged ();
}

void ApplicationManager::addDetailsOfIncomeTransaction() {
    transactionManager -> addDetailsOfIncomeTransaction();
}

void ApplicationManager::addDetailsOfExpenseTransaction() {
    transactionManager -> addDetailsOfExpenseTransaction();
}

void ApplicationManager::printCurrentMonthBalance() {
    transactionManager -> printCurrentMonthBalance();
}

void ApplicationManager::printLastMonthBalance() {
    transactionManager -> printLastMonthBalance();
}

void ApplicationManager::printBalanceForChoosenPeriod() {
    transactionManager->printBalanceForChoosenPeriod();
}

/*
void ApplicationManager::showAllUsers() {
    userManager.showAllUsers();
}
*/
