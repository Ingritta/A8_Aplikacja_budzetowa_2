#include "FileWithUsers.h"

vector <User> FileWithUsers::readUsersFromFile() {

    User user;
    vector <User> users;

    if (xml.Load(NAME_OF_FILE)) {
        xml.FindElem();
        xml.IntoElem();

        while (xml.FindElem("User")) {
            xml.IntoElem();
            xml.FindElem("UserId");
            user.setId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem("Login");
            user.setLogin(xml.GetData());
            xml.FindElem("Password");
            user.setPassword(xml.GetData());
            xml.OutOfElem();

            users.push_back(user);
        }
    }
    return users;
}

void FileWithUsers::addUserToFile (User user) {

    bool fileExists = xml.Load(NAME_OF_FILE);

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem(NAME_OF_FILE);
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.Save(NAME_OF_FILE);
}

void FileWithUsers::changePasswordInFile(int loggedUserId, string newPassword) {

    if (xml.Load(NAME_OF_FILE)) {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("User")) {
            xml.IntoElem();
            xml.FindElem("UserId");
            if (atoi(MCD_2PCSZ(xml.GetData())) == loggedUserId) {
                xml.FindElem("Password");
                xml.RemoveNode();
                xml.AddElem("Password", newPassword);
            } else {
                xml.OutOfElem();
            }
        }
    }
    xml.Save(NAME_OF_FILE);
}
