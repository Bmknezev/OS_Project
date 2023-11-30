#include "../functions.h"



void readFile(string fileName) {
    if ( !testForTxt(fileName) ) { return; }
    ifstream readFile(fileName);
    string data;

    ostringstream sstr;
    sstr << readFile.rdbuf();
    data = sstr.str();
    //readFile >> data;
    int strLen = data.length();
    int numberOfLinesPerPage;
    cout << "How many lines per page? : ";
    cin >> numberOfLinesPerPage;
    int counter = 0;
    for (int i = 0; i < strLen; i++) {
        if ( data[i] == '\n' ) {
            counter++;
        }
    }
    int countLines = 0;
    for (int i = 0; i < strLen; i++) {
        cout << data[i];
        if (data[i] == '\n') {
            countLines++;
        }
        if (countLines >= numberOfLinesPerPage) {
            string temp;
            cin.ignore();
            countLines = 0;
        }

    }
}
