#ifndef SUPPORTIVEMETHODS_H
#define SUPPORTIVEMETHODS_H

#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <iomanip>


using namespace std;

class SupportiveMethods {

public:
    static string convertIntToString(int number);
    static int convertStringToInt(string number);
    static string getNumber(string text, int signPosition);
    static string getLine();
    static string replaceFirstLetterForCapitalRestForSmall(string text);
    static char loadChar();
    static int loadInteger();
    static float convertStringToFloat(string number);
    static int cutDashes(string date);
};

#endif
