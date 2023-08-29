#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "User.h"
#include "XmlFile.h"
#include "FileWithUsers.h"
#include "DateManager.h"//?

using namespace std;

class UserManager {
    int loggedUserId;
    User user;
    vector <User> users;
    FileWithUsers fileWithUsers;

    User giveDataOfNewUser();
    int getNewUserId();
    bool checkIfLoginExists(string login);
    void saveAllUsersInFile();
    char selectOptionFromUserMenu();

public:
    UserManager(string nameOfFileWithUsers) : fileWithUsers(nameOfFileWithUsers) {
        loggedUserId = 0;
        users = fileWithUsers.readUsersFromFile();
    };
    bool checkIfUserIsLogged ();
    void userRegistration();
    void userLogin();
    void userLogout();
    void changePasswordOfLoggedUser();
    char selectOptionFromMainMenu();
    int getLoggedUserId();
};

#endif

//void showAllUsers();
