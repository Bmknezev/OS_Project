#include "functions.h"

bool testForTxt(string fileName) {
    return (fileName.find(".txt") != string::npos);
}

