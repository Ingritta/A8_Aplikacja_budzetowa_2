#ifndef XMLTFILE_H
#define XMLTFILE_H
#include <iostream>

#include "Markup.h"

using namespace std;

class XmlFile {


protected:

    const string NAME_OF_FILE;

public:
    XmlFile(string nameOfFile) : NAME_OF_FILE(nameOfFile) {}
    string getFileName();
};

#endif
