#include "IncomeFile.h"
#include "TransactionManager.h"
#include "SupportiveMethods.h"

string IncomeFile::getFileName() {
    return NAME_OF_FILE;
}

int IncomeFile::getLastIncomeId() {
    return lastIncomeId;
}

void IncomeFile::addTransactionToFile(Income income) {

    bool fileExists = xml.Load(NAME_OF_FILE);

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem(NAME_OF_FILE);
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", income.getIncomeId());
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("Date", income.getDate());
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Quota", income.getQuota());
    xml.Save(NAME_OF_FILE);
    lastIncomeId++;
}

vector <Income> IncomeFile::readIncomeTransactionsOfLoggedUserFromFile(int loggedUserId) {
    Income income;
    vector <Income> incomes;

    if (xml.Load(NAME_OF_FILE)) {
        xml.FindElem();
        xml.IntoElem();

        while (xml.FindElem("Income")) {
            xml.IntoElem();
            xml.FindElem("UserId");
            if (atoi(MCD_2PCSZ(xml.GetData())) == loggedUserId) {
                income.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
                xml.FindElem("IncomeId");
                income.setIncomeId(atoi(MCD_2PCSZ(xml.GetData())));
                xml.FindElem("Date");
                income.setDate(atoi(MCD_2PCSZ(xml.GetData())));
                xml.FindElem("Item");
                income.setItem(xml.GetData());
                xml.FindElem("Quota");
                income.setQuota(SupportiveMethods::convertStringToFloat(MCD_2PCSZ(xml.GetData())));
                xml.OutOfElem();

                incomes.push_back(income);
            }
        }
    }
    lastIncomeId = income.getIncomeId();
    return incomes;
}
