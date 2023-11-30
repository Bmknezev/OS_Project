//
// Created by Francisco on 2023-11-29.
//

#include "../functions.h"

using namespace std;
using namespace filesystem;

bool createFolder(string& folderName) {
    try {
            // this saves the current path to a variable
        path currentPath = current_path();
            // this derives the new folders path using the current path and the folders name
        path newFolderPath = currentPath / folderName;

            // this tries to create the folder
        if (create_directory(newFolderPath)) {
                // this prints a message indicating the function was sucessful
            cout << "Folder '" << folderName << "' created successfully." << endl;
            return true;
        } else {
                // this prints a message to indicate that the function was unsuccessful
            cerr << "Failed to create folder '" << folderName << "'." << endl;
            return false;
        }
    } catch (const exception& e) {
            // this prints a message to indicate that the function was unsuccessful
        cerr << "Exception: " << e.what() << endl;
        return false;
    }
}