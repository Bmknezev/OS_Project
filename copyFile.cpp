#include "functions.h"



void copyFile(string oldFile, string newFile) {
    if (!testForTxt(oldFile)) { return; }
    ifstream readFile(oldFile);
    string data;

    ostringstream sstr;
    sstr << readFile.rdbuf();
    data = sstr.str();

    ofstream writeFile(newFile);
    writeFile << data;
}
