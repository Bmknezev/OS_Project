#include "functions.h"


void renameFile( string oldFileName, string newFileName ) {
    cout << "Renaming " << oldFileName << " to " << newFileName << endl;
    rename(oldFileName.c_str(), newFileName.c_str()); // rename file
}
