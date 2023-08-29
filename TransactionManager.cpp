#include "TransactionManager.h"

int TransactionManager::getNewIncomeId() {

    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getIncomeId() + 1;
}

int TransactionManager::getNewExpenseId() {

    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().getExpenseId() + 1;
}

char TransactionManager::selectOptionFromUserMenu() {
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj wplyw" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";

    choice = SupportiveMethods::loadChar();

    return choice;
}

void TransactionManager::addDetailsOfIncomeTransaction() {
    Income income;
    system("cls");
    cout << " >>> DODAWANIE NOWEJ TRANSAKCJI <<<" << endl << endl;
    income = giveDataOfNewIncomeTransaction();
    incomes.push_back(income);
    incomeFile.addTransactionToFile(income);
}

void TransactionManager::addDetailsOfExpenseTransaction() {
    Expense expense;
    system("cls");
    cout << " >>> DODAWANIE NOWEJ TRANSAKCJI <<<" << endl << endl;
    expense = giveDataOfNewExpenseTransaction();
    expenses.push_back(expense);
    expenseFile.addExpenseToFile(expense);
}

Income TransactionManager::giveDataOfNewIncomeTransaction() {
    Income income;

    string writtenQuota = "";

    income.setIncomeId(getNewIncomeId());
    income.setUserId(LOGGED_USER_ID);
    income.setDate(askAboutDate());

    cout << endl << "Podaj zrodlo wplywu: ";
    income.setItem(SupportiveMethods::getLine());

    income.setQuota(correctQuota());

    return income;
}

Expense TransactionManager::giveDataOfNewExpenseTransaction() {
    Expense expense;
    string writtenQuota = "";

    expense.setExpenseId(getNewExpenseId());
    expense.setUserId(LOGGED_USER_ID);
    expense.setDate(askAboutDate());

    cout << endl << "Przeznaczenie: ";
    expense.setItem(SupportiveMethods::getLine());

    expense.setQuota(correctQuota());

    return expense;
}

float TransactionManager::correctQuota() {
    string writtenQuota = "";
    float quota = 0;
    do {
        cout << endl << "Podaj kwote: ";
        writtenQuota = SupportiveMethods::getLine();
    } while (!checkWrittenQuota(writtenQuota));

    quota = SupportiveMethods::convertStringToFloat(writtenQuota);

    return quota;
}

bool TransactionManager::checkWrittenQuota(string writtenQuota) {
    int k = 0;
    if (writtenQuota.length() == 0) {
        return false;
    }
    size_t position = writtenQuota.find(',');
    for (unsigned int i = 0; i < writtenQuota.length(); i++) {
        if (writtenQuota[i] == ',') {
            writtenQuota.replace(position, 1, ".");
            k++;

        } else if(!isdigit(writtenQuota[i]) && writtenQuota[i] != '.') {
            cout << endl << "Wpisano nieprawidlowa wartosc!" << endl;
            return false;

        } else if (writtenQuota[i] == '.') {
            k++;

        } else if (k > 1) {
            cout << endl << "Wpisano nieprawidlowa wartosc!" << endl;
            return false;
        }
    }
    return  true;
}

void TransactionManager::printDetailsOfIncomeTransaction(Income income) {
    cout << endl << "Id transakcji:                " << income.getIncomeId() << endl;
    cout << "Id uzytkownika:                       " << income.getUserId() << endl;
    cout << "Data transakcji:                      " << dateManager.addDashes(income.getDate()) << endl;
    cout << "Zrodlo:                               " << income.getItem() << endl;
    cout << "Kwota:                                " << setprecision(2) << fixed << income.getQuota() << endl;
}

void TransactionManager::printDetailsOfExpenseTransaction(Expense expense) {
    cout << endl << "Id transakcji:                " << expense.getExpenseId() << endl;
    cout << "Id uzytkownika:                       " << expense.getUserId() << endl;
    cout << "Data transakcji:                      " << dateManager.addDashes(expense.getDate()) << endl;
    cout << "Przeznaczenie:                        " << expense.getItem() << endl;
    cout << "Kwota:                                " << setprecision(2) << fixed << expense.getQuota() << endl;
}

int TransactionManager::askAboutDate() {
    int dateOfTransaction = 0;
    string date = "";
    cout << "Jezeli chcesz wpisac date inna niz dzisiejsza wpisz 't', jesli nie wcisnij dowolny klawisz: ";
    if(SupportiveMethods::loadChar() == 't') {
        do {
            cout << endl << "Podaj date: ";
            dateManager.setWrittenDate(SupportiveMethods::getLine());
            date = dateManager.getWrittenDate();
        } while (!dateManager.checkIfDateIsWrittenProperly(date) || !dateManager.checkDetailsOfWrittenDate());
        dateOfTransaction = SupportiveMethods::cutDashes(date);
    } else {
        dateOfTransaction = SupportiveMethods::cutDashes(dateManager.getDateFromOs());
        cout << endl << "Data transakcji: " << dateManager.getDateFromOs() << endl;
    }
    return dateOfTransaction;
}

void TransactionManager::printCurrentMonthBalance() {

    choosenBeginDate = dateManager.countFirstDayOfCurrentMonth();
    endDate = SupportiveMethods::cutDashes(dateManager.getDateFromOs());

    countIncomesBalance(incomes);

    choosenBeginDate = dateManager.countFirstDayOfCurrentMonth();
    countExpensesBalance(expenses);

    printBalance();
}

void TransactionManager::printLastMonthBalance() {

    choosenBeginDate = SupportiveMethods::convertStringToInt(dateManager.countLastMonth());
    endDate = dateManager.countFirstDayOfCurrentMonth() - 1;

    countIncomesBalance(incomes);

    choosenBeginDate = SupportiveMethods::convertStringToInt(dateManager.countLastMonth());
    countExpensesBalance(expenses);

    printBalance();
}

void TransactionManager::printBalanceForChoosenPeriod() {

    cout << endl << "Podaj date poczatkowa: " << endl;
    int beginDate = askAboutDate();
    choosenBeginDate = beginDate;

    cout << endl << "Podaj date koncowa: " << endl;
    endDate = askAboutDate();

    countIncomesBalance(incomes);

    choosenBeginDate = beginDate;
    countExpensesBalance(expenses);

    printBalance();
}

void TransactionManager::countIncomesBalance(vector <Income> incomes) {
    incomeBalance = 0;
    system("cls");
    if(incomes.empty()) {
        cout << "--------------------------------------------------" << endl;
        cout << "               >> BRAK TRANSAKCJI <<              " << endl;
        cout << "--------------------------------------------------" << endl;
    } else {
        cout << "--------------------------------------------------" << endl;
        cout << "                    >> WPLYWY <<" << endl;
        cout << "--------------------------------------------------" << endl;
        while(choosenBeginDate <= endDate) {
            for (vector <Income>::iterator  itr = incomes.begin(); itr != incomes.end();  itr++ ) {
                if (itr -> getDate() == choosenBeginDate) {
                    printDetailsOfIncomeTransaction(*itr);
                    incomeBalance += itr -> getQuota();
                    amountOfIncomesTransactions++;
                }
            }
            choosenBeginDate++;
        }
    }
}

void TransactionManager::countExpensesBalance(vector <Expense> expenses) {
    expenseBalance = 0;
    if(expenses.empty()) {
        cout << "--------------------------------------------------" << endl;
        cout << "               >> BRAK TRANSAKCJI <<              " << endl;
        cout << "--------------------------------------------------" << endl;
    } else {
        cout << "--------------------------------------------------" << endl;
        cout << "                   >> WYDATKI <<" << endl;
        cout << "--------------------------------------------------" << endl;
        while(choosenBeginDate <= endDate) {
            for (vector <Expense>::iterator  itr = expenses.begin(); itr != expenses.end(); itr++) {
                if (itr -> getDate() == choosenBeginDate) {
                    printDetailsOfExpenseTransaction(*itr);
                    expenseBalance += itr -> getQuota();
                    amountOfExpensesTransactions++;
                }
            }
            choosenBeginDate++;
        }
    }
}

void TransactionManager::printBalance() {
    float balance = incomeBalance - expenseBalance;
    if (amountOfIncomesTransactions == 0) {
        cout << "--------------------------------------------------" << endl;
        cout << ">> Nie odnotowano wplywow w wybranym okresie <<" << endl;
    } else {
        cout << "--------------------------------------------------" << endl;
        cout << setprecision(2) << "Suma wplywow wynosi: " << fixed << incomeBalance << endl;
        cout << "--------------------------------------------------" << endl;
    }
    if (amountOfExpensesTransactions == 0) {
        cout << "--------------------------------------------------" << endl;
        cout << ">> Nie odnotowano wydatkow w wybranym okresie <<" << endl;
    } else {
        cout << "--------------------------------------------------" << endl;
        cout << setprecision(2) << "Suma wydatkow wynosi: " << fixed << expenseBalance << endl;
        cout << "--------------------------------------------------" << endl;
    }
    cout << "--------------------------------------------------" << endl;
    cout << setprecision(2) << "Bilans wynosi: " << fixed << balance << endl;
    cout << "--------------------------------------------------" << endl;
    system ("pause");
}

