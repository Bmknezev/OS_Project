//
// Created by Francisco on 2023-11-29.
//

#include <iostream>
#include <filesystem>

using namespace std;
using namespace filesystem;

bool enterSubdirectory(string& subfolderName){
    try {
            // this saves the current path to a variable
        path currentPath = current_path();
            // this derives the subdirectory path using the current path and the subdirectory name
        path subdirectoryPath = currentPath / subfolderName;

            // this checks if the subdirectory actually exists
        if (is_directory(subdirectoryPath)) {
                // this changes the current path to be the subdirectory
            current_path(subdirectoryPath);
                // this prints a message to indicate that this was successful
            cout << "Changed to subfolder '" << subfolderName << "'." << endl;
            return true;
        } else {
                // this prints a message to indicate that the function was unsuccessful
            cerr << "Subfolder '" << subfolderName << "' does not exist: " << endl;
            return false;
        }
    } catch (const exception& e) {
            // this prints a message to indicate that the function was unsuccessful
        cerr << "Error in enterSubdirectory: " << e.what() << endl;
        return false;
    }
}