#include "DateManager.h"

void DateManager::setWrittenDate(string newWrittenDate) {
    writtenDate = newWrittenDate;
}

string DateManager::getWrittenDate() {
    return writtenDate;
}

const string DateManager::getDateFromOs() {
    string date = "";
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[11];
    tstruct = *localtime(&now);

    strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
    date = buf;

    return buf;
}

bool DateManager::checkIfDateIsWrittenProperly(string writtenDate) {
    if (writtenDate.length() != 10) {
        cout << endl << "Niepoprawna ilosc znakow. Wpisz date w formacie YYYY-MM-DD!" << endl;
        return false;
    }
    for (size_t signPosition = 0; signPosition <= writtenDate.length(); signPosition++) {
        if (writtenDate[signPosition] == '-') {
            if(signPosition == 4 || signPosition == 7) {
                continue;
            } else {
                cout << endl << "Niepoprawny zapis daty. Wpisz date w formacie YYYY-MM-DD!" << endl;
                return false;
            }
        }
    }
    return true;
}

int DateManager::checkDetailsOfWrittenDate() {
    if (SupportiveMethods::cutDashes(getDateFromOs()) < SupportiveMethods::cutDashes(writtenDate)) {
        cout << endl << "Wpisany rok jest nieprawidlowy - data trasakcji jest pozniejsza od daty dzisiejszej. Wpisz poprawny rok!" << endl;
        return false;
    } else if (cutMonth(writtenDate) > 12) {
        cout << endl << "Wpisany miesiac jest nieprawidlowy. Wpisz poprawny miesiac!" << endl;
        return false;
    } else if (checkIfIsLeapYear() && cutMonth(writtenDate) == 2 && cutDay(writtenDate) > 29) {
        cout << endl << "Wpisany dzien jest nieprawidlowy. Wpisz poprawny dzien!" << endl;
        return false;
    } else if (!checkIfIsLeapYear() && cutMonth(writtenDate) == 2 && cutDay(writtenDate) > 28) {
        cout << endl << "Wpisany dzien jest nieprawidlowy. Wpisz poprawny dzien!" << endl;
        return false;
    } else if ((cutMonth(writtenDate) == 4 || cutMonth(writtenDate) == 6 || cutMonth(writtenDate) == 9 || cutMonth(writtenDate) == 11) && cutDay(writtenDate) > 30) {
        cout << endl << "Wpisany dzien jest nieprawidlowy. Wpisz poprawny dzien!" << endl;
        return false;
    } else if (cutDay(writtenDate) > 31) {
        cout << endl << "Wpisany dzien jest nieprawidlowy. Wpisz poprawny dzien!" << endl;
        return false;
    }
    return true;
}

bool DateManager::checkIfIsLeapYear() {
    if (cutYear(writtenDate)%4 == 0 && (cutYear(writtenDate)%100 != 0 || cutYear(writtenDate)%400 == 0)) {
        return true;
    } else {
        return false;
    }
}

int DateManager::countFirstDayOfCurrentMonth() {
    int searchedDate = SupportiveMethods::cutDashes(getDateFromOs()) - cutDay(getDateFromOs()) + 1;
    return searchedDate;
}

string DateManager::countLastMonth() {
    string searchedDate = "";
    string year = SupportiveMethods::convertIntToString(cutYear(getDateFromOs()));

    int lastMonth = cutMonth(getDateFromOs()) - 1;
    string month = SupportiveMethods::convertIntToString(lastMonth);

    if (month.length() > 1) {
        searchedDate = year + month + "01";
    } else {
        searchedDate = year + "0" + month + "01";
    }
    if (lastMonth < 2) {
        year = SupportiveMethods::convertIntToString((cutYear(getDateFromOs()) - 1));
        searchedDate = year + "12" + "01";
    }
    return searchedDate;
}

int DateManager::cutYear(string date) {
    int i = 0;
    string year = "";
    while (isdigit(date[i])) {
        year += date[i];
        i++;
    }
    int yearInt = stoi(year);
    return  yearInt;
}

int DateManager::cutMonth(string date) {
    int i = 5;
    string month = "";
    while (isdigit(date[i])) {
        month += date[i];
        i++;
    }
    int monthInt = stoi(month);
    return monthInt;
}

int DateManager::cutDay(string date) {
    int i = 8;
    string day = "";
    while (isdigit(date[i])) {
        day += date[i];
        i++;
    }
    int dayInt = stoi(day);
    return dayInt;
}

string DateManager::addDashes(int date) {
    string dateWithDashes = SupportiveMethods::convertIntToString(date);
    string year, month, day;

    for (int i = 0; i < 4; i++) {
        year += dateWithDashes[i];
    }
    for (int i = 4; i < 6; i++) {
        month += dateWithDashes[i];
    }
    for (int i = 6; i < 8; i++) {
        day += dateWithDashes[i];
    }

    dateWithDashes = year + '-' + month + '-' + day;

    return dateWithDashes;
}
