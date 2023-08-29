#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include "DateManager.h"

using namespace std;

class Income {
    int incomeId;
    int userId;
    int date;
    string item;
    float quota;

public:
    Income (int incomeId = 0, int userId = 0, int date = 0, string item = "", float quota = 0) {
        this -> incomeId = incomeId;
        this -> userId = userId;
        this -> date = date;
        this -> item = item;
        this -> quota = quota;
    }
    int getIncomeId();
    int getUserId();
    int getDate();
    string getItem();
    float getQuota();
    void setIncomeId(int newId);
    void setUserId(int newLoggedUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setQuota(float newQuota);
};

#endif
