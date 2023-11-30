#include "functions.h"

void createFile(string fileName ) {
    // Create File
    if ( fileName.find('.') != string::npos ) {
        ofstream MyFile(fileName);
        cout << fileName << " Created!" << endl;
    }
    else {
        cout << "Error: file does not have an extension" << endl;
    }
}


