//
// Created by Francisco on 2023-11-29.
//

#include <iostream>
#include <filesystem>

using namespace std;
using namespace filesystem;

bool createFolder(string& folderName) {
    try {
        path currentPath = current_path();
        path newFolderPath = currentPath / folderName;

        if (create_directory(newFolderPath)) {
            cout << "Folder '" << folderName << "' created successfully." << endl;
            return true;
        } else {
            cerr << "Failed to create folder '" << folderName << "'." << endl;
            return false;
        }
    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
        return false;
    }
}