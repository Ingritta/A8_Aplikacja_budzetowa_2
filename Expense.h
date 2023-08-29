#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include "DateManager.h"

using namespace std;

class Expense {
    int expenseId;
    int userId;
    int date;
    string item;
    float quota;

public:
    Expense (int expenseId = 0, int userId = 0, int date = 0, string item = "", float quota = 0) {
        this -> expenseId = expenseId;
        this -> userId = userId;
        this -> date = date;
        this -> item = item;
        this -> quota = quota;
    }
    int getExpenseId();
    int getUserId();
    int getDate();
    string getItem();
    float getQuota();
    void setExpenseId(int newId);
    void setUserId(int newLoggedUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setQuota(float newQuota);
};

#endif
