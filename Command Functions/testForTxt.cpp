#include "functions.h"

bool testForTxt(string fileName) {
    if (fileName.find(".txt") != string::npos){
        return true;
    } else {
        cout<< "Error: file must be a .txt file" << endl;
        return false;
    }
}

