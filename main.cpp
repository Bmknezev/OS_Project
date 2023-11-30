
#include <iostream>

#include <string>

#include "functions.h"

using namespace std;



int main() {

    string choice;
    cout << "Welcome to the File Manager" << endl;

    do {
        //functions, new, remove, rename, write, modify, clear, read, copy, help, exit
        cin >> choice;

        if (choice == "new") {
            string fileName;
            cout << "Enter the name of the file: ";
            cin >> fileName;
            createFile(fileName);
        }
        else if (choice == "remove") {
            string fileName;
            cout << "Enter the name of the file: ";
            cin >> fileName;
            deleteFile(fileName);
        }
        else if (choice == "rename") {
            string oldFileName;
            string newFileName;
            cout << "Enter the name of the file to rename: ";
            cin >> oldFileName;
            cout << "Enter the new name of the file: ";
            cin >> newFileName;
            renameFile(oldFileName, newFileName);
        }
        else if (choice == "write") {
            string fileName;
            cout << "Enter the name of the file: ";
            cin >> fileName;
            writeTxt(fileName);
        }
        else if (choice == "modify") {
            string fileName;
            cout << "Enter the name of the file: ";
            cin >> fileName;
            modifyTxt(fileName);
        }
        else if (choice == "clear") {
            string fileName;
            cout << "Enter the name of the file: ";
            cin >> fileName;
            removeText(fileName);
        }
        else if (choice == "read") {
            string fileName;
            cout << "Enter the name of the file: ";
            cin >> fileName;
            readFile(fileName);
        }
        else if (choice == "copy") {
            string oldFile;
            string newFile;
            cout << "Enter the name of the file to copy: ";
            cin >> oldFile;
            cout << "Enter the name of the new file: ";
            cin >> newFile;
            copyFile(oldFile, newFile);
        }
        else if (choice == "help") {
            cout << "Commands:" << endl
            << "\tCreate a new file: new" << endl
            << "\tDelete a file: remove" << endl
            << "\tRename a file: rename" << endl
            << "\tCopy a file: copy" << endl
            << "\tMove a file from one directory to another: move" << endl
            << "\tAppend text to the end of a text file: write" << endl
            << "\tInsert text into a text file: modify" << endl
            << "\tRemove all text in a text file: clear" << endl
            << "\tRead all text from a text file: read" << endl
            << "\tGet help with using a command: <command> help" << endl
            << "\tExit the POFM: exit" << endl;
        }
        else if (choice == "exit") {
            cout << "Exiting..." << endl;
        }
        else {
            cout << "Invalid choice" << endl;
        }

    } while (choice != "exit");

}