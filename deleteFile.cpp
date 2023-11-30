#include "functions.h"

void deleteFile( string fileName ) {
    cout << "Deleting " << fileName << endl;
    remove(fileName.c_str()); // delete file
}