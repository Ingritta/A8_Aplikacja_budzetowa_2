#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <ctime>
#include <sstream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <conio.h>

#include "SupportiveMethods.h"
#include "Income.h"

using namespace std;

class DateManager {

private:

    int dateFromOS;
    string writtenDate;

    bool checkIfIsLeapYear();
    void compareDates();
    int cutYear(string writtenDate);
    int cutMonth(string writtenDate);
    int cutDay(string writtenDate);

public:

    bool checkIfDateIsWrittenProperly(string writtenDate);
    void setWrittenDate(string newWrittenDate);
    const string getDateFromOs();
    string getWrittenDate();
    string addDashes(int date);
    string countLastMonth();
    int cutDashes(string date);
    int checkDetailsOfWrittenDate();
    int countFirstDayOfCurrentMonth();
};

#endif

