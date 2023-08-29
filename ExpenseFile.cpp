#include "ExpenseFile.h"

string ExpenseFile::getFileName() {
    return NAME_OF_FILE;
}

int ExpenseFile::getLastExpenseId() {
    return lastExpenseId;
}

void ExpenseFile::addExpenseToFile(Expense expense) {

    bool fileExists = xml.Load(NAME_OF_FILE);

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem(NAME_OF_FILE);
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseId", expense.getExpenseId());
    xml.AddElem("UserId", expense.getUserId());
    xml.AddElem("Date", expense.getDate());
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Quota", expense.getQuota());
    xml.Save(NAME_OF_FILE);
    lastExpenseId++;
}

vector <Expense> ExpenseFile::readExpenseTransactionsOfLoggedUserFromFile(int loggedUserId) {
    Expense expense;
    vector <Expense> expenses;

    if (xml.Load(NAME_OF_FILE)) {
        xml.FindElem();
        xml.IntoElem();

        while (xml.FindElem("Expense")) {
            xml.IntoElem();
            xml.FindElem("UserId");
            if (atoi(MCD_2PCSZ(xml.GetData())) == loggedUserId) {
                expense.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
                xml.FindElem("ExpenseId");
                expense.setExpenseId(atoi(MCD_2PCSZ(xml.GetData())));
                xml.FindElem("Date");
                expense.setDate(atoi(MCD_2PCSZ(xml.GetData())));
                xml.FindElem("Item");
                expense.setItem(xml.GetData());
                xml.FindElem("Quota");
                expense.setQuota(SupportiveMethods::convertStringToFloat(MCD_2PCSZ(xml.GetData())));
                xml.OutOfElem();

                expenses.push_back(expense);
            }
        }
    }
    lastExpenseId = expense.getExpenseId();
    return expenses;
}

