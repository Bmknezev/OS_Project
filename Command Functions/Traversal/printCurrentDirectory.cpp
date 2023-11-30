//
// Created by Francisco on 2023-11-29.
//

#include "../functions.h"

using namespace std;
using namespace filesystem;

void printCurrentDirectory(){
    try {
            // this saves the current path to a variable
        path currentPath = current_path();
            // this prints a header message to the user
        cout << "\nContents of the current directory:\n";
            // this prints all the folders and files in the directory

            if (!filesystem::is_empty(currentPath)){
                for (const auto& entry : directory_iterator(currentPath)) {
                    // this denotes whether they're a folder or a file
                    if (is_directory(entry.status())) {
                        cout << "<folder>";
                    } else {
                        cout << "<file>\t";
                    }
                    // this prints the file name
                    cout << entry.path().filename() << std::endl;
                }
            }
            else{
                cout << "\tThis directory is empty" << endl;
            }
    } catch (const exception& e) {
            // this prints an error message
        cerr << "Exception: " << e.what() << std::endl;
    }
}