#include "Expense.h"

void Expense::setExpenseId(int newExpenseId) {
    if (newExpenseId >= 0) {
        this -> expenseId = newExpenseId;
    }
}

void Expense::setUserId(int LOGGED_USER_ID) {
    if (userId >= 0) {
        this -> userId = LOGGED_USER_ID;
    }
}

void Expense::setDate(int newDate) {
    if (date >= 0)
        this -> date = newDate;
}

void Expense::setItem(string newItem) {
    this -> item = newItem;
}

void Expense::setQuota(float newQuota) {
    if (quota >= 0) {
        this -> quota = newQuota;
    }
}

int Expense::getExpenseId() {
    return this -> expenseId;
}

int Expense::getUserId() {
    return this -> userId;
}

int Expense::getDate() {
    return this -> date;
}

string Expense::getItem() {
    return this -> item;
}

float Expense::getQuota() {
    return this -> quota;
}

