//
// Created by Francisco on 2023-11-29.
//

#include <iostream>
#include <filesystem>

using namespace std;
using namespace filesystem;

int printCurrentDirectory(){
    try {
        // Get the current path
        path currentPath = current_path();

        // Iterate over the contents of the current directory
        for (const auto& entry : directory_iterator(currentPath)) {
            // Check if it's a directory or a regular file
            if (is_directory(entry.status())) {
                cout << "<folder>";
            } else {
                cout << "<file>\t";
            }

            // Print the file/folder name
            cout << entry.path().filename() << endl;
        }
    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
        return 1;
    }
}