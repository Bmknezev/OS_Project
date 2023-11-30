#include "../functions.h"



void removeText(string fileName) {
    if (testForTxt(fileName)) {
        ofstream out(fileName);
        out.close();
    }

}
