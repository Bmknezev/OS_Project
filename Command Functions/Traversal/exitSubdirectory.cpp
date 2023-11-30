//
// Created by Francisco on 2023-11-29.
//

#include <iostream>
#include <filesystem>

using namespace std;
using namespace filesystem;

bool exitSubdirectory(string root) {
    try {
            // this saves the current path to a variable
        path currentPath = current_path();
            // this derives the parent path using the current path
        path parentPath = currentPath.parent_path();

            // this checks if the parent path is different from the current path
        if (parentPath != currentPath && currentPath != root) {
                // this changes the current path to be the parent path
            current_path(parentPath);
                // this prints a message to indicate that this was successful
            cout << "Exited from subdirectory." << endl;
            return true;
        } else {
                // this prints a message to indicate that the function was unsuccessful
            cerr << "Already in the root directory." << endl;
            return false;
        }
    } catch (const exception& e) {
            // this prints a message to indicate that the function was unsuccessful
        cerr << "Error in exitSubdirectory: " << e.what() << endl;
        return false;
    }
}