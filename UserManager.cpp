#include "UserManager.h"

char UserManager::selectOptionFromMainMenu() {
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = SupportiveMethods::loadChar();

    return choice;
}

void UserManager::userRegistration() {
    User user = giveDataOfNewUser();

    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserManager::giveDataOfNewUser() {
    User user;

    user.setId(getNewUserId());
    string login;

    do {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    } while (checkIfLoginExists(user.getLogin()) == true);

    string password;
    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);
    return user;
}

int UserManager::getNewUserId() {

    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::checkIfLoginExists(string login) {
    for (size_t i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::userLogin() {
    User user;
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = SupportiveMethods::getLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            for (int numberOfTests = 3; numberOfTests > 0; numberOfTests--) {
                cout << "Podaj password. Pozostalo prob: " << numberOfTests << ": ";
                password = SupportiveMethods::getLine();

                if (itr -> getPassword() == password) {
                    loggedUserId = itr -> getId();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");

                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

void UserManager::changePasswordOfLoggedUser() {
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = SupportiveMethods::getLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if (itr -> getId() == loggedUserId) {
            itr -> setPassword (newPassword);

            fileWithUsers.changePasswordInFile(loggedUserId,newPassword);

            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
}

int UserManager::getLoggedUserId() {
    return loggedUserId;
}

bool UserManager::checkIfUserIsLogged () {
    if (loggedUserId == 0) {
        return true;
    } else {
        return false;
    }
}

void UserManager::userLogout() {
    loggedUserId = 0;
}

char UserManager::selectOptionFromUserMenu() {
    return 0;
}
/*
void UserManager::showAllUsers() {
    for (size_t i = 0; i < users.size(); i++) {
        cout << users[i].getId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
        system("pause");
    }
}
*/

