//
// Created by Francisco on 2023-11-29.
//

#include "../functions.h"

using namespace std;
using namespace filesystem;

bool deleteFolder( string folderName, path folderPath){
    // this deletes the folder and everything in it
    remove_all(folderPath);
    // this prints a success message
    cout << "Folder '" << folderName << "' deleted successfully." << endl;
    return true;
}

bool deleteFolder(string& folderName) {
    try {
            // this saves the current path to a variable
        path currentPath = current_path();
            // this derives the folders path using the current path and the folders name
        path folderPath = currentPath / folderName;

            // this checks if the folder exists
        if (exists(folderPath) && is_directory(folderPath)) {
                // this checks if the folder is not empty
            if (!filesystem::is_empty(folderPath)){
                    // this creates a string to hold the confirmation from the user
                string confirmation = "";
                    // this prints a message asking if the user is sure they want to delete the folder
                cout << "The folder '" << folderName << "' is not empty, Do you still want to delete it?"
                << endl << "\tYes, delete the folder: yes" << endl << "\tNo, cancel deletion: no" << endl;
                    // this gets the users answer
                getline(cin, confirmation);

                    // this checks if the user said yes
                if (confirmation == "yes" || confirmation == "Yes"){
                    return deleteFolder(folderName, folderPath);
                }
                else {
                        // this prints a message indicating why the deletion was cancelled
                    cout << "Folder deletion was cancelled by the user" << endl;
                    return false;
                }
            }
            return deleteFolder(folderName, folderPath);

        } else {
                // this prints a message indicating that the function was not successful
            cerr << "Folder '" << folderName << "' does not exist: "  << endl;
            return false;
        }
    } catch (const exception& e) {
            // this prints a message indicating that the function was not successful
        cerr << "Error in deleteFolder: " << e.what() << endl;
        return false;
    }
}