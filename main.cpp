#include <iostream>
#include "ApplicationManager.h"

using namespace std;

int main() {
    ApplicationManager ApplicationManager ("Users.xml", "Incomes.xml", "Expenses.xml");

    char choice;

    while (true) {
        if (ApplicationManager.checkIfUserIsLogged()) {

            choice = ApplicationManager.selectOptionFromMainMenu();

            switch (choice) {
            case '1':
                ApplicationManager.userRegistration();
                //ApplicationManager.showAllUsers();
                break;
            case '2':
                ApplicationManager.userLogin();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {

            choice = ApplicationManager.selectOptionFromUserMenu();

            switch (choice) {
            case '1':
                ApplicationManager.addDetailsOfIncomeTransaction();
                break;
            case '2':
                ApplicationManager.addDetailsOfExpenseTransaction();
                break;
            case '3':
                ApplicationManager.printCurrentMonthBalance();
                break;
            case '4':
                ApplicationManager.printLastMonthBalance();
                break;
            case '5':
                ApplicationManager.printBalanceForChoosenPeriod();
                break;
            case '6':
                ApplicationManager.changePasswordOfLoggedUser();
                break;
            case '7':
                ApplicationManager.userLogout();
                break;
            }
        }
    }
    return 0;
}


