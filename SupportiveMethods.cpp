#include "SupportiveMethods.h"

string SupportiveMethods::convertIntToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int SupportiveMethods::convertStringToInt(string number) {
    int integer;
    istringstream iss(number);
    iss >> integer;

    return integer;
}

float SupportiveMethods::convertStringToFloat(string number) {
    float floatNumber = stof(number);

    return floatNumber;
}

string SupportiveMethods::getNumber(string text, int signPosition) {
    string number = "";
    while(isdigit(text[signPosition]) == true) {
        number += text[signPosition];
        signPosition ++;
    }
    return number;
}

string SupportiveMethods::getLine() {
    string entrance = "";
    getline(cin, entrance);
    return entrance;
}

string SupportiveMethods::replaceFirstLetterForCapitalRestForSmall(string text) {
    if (!text.empty()) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

char SupportiveMethods::loadChar() {
    string entrance = "";
    char sign  = {0};

    while (true) {
        getline(cin, entrance);

        if (entrance.length() == 1) {
            sign = entrance[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return sign;
}

int SupportiveMethods::loadInteger() {
    string entrance = "";
    int number = 0;

    while (true) {
        getline(cin, entrance);

        stringstream myStream(entrance);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}

int SupportiveMethods::cutDashes(string date) {
    date = date.erase(4,1);
    date.erase(6,1);
    int dateInt = (atoi(date.c_str()));

    return dateInt;
}

