#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "User.h"
#include "SupportiveMethods.h"
#include "XmlFile.h"
#include "Markup.h"

using namespace std;

class FileWithUsers : public XmlFile {

    CMarkup xml;

public:
    FileWithUsers(string nameOfFile) : XmlFile(nameOfFile) {};
    void addUserToFile(User user);
    vector <User> readUsersFromFile();
    void changePasswordInFile(int loggedUserId, string newPassword);
};

#endif
