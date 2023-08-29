#include "Income.h"

void Income::setIncomeId(int newIncomeId) {
    if (newIncomeId >= 0) {
        this -> incomeId = newIncomeId;
    }
}

void Income::setUserId(int LOGGED_USER_ID) {
    if (userId >= 0) {
        this -> userId = LOGGED_USER_ID;
    }
}

void Income::setDate(int newDate) {
    if (date >= 0)
        this -> date = newDate;
}

void Income::setItem(string newItem) {
    this -> item = newItem;
}

void Income::setQuota(float newQuota) {
    if (quota >= 0) {
        this -> quota = newQuota;
    }
}

int Income::getIncomeId() {
    return this -> incomeId;
}

int Income::getUserId() {
    return this -> userId;
}

int Income::getDate() {
    return this -> date;
}

string Income::getItem() {
    return this -> item;
}

float Income::getQuota() {
    return this -> quota;
}

